// rake.c

#include <weapon.h>
#include <ansi.h>

inherit RAKE;

void create()
{
  set_name("����"NOR, ({ "zhu pa", "pa","rake" }) );
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 8000);
    set("material", "iron");
    set("long", "һ����������ҡ�\n");
    set("wield_msg", "$N����һ��$n������һ���ٹ�ͷ����\n");
  }
  init_rake(35);
  setup();
}


