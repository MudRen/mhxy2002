
inherit ROOM;

void create()
{
        set("short", "����ǰ");
        set("long", @LONG

����·�ԵĲݵأ����¹�����ֻ��·��һ�����ᣬ�����ڴ���֮�䣬΢��
������������ɡ���Զ�������������ɽ����һƬС�ɵ�¥�󣬷�����
������������������ʹ�һ�㡣
LONG
        );
        set("exits", ([ 
    "north" : __DIR__"valley",
]));
        set("outdoors", "mojiao");

	setup();
        replace_program(ROOM);
}

