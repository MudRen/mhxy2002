//by tianlin 2001.7.31

#include <ansi.h>
#include <weapon.h>

inherit RAKE;

void create()
{
  set_name(HIY"��ת"NOR+CYN"����"NOR+HIC"��"NOR, ({ HIR"jingang pa"NOR, "pa","rake" }) );
  set_weight(19000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 138000);
    set("material", "iron");
    set("long", "����һ����ղ����İ��ӡ�\n");
    set("wield_msg", "$N����һ��$n������һ���ٹ�ͷ����\n");
  }
  init_rake(175);
  setup();
}


