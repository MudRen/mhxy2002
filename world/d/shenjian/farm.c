// LLY@FYSY
inherit ROOM;

void create()
{
	set("short", "ׯ�ڵ�");
	set("long", @LONG
һƬãã�ޱߵĵ�����е���������������ũ��������
�ĸ����š� 
LONG
	);
	set("exits", ([
		"north" : __DIR__"croad2",
		]));
	set("objects", ([
		__DIR__"npc/farmer" : 1,
	]));
	set("outdoors", "shenjian");
	set("coor/x",-1045);

	set("coor/y",10);

	set("coor/z",0);
	setup();
replace_program(ROOM);

}
