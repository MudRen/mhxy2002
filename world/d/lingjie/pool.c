// link
inherit ROOM;
#include <room.h>
#include <ansi.h>
void create()
{
        set("short", HIC"�ػ��"NOR);
        set("long", @LONG
�����ǻػ�������룬������Ȼ���Ǻ���������Щ���ġ�ˮ�沨��
������չ��ӳ���������۰�Ĺ�â��һ������Ӱ���Ļ����˻���ȦȦ
ˮ��������������г��Ϫ�档
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"qianpool",
  "south" : __DIR__"swimrm",
]));
      set("coor/x",40);
	set("coor/y",100);
	set("coor/z",-10);
        set("objects", ([
           __DIR__"obj/xueguo" : 1,
        ]) );
	setup();
	create_door("south", "ˮբ", "north", DOOR_CLOSED);
	create_door("north", "ˮ��", "south", DOOR_CLOSED);
}
void init()
{
	if(interactive(this_player()))
	call_out("do_flush",5,this_player());
}

void do_flush(object me)
{
	object room;

	if(!me || environment(me) != this_object())
                return;
	tell_object(me,"�������ǰ��ȥ����\n");
	room= load_object(__DIR__"qianpool");
	me->move(room);
	me->add("gin",-40);
	me->add("kee",-40);
}	
