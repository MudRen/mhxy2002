//shushan by yushu 2000.11
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short",HIR "��" HIY "������" HIR "��" NOR);
  set ("long", @LONG

����׷���Ӻ������������ĵط������������С��¯�������������ƣ�
�������������ɾ�һ�㡣
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"hsg",
]));

  setup();
}






