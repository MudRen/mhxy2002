// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��Ժ");
        set("long", @LONG
�����������������������ɽׯ������ô���ط���һ��СС��
Ժ�ӣ�����һЩ��֪���Ļ��ݣ��Ա߻��и����ߵ�С¥�����ɵ�������
��¥ȥ������
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"ty",
  "northup" : __DIR__"hyxl",
]));
        set("coor/x",-1310);

	set("coor/y",400);

	set("coor/z",10);
set("no_magic",1);
	setup();
}
