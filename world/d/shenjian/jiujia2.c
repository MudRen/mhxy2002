// LLY@FYSY
#include <room.h>

inherit ROOM;
void create()
{
        set("short", "С����");
        set("long", @LONG
����һ���޽��ں��ߵ�С���룬վ���������Կ��������ĺ���ɽɫ��
������ˮ����ɽ�Ǵ��Ʒ塣
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"jiujia",
]));
        set("coor/x",-1085);

	set("coor/y",15);

	set("coor/z",0);
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
    write("��С���߳�������һ�Ƕ��⣬˵����û�²�Ҫ�ҽ��¡�˵���ݺݵĵ�����һ�۾ͻص�ǰ��ȥ�ˣ�\n");
    return 1;
   }
	
 if (query("exits/down")) return 1;
 if (!objectp(boat=find_object(__DIR__"xiaochuan")))
  boat=load_object(__DIR__"xiaochuan");
 boat->set("exits/up",__DIR__"jiujia2");
 boat->set("no_fight",1);
 boat->set("no_magic",1);
 set("exits/down",__DIR__"xiaochuan");
 boat->set_temp("mark/dest","sjhupan1");
 call_out("boat_leave",10,boat);
 return 1;
}

void boat_leave(object boat)
{
	if (query("exits/down")) delete("exits/down");
	if (boat->query("exits/up")) boat->delete("exits/up");
	message("vision","����������Զ��Ư���ˡ�\n",this_object()); 
	message("vision","С����Զ������ɽׯ��ȥ��\n",boat);
	boat->delete("no_fight");
	boat->delete("no_magic");
	boat->boat_run(0);
}
