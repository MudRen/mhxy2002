inherit ROOM;
int do_jump(string arg);
void create ()
{
  set ("short", "����");
  set ("long", @LONG

�����Ǻ���������װ�ε��ţ�һ����������ר�ŽӴ������
�ط��������ڵذ���ȴ��һ��СС��(hole).

LONG);

  set("exits", ([
        "south" : __DIR__"dating4",
      ]));
  set("item_desc", ([ /* sizeof() == 2 */
          "hole": "
һ���ǳ�С���ۣ��Ӷ���������ԼԼ���ŵ�Щ����ǵ�ζ����\n",
]));

  setup();
}

void init()
{
  add_action("do_jump", "zuan");
  add_action("do_jump", "xiaqu");
}
int do_jump(string arg)
{
  object me=this_player();
  int myeffcor=me->query("cor");
  int mycor=me->query_cor();

  if ( !arg || ((arg !="hole") ))
    return notify_fail("�㵽����ȥ�� \n");
if(myeffcor<18)
    return notify_fail("�㿴����ôС���ۣ�����̾�˿����� \n");

  message_vision("$N���˼�������,�����һֻ����,���˽�ȥ��\n", me);
  me->move(__DIR__"huomigong/entrance");
  message_vision("$N�����˵ķ��˹���,�ֱ����ԭ�Ρ�\n", me);
  return 1;
}
