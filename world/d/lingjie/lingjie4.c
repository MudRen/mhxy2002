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
  "north" :  __DIR__"lingjie3",
  "south" : __DIR__ "lingjie8",
  "west" : __DIR__ "lingjie9",
  "east" : __DIR__ "lingjie10",
]));

  setup();
}