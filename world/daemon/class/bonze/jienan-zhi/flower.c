#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int damage, ap, dp;
        int number, size, i, four,amount;
        object *tar;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ������մ������\n");

        if((int)me->query("force") < 50+(int)me->query("force_factor") )
                return notify_fail("�������������\n");
        if((int)me->query("kee") < 200 )
                return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("jienan-zhi", 1) <100)
                return notify_fail("��Ľ���ָ���𻹲�����\n");
              if((int)me->query_skill("huadao", 1) < 20)
                return notify_fail("��Ի����������˽⣡\n");

        tar=all_inventory(me);
        size = sizeof(tar); 
        if(size) {
                for(i=0;i<size;i++)
                if(tar[i]->query("material") == "flower") {
                        if (tar[i]->query_amount())
                              number+=tar[i]->query_amount();
                        else number++;
}
}
        write((string)number+"\n");

        if((int)number < 1)
               return notify_fail("�������޻�������մ����\n");

        me->add("force", -50-(int)me->query("force_factor"));
        me->receive_damage("kee", 100);
        msg = HIG
"\n$N��¶����Ц�ݣ���������ָ£�����У���մ��״\n"+
"$n�е���̬���һʱ�䲻֪���ԣ�ֻ���������������������æ���ܣ�\n" NOR;

        ap = me->query_skill("jienan-zhi", 1)+me->query_skill("huadao",1);
        ap = ( ap * ap * ap / (4 * 400) );
        ap = ap*250 + (int)me->query("combat_exp");
        dp = target->query_skill("parry");
        dp = ( dp * dp * dp / (4 * 400) );
        dp = dp*250 + target->query("combat_exp"); 
        if( random((ap + dp)/1000+1) <  dp/1000 ) {
                msg += HIC "����$n��ļ�ʱ��ָ���������������󰭣�\n\n"NOR;
                message_vision(msg, me, target);
        } else {
damage = 50+random(50)+(int)me->query("force_factor")+random((int)me->query_skill("huadao",1))*2;
                msg += HIC "������ָ�翴������������ȴ�缲�罫$n����������������ɢȥ��\n" NOR;
                       target->receive_wound("sen", damage);
                        target->receive_wound("kee", damage);
                                           target->add("force",-damage/10);
                        me->improve_skill("jienan-zhi", 1, 1);
                message_vision(msg, me, target);
}

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
}
}

        for (i = 0; i< size; i++){
           if (tar[i]->query("material") == "flower"){
                amount=tar[i]->query_amount();
                if (amount) four+=amount;
                  else four++;
                if (four <= 1)
                destruct(tar[i]);
                else {
                       tar[i]->set_amount(four-1);
                       four=1;
                       break;
}
}
}
        me->start_busy(random(4));
        return 1;
}
