// xiaolu2.c �ּ�С��
// by Xiang

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "�ּ�С��");
        set("long", @LONG
������һ��С���ϣ��������������ӣ�����ɭɭ���������أ�������Ҷ
��������������������Ķ����������ƺ���һ����ª��СԺ��
LONG );
        set("exits", ([
                "south" : __DIR__"xiaoyuan.c",
                "north" : __DIR__"xiaolu1",
        ]));
        set("objects", ([
                __DIR__"npc/qingfeng" : 1,
                __DIR__"npc/mingyue" : 1,
        ]));
        create_door("south", "����", "north", DOOR_CLOSED);
        set("outdoors", "wudang");
        setup();
        replace_program(ROOM);
}

