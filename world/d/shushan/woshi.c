//shushan by yushu 2000.11
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short",HIR "��" HIY "����" HIR "��" NOR);
  set ("long", @LONG

�ϱߵĴ��Ϲ���һֻ�������������������Ÿ衣����ǽ���Ϲ���
һ��ϸ��ɽˮ����������һ�������Ρ�������һ�Ŵ�(bed).
LONG);

  set("no_fight", 1);
  set("item_desc", ([ /* sizeof() == 1 */
  "bed" : "˯���õĴ���(gosleep,gobed,bed)�� 
",
       ]));
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"hsg",
]));
 set("no_magic", 1);

  setup();
}

void init()
{
        add_action("do_bed", "gosleep");
        add_action("do_bed", "gobed", );
        add_action("do_bed", "bed");
        add_action("do_push", "push");
}

int do_bed()
{       object me;
        me=this_player();
        message_vision(HIY "$N�ƿ�ɴ�ʣ�׼���ϴ��ˡ�\n\n" NOR, me);
        me->move(__DIR__"chuang");
            message_vision(HIY "\nɴ������һ����$N���˽�����\n" NOR, me);
                return 1;
}

int do_push(string arg)
{
  object me=this_player();
  int myeffstr=me->query("str")+me->query_skill("unarmed", 1)/10-2;
  int mykar=me->query_kar(), diff=40-mykar, percentage;
  int mymaxkee=me->query("max_kee"), mymaxsen=me->query("max_sen");
  if ((arg != "zhuyi" && arg != "����") || !arg)
    return notify_fail("��Ҫ��ʲô��\n");
  if (me->is_busy()) return notify_fail("��æ���أ�\n");
  if (me->query_temp("no_move")) return notify_fail("�㱻��ס�ˣ�ʲôҲ�ɲ��ˡ�\n");
  if (me->query_skill("xianfeng-spells", 1) > 160
   && me->query("family/family_name") == "��ɽ��")
  {
      message_vision("$N�����ɷ���������һ���������˲����ˣ�\n", me);
      me->move(__DIR__"midao");
      return 1;
  }
  if (me->query_str()<30||myeffstr<20)
    {
      message_vision("$Nʹ�������Σ���������˿������\n", me);
      return 1;
    }
  message_vision("$N�����ƶ����Σ�ͻȻһ���紵��,�˲�����\n", me);
  me->move(__DIR__"midao");
  return 1;
}


