// Room: /changan/mufa.c

inherit ROOM;

void create ()
{
  set ("short", "��");
  set ("long", @LONG

�������Ǻ�ɫ����ɫ���죬��ɫ��ˮ��һ����ɫ������...
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"wu.c",
]));
set("zuo_trigger", 0);
  set("outdoors", 1);

  setup();
}
