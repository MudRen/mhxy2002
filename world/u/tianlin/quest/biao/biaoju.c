//paimaiwu.c by litchi

inherit ROOM;

void create ()
{
        set ("short", "�����ھ�");
        set ("long", @LONG

�����ھ֡�

���������Ѻ��
���
   Ҫ����: ask lin about job
   ���ڳ�: gan che to ����
   ����������� ask lin about over 
   �����ʵ���겻�����񡣡���ֻ�������50���ƽ��ˣ���

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
          "southwest" : "/d/city/dongmen",
        ]));
        set("objects", 
        ([ //sizeof() == 1
                "/u/tianlin/quest/biao/linzhennan":1,
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
//      replace_program(ROOM);
}

void init()
{
  add_action("do_fight", "fight");
  add_action("do_kill", "kill");
  add_action("do_steal", "steal");
  add_action("do_cast", "cast");
  add_action("do_ji","ji");
  add_action("do_throw","throw");
  add_action("do_list","list");
  add_action("do_yao","yao");
}

void die()
{
 return;
}

int do_fight(string arg)
{
  object who = this_player();
  object me = this_object();

  if (arg && present(arg,environment(who))==me)
  {
        message_vision("$N���������ܣ�������������Ʈ��,ʣ��$N�����վ�����\n",who);
     return 1;
  }
  return 0;
}

int do_kill(string arg)
{
  object who = this_player();
  object me = this_object();

  if (arg && present(arg,environment(who))==me)
  {
message_vision("$N��������ɱ�������ϣ�����������Сѧ��ҵ,û��$Nһ���ʶ��\n",who);

    return 1;
  }
  return 0;
}

int do_cast(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision("$N���������Ͻ��Ͱ͵����˼�������Լ����о��������ˡ�\n",who);

  return 1;
}
int do_steal(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision("$N��͵������������������û������\n",who);

  return 1;
}


int do_ji(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision("$N���������ǰ˼���룬����û�ҡ�\n",who);

  return 1;
}

int do_throw(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision("$N�ͳ����������˿������ϣ����Ĳ��㣬�ְѰ�������������\n",who);

  return 1;
}
