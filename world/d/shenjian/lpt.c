// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ƫ��");
        set("long", @LONG
������ר���д����ñ������ŵĵط���һ�Ŵ���ʯ��ĥ�Ĵ���
�������У����Ϸ��ż����񱭣������������͸������ð��������
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"dt",
  "west" : __DIR__"cf",
]));
set("objects", ([
		__DIR__"npc/guard" : 2,
          	]));
               set("coor/x",-1320);

	set("coor/y",260);

	set("coor/z",10);
set("no_magic",1);
	setup();
}
