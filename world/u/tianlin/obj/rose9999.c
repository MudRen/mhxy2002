//by tianlin 2001/5/1
#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit NECK;

//#include "message.h"

void create ()
{
  set_name("[44m[1;35m��ǧ�Űپ�ʮ�Ŷ�õ��[2;37;0m", ({ "flower"}));
  set_weight(100);
  set("long","һ��õ�壬�͸��ҵİ���"+query("name")+"��\n");
  set("unit", "��");
  set("armor_prop/armor", 5);
  set("armor_prop/personality", 6);
  set("unequip_msg","$N��"+query("name")+"�����ժ����������\n");
  set("wear_msg", "$N����"+query("name")+"�����������������˵����ᡣ\n");
  setup();
}


