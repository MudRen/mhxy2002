//jueshi.c by yushu 2000.11
#include <weapon.h>
#include <ansi.h> 
inherit F_UNIQUE;
inherit SWORD;
void create()
{
        set_name(RED"�콣"NOR, ({"sky sword", "sword", "jian"}));
        set_weight(50000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
              set("unit", "��");
              set("long", "һ�ѵ���ɫ��ϸ�����������ǳ��Ļ�����\n");
              set("no_sell", 1); 
              set("no_give", 1);
              set("no_drop", 1);
              set("no_put", 1);
              set("value", 30000); 
              set("replace_file", "/d/obj/weapon/sword/qinghong");
              set("material", "gold");
              set("wield_msg", "$N��ৡ���һ�����һ��$n�������У�\n");
              set("unwield_msg", "$N�����е�$n�������䣬���¶��һ˿Ц�⣮\n");
              set("weapon_prop/int", 2);

        }
        init_sword(150); 
        set("is_monitored",1);
        setup();
}

void announce(object who)
{
    if(!this_object()) return;
    if(!who) return;
    CHANNEL_D->do_channel(this_object(), "rumor", 
            "��˵"+who->query("name")+"�õ���"+name()+"��\n");
}
void init()
{
    call_out("self_dest",1200+random(600),this_object());
    remove_call_out("announce");
    call_out("announce",random(10),this_player());
}


