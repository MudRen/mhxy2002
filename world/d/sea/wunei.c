inherit ROOM;

void create ()
{
  set ("short", "ʯ����");
  set ("long", @LONG

ʯ���ں����˵ģ���ɢ����һ��˵�������Ĺ�ζ��������֮��Ż��
��Χ��ϡ������������(pole)���������ż�˿Ѫ����
LONG);
set("item_desc", ([ /* sizeof() == 1 */
  "pole" : "˿˿Ѫ�����·��̺����������飬���ʵĶ���ȴ��˿˿�Թ����¡�\n",
]));

          set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/beast" : 1,
]));

  set("exits", ([ /* sizeof() == 4 */
//  "east" : __DIR__"yujie2.c",
]));
}
void init()
{
  add_action("do_climb", "climb");
 }


int do_climb(string arg)
{
 object me=this_player();
 
  if( (!arg) || !((arg == "pole") || (arg == "����")))
    return notify_fail("��ʲô��\n");
  if (me->is_busy()) return notify_fail("��������æ���ء�");
  if( me->query("kee") < (int)(me->query("max_kee")/2)){
    me->receive_damage("kee",(int)me->query("max_kee")*10/100);
    return notify_fail("�����ӷ��飬һͷ������������ѽ��\n");
}

	  if ((int)me->query_skill("dodge", 1)<120 )
	  {
	  message_vision("$N���˿����ʵ�������û��¶��\n", me);
   }
      else
        {
	  message_vision("$Nɨ��һ�����������һ��������ȥ��ֻ���¡�������������������\n", me);
          me->move(__DIR__"enter.c");
        }
    me->receive_damage("kee", (int)me->query("max_kee")*10/100);
  return 1;
}
