// LLY@FYSY
#include <room.h>
inherit ROOM;
int do_north(string arg);
void create()
{
        set("short", "СС�ӻ���");
        set("long", @LONG
����������ĵط�һ������Ƽҵ�����Ҳ�����ӻ��塣
Ҫ����ɽׯȥ���ˣ�ͨ�����þ��������л�ƹ��ת�
�Ƽұ���������͸����������ſ��Կ���һ��СС�Ĵ��롣
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
            "south" : __DIR__"ctree",
]));
        set("objects", ([
        __DIR__"npc/waiter": 1 ,
        ]) );
        set("NONPC",1);
        set("coor/x",-1075);

	set("coor/y",15);

	set("coor/z",0);
set("no_magic",1);
	setup();
  }
void init()
{

add_action("do_north","north");
}
int do_north(string arg)
{
        object room;
        object me;
                me = this_player();
		if( (int)me->query_skill("sword",1) > 10 )
		 {
          message_vision("$N�����ţ����ݺ��С�������˹�ȥ,��С����$N���˵�������һ��л�ƹ���Ȼ�����������㡣\n", me);
          room = load_object(__DIR__"jiujia2");
	      me->move(room);
//		 return notify_fail("");
		 return 1;
		 }
		 else
		 {
          message_vision("���ź���һ��Ʈ���������$N˵������Խ��������軹���������ǿ��뿪��ɽׯ�ɣ�                        \n", me);		  
		  return 1;
		 }
        }
	       

