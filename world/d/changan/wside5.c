//By tianlin@mhxy for 2001.9.28

inherit ROOM;

void create ()
{
  set ("short", "��ˮ֮��");
  set ("long", @LONG

��ˮ��ȥ������ǹ��������ڴˣ��㲻�ɵ��Ŀ�����������
������һ��������΢����һ��������Ϣ����֪�ɺδ�Ʈ����

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"ph",
  "east" : __DIR__"wside4",
  "north" : __DIR__"bx2",
//  "southeast" : "/d/changan/lichunyuan",

]));
  set("objects", ([ /* sizeof() == 1 */
//  "/d/changan/npc/wanfan" : 1,
]));

  set("outdoors", "changan-south");

  setup();
}
