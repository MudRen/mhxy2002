//Cracked by Roath
#include <weapon.h>

inherit F_UNIQUE;
inherit STAFF;

void create()
{
        set_name( "��ͷ����", ({ "dragon staff", "zhang", "staff" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����ɫ��ͷ���ȣ����»���Щ���Ʒɷ�֮��Ļ��ơ�
���ֳ��أ�һ����֪���Ƿ��\n");
                set("value", 0);
                set("no_sell",1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_put", 1);
				set("replace_file", "/d/obj/weapon/staff/shugan");
                set("wield_msg", "$N�ó�$n����������ﻹ�����˼�����\n");
                set("unwield_msg","$N�����е�$n������\n");
        	set("weapon_prop/intelligence", 5);
                set("material", "wood");
        }
        init_staff(30);
        set("is_monitored",1);
        setup();
}
void announce(object who)
{
    if(!this_object()) return;
    if(!who) return;
    CHANNEL_D->do_channel(this_object(), "rumor", 
	    "��˵[1;33m"+who->query("name")+"[2;37;0m[1;35m�õ��˴�˵�е�[37m"+name()+"[2;37;0m[1;35m��[2;37;0m\n");
}
 void init()
{
    call_out("self_dest",1+random(1),this_object());
    remove_call_out("announce");
    call_out("announce",random(1),this_player());
} 
