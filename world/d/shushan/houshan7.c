//shushan by yushu 2000.11
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", HIR "��" HIG "̨��" HIR "��" NOR);
  set ("long", @LONG

����ʯ�̳ɵ�̨�ף�ʪ������̨�����泤����޺̦����С�ĵ�
���ţ�����һ��С�Ļ���������ǰ�߾��ǡ���ɽ�����ˡ�
LONG);

  set("outdoors", 2);
  set("exits", ([ /* sizeof() == 1 */
       "down" : "/d/shushan/houshan6",
      "north" : "/d/shushan/hsg",
 ]));

  setup();
}






