// LLY@FYSY
#include <room.h>
inherit ROOM;
int do_north(string arg);
void create()
{
        set("short", "���Ʒ嶥");
        set("long", @LONG
���϶��͵�ɽ�ڣ������������ƣ�̧����ȥ�����Ʒ嶥������˵�
�������Ĵ��Ƿ����̲ݺ�һЩ��֪�����ʻ�����ˮ����������Լ������
���ߣ������������Ƶ��Ǳ�һƬ���ϵĽ���ģ���ɼ�����ؾ�����ɽ
ׯ�ˡ�
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
]));
          set("coor/x",-1025);

	set("coor/y",55);

	set("coor/z",80);
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
if (me->query("baishi-xie"))
		 {
          message_vision("$N���������Ƶĵط����˽�ȥ��\n", me);
          room = load_object(__DIR__"cyfd1");
	      me->move(room);
		 return 1;
		 }
		 else
		 {
          message_vision("$N����һ������ɽ���ϻ�������ȥ��\n", me);
          room = load_object(__DIR__"cyf");
	   me->move(room);
          message_vision("$N�䵽·�ߵ�һ�����ϵ���������\n", me);
               me->unconcious();
	//	 return notify_fail("");
		 return 1;
		 }
        }
	       

