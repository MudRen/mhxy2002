#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"ʥ�����"NOR);
        set("long", @LONG
������������Ѿ�������,���Դ��������ʥ���
������档������ǹ������Ϣ��˯���ˣ�����
���߾���ʥ��ĸ��߲㡣
LONG
        );
        set("exits", ([
                "up" : __DIR__"shengdian3",
                "down" : __DIR__"shengdian1",
                "enter" : __DIR__"bedroom",
        ]) );
        set("coor/x",-1020);
        set("coor/y",-70);
        set("coor/z",-150);
        setup();
        replace_program(ROOM);
}


