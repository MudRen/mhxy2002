//By tianlin@Mhxy for 2002.1.20,����ɱ���˲���lian

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string skillname;
        int skill, skill_basic,time;
        int i;
        seteuid(getuid());
        if( environment(me)->query("no_fight") || 
                environment(me)->query("no_magic") )
                   return notify_fail("��ȫ���ڽ�ֹ������\n");

        if( me->is_fighting() )
                return notify_fail("���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");

        if( me->query("PKS")>0 )
                return notify_fail("���ɱ���ˣ������������±�����ɱ�㡣\n");

        if( !arg ) return (__DIR__"enable")->main(me, arg);

        if(sscanf(arg, "%s %d", arg, time)!=2 )

        if(sscanf(arg, "%s %d", arg, time)!=2 )
            time=1;

        if(time<1) time=1;
        if(time>50) time=50;

        if( !stringp(skillname = me->query_skill_mapped(arg)) )
                return notify_fail("��ֻ����ϰ�� enable ָ�������⼼�ܡ�\n");
        skill_basic = me->query_skill(arg, 1);
        skill = me->query_skill(skillname, 1);

        if( skill < 1 )
                return notify_fail("�����û��ѧ�᡹����ܰɣ������ȥ��̱��ˡ�\n");
        if( skill_basic < 1 )
                return notify_fail("����ⷽ��ļ��ܻ���һ�ϲ�ͨ����ô��ȴӻ���ѧ��\n");

        if( skill*skill*skill/10 > (int)me->query("combat_exp") )
                return notify_fail("�����ѧ�������������ٶ�Ҳû�á�\n");

        notify_fail("�����ڲ�����ϰ����ܡ�\n");
        if( !SKILL_D(skillname)->valid_learn(me) ) return 0;
        notify_fail("��������ϰ" + to_chinese(skillname) + "�����ǲ�û���κν�����\n");
        if(skill_basic <= skill && random(100)==0)
          write("���" + to_chinese(skillname)+ 
            "��������ˣ���������ʦ�������̰ɣ�\n");
        if( SKILL_D(skillname)->practice_skill(me) ) 
        {
        for(i=0;i<=time;i++) {
                me->improve_skill(skillname, skill_basic/5+1, skill_basic > skill? 0: 1);
                me->add("sen", -5);
                              }
                write( HIY "���" + to_chinese(skillname) + "�����ˣ�\n" NOR);
                return 1;

        }

        else return 0;
}

int help(object me)
{
        write(@TEXT
ָ���ʽ��practice <��������>

��: practice parry 50
���ָ��������ϰĳ������ļ��ܣ�������ܱ����Ǿ��� enable ��רҵ���ܡ�
��������Ļ��������㹻�ߣ����Ծ�����ϰֱ����������������������ֻ��
��������ܵĵȼ��йأ����仰˵���ڼ���ϰ��ʹ�����ѧ���������ʤ������
��Ψһ;������Ȼ������֮ǰ������ʵ�������л���㹻�ľ�����������Ļ�
�����ܡ�
TEXT
        );
        return 1;
}

