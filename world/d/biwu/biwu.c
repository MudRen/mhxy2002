inherit ROOM;

void create()
{
	set("short", "������᳡");
	set("long", @LONG
[33m            ����������������������������������[0m
[33m                ��                              ��[0m
[33m                �� [35m ��  ��  ��  ��  ��  ��  ��[33m  ��[0m
[33m                ��                              ��[0m
[33m                ����������������������������������[0m

[33m        ����������                              ����������[0m
[33m        ��      ��                              ��      ��[0m
[33m        ��  [36m��[33m  ��                              ��  [36mȭ[33m  ��[0m
[33m        ��      ��                              ��      ��[0m
[33m        ��  [36m��[33m  ��  [0m�����Ƿ��Ʊ���������᳡��[33m��  [36m��[33m  ��[0m
[33m        ��      ��                              ��      ��[0m
[33m        ��  [36m��[33m  ��  [0m��������Կ�������Ĵ���̨��[33m��  [36m��[33m  ��[0m
[33m        ��      ��                              ��      ��[0m
[33m        ��  [36m��[33m  ��  [0m��̨�������һ���ܴ�Ķ�����[33m��  [36mɽ[33m  ��[0m
[33m        ��      ��                              ��      ��[0m
[33m        ��  [36m��[33m  ��  [0m��̨����һ������(sign)��[33m    ��  [36m��[33m  ��[0m
[33m        ��      ��                              ��      ��[0m
[33m        ��  [36m��[33m  ��                              ��  [36m��[33m  ��[0m
[33m        ��      ��               ------ [0;5;37m��ѩ[0;33m��  ��      ��[0m
[33m        ����������                              ����������[0m

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
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"leitai",
  "out" : "/d/city/center.c",
  "north" : __DIR__"ready",
//  "south" : __DIR__"guodao3",
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
