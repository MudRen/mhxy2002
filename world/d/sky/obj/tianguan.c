// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>
#include <ansi.h>

inherit HEAD;
inherit F_UNIQUE;

void create()
{
  set_name(HIY"�����" NOR, ({ "tian guan", "guan" }) );
  set_weight(700);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long","һ����ϼ��֯�Ľ�ɫ��ڣ��������ž�����צ������\n");
    set("value", 800);
    set("armor_prop/armor", 10);
    set("armor_prop/spells", 30);
    set("armor_prop/dodge", 30);
    set("replace_file", "/d/qujing/tianzhu/obj/longguan");
    set("material", "silk");
    set("armor_prop/personality", 1);
  }
  setup();
}

