// by Repoo
#include <ansi.h>
inherit ROOM;
void create ()
{
   set ("short", RED" ����̨ "NOR);
  set ("long", @LONG

����������������еĵط���Զ�����죬�������أ�
һ�ж�����ô��������翡�

LONG);
  set("exits", ([ /* sizeof() == 2 */
                 "east" : __DIR__"rongshi",
                 "west" : __DIR__"kushi",
                 ]));
  set("objects", ([
]));
  set("outdoors", 1);
  setup();
}
void init()
{
        add_action("do_cast", "cast");
}
int do_cast (string arg)
{
  object who = this_player();
      tell_object(who,"���������ĵط���������������\n");
      return 1;
}
