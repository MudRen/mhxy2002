// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�䳡����");
        set("long", @LONG
������䳡�ǳ��Ĵ󣬿��Կ�����ɽׯ���ڲ�ͬ�ĵط�������
����ϸɰ�̳ɣ���ɽׯ�ĵ���������ר�ĵ����Ź���
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"qhuayuan",
  "south" : __DIR__"rroad",
    "east" : __DIR__"rwuc",
    "west" : __DIR__"lwuc",
]));
     set("objects", ([
		__DIR__"npc/guard3" : 1,
                __DIR__"npc/guard1" : 1,
                  __DIR__"npc/guard2" : 1,
                  __DIR__"npc/zhen" : 1,
	]));
  set("outdoors", __DIR__);
	setup();
}
