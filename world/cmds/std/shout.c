// shout.c
// By tianlin@mhxy for 2001.9.21���¸�д
// �벻Ҫ��,лл
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        if((int)me->query("max_force") < 2000&& !wizardp(me)  )
                return notify_fail("���������򲻹���\n");
        if((int)me->query("force") < 800&& !wizardp(me)  )
                return notify_fail("��û�������˿���ٽ��ˣ�\n");
        if((int)me->query("daoxing") < 686000&& !wizardp(me)  )
                return notify_fail(HIB"��ĵ��в���,�޷���ᵽ"HIY"shout"HIB"�İ���֮����\n"NOR);
        if((int)me->query("sen") < 500&& !wizardp(me)  )
                return notify_fail(HIB"���������,����Ϣһ�°�\n"NOR);
	 if( time()-(int)me->query_temp("shout_temp") < 8&& !wizardp(me) )
                return notify_fail(RED"��ոս���,���ǵȻ��ڽаɣ�\n"NOR);
        if (!arg) return notify_fail("����Ҫ���ʲô��\n");
          shout(HIR + me->name() +  "������Х��"HIW+ arg + "\n" NOR);//this is by tianlin 2001.
          write(HIR "��������Х��"HIW+ arg + "\n" NOR);
	 if( !wizardp(me) )
          me->add("force", -100);
	 if( !wizardp(me) )
          me->add("sen", -500);
	 if( !wizardp(me) ) 
          me->set_temp("shout_temp",time());
        return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : shout <ѶϢ>
 
���ָ�����㽫 <ѶϢ> ���ͳ�ȥ, ����������Ϸ�е��˶�
��������Ļ�. ���� (������Ϊ20������,Ҫ�����һ��ǧ��
ʹ��һ�ε�500�㾫��,100������.)
 
see also : tune
HELP
    );
    return 1;
}
