// Room: come to shanshipo.c  writted by smile 12/10/1998

inherit ROOM;

void create ()
{
  set ("short", "С·");
  set ("long", @LONG

    ����һ������������С·��������ȥ������������һ����
�����ƵĴ�ɽ��
LONG);

  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 1 */
  "west" : "/d/qujing/baigudong/sroad",
   "southeast"  : "/d/qujing/village/road4",
]));

  setup();
}






