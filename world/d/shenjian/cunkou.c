// LLY@FYSY
#include <room.h>

inherit ROOM;
void create()
{
        set("short", "С���");
        set("long", @LONG
���Ǹ�СС�Ĵ��䣬��������˴�඼��л�������������ңң��������Զ
������ҡҷ����ˮ��,���Ա߿��Կ���һ�����̵�ɽ��,��ž��ǽ������˳�����
���Ĵ��Ʒ��ˣ�Ҫȥ��ɽׯ����,��Ҫ�������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"croad", 
  "north" : __DIR__"cyf",
  "southeast" : __DIR__"road",
  "south" : __DIR__"yaodian",
]));

        set("outdoors", "shenjian");
        set("coor/x",-1015);

	set("coor/y",15);

	set("coor/z",0);
	setup();
}
