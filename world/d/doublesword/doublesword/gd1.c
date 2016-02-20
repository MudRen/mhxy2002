#include <room.h>

inherit ROOM;

void create()
{
    set("short", "�ȵ�");
        set("long", @LONG
ֻ���չ����ˣ�һƬ���������ڻ��У�������һ�ڴ�֮�� ��
û�뵽�ڻʹ��󹬻�����ôһ�����εĵط�.
LONG
        );
        setup();
 
}
void init()
{
        object ob = this_player();
        object jing=new(__DIR__"npc/xiniu-jing");
        if( present("xiniu jing",environment(ob)))
                return 0;
         ob->set("laojun_killjingover", 1);
        message_vision("��Ȼ��������\n",ob);
        message_vision("��֪�������һֻ�������˳�����\n",ob);
      jing->move(environment(ob));
     add_action("do_look", "look");
        add_action("do_climb", "climb");
}
int do_look(string arg)
{
       if( !arg || arg == "" || arg !=  "cliff") return 0;
             write(
             "����ϸ��������,��ɽ��ֹ�������ĺ������ƺ�����һ������(climb)�ĵط���\n"
             );
             this_player()->set_temp("huanggong_look2", 1);
             return 1;
}
int do_climb(string arg)
{
       object me;
       me = this_player(); 
       if ( !arg ) return 0;
       if (!me->query_temp("huanggong_look2"))
        return notify_fail("��û��ϸ����������\n");
       if (!living(me)) return 0;
       if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 50) 
       return notify_fail("�����ϸ���̫�࣬�޷��ƶ���\n");
       message_vision("$N������ѽ����\n", me);
      if((int)me->query_skill("dodge",1) < 200 )  
       return notify_fail("����Ŀǰ���Ṧ��Ϊ��������ȥ�ġ�\n"); 
       message_vision("$N����һԾ��\n", me);
       me->move(__DIR__"qb");
       tell_room(environment(me), me->name() + "�ӹȵ׾�ȻԾ�����ˡ�\n", ({ me }));
       me->delete_temp("huanggong_look1");
       me->delete_temp("huanggong_look2");
       return 1;
}
