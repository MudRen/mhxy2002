// LLY@FYSY
#include <room.h>
inherit ROOM;
int do_dive(string arg);
void create()
{
        set("short", "���Ʒ嶥");
        set("long", @LONG
���������������ֻ���һ�߿��Կ����һ�㣬��ϸһ����
���������Ǵ���ʮ����ָ֮���ˡ�
LONG
        );
        set("item_desc", ([
                "lake": "��������ԣ������壩����ȥǱ�����ס�\n",
                "water" : "��������ԣ������壩����ȥǱ�����ס�\n",
                "��ˮ��" : "��������ԣ������壩����ȥǱ�����ס�\n"
        ]) );

         set("coor/x",-1025);

	set("coor/y",65);

	set("coor/z",80);
set("no_magic",1);
	setup();
}
void init()
{

add_action("do_dive","dive");
}
int do_dive(string arg)
{
        object room;
        object me;
                me = this_player();
		message_vision("$N����������ˮ��������ȥ��\n", me);
          room = load_object(__DIR__"hudi");
	      me->move(room);
//		 return notify_fail("");		
		 return 1;		
        }
	       

