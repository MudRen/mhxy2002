//By tianlin@mhxy for 2001.12.30

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", HIY"��"HIC"��"HIY"��"HIR"����"HIY"��"HIC"��"HIY"��"NOR);
  set ("long", @LONG

�����������ڤ��������������,������������߰���Ķ���,
ڤ�������������ȴ���ڤ˼��
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"new-walk2",
]));
  set("hell", 1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/mingwang" : 1,
]));

  setup();
}
