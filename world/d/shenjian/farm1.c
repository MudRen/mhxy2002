// LLY@FYSY
inherit ROOM;

void create()
{
	set("short", "�˵ص�");
	set("long", @LONG
һƬ�����͵Ĳ˵ء�����ũ�������ֵĸ����š� 
LONG
	);
	set("exits", ([
		"south" : __DIR__"croad2",
		]));
	set("objects", ([
		__DIR__"npc/farmer" : 1,
	]));
	set("outdoors", "shenjian");
	set("coor/x",-1045);

	set("coor/y",20);

	set("coor/z",0);
	setup();
replace_program(ROOM);

}
