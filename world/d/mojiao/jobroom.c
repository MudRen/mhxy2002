inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "�����");
  set ("long", @LONG

һ������ã���Ϳ�������ɫɫ���˽���������һ���ߴ���������
��æ���������飬�����С���
LONG);

  set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/long" : 1,
  __DIR__"npc/shinv" : 2,
]));
  set("exits", ([ /* sizeof() == 1 */
   "west" : __DIR__"dating4",
]));
set("no_time",1);
set("no_fight",1);
set("no_magic",1);
  setup();
}
