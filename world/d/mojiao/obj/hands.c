#include <ansi.h>
#include <armor.h>
inherit HANDS;
void create()
{
  set_name(HIY "�ƽ�����" NOR, ({"golden hands", "hands"}));
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "golden");
    set("unit", "ֻ");
    set("value", 400000);
    set("armor_prop/armor", 50);
  }
  setup();
}
