//live
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIC"��ɽ�嶥"NOR);
        set("long", @LONG
      ���������ɽ�Ľ����������ǲ�������
LONG
        );
        
        set("exits", ([ /* sizeof() == 2 */
                "enter" : __DIR__"houdian",
        ]));
        set("objects", ([
                 "/d/qujing/lingshan/npc/shenjiang.c" : 1,
			//	 "/d/qujing/lingshan/npc/tianbing.c" : 3,
        ]));

        setup();
}