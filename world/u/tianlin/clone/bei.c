//by angela@mhxy 2001.12.25
#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
      set_name(HIY"���ȱ�"NOR, ({"kafei bei", "bei"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 2000);
                set("long", HIY"����"HIW"�����衡�ɡ�ѩ"HIY"�Ŀ��ȱ�"BLINK""HIC"
         _..,----,.._
      .-;'-.,____,.-';
     (( |            |
      `))            ;
       ` \          /
      .-' `,.____.,' '-.
     (     '------'     )
      `-=..________..--'
 \n"NOR);
                set("no_sell", 1);
                set("material", "steel");
                set("armor_prop/spells", 5);
                set("armor_prop/armor", 1);
                set("armor_prop/intelligence", 10);
                set("no_drop","��ô�õı������˶��ϧѽ��\n");
                set("no_sell", 1);
        }
        setup();
}

 