inherit ROOM;

void create()
{
	set("short", "������᳡");
	set("long", @LONG
��������!
��������!
��������!
��������!
��������!
��������!
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "������֪:
    jump ������̨
����
",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/referee" : 1,
]));
	set("no_beg", 1);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"pintai",
  "up" : __DIR__"leitai",
  "out" : __DIR__"gate",
]));
	set("no_clean_up", 0);
	set("no_death_penalty", 1);
        setup();
}

void init()
{
   add_action("do_quit", "quit");
     add_action("do_gogo", "out");
}
int do_quit()
{
  write("���ڱ������ڼ䲻���˳�����������\n");
  return 1;
}

int do_gogo()
{
        object me;
        me = this_player();
        me->set_temp("marks/allow_biwu",0);
        return 0;
}
