//jiz.

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        int mypot,tapot,time;

        if( !target ) target = offensive_target(me);

        if( !target

        ||      !target->is_character()

        ||      !me->is_fighting(target) )
               return notify_fail("��������ʧ��ֻ����ս���в���ʹ�á�\n");
        if(me->query("family/family_name")!="����ɽ���Ƕ�")
               return notify_fail("�Ƿ���ɽ���Ƕ������á�������ʧ����\n");
        if( (int)me->query_skill("qianjun-bang", 1) < 150 )
                return notify_fail("�����Ϊ�������ʹ������һ�У�\n");
        if( target->is_busy() )
                return notify_fail(target->name()+"������Ķ�������ʹ�Է���ã��\n");

       message_vision(WHT"$N���б���������������������ʣ���$n����������
 $n�·𿴵����Լ��Ĺ�ȥ�����������޵Ļ�����ȥ��\n\n"NOR,me, target);

        mypot=(int)me->query_skill("stick");
    mypot=mypot*mypot*mypot/3 + random( (int)me->query("combat_exp"));

        tapot=(int)target->query_skill("parry");
        tapot=tapot*tapot*tapot/10 + random( (int)target->query("combat_exp"));

     time=(int)me->query_skill("qianjun-bang", 1) /4;
        if ( time > 10 ) time = 10;
        if ( time < 3  ) time = 3;

        if ( random( mypot + tapot ) > tapot ) {
                       message_vision(HIC"$N������վ���ţ�һ��������ʧ�ĸо�ӿ����ͷ����ʱ�����Լ�����ս���У�\n"NOR,target);
         target->start_busy(3+random(time));
          me->start_busy(random(2));

        }else {
        message_vision(HIC"����$N�ܿ�ӻ����н��ѳ���������Ͷ��ս����\n"NOR,target,
me);
               me->start_busy(1+random(3));
        }

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
                me->kill_ob(target);
        }
        return 1;
}
