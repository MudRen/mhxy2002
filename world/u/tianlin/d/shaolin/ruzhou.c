// Room: /d/shaolin/ruzhou.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "���ݳ�");
	set("long", @LONG
���ݳ��Ǳ����Ĵ�ǣ������Ǳ��ұ���֮�ء��������ڴ�פ
���ر����̲��������������ˣ����������𸽽�ɽ�ϵĲݿܡ���
��һ�Ӷӹٱ�����ȥȥ��һ��ɭ������������������������֮
һ����ɽ��
LONG
	);

	set("exits", ([
		"south" : __DIR__"yidao3",
		"west" : __DIR__"shijie1",
	]));

        set("objects", ([
                "/d/suburb/xkx/city/npc/wujiang" : 1,
                "/d/suburb/xkx/city/npc/bing" : 3,
        ]));

	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}



