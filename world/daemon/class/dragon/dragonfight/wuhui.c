//Cracked by Roath
//by tianlin 2001.8�޸�
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
	int i, j;	        
	if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʹ����һ�С�"+HIY"��"NOR+HIC"��"NOR+HIW"��"NOR+HIR"��"NOR+"����\n");

        if(!me->is_fighting())
                return notify_fail("��"+HIY"��"NOR+HIC"��"NOR+HIW"��"NOR+HIR"��"NOR+"��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if(me->query("family/family_name") != "��������" )
                return notify_fail("�����Ķ�͵ѧ�����书��Ҳ��ʹ�ã�\n");

        if( (int)me->query_skill("dragonfight",1) < 120)
        return notify_fail("������в�������������!!\n");

        if((int)me->query("force") < 700 )
                return notify_fail("�������������\n");

        if((int)me->query("kee") < 200 )
                return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");

        weapon=me->query_temp("weapon");

        if( me->query("env/brief_message") ){
                i=1;
        } else {
                i=0;
        }
        if( target->query("env/brief_message") ){
                j=1;
        } else {
                j=0;
	}

	me->delete("env/brief_message");
	target->delete("env/brief_message");

	message_vision(YEL"\n$N˫��ƽƽ�ᵽ��ǰ����ɫ���صĻ���ʩ������ָ�����һ�С�"+HIY"��"NOR+HIC"��"NOR+HIW"��"NOR+HIR"��"NOR+YEL"��һ�а�ʽ����Է���"NOR, me);

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
       message_vision(HIC"\n��һʽ��$N����һʽ��������Ұ���������ޱȵ�����Է���\n"NOR, me, weapon);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
       message_vision(HIR  "�ڶ�ʽ��$N˫��ʩ��һʽ��������½��������ԼԼ�����Ʒ�����Է���\n"NOR, me, weapon);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
       message_vision(HIB  "����ʽ��$N�������أ�����һʽ��Ǳ����������������Է���\n"NOR, me, weapon);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
       message_vision(HIY  "����ʽ��$Nʹ������Ծ���졹����Է����������ƣ�\n"NOR, me, weapon);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
       message_vision(HIG "����ʽ��$N˫��һʽ��˫��Ϸˮ��һǰһ����Է�����ǰ��\n"NOR, me, weapon);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
       message_vision(HIM  "����ʽ��$N����ת����ʹ����������������Է��������£�\n"NOR, me, weapon);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
       message_vision(YEL  "����ʽ��$N����һת��ͻȻ�۵��Է���ǰ��һʽ����ս��Ұ��ֱ����Է�����. \n"NOR, me, weapon);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
       message_vision(HIW "�ڰ�ʽ��$NͻȻ����˫�ƾӸ��������һʽ����Х���졹ȫ������Է���\n"NOR, me, weapon);
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"));


        if( i ) me->set("env/brief_message", 1);
        if( j ) target->set("env/brief_message", 1);

	me->receive_damage("kee", 100);
	me->add("force", -400);//�Ҹ������һ��

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

	me->start_busy(3);//�Ӵ�busy
	return 1;
}
