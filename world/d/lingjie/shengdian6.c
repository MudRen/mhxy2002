#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"ʥ������"NOR);
        set("long", @LONG
�ò������ߵ�������,�������ЪЪ����,��ΧһƬ����
�ľ���,���!������һֻ��ֵĶ��ﵲס�˼���ǰ����
·��,�������ٲ���һ����ս�ˡ�
LONG
        );
        set("exits", ([
                "up" : __DIR__"shengdian7",
                "down" : __DIR__"shengdian5",
                "enter" : __DIR__"shengtian",
        ]) );
        set("objects", ([
                __DIR__"npc/shuilinger":1,
        ]) );
        set("coor/x",-1020);
        set("coor/y",-70);
        set("coor/z",-150);
        setup();
        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{       
        object a;
//        if( wizardp(me)) return 1;

        if (dir == "up") {
                if(objectp(a=present("shuilinger", environment(me))) && living(a) )
                return notify_fail("ˮ�����м�Ŀ�����һ�ۣ����˰�,�α������أ�\n");

        return ::valid_leave(me, dir);
        }

        return 1;
}

