
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIC"�ػ����"NOR);
        set("long", @LONG
��ں�ˮ���ƺ��������������ڲ���������վ����������ƽ�죬���ճ�
ǹ״�����ַ����������󴦣�����Ϥ�Ķ���-----���裡
LONG
        );
        
        set("exits", ([ /* sizeof() == 2 */
                "out" : __DIR__"pool",
        ]));
        set("objects", ([
                 "/d/lingjie/npc/youzhu.c" : 1,
				         ]));

        setup();
}