#include <ansi.h>
#include <armor.h>
inherit SURCOAT;
void create()
{
  set_name(HIY "�ƽ�����" NOR, ({"golden pifeng", "pifeng"}));
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("unit", "��");
    set("value", 400000);
    set("armor_prop/armor", 70);
    set("armor_prop/courage",8);
  }
  setup();
}
