// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */

// Room: /d/4world/center.c
inherit ROOM;

void create ()
{
  set ("short", "[37m�˰������[m");
  set ("long", @LONG
����ǰ˰��������,��Ȼ�ǺƺƵ���,һ���޼�.
�ӱߵ�ˮ�����Ƿ�ʢ,�㲻�ɵ�������(fang)��
ȥ.
LONG);
  set("exits", ([
  "east" : __DIR__"xitian",
]));

  setup();
}
void init()
{
    add_action("do_fang", "fang");
    set("no_clean_up", 0);
        setup();
}

int do_fang(string arg)
{
        object me, ob, a, b;
        me=this_player();
        if ( !arg || ((arg != "horse") ))
                return notify_fail("��Ҫ��ʲô�ų�ȥ��\n");
  if ( !present("tian-ma", this_player()) )
     return notify_fail("����û������,��ʲô�Ű�!!\n");
  if(objectp(a=present("tianpeng yuanshuai", environment(me))))
  return notify_fail("����Ԫ˧���һ��:С��,������˧���˻���͵�ҵ�ˮ��!!\n");
  if(!me->query_temp("marks/��"))
  return notify_fail("�㻹ûȥ��������,��ô�ܰ����ų�ȥ��!!!\n");
//  if(!me->query_temp("give_horse"))
//  return notify_fail("������²������Լ�ȥ�����Ҫ�İ�!!\n");
  message_vision("$N������,����ǣ���ӱ�,�������гԲݡ�\n",me);
  message_vision("ֻ����������һ��ˮ��,���������˼�����Ӱ!!\n",me);
  me->delete_temp("marks/��",1);
  ob=present("tianpeng yuanshuai");
     if( !ob) {
  seteuid(getuid());
  ob=new("/d/sky/npc/zhu");
}
  ob->move(__DIR__"river");
   return 1;
}
