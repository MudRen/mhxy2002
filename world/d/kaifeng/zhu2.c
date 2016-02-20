// by cih 10/01/2002
// Room: /d/kaifeng/zhu2

#include <ansi.h>
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
        "south" : __DIR__"zhu1",
      ]));
  set("objects", ([
        __DIR__"npc/chunchun" :  1,
      ]));

  set("outdoors", "kaifeng");

  setup();
}
void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
       object chunchun;
       object me=this_player();
 
       if( (!arg) || !((arg == "wall") || (arg == "ǽ")))
               return notify_fail("��ʲô��\n");
       if (me->is_busy()) return notify_fail("��������æ���ء�");
       if( me->query("kee") < (int)(me->query("max_kee")/3)){
               me->receive_damage("kee",(int)me->query("max_kee")*20/100);
               return notify_fail("�����ӷ��飬һͷ������������ѽ��\n");
}
       if (!((string)me->query("family/family_name")=="����˧��" )&&
       objectp(chunchun = present("chun chun", environment(me))) && living(chunchun))
{
               message_vision(HIM"����˵��:��λ���������ҵ���ǰ�͸����ҿ����ǽ,�������!\n"NOR, me);
}
       else
{
       if ((int)me->query_skill("dodge", 1)<100 && (int)me->query_skill("chaos-steps", 1) < 100)
{
               message_vision("$NС���������������һ�㣬����ͷ���ۻ����͸Ͻ�����������\n", me);
               me->improve_skill("dodge", 100-me->query("str"));
               tell_object(me, "�������һЩ�����Ṧ��������š�\n");
}
      else
{
               message_vision(HIG"$N������ǽ��һ����ֻ�������Ѿ�����������\n"NOR, me);
               me->move(__DIR__"shuding.c");
}
}
               me->receive_damage("kee", (int)me->query("max_kee")*10/100);
               return 1;
}


