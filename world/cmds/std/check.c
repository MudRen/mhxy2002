//by tianlin@mhxy 2001.5.1.
//check.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me,string arg)
{
        object ob;
        int mana_cost;
        int sen_cost;
        string msg;

        if(!arg) 
                return notify_fail("�������˭��״̬��\n");
        if((int)me->query("daoxing")<5000)
                return notify_fail("��ĵ��в������ò��˵ض��顣\n");
        if((int)me->query("mana")<60) 
                return notify_fail("��ķ����������ò��˵ض��顣\n");
        if((int)me->query("sen")<=50)
                return notify_fail("������̫���ˣ���Ϣ��Ϣ�ɣ�\n");
        mana_cost=-(100-(int)me->query_skill("spells"))/4-40;
        mana_cost=mana_cost+10;
        if(mana_cost > -50) mana_cost=-50;
        me->add("mana", mana_cost);
        sen_cost=50;
        message_vision(HIY "$N���˸��䣬����������϶���������[1;37m��˳�����[2;37;0m[1;33m���в��ӣ��ش����������\nֻ��һ���������һ����ɫ���ŵļһ���$N���ߵ���˵�˼��仰��\n" NOR, me);
        ob = find_player(arg);
        if(!ob) {
            ob=present(arg,environment(this_player()));
            if(ob && !living(ob)) ob=0;
        }
        if( !ob ) ob = find_living(arg);
        if(!ob || (ob->query("env/invisibility") && wizardp(ob) ))
                return notify_fail("˳���������˸���˵����С�˷�����ǳ��ʵ���Ҳ�������ˣ�����\n");
        
        write("˳��������㣺"+ob->query("name")+"[2;37;0m��[1;33m����[2;37;0m�Ѵ�"+RANK_D->describe_dx((int)ob->query("daoxing"))+"�ľ��硣\n");  
        write("˳��������㣺"+ob->query("name")+"[2;37;0m��[1;36m�书[2;37;0m�Ѵ�"+RANK_D->describe_exp((int)ob->query("combat_exp"))+"�ľ��硣\n");
        write("˳��������㣺"+ob->query("name")+"[2;37;0m��[1;37m����[2;37;0m��Ϊ�Ѵ�"+RANK_D->describe_fali((int)ob->query("max_mana"))+"�ľ��硣\n");   
        write("˳��������㣺"+ob->query("name")+"[2;37;0m��[1;31m����[2;37;0m��Ϊ����"+RANK_D->describe_neili((int)ob->query("max_force"))+"�Ļ��\n"); 


        message_vision("$N��ȻĪ������ض�����һ�¡�\n",ob); 
        msg="�㼱æ��ָһ�㣬";
        if(ob->query("daoxing")>me->query("daoxing")/5)
          msg+="ԭ����[5m[1;32m"+me->name()+"("+me->query("id")+")"+
               "[2;37;0m���ڴ�����ĵ��С�\n";
        else
          msg+="����ȴֻ��һƬãȻ��[2;37;0m\n";//By tianlin@mhxy for 2001.10.7�Ҹ�����������
        tell_object(ob, msg);

        return 1;
}

int help(object me)
{
        string desc_dx, desc_fali, desc_exp;

        write(@HELP
ָ���ʽ : check|cha [<ĳ��>]

�ض���: �����������ڵĵ���,�������书����

HELP
    );

        write("���о��磺\n\n");
        write(RANK_D->query_description(0));
        write("\n��ѧ���磺\n\n");
        write(RANK_D->query_description(1));
        write("\n������Ϊ��\n\n");
        write(RANK_D->query_description(2));
        write("\n\n");  
                
    return 1;
}