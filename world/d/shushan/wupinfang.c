// wupinfang.c ��Ʒ�� by yushu 2000.11

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIR "��" HIY "��Ʒ��" HIR "��" NOR);
	set("long", @LONG
������Ʒ����һ������ӡ�����ŵ��������룬��������Ĺܼ���
�����渺��ģ�һЩ�����ڸ�����Ʒ���ߵĹܼ�˵��ʲô��
LONG
	);
        set("no_fight",1);
        set("exits", ([
		"north": __DIR__"changlang3",
		"west" : __DIR__"eshilu",
		"south": __DIR__"changlang2",

		]));


	set("objects", ([
		__DIR__"npc/heer" : 1,
              __DIR__"npc/dizi" : 1,
              __DIR__"npc/dizi1" : 1,
             ]));


       setup();
	replace_program(ROOM);
}

