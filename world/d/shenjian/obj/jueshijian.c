//By tianlin@mhxy for 2001.10.7

#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE; 
inherit SWORD;

void create()
{
    set_name(HIR"��"NOR+HIW"����"NOR+HIC"��"NOR, ({ YEL"jueshihao jian"NOR,"jueshihao jian","jian" ,"baojian" ,"sword" }) );
    set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "��");
        	set("value", 123311);
        	set("no_sell", "1");
        	set("no_give", "1");
        	set("no_put", "1");
	       set("replace_file", "/d/obj/weapon/sword/qinghong");
        	set("armor_prop/armor", 50);
        	set("armor_prop/personality", 50);
        	set("material", "iron");
              set("rumor_msg",1);
        	set("long", "������ɽׯ����ɽ����,Ҳ���������еı���,һ�������ò������ġ�\n");
        	set("wield_msg",HIY"$N�͵ذγ�$n"NOR+HIY"����˳��ת����Ȧ��\n"NOR);
        	set("unwield_msg", HIG"$N���������е�$n"NOR+HIG"����������\n"NOR);
	}
    	init_sword(200);
	setup();
}
void self_dest(object me)
{
    if(!me) return;
    if(!environment(me)) return;
    tell_object(environment(me),name()+
	    "һ������������$n��ͻ��������ϼ�������ˣ�\n");
    destruct(me);
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int pro;
        int dam;
        pro = (int) victim->query_temp("apply/armor_vs_fire");
        dam = (int) me->query("force");
        if(dam > pro)
        {
        victim->receive_wound("kee",50);
        victim->receive_wound("sen",50);
        return HIR"��"NOR+HIW"����"NOR+HIC"��"NOR+HBRED+HIW"ͻȻ������������,���"NOR+BLINK+MAG"��$n"NOR+MAG+BLINK"��"NOR+HBRED+HIW"���ñ���Щ�������ˡ�\n" NOR;
        }
}


