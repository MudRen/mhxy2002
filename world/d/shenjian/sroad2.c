// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����С·");
        set("long", @LONG
����Сʯ���ϣ��������Ȼ�������Ѷ���δ���й������ʺ�
���������˲��ɵ��뵽��ʫ����Զ�Ϻ�ɽʯ��б�����������
�ң�ͣ������������˪Ҷ��춶��»�����
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"sroad3",
  "south" : __DIR__"sroad1",
]));
          set("coor/x",-1310);

	set("coor/y",195);

	set("coor/z",10);
set("no_magic",1);
	setup();
}
