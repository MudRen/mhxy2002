// LLY@FYSY
#include <room.h>

inherit ROOM;
void create()
{
        set("short", "��ˮ����");
        set("long", @LONG
��ˮ���ĺ�ˮ��������ˮ����������ӳ������Ϧ����Զ���Ĵ��Ʒ��
����ͼ�������ϴ�����ˮ�����߷·���һƬ���֡�
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"croad2",
]));
        set("coor/x",-1055);

	set("coor/y",15);

	set("coor/z",0);
	setup();
}
init()
{
add_action("do_north", "north");
}


int do_north(string arg)

{object room, me;

  
 me = this_player();

tell_object(me, "���ƹ�һ�ԴԵ���֦�������Լ�����һƬ�ӻ�����...\n\n");
   room=find_object(__DIR__"ctree");
if(!objectp(room)) room=load_object(__DIR__"ctree");

me->move(room);
return 1;

}