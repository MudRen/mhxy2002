// Room: /4world/houshan4
//by tianlin 2001.5.1
inherit ROOM;

void create ()
{
  set ("short", "[33m������[m");
  set ("long", @LONG

�������С��Ƴγε�⨺�����Ȼ�Ѿ���͸���Ѿ���һЩ������
����������һ�����Ʈ�������ˮ�����˳�����
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/d/obj/drug/mihoutao" : 2,
  "/d/4world/npc/liuer-mihou" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"houshan3",
]));

  setup();
}
