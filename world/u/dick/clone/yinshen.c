//by tianlin 2001.5.1
//δ����!
#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
      set_name(HIY"����ѫ��"NOR, ({"yinshen zhang", "zhang"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 2000);
                set("long", HIY"����������õ�ѫ��! \n"NOR);
                set("no_sell", 1);
                set("material", "steel");
                set("armor_prop/spells", 5);
                set("armor_prop/armor", 1);
                set("armor_prop/intelligence", 10);
                set("env/invisibility", 1);
                set("no_drop","��ô�õı�����˶��ϧѽ��\n");
                set("no_sell", 1);
        }
        setup();
}
int query_autoload() { return 1; }

 