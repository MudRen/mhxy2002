inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIC"����"NOR);
        set("long", @LONG
������ʥ���Ĳ������,����С�����ȹ�ͨ����,�����е�
ʯ�����Ǻ����������,�ǳ��ľ�ϸ,��ģ��ȥ��һ��˵����
�������
LONG
        );
        set("exits", ([
                "west" : __DIR__"wangroom1",
                "east" : __DIR__"wangroom2",
                "out" : __DIR__"shengdian4",
                "south" : __DIR__"bedroom1",
        ]) );
                 set("objects", ([
                __DIR__"npc/shadow":1,
                
        ]) );

        set("no_fight",1);
       set("no_sleep", 1);
       set("no_magic", 1);


        setup();
        replace_program(ROOM);
}
