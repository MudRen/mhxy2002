// created by snowcat.c 4/4/1997
// room: /d/nuerguo/xiaolu1.c

inherit ROOM;

void create ()
{
  set ("short", "С·");
  set ("long", @LONG

����һ����ϸ�ֳ���ɽ��С����һ����ߣ�һ����͡�·��
�����ǲ�֪����Ұ��Ұ�ݡ�����ٵ����ţ�����ɽ����һ��
���͡�

LONG);

  set("exits", ([
    "east"       : __DIR__"jieyang",
    "westup"     : __DIR__"xiaolu2",
  ]));
  set("outdoors", __DIR__"");
    set("have_coin", 10);
  setup();
}

void init()
{
   add_action("do_dig", "waqianl");
   add_action("do_dig", "waqianl");
}

int do_dig(string arg)
{
   object ob,coin;
   object who=this_player();
   object where=this_object();
   if( (!arg) || (arg != "qiu yin" && arg != "coin" && arg !="���") )
      return notify_fail("����ʲô��\n");
   if( !(ob = who->query_temp("weapon")) || ( (string)ob->query("skill_type")!="axe" && 
(string)ob->query("skill_type")!="blade" && (string)ob->query("skill_type")!="sword" ) )
      return notify_fail("�Ҹ��÷����ļһ����ڰɡ�\n");
   if( who->query("kee")<50 )
      return notify_fail("��̫���ˣ���Ъ������ڰɡ�\n");
   who->add("mud_age",10000);
   if (random(10) > where->query("have_coin"))
      message_vision("$N������з�����ȥ�����ʲôҲû�ҵ���\n", who);
   else  
     {
     coin=new("/obj/money/coin");
     coin->move(who);
        message_vision("$N��������ҵ�һֻ��򾣬����ץ�˳�����\n", who);
     where->add("have_coin",1);
     call_out("regenerate", 300);


     }
     return 1;
}

int regenerate()
{
   object where=this_object();
   if (where->query("have_coin") < 10)  
        where->add("have_coin",1);
   return 1;
}



