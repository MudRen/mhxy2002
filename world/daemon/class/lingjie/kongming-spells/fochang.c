// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// preach.c
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        string msg;
        int damage, ap, dp;

        if( !target ) return notify_fail("cast peach on sb\n");

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭�󳪣�\n");

        if( me->query_temp("preaching") )
                return notify_fail("�������󳪣�\n");

                if (!me->query("rulai/0808"))
                
                return notify_fail("û����������������ô���Ȱ˵��\n");
                
       
        
        if((int)me->query("mana") < 70 )
                return notify_fail("��ķ���������\n");

        if((int)me->query("sen") < 70 )
                return notify_fail("���޷����о�����\n");
        
        write("��Ҫ��Ȱ�����������ϵ�ʲô������");
        input_to( (: call_other, __FILE__, "select_object", me, target :));        
        return 1;
}

void select_object(object me, object target, string name)
{
        object ob;
        int sp,dp;
        if(!name||name==""){
                write("ֹͣ�󳪡�\n");
                return;
        }        

        if( !ob = present(name, target) ) {
                object *inv;
                inv = all_inventory(target);
                if( !sizeof(inv) ){
                        write( target->name() + "���Ͽ�����û��ʲ������ֵ���󳪶�����\n");
                        return;
                }
                ob = inv[random(sizeof(inv))];
        }

        if ( ob->query("no_drop") || ob->query("owner")){
                write(target->name()+"���󲻻�������Ƶġ�\n");
                return;
        }

        sp = (int)me->query_skill("spells",1) * (int)me->query_skill("spells",1) 
         + (int)me->query_cps() * (int)me->query_cps() * (int)me->query_cps() ;
       /* if( sp < 5000 ){
            write("�㻹û�е����󳪵Ľ׶Ρ�\n");
            return;
        }
                */
        dp = (int) target->query("faith")-(int)target->query("bellicosity") + 
        (int)target->query_cps() * (int)target->query_cps() * (int)target->query_cps() * (int)target->query_cps() +
        (int)target->query_int()*(int)target->query_int()*(int)target->query_int();
        tell_object(me, "��ׯ�ϵ���" + target->name() + "��˵��"
                        + ob->query("unit") + ob->name() +"�����ֻ���...\n\n");
        tell_object(target, me->name() + "����ׯ�ϣ�����������˵������λ" + RANK_D->query_respect(target) + "���������Σ�����" 
                        + ob->query("unit") + ob->name() + "�� ...��\n\n");
        message("vision", "ֻ��" + me->name() + "����ׯ�ϣ��������࣬\n��" 
                + target->name() + "�����䷳�����ţ�����",environment(me), ({ me, target }) );

        if( ob->query("equipped"))dp=dp*2;
        
        me->set_temp("preaching", 1);
        me->add("mana", -50);
        me->receive_damage("sen", 50);
        call_out( "compelete_preach",random(3)+1, me, target, ob, sp, dp);
}

private void compelete_preach(object me, object target, object ob, int sp, int dp)
{
        int amount;
        object ob1;

        me->delete_temp("preaching");
        if(!target) {
                tell_object(me, "̫��ϧ�ˣ����󳪵����Ѿ������ˡ�\n");
                return;
        }
        if( environment(target) != environment(me) ) {
                tell_object(me, "̫��ϧ�ˣ�������һ������ˡ�\n");
                return;
        }

        if(!target->query("spi")) {
                tell_object(me,target->name()+"��������޶����ԣ�\n");
                return;
        }
        if( living(target) && (random(sp+dp) > dp/2) && ob->move(environment(me))) 
        {
                                        message_vision("$N����$n���󳪣����ид���һ��������һ" 
                                + ob->query("unit") + ob->name() + "���ڵ��¡�\n",target,me);
                                target->die();
                                me->add("rulai/teshu",1);
                                me->set("rulai/0808",0);
             me->start_busy(1);
        } 
        else 
        {
                if( random(sp+dp) > dp/3 ) {
                message_vision("$N��һ����ʯ�㣬��$n���󳪺�����ᡣ\n", target,me);
             me->start_busy(2);
                        //target->unconcious();
                        return;
                }
                else
                message_vision("$N�ݺݵص���$nһ�ۣ��ȵ��������ᣡȥ���˰ɣ�\n", target,me);
                if(!environment(target)->query("no_fight"))     
              target->fight_ob(me);
                        //target->unconcious();
         me->start_busy(2);
        }
}
