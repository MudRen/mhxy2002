//shushan2.c by yushu 2000.11
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short",HIR "��" HIG "��üɽ" HIR "��" NOR);
  set ("long", @LONG
������ͨ����ɽ�ɵ�ɽ·��·��᫲�ƽ���Ա߾���ɽ�£�
����һ�������ɵ�ͷ��Ŀѣ����Ͻ������۾�������һ������
��ˤ�÷�����ǡ�
LONG);

  set("outdoors", 2);
  set("exits", ([ /* sizeof() == 2 */
  "northeast" : "/d/shushan/shushan3",
  "southdown" : "/d/shushan/shushan1", 
]));

  setup();
}

void init ()
{
  add_action ("do_jump","jump");
}

int do_jump (string arg)
{
  string *rooms = ({
    "jianfen",
});

  object who = this_player();
  message_vision ("$N��������ţ�����һ������\n",who);
  who->move(__DIR__+rooms[random(sizeof(rooms))]);
  return 1;
}







