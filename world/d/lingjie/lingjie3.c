#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

����һƬ�ڰ�,��������,�������ʧȥ���κ���ϵ,��ֻ����
���ޱ��޼ʵĺڰ��е�������,��ͣǰ���ˡ�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"lingjie2",
  "north" :  __DIR__"lingjie5",
  "south" : __DIR__ "lingjie4",
  "west" : __DIR__ "lingjie6",
  "east" : __DIR__ "lingjie7",
]));

  setup();
}



