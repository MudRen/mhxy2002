
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIC"��ɽ����"NOR);
        set("long", @LONG
�谵�ĵƹ⣬һλ�����������ǧ��������һ�ա�
LONG
        );
        
        set("exits", ([ /* sizeof() == 2 */
                "out" : __DIR__"houdian",
        ]));
        set("objects", ([
"/d/xueshan/npc/kongquedapeng.c" : 1,
				         ]));

        setup();
}
