// link

inherit ROOM;
#include <room.h>
#include <ansi.h>
void create()
{
        set("short", BLU"�ػ���"NOR);
        set("long", @LONG
����ĺ�ˮӦ��˵�Ǻ�����ˣ�ֻ���Ṧˮƽ�ܸߵ��˲Ÿ�������
�Σ����ҪС��һ�㣬��ˮ���ߡ�
......ˮ��Խ��Խ���������Ѿ�����ס����......
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"pool",
]));
      	set("coor/x",40);
	set("coor/y",120);
	set("coor/z",-20);
	setup();
	create_door("south", "ˮ��", "north", DOOR_CLOSED);
}
void init()
{
	if(interactive(this_player()))
	call_out("do_flush",10,this_player());
	add_action("do_swim", "swim");
}


int do_swim(string arg)
{
 object me=this_player();
 
    if (me->is_busy()) return notify_fail("��������æ���ء�");
  
	  if ((int)me->query_skill("force", 1)<180 )
	  {
	  message_vision("$N����һ���ļ���ˮ����ȴ�����춯��\n", me);
   }
      else
        {
	  message_vision("$N���˿��ļ���ˮ�����������˹�ȥ!��\n", me);
	  tell_object(me,"���ϰ���ȴ����һ��������Ц���еĳ�����!\n");
	  
   me->move(__DIR__"master.c");
        }
    me->receive_damage("kee", (int)me->query("max_kee")*10/100);
  return 1;
}

void do_flush(object me)
{
        object room;
	if(!me || environment(me) != this_object())
		return;
	tell_object(me,"һ����ӿ�����㱻�޴��ˮ��һ�壬��ʲôҲ��֪���ˡ���\n");
	room= load_object("/d/lingjie/lang");
	me->move(room);
}	



