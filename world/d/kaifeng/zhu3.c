// by cih 10/01/2002
// Room: /d/kaifeng/zhu2

inherit ROOM;

void create ()
{
  set ("short", "��·");
  set ("long", @LONG

���������ν����·�ľ�ͷ�ˡ���һ·���������������ͬʱ��
��·�ϻ�������õ�壬�����˽�Ҳ�Ǹ������ٿ˵���Ŷ������
���������Ǹ��Ͱ���Χǽ������ֻҪ���ʲôׯ�ڰ��Ƶ��˶�
��������׾ٵķ���ȥ�Ƶ�(climb)

LONG);

  set("exits", ([
  "northeast" : __DIR__"zhu1",
      ]));

  set("outdoors", "kaifeng");

  setup();
}
void init()
{
        add_action("do_climb", "climb");
}
int do_climb(string arg)
{       object me;
        me=this_player();

        if ( !arg || ((arg != "wall") ))
                return notify_fail("��Ҫ��ʲô��\n");
        else
                message_vision("$Nһ��ǽͷ�����˹�ȥ��\n", me);
                me->move("/d/kaifeng/donghu8");
                me->set_temp("apply/dodge",0);
                me->set_temp("ride/dodge",0);
                tell_room( environment(me), "�����ˡ�һ����" + me->name() + "��ǽͷ��ˤ��������\n",
({me}) );
                return 1;
}


