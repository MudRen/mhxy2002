#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
  set ("short", NOR+WHT+U"Сé��"NOR);
  set ("long", @LONG

�����������Ժ��һ��Сé�ݣ������Ǹ��������
��Ϣ�ĵط���

LONG);

set("exits", ([ /* sizeof() == 4 */
"east" : __DIR__"zhulin5",
]));

        set("no_clean_up", 0);
        setup();
}

void init()
{
	add_action("do_bed", "gosleep");
	add_action("do_bed", "gobed" );
	add_action("do_bed", "bed");
}

int do_bed()
{       object me;
        me=this_player();
      	message_vision(HIY "$N�ƿ�ɴ�ʣ�׼���ϴ��ˡ�\n\n" NOR, me);
  	me->move("/d/tianpeng/bed");
            message_vision(HIY "\nɳ������һ����$N���˽�����\n" NOR, me);
         	return 1;
}
