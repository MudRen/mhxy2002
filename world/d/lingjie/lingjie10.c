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
  "west" : __DIR__ "lingjie4",

]));

  setup();
}