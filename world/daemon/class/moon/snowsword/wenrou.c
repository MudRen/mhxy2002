#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int attackp, defendp;


        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("�������һ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

       // if( !objectp(target) || target->query("id") == "mu ren" )
         //       return notify_fail("��Ҫ����˭��������\n");

        if( me->query_temp("sucked") )
                return notify_fail("��ո��˹��������һ��!\n");

        if (!objectp(weapon = me->query_temp("weapon")) 
        || (string)weapon->query("skill_type") != "sword")
                  return notify_fail("������һ������ʼʱ�����н����֣�\n");
        if (me->query_skill_mapped("force")!="moonforce")  
         return notify_fail("������һ�����������Բ���ķ�����ʹ�á�\n");   
         if(me->query_skill_mapped("dodge")!="moondance")
         return notify_fail("������һ��������������������²���ʹ�á�\n");    

        if( (int)me->query_skill("moonforce", 1) < 140 )
                return notify_fail("���Բ���ķ�������죬����ʹ�á�����һ�������\\n");


        if( (int)me->query("force",1) < 500 )
                return notify_fail("����������������ܻ���Է�������\n");

        if( (int)target->query("force") <= 100 )
                return notify_fail( target->name() + "�Ѿ�û��ʲô�����ˣ�\n");

          message_vision( HIR "$NͻȻ�����ü������ᣬ����"+me->query_temp("weapon")->name()+"�������ǰһ�ͣ�������$n�Ĳ�֪ʲô��λƮȥ��\n" NOR,
                me, target );

        attackp = me->query_skill("force", 1)/2 + me->query_skill("moonforce", 1) + me->query_skill("dodge");
        defendp = target->query_skill("force") + target->query_skill("dodge");

        me->set_temp("sucked", 1);

        if( attackp / 2 + random(attackp) > defendp || !living(target) )
        {
                  message_vision(HIY "$pһʱ�������ܣ�ֻ�û�����˫�ֽ�����һ��,˫�ֵ�ʱ�类ճסһ��Ľ����ڽ����ϡ���\n" NOR, me, target );
                tell_object(me, HIB "���" + target->name() + "��ˣ���������Բ���ķ������Է�����������������...\n" NOR);
                 message_vision(HIY "$p�ƺ���˵ʲô������ȫ���������ֳ�����ʹ��ı��飬˫��ȴ�ֳ��Ѳ�������\n" NOR, me, target );
                tell_object(
                        target, HIB "����������΢΢һ��������ԴԴ������˳�ŶԷ�"+me->query_temp("weapon")->name()+"��ס����ӿȥ����\n" + 
                        "��ʱ����һ����ȫȻ�᲻������������ֻ���ζԷ���ȡ��������������\n" 
                        NOR);

                if( !target->is_killing(me) ) target->kill_ob(me);

                target->add("force", -1*((int)me->query_skill("moonforce", 1) + target->query("force_factor")) );
                if ( target->query("force") <1 ) target->set("force",0);
                me->add("force", (int)me->query_skill("moonforce", 1) + target->query("force_factor") );

                me->start_busy(1+random(2));
                target->start_busy(3+ random(7));
                me->add("force", -200);

                call_out("del_sucked", 10, me);
        }
        else
        {       
                message_vision(HIY "����$p������$P����ͼ��Ѹ�ٵرܿ�����һ����\n" NOR, me, target);
                me->start_busy(1+random(2));
                call_out("del_sucked", 10, me);
        }

        return 1;
}

void del_sucked(object me)
{
if (!me)
return;
        if ( me->query_temp("sucked"))
        me->delete_temp("sucked");
}
