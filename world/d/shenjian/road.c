// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����С��");
        set("long", @LONG
����һ����ʯ�̳ɵ�С�����ߵ����̧����ȥ��һ��ɽ��
����ͷ������ǰ�߲�Զ�����������µ���ˮ���ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"cunkou",
  "north" : __DIR__"shop",
  "south" : "/d/city/dongmen",
  ]));
        set("objects", ([
        __DIR__"npc/xiaotong": 1,
        __DIR__"npc/jifu": 1,
                            ]) );
        set("coor/x",-1010);

	set("coor/y",10);

	set("coor/z",0);
	setup();
    }
