// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

���������ȽȽ���������ǽ�����׻������ϱ���һ����ľ��
��(windows)��������һ��Ժ���ٴ��ɼ�Ժ�д���͸͵�����
�����ҡ,������һ���޵��š�
LONG);
set("item_desc", ([ /* sizeof() == 1 */
  "windows" : "������ҫ�ۣ�һʱ�����������۾���ȴ�䴰��һ���ߴ�����䡣\n",
]));

  set("exits", ([
        "north"   : __DIR__"daxiong",
      ]));
  set("objects", ([
        __DIR__"npc/xiantong" : 2,
     ]));

  setup();
}
void init()
{
 add_action("do_out", "out");
 }


int do_out(string arg)
{
 object me=this_player();
 
  if( (!arg) || !((arg == "windows") || (arg == "����")))
    return notify_fail("����ȥ���\n");
  if (me->is_busy()) return notify_fail("��������æ���ء�");
  if( me->query("kee") < (int)(me->query("max_kee")*2/3)){
    me->receive_damage("kee",(int)me->query("max_kee")*10/100);
me->move("/d/qujing/lingshan/siqian");
me->unconcious();
return 1;
}
	  if ((int)me->query_skill("force", 1)<180 )
	  {
	  message_vision("$N���˿����ܵ�Сͯ������ĵ�����ͷ��\n", me);
   }
      else
        {
	  message_vision("$N���˿����ܵ�Сͯ�������ǲ�ע�⣬һ���̴��˳�ȥ!��\n", me);
	  tell_object(me,"�����£�ȴ���ּ������ѳ�������ǰ!\n");
	  
   me->move(__DIR__"windows.c");
        }
    me->receive_damage("kee", (int)me->query("max_kee")*10/100);
  return 1;
}



