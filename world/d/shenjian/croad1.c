// LLY@FYSY
#include <room.h>

inherit ROOM;
void create()
{
        set("short", "����С·");
        set("long", @LONG
����һ����ʯ�̳ɵ�С·���·���һ�ҿ�ջ������Ϣ��Ϣ��
�ߵ����̧����ȥ����ɽ��ˮ�����ܶ������صĴ�������
����ˮ��Խ��Խ���ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"croad",
  "west" : __DIR__"croad2",
  "south" : __DIR__"chotel",
  "north" : __DIR__"chouse2",
]));
        set("objects", ([
        __DIR__"npc/farmer": 1,
                        ]) );
       set("coor/x",-1035);

	set("coor/y",15);

	set("coor/z",0);
	setup();
       }
