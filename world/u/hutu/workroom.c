//Cracked by Roath
// Room: /moon/wroom.c
//cglaem...12/13/96.

#include <ansi.h>
inherit ROOM;

void create ()
{
set ("short", HBRED+HIR"��Ϳ��"NOR);
  set ("long", @LONG

������Ǵ������Ϳ�ļң�������������ܰ��ʫ�黭�⡣
ǽ�Ϲ���һ�����,����֣���ŵ��ѵú�Ϳ��
LONG);

  set("no_fight", 1);
  set("item_desc", ([ /* sizeof() == 1 */
  "bed" : "ˮ����(gosleep,gobed,bed)�� 
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "wiz" : "/d/wiz/wizroom",
  "kz" : "/d/city/kezhan",
  "out" : "/u/xlan/workroom",
]));
  set("no_magic", 1);

  setup();
}

void init()
{
        add_action("do_bed", "gosleep");
        add_action("do_bed", "gobed", );
        add_action("do_bed", "bed");
}

int do_bed()
{       object me;
        me=this_player();
        message_vision(HIY "$N�ƿ�ɴ�ʣ�׼���ϴ��ˡ�\n\n" NOR, me);
        me->move(__DIR__"sleep");
            message_vision(HIY "\nɴ������һ����$N���˽�����\n" NOR, me);
                return 1;
}

