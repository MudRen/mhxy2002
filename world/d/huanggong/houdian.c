// by snowcat

inherit ROOM;

void create()
{
  set ("short", "���");
  set ("long", @LONG

�����ׯ�����£�ǽ�ϻ��н���Ϸ�飬��ϻ�����ɫ���ƶ����
�ƣ��������ʡ���ǽ���Ƿ�β���磬����������������̺������һ
����˿�������Ỻ��Ʈ����

LONG);
  set("exits", ([ 
    "south" : __DIR__"dadian",
  ]));
  set("objects", ([
    __DIR__"npc/girl" : 2,
  ]));
  setup();
}
void init()
{
     add_action("do_look", "look");
        add_action("do_move", "move");
}
int do_look(string arg)
{
       if( !arg || arg == "" || arg !=  "wall") return 0;
             write(
             "����ϸ�������ܡ���������������һ�鰼�ݵĹ⻬�Ķ������ƺ��ǰ�Ŧ(button)��\n"
             );
             this_player()->set_temp("huanggong_look1", 1);
             return 1;
}
int do_move(string arg)
{
       object me;
       me = this_player(); 
       if (arg != "button" ) return 0;
       if ( !arg ) return 0;
       if (!me->query_temp("huanggong_look1"))
        return notify_fail("�㶯������\n");
       if (!living(me)) return 0;
       if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 50) 
       return notify_fail("�����ϸ���̫�࣬�޷��ƶ���\n");
       message_vision("$N�ƺ�����һ�����ҡ�\n", me);
      if((int)me->query_skill("dodge",1) < 200 )  
       return notify_fail("����Ŀǰ���Ṧ��Ϊ�����ҽ�ȥ��\n"); 
       message_vision("$N�����˽�ȥ��\n", me);
       me->move(__DIR__"qb");
       tell_room(environment(me), me->name() + "�Ӻ󹬾�Ȼ�����ˡ�\n", ({ me }));
       me->delete_temp("jqg_look1");
       me->delete_temp("jqg_look2");
       return 1;
}

