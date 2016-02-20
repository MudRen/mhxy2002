//By tianlin@mhxy for 2002.1.17

#include <skill.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int finish(object me, int kee_cost);

int main(object me, string arg)
{
        int kee_cost, busy_time ;
        string force_name;
        seteuid(getuid());
        
        if(environment(me)->query("no_fight")  ||
           environment(me)->query("no_magic") )
              return notify_fail("��ȫ���ڽ�ֹ������\n");
              
        if( !stringp( force_name = me->query_skill_mapped("force") ) )
                return notify_fail("��������� enable ѡ����Ҫ�õ��ڹ��ķ���\n");
        if (me->is_busy() || me->query_temp("pending/exercising")
                || me->query_temp("doing_xiudao")|| me->query_temp("pending/meditating"))
              return notify_fail("��������æ���أ��Ȼ����˵�ɡ�\n");  
    
        if( me->is_fighting() )
                return notify_fail("ս���в������ڹ������߻���ħ��\n");

        if( !stringp(me->query_skill_mapped("force")) )
                return notify_fail("��������� enable ѡ����Ҫ�õ��ڹ��ķ���\n");

        if( !arg
        ||      !sscanf(arg, "%d", kee_cost) )
                return notify_fail("��Ҫ��������������\n");

        if( kee_cost < 10 ) return notify_fail("������Ҫ�� 10 �㡸��������������\n");

        if( (int)me->query("kee") < kee_cost )
                return notify_fail("�����ڵ���̫���ˣ��޷�������Ϣ����ȫ������\n");
        me->receive_damage("kee", kee_cost);
 
        force_name = to_chinese(force_name);
        write(HBRED+HIW"������" + HIC + force_name + NOR + HBRED+HIW + "��һ����Ϣ�Ե���ӿ�ϣ���ʼ������������\n"NOR);
        me->set_temp("pending/exercise", 1);
        if(busy_time<0) busy_time = 0;
        me->start_busy(1);
        
        call_out("finish",1, me, kee_cost);
        return 1;
}

int finish(object me, int kee_cost)
{
        int force_gain;

        // This function ranged from 1 to 15 when kee_cost = 30
        force_gain = kee_cost * ((int)me->query_skill("force", 1)/10
                + (int)me->query_con()/2+random(25)) / 25;

        me->set_temp("pending/exercise", 0);
        if( force_gain < 1 ) {
                tell_object(me, "���ǵ����й���ϣ�ֻ����ȫ���顣\n");
                me->start_busy(1);
                return 1;
        }

        me->add("force", force_gain );
        tell_object(me, "���й���ϣ���һ����������վ��������\n");

        if( (int)me->query("force") > (int)me->query("max_force") * 2) {
                if( (int)me->query("max_force") >= 
                (int)me->query_max_force() ) {
                        tell_object(me, "�������Ϣ�鲼ȫ����ʱȴû�й��������ļ����ƺ�������Ϊ�Ѿ�������ƿ����\n");
                } else {
                        tell_object(me, "���������ǿ�ˣ�\n");
                        me->add("max_force", 1);
if ( (int)me->query("max_force") > (int)me->query("maximum_force"))
me->set("maximum_force", (int)me->query("max_force"));
                }
                me->set("force", me->query("max_force"));
        }       
        
        me->start_busy(1);
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : exercise|dazuo [<�ķѡ�����������Ԥ��ֵ 10>]

�����������������ڵ����ڸ�����������������ѵ�����弡���������
��������������������������ʽ����������������

��ο� help stats
HELP
        );
        return 1;
}
