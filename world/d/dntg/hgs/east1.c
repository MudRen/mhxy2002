// Room: /d/4world/east1.c
inherit ROOM;

void create ()
{
  set ("short", "��Է��");
  set ("long", @LONG

��Է����û��ʲô�̼ң���������Ҳ���ࡣ������һ�Ҵ����ݣ�
���治ʱ�������䷢����������һ������ͭ���Ŵ󿪣�����Ҳ
��������Ժ�䡣�ϱ��Ǹ���Ժ��������ʮ�ֵظɾ���
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"shuyuan.c",
  "west" : __DIR__"center",
  "south" : "/d/wuguan/school1",
  "east" : __DIR__"east2.c",
]));
  set("outdoors", __DIR__"");

  setup();
}
