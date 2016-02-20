#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)

  {
//              string msg;
        object weapon = me->query_temp("weapon");
        int cost = me->query_skill("qianjun-bang", 1)/2;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("ǣ�ƹ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if(!living(target))
                return notify_fail("���˱����Ͳ��ܶ�,����ʲô��ʥ��ƣ�\n");
        if(!weapon || weapon->query("skill_type") != "stick" )
                return notify_fail("������û�а��ӣ����ʹ�á���ʥ��ơ��־���\n");
        if(me->query_temp("YSJL/chan"))
                return notify_fail("������ʹ�á���ʥ��ơ��־���\n");
        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");
        if( (int)me->query_skill("qianjun-bang", 1) < 100 )
                return notify_fail("���ǧ��������������죬��Ҫ���������ˡ�\n");
              if(me->query_temp("last_zuijiu")+5>time())
                return notify_fail("��ո�ʹ������ʥ��ơ�,��ЪһЪ�ɡ�\n");
        if( me->query("force") <= 500 )
                return notify_fail("�������������\n");
        if( me->query("max_force") <= 700 )
                return notify_fail("���������Ϊ������\n");
        if(me->query_temp("combat_wield"))
                return notify_fail("��û�ð��ӣ�����ʹ������ʥ��ơ���\n");
        if (me->query_skill_mapped("stick") != "qianjun-bang")
                 return notify_fail("�������޷�ʹ�á���ʥ��ơ���\n");
        if(userp(me)){
    
            if( (int)me->query_skill("wuxiangforce", 1) < 100 )
                return notify_fail("�����������Ϊ���������ܰ����б�����������ʥ��ơ���\n");
            if( me->query_skill_mapped("force") != "wuxiangforce")
                return notify_fail("�����õ��ڹ���ǧ������������㣣�\n");
            }
        me->add("force", -cost);
        me->add("mana", -10);

        message_vision(CYN"\n$NĬ��������,�������д�"+weapon->name()+CYN"�к��������м���ǿ�ҵľ�ζ���ڿ�����һȦȦƯ�ţ�
�þò�ɢ���������ۣ������ۼ�װ������ͻȻֻ��������һ���������$n������\n\n"NOR, me, target);
        if( ((random(me->query("combat_exp")) + (me->query("combat_exp")/4) > (int)target->query("combat_exp")*1/2 ))) {
                message_vision(HIW"$nһ�������Ҹ�����,��ʱĿ�ɿڴ���\n"NOR,me, target);
                target->start_busy(3);
                me->start_busy(random(2));
        } else {
                message_vision(HIY"����$p������$P����ͼ����û���ϵ���\n" NOR, me, target);
                me->start_busy(random(1));
        }
                                                 
        me->set_temp("last_zuijiu",time());
        return 1;
}
