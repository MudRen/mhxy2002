//shushan by yushu 2000.11
inherit ROOM;
#include <room.h>
#include <ansi.h>
void create ()
{
  set ("short",HIR "��"HIY "Ժ��" HIR "��" NOR);
  set ("long", @LONG

������ɽ���ɵ�Ժ��,��ש�̳ɵĵ��Եø���ɾ�
�м�����ɽ���ɵ��������������䡣
LONG);

  set("outdoors", "/u/dragon/kfadd/door");
  set("exits", ([ /* sizeof() == 4 */
  "north" : "/d/shushan/dadian",
  "out" : __DIR__"door",
  ]));

create_door("out", "ʯ��", "enter", DOOR_CLOSED);
  setup();
}
