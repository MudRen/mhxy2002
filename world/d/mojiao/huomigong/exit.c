
// create by qlwy 28/06/2001
// room: maojiao/exit.c

inherit ROOM;

void create ()
{
        set ("short", "�Թ�����");
        set ("long", @LONG

�����߳����Թ��ˣ�������������������������
�����๼��

LONG);
        set("exits", 
        ([ //sizeof() == 2
                  "south" : __DIR__"outhmg0", 
//                "north" : __DIR__"xxx", ��������
        ]));
        setup();
}
void init()
{
  add_action("do_turn", "turn");
}
int do_turn(string arg)
{
  object me=this_player();
  int myeffstr=me->query("str")+me->query_skill("unarmed", 1)/10-2;
  int mykar=me->query_kar(), diff=40-mykar, percentage;
  int mymaxkee=me->query("max_kee"), mymaxsen=me->query("max_sen");
  if ((arg != "8310" && arg != "8011") || !arg)
    return notify_fail("��Ҫתʲô��\n");
  if (me->is_busy()) return notify_fail("��æ���أ�\n");
  if (me->query_temp("no_move")) return notify_fail("�㱻��ס�ˣ�ʲôҲ�ɲ��ˡ�\n");
  if (me->query_skill("tianmo", 1) > 50
   && me->query("family/family_name") == "ħ��")
  {
      message_vision("��������һֻ����һ��ץס$N�����žͲ����ˣ�\n", me);
      me->move(__DIR__"tower");
      return 1;
  }
  if (me->query_str()<40||myeffstr<20)
   {
      message_vision("$N���˾�ţ����֮��Ҳû��ת��һ�֡�\n", me);
      return 1;
   }
  if(random(diff)>4)
   {
      message_vision("ͻȻ�ҷ���ð��һ���ҽ�������$N����\n", me);
      percentage=diff*2;
      me->receive_wound("kee", mymaxkee*percentage/100);
      return 1;
   }
  message_vision("$N���һ����ת���˻��ء�\n", me);
  me->move(__DIR__"tower");
  return 1;
}


