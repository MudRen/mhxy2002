// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */

// jiudai.c  �ƴ�

inherit ITEM;
inherit F_LIQUID;
inherit F_AUTOLOAD;

int query_autoload() { return 1; }
void create()
{
   set_name("����ɽ", ({"yan"}));
   set_weight(20);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "����һ������δ������κ��˶�û�м���������,������ӡ���ĸ�С��:�ռ�����\n");
     set("unit", "��");
     set("value", 20);
     set("max_liquid", 9000000000);
   }
}
