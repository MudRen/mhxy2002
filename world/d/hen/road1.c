// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "�����ߵ�");
  set ("long", @LONG

        �����ڼ��ѵ��ߵ��ϣ��������Ǽ��е����⣬������ιС��
   �ĵط��������Ǹ�С��ϴ��ĵط���

LONG);

  set("outdoors", "changan");
  set("exits", ([ /* sizeof() == 4 */
         "north" : __DIR__"room",
         "east": __DIR__"feed",
         "west": __DIR__"bathe",
         "south": __DIR__"road2",
]));

        setup();
}
