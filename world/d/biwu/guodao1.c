// Room: /u/biwu/guodao1.c
// Date: bye linxue([1;37m��ѩ[2;37;0m) Fri Apr 30 09:45:43 1999
inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
-----------����һ��ʲ��Ҳû�еĿշ��䡣---------------------
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"pintai",
  "southdown" : __DIR__"guodao",
]));
	set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
