// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ˮ����");
        set("long", @LONG
��ǰ��Ҷ���裬վ��������Կ���Զ����ɽ�壬�Ӻ��洵���ķ��г�
�������㣬��һ�ִ�Զɽ�����ķҷ���
LONG
        );
         set("coor/x",-1310);

	set("coor/y",165);

	set("coor/z",5);
set("no_magic",1);
	setup();
}
void init()
{
  add_action("do_yell", "yell");
}
int do_yell(string arg)
{
 object boat;
 object me,oob;
 int i;

 if(!arg || arg=="")
  {
   write("��Ҫ��ʲô��\n");
   return 1;
  }
 if( arg == "л�ƹ�")
  {
   me = this_player();
   message_vision("$N�����ľ��ĺ��溰����л�ƹ�......һ���촬�����ĳ���������ǰ��\n", me);
  }
  else
   {
    write("һ�����ϵ������������˵����û�¾����뿪����Ҫ���С�С�\n");
    return 1;
   }
	
 if (query("exits/down")) return 1;
 if (!objectp(boat=find_object(__DIR__"xiaochuan")))
  boat=load_object(__DIR__"xiaochuan");
 boat->set("exits/up",__DIR__"sjhupan1");
 boat->set("no_fight",1);
 boat->set("no_magic",1);
 set("exits/down",__DIR__"xiaochuan");
 boat->set_temp("mark/dest","jiujia2");
 call_out("boat_leave",10,boat);
 return 1;
}

void boat_leave(object boat)
{
	if (query("exits/down")) delete("exits/down");
	if (boat->query("exits/up")) boat->delete("exits/up");
	message("vision","������������ˮ����Ư���ˡ�\n",this_object()); 
	message("vision","С����Զ����л�Ҵ廮ȥ��\n",boat);
	boat->delete("no_fight");
	boat->delete("no_magic");
	boat->boat_run(0);
}
