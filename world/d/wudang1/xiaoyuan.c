//[4;53m[1;31mBy tianlin@mhxy for 2001.9.27[2;37;0m

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��ɽСԺ");
        set("long", @LONG
���Ǻ�ɽ��һ��СԺ�����ü�򵥵�������һ����һ����һ�Ρ�һ���ţ�
��Ҳû�б��ʲ��Ƚ�����עĿ����ǽ�Ϲ���һ�ѽ�����������䵱��ɽ
��ʦ��������������ڡ�
LONG );
        set("exits", ([
                "north" : __DIR__"xiaolu2",
        ]));
        set("objects", ([
                __DIR__"npc/zhang" : 1,
        ]));
        create_door("north", "����", "south", DOOR_CLOSED);
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
