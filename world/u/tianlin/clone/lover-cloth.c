#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(RED"�������ȹ"NOR, ({ "lover cloth", "cloth" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
  set("long", "����һ��С���������ȹ�ӣ���Ϊ���Ļ۸�������\n");
  set("unit", "��");
  set("value",100000);
  set("material", "cloth");
  set("armor_prop/armor", 100);
  set("armor_prop/personality", 100);
 set("wear_msg",HIY "ֻ��$N�������ֵ�����һ��$n��NOR\n");
                set("unequip_msg",HIY "$N�����ϵ�$n����������NOR\n");
        }
        setup();
}