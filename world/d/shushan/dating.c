// dating.c ���� by yushu 2000.11

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIR "��" HIY "����" HIR "��" NOR);
	set("long", @LONG
 ��������ɽ�ɴ��������п�������һ�Ű����������Ϲ�����ɽ�ɽ�ʥ����λ��
�Ա߷���������ɻ�ƿ�����ż�֧��ȸ�ᣬǽ��д�������֡���ɽ�ɡ���
LONG
	);
        set("no_sleep_room","1");
        set("exits", ([
	      "westdown" : __DIR__"wshilu1",
	      "eastdown" : __DIR__"eshilu",
            "southdown" : __DIR__"dadian",
               ]));


	set("objects", ([
		__DIR__"npc/jiujianxian" : 1,
              __DIR__"npc/dizi" : 2,
              __DIR__"npc/dizi1" : 2,
       ]));
       setup();
	replace_program(ROOM);
}



       