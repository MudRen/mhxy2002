//link
inherit ROOM;
#include <room.h>
#include <ansi.h>
void create()
{
        set("short", HIC"�ػ��"NOR);
        set("long", @LONG
���������Ļػ����Ҳ������������˱Ƚ��ٵ�Ե�ʰɣ������
��ˮ�����úܸɾ������̵ĺ�ˮ�������ԣ�����ͦ�ɰ��ġ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"shengdian",
  "north" : __DIR__"pool",
]));
	set("valid_startroom",1);
        set("objects", ([
	__DIR__"obj/pool" : 1,
                        ]) );
        set("coor/x",40);
	set("coor/y",80);
	set("coor/z",0);
	setup();
	create_door("north", "ˮբ", "south", DOOR_CLOSED);
}
void init()
{		
	add_action("do_swim","swim");
}

int do_swim()
{
	object me;
	object room;
	me = this_player();
	message_vision("$N����ˮ�У���ʼ��Ӿ������\n",me);
	room = load_object(__DIR__"pool");
	me->move(room);
	me->add("gin",-40);
	me->add("kee",-40);
	return 1;	
}
