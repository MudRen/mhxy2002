// Room: /u/biwu/pintai.c
// Date: bye linxue([1;37m��ѩ[2;37;0m) Fri Apr 30 09:52:22 1999
inherit ROOM;

void create()
{
	set("short", "ɽ��ƽ̨");
	set("long", @LONG
-----------����һ��ʲ��Ҳû�еĿշ��䡣---------------------
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"biwu2",
  "south" : __DIR__"guodao1",
  "east" : __DIR__"biwu1",
  "northup" : __DIR__"guodao2",
]));
	set("objects", ([ /* sizeof() == 1 */
    __DIR__"npc/waiter" : 2,
]));
	set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
