// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�䳡");
        set("long", @LONG
һ��һ�ŵ�÷��׮�����ڳ��ص����룬����������ר��
����ϰ���Ṧ�Ͳ��������̹��򡣴�������Կ������ߵ���
�����ƽ����������·����ȶ���
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"nans",
  "west" : __DIR__"wuc",
  "north" : __DIR__"rqhuayuan",
]));
         set("objects", ([
		__DIR__"npc/guard3" : 1,
                __DIR__"npc/guard1" : 3,
	]));
        set("coor/x",-1300);

	set("coor/y",240);

	set("coor/z",10);
set("no_magic",1);
	setup();
}
