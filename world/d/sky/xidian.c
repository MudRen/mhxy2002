// Room: /d/sky/xidian.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������ׯ�����£�ǽ�ϻ��н���Ϸ�飬��ϻ�����ɫ���ƶ����
�ƣ��������ʡ���ǽ���Ƿ�β���磬����������������̺������һ
����˿�������Ỻ��Ʈ����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"nanmenting",
]));

    set("objects", ([
    __DIR__"npc/leader" : 1,
 ]));
	setup();
}
