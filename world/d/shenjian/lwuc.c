// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�䳡");
        set("long", @LONG
�������ñ����ļ��Ӱڷ���ǽ�ߣ�����ŵ�ȫ�Ǹ��ָ����Ľ�����
ɽׯ�򽣵�����������������ׯ�е�������Ҳ���ǽ������������м���
����ר�ĵ����Ž�����
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"wuc",
  "west" : __DIR__"nvs",
  "north" : __DIR__"lqhuayuan",
  "south" : __DIR__"ml",
]));
     set("objects", ([
		__DIR__"npc/guard3" : 1,
                __DIR__"npc/guard2" : 3,
	]));
  set("outdoors", __DIR__);
        set("coor/x",-1320);

	set("coor/y",240);

	set("coor/z",10);
	setup();
}
