// fanting.c ���� by yushu 2000.11

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIR "��" HIY "����" HIR "��" NOR);
	set("long", @LONG
��������ɽ�ɵķ���,��������ͨ����ɽ�ɴ�����·����������
���кܶ�óԵġ��ܶ���Χ������������óԵ��ء������Ҫ
Щ(yao)�Եġ�

LONG
	);
        
       set("no_fight",1);
             set("exits", ([
	      "east" : __DIR__"wshilu",
	]));

        set("objects", ([ /* sizeof() == 2 */
        __DIR__"npc/qinger" : 1,
        __DIR__"npc/dizi1" : 1,
        __DIR__"npc/dizi" : 1,
        "/d/ourhome/obj/hulu" :1,
        ]));
       set("clean_up", 1);
       set("resource", ([ /* sizeof() == 1 */
       "water" : 1,
       ]));

      setup();
}
int valid_leave()
{
       if((present("gongbao jiding", this_player())))
            return notify_fail("���깬������������\n");
            if((present("hulu", this_player())))
            return notify_fail("�㲻�ܰѺ�«���ߣ�\n");
             return ::valid_leave();
}


