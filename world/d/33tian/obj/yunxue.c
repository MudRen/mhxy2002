// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>
#include <ansi.h>

inherit BOOTS;
inherit F_UNIQUE;

void create()
{
  set_name( HIG "��Ӱ��ѥ" NOR, ({ "yun xue", "yunxue", "xue" }) );
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "˫");
    set("long", "һ˫�������ʵص�ѥ�ӡ�\n");
    set("value", 120);
    set("material", "boots");
    set("no_sell",1);
    set("material", "boots");
    set("armor_prop/dodge", 30);
    set("armor_prop/spells",15);
    set("replace_file", "/d/qujing/tianzhu/obj/yunxue");
  }
  setup();
}

