// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /d/qujing/wudidong/temple-qiandian.c
// created 6-20-97 pickle
inherit ROOM;

void create ()
{
  set ("short", "[37m������[m");
  set ("long", @LONG

һ�����Ϻõĵ�ذ��������С��,�������,���滹����һЩ
��֪������ʲô��ͼ��.�ŵ�������һ���峺��С��,�������ǵ��
������һЩ����,����ԧ���ں������е�����,ż��Ҳ�ܿ���һ��ֻ
�ɺ״����Ϸɹ�,�ŵı���(north)�������������ˡ�
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "north" : "һϮ���̵���������֮����������͵͵�ҿ�(jie)���������ģ����
",
]));
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"nanmenting.c",
  "north" : __DIR__"dadian",
]));
  set("light_up", 1);

  setup();
}

void init()
{
  add_action("do_knock", "jie");
}

int do_knock()
{
  object me=this_player();
  string myrespect=(string)RANK_D->query_respect(me);

  if (me->query("obstacle/sky") != "done")
//   if (!me->query_temp("zhanyao_asked"))  
{
  
  message_vision("$N����Ľҿ������������濴�˿���\n", me);
  message_vision("$N��û�˷��֣���͵͵�����˽�ȥ�����ŵ�����¶��һ˿Ц�ݡ�\n", me);
  me->move(__DIR__"dianmen");
  return 1;
   }
  message_vision("$Nһ�ѳ����˹��������һ�������˽�ȥ��\n",me);
  me->move(__DIR__"dianmen2");
  return 1;
}






