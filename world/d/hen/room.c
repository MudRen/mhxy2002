// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "�������");
  set ("long", @LONG

        �������ǿ�ս�����ĵ����أ������Ҳ����һֻС��������
    С����һֻ�ɣ�

LONG);

  set("outdoors", "changan");
  set("exits", ([ /* sizeof() == 4 */
  "out" : "/d/city/kezhan",
  "south" : __DIR__"road1",
  "west" :__DIR__"home",
]));


  set("objects", ([//sizeof() == 1
    __DIR__"npc/waiter" : 1,
  ]));
        setup();
}
