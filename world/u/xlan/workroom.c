//changan city
// [lsg 2000/11/16]
inherit ROOM;
#include <ansi.h>;

void create ()
{
 set ("short", HBRED+HIW"�������ʹ�"NOR);
        set ("long", @LONG

  ����������У�΢��ϮϮ��һ���޴���Ʋ�Χ�����������ʹ�
��̻Ի͵Ĺ����ǻʹ����������С��������һ������ȥ�ĵط�
�������С�ţ����󣬻�԰.....���������˹��������మ����Ӱ.......
LONG);
        set("exits", 
        ([ //sizeof() == 2
                "wiz" : "/d/wiz/wizroom",
                "kz" : "/d/city/kezhan",
                "enter" : "/u/pkyou/workroom",
                        ]));

        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}



