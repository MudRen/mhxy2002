// rake.c

#include <weapon.h>
#include <ansi.h>

inherit RAKE;

void create()
{
    set_name(WHT"�ų�������"NOR, ({ "tianpeng pa", "pa","rake" }) );
  set_weight(9000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 8000);
    set("material", "iron");
    set("long", "һ�������ľųݸְҡ�\n");
    set("wield_msg", "$N����һ��$n������һ���ٹ�ͷ����\n");
  }
  init_rake(155);
  setup();
}


