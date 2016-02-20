//by mhsj@gslxz /2001/7/31
inherit ROOM;

int room_status = 0;
int *big = allocate(2);
int *res = allocate(2);

int random2 (int i)
{
  return (random(i)+uptime()) % i;
}

mapping gutous = ([ 
  "tc" : "[1;33mͷ��[2;37;0m",
  "sd" : "[37m˫��[2;37;0m",
  "qx" : "[1;31m����[2;37;0m",
  "sx" : "[31mɢ��[2;37;0m",
 ]); 

void create()
{
  set ("short", "������");
  set ("long", @LONG

�������һ�����������м����һ�����̡��Ŀ������۾�������¶ġ�
��ϯ��һλ���ӣ����ﲻ����Ū��һ��������������������вơ�

ǽ�Ϲ���һ���ң�����д�ţ�
    [1;33mͷ��[2;37;0m[33m��������ÿ�ο���ǰȷ����      ��һӮ��ʮ��[2;37;0m
    [37m˫��[33m����������ͬ����Ϊż����      ��һӮʮ��[2;37;0m
    [1;31m����[2;37;0m[33m������֮��Ϊ�ߣ�              ��һӮ��[2;37;0m
[31m    ɢ��[33m������֮��Ϊ�����壬�ţ�ʮһ����һӮ��[2;37;0m

�ҽ���һ������[1;31m(paizi)[2;37;0m��

LONG);

  set("item_desc",([
    "paizi" : "Ѻ[1;33mͷ����[2;37;0m�� gutou tc <amount> <money>\n"+ 
              "Ѻ[37m˫����[2;37;0m�� gutou sd <amount> <money>\n"+ 
              "Ѻ[1;31m������[2;37;0m�� gutou qx <amount> <money>\n"+ 
              "Ѻ[31mɢ����[2;37;0m�� gutou sx <amount> <money>\n" 
  ])); 
  set("objects", ([ /* sizeof() == 1 */
    __DIR__"npc/zhuangd" : 1,
  ]));
  set("exits", ([ /* sizeof() == 1 */
      "westdown" : __DIR__"pianting",
  ]));
  set("light_up", 1);
  set("no_fight", 1);
  set("no_magic", 1);
  setup();
}

void init ()
{
  add_action ("do_gutou","gutou");
     add_action("do_quit","fly");
    add_action("do_quit","exit");

  add_action("do_quit","quit");  


  if (room_status > 0)
    return;

  remove_call_out ("gamble_prepare");
  remove_call_out ("gamble_start");
  remove_call_out ("gamble_perform");
  remove_call_out ("gamble_finish");
  call_out ("gamble_prepare",2);
  room_status = 1;
}
  int do_quit(string arg)
  {
  write(this_player()->query("name")+"[5m[31m�����ʲô����BUGĪ������ֻ���ԶĲ���[2;37;0m\n");
  return 1;
  }

int do_gutou (string arg)
{
  object me = this_player();
  string what;
  int amount;
  string money;
  object ob;

  if (! arg ||
      sscanf (arg,"%s %d %s",what,amount,money) != 3)
    return notify_fail("��ʹ�ã� gutou <Ѻ������> <��Ŀ> <����>\n");

  if (what != "tc" &&
      what != "sd" &&
      what != "qx" &&
      what != "sx")
    return notify_fail("��ҪѺʲô����\n");

  ob = present (money+"_money", me);
  if (! ob)
    return notify_fail("������û�����ֻ��ҡ�\n");
  if (amount < 1)
    return notify_fail("���ѺһЩǮ��\n");
  if (amount > ob->query_amount())
    return notify_fail("�����ϵ�Ǯ����Ѻ��\n");

  if (me->query_temp ("gamble_gutou/amount") > 0)
    return notify_fail("���Ѿ�Ѻ���ˡ�\n");

  if (room_status > 1)
    return notify_fail("�������ڶ��أ��Ե�Ƭ�̡�\n");

  me->set_temp("gamble_gutou/kind",what);
  me->set_temp("gamble_gutou/amount",amount);
  me->set_temp("gamble_gutou/money",money);
  message_vision (sprintf("$N�ó�%s%s%s��Ѻ��%s�ϡ�\n",
                          chinese_number(amount),
                          ob->query("base_unit"),
                          ob->query("name"),
                          gutous[what]),
                  me);
  if (amount == ob->query_amount())
    destruct (ob);
  else
    ob->add_amount(-amount);

  return 1;
}

int valid_leave(object me, string dir)
{
  if (dir == "westdown")
  {
    if (me->query_temp ("gamble_gutou/amount") > 0) 
      message_vision ("$N����Ѻ����Ǯ��\n",me);
    me->delete_temp("gamble_gutou");
  }
  return ::valid_leave(me,dir);
}

void display_gutou (object room, int i)
{
  string str;
  switch (i)
  {
    case 1:
    {
      str = 
"[37m����������[2;37;0m\n"+
"[37m����������[2;37;0m\n"+
"[37m����[1;31m��[2;37;0m[37m����[2;37;0m\n"+
"[37m����������[2;37;0m\n"+
"[37m����������[2;37;0m\n";

      break;
    } 
    case 2:
    {
      str = 
"[37m����������[2;37;0m\n"+
"[37m����������[2;37;0m\n"+
"[37m��[1;31m�񡡡�[2;37;0m[37m��[2;37;0m\n"+
"[37m����������[2;37;0m\n"+
"[37m����������[2;37;0m\n";
      break;
    } 
    case 3:
    {
      str =
"[37m����������[2;37;0m\n"+
"[37m��[1;31m��[2;37;0m[37m������[2;37;0m\n"+
"[37m��[1;31m����[2;37;0m[37m����[2;37;0m\n"+
"[37m����[1;31m����[2;37;0m[37m��[2;37;0m\n"+
"[37m����������[2;37;0m\n";
      break;
    } 
    case 4:
    {
      str = 
"[37m����������[2;37;0m\n"+
"[37m��[1;31m�񡡡�[2;37;0m[37m��[2;37;0m\n"+
"[37m����������[2;37;0m\n"+
"[37m��[1;31m�񡡡�[2;37;0m[37m��[2;37;0m\n"+
"[37m����������[2;37;0m\n";
      break;
    } 
    case 5:
    {
      str =
"[37m����������[2;37;0m\n"+
"[37m��[1;31m�񡡡�[2;37;0m[37m��[2;37;0m\n"+
"[37m��[1;31m����[2;37;0m[37m����[2;37;0m\n"+
"[37m��[1;31m�񡡡�[2;37;0m[37m��[2;37;0m\n"+
"[37m����������[2;37;0m\n";
      break;
    } 
    case 6:
    {
      str = 
"[37m����������[2;37;0m\n"+
"[37m��[1;31m�񡡡�[2;37;0m[37m��[2;37;0m\n"+
"[37m��[1;31m�񡡡�[2;37;0m[37m��[2;37;0m\n"+
"[37m��[1;31m�񡡡�[2;37;0m[37m��[2;37;0m\n"+
"[37m����������[2;37;0m\n";
      break;
    } 
  }
  tell_room (room,str);
}

int rdm()
{
  return random2(6)+1;
}

void gamble_prepare ()
{
  object room = this_object();
  tell_room (room,"�вƳ������¿��̣�Ԥ��ͷ�ʣ�\n");
  tell_room (room,"�вƽ���ö������������һ����\n");
  big[0] = rdm();
  big[1] = rdm();
  // keep two numbers different for a probability == 1/36
  while (big[0] == big[1])
  {
    reset_eval_cost();
    big[1] = rdm();
  }
  display_gutou (room,big[0]);
  display_gutou (room,big[1]);
  tell_room (room,"�вƽе���ͷ������"+chinese_number(big[0])+
                  chinese_number(big[1])+"��\n");
  tell_room (room,"�����в�������˳�ֽ������������ջأ����ڿ���ѺǮ��\n");
  room_status = 1;
  call_out ("gamble_start",24);
}
 
void gamble_start ()
{
  object room = this_object();
  tell_room (room,"�вƺ���������ͣѺ��\n");
  tell_room (room,"�ֲ���������ͷ��������"+chinese_number(big[0])+
                  chinese_number(big[1])+"��\n");
  tell_room (room,"Ȼ����ö�����ӽ��������ѣ�һ�ֳ�һ��ҡ��������\n");
  room_status = 2;
  call_out ("gamble_perform",6,0);
  call_out ("gamble_perform",12,1);
  call_out ("gamble_finish",18);
}

void gamble_perform (int i)
{
  object room = this_object();

  tell_room (room,"���ѵ����������ϣ��������˳�����\n");
  res[i] = rdm();
  display_gutou (room,res[i]);
}

void player_wins (object who, int total)
{
  object money = new ("/obj/money/"+who->query_temp("gamble_gutou/money"));
  int amount = who->query_temp("gamble_gutou/amount");
  total = total * amount;
  money->set_amount(total);
  message_vision (sprintf("$NӮ��%s%s%s��\n",
                          chinese_number(total),
                          money->query("base_unit"),
                          money->query("name")),
                  who);
  money->move(who);
}

void player_loses (object who, int total)
{
  object money = new ("/obj/money/"+who->query_temp("gamble_gutou/money"));
  total = who->query_temp("gamble_gutou/amount");
  message_vision (sprintf("�вƽ�$NѺ�������е�%s%s%s���ߡ�\n",
                          chinese_number(total),
                          money->query("base_unit"),
                          money->query("name")),
                  who);
  destruct (money);
}

void gamble_finish ()
{
  string win;
  int total, i;
  object room = this_object();
  object *list = all_inventory(room);
  if (res[0]==big[0] && res[1]==big[1])
  {
    total = 36;
    win = "tc";
  }
  else if (res[0]==res[1] && (res[0]/2*2 == res[0]))
  {
    total = 12;
    win = "sd";
  }
  else 
  {
    int r = res[0]+res[1];
    if (r==7)
    {
      total = 6;
      win = "qx";
    }
    else if (r==3 || r==5 || r==9 || r==11) 
    {
      total = 3;
      win = "sx";
    }
    else
    {
      total = 0;
      win = "none of them";
    }
  }
  if (total == 0)
    tell_room (room,"�вƽе���"+chinese_number(res[0])+
                    chinese_number(res[1])+"�������̣�\n");
  else
    tell_room (room,"�вƽе���"+chinese_number(res[0])+
                    chinese_number(res[1])+"����"+gutous[win]+"��\n");
  i = sizeof(list);
  while (i--)
  {
    if (!userp(list[i]))
      continue;
    if (list[i]->query_temp("gamble_gutou/kind") == win)
      player_wins(list[i],total);
    else if (list[i]->query_temp("gamble_gutou/kind"))
      player_loses(list[i],total);
    list[i]->delete_temp("gamble_gutou");
  }
  tell_room (room,"\n");
  if(sizeof(filter_array(all_inventory(this_object()), (:userp:))))
  call_out ("gamble_prepare",5);
  else
  room_status=0;
}
