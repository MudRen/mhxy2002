// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����С·");
        set("long", @LONG
���Ҷ��Ƿ�ҶƮ�裬ԶԶ����ȥ����ɽׯ�Ǻ�ΰ���ϵĽ�
��������Լ�ɼ���
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"sroad2",
  "south" : __DIR__"sroad",
]));
          set("coor/x",-1310);

	set("coor/y",185);

	set("coor/z",10);
set("no_magic",1);
	setup();
}
