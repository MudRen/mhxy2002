//Cracked by Roath
// Room: /moon/wroom.c
//cglaem...12/13/96.

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "�ϹϼҵĴ���");
  set ("long", @LONG

������ͨ���ϹϼҵĴ��ţ��ӱ����Ͽ���ȥ����û���κ�ȥ�Ϲϼҵ�·
���Ǿ�˵ ֻҪ����Ե�˾Ϳ϶����ҵ�ȥ�Ϲϵĵط� ��֪���Ƿ���Ǵ�
˵�е���Ե�ˣ���˵�Ϲϼ���ǳ��ĺ��������ܻ���ʲô����û�м���
�ı�����
LONG);

  set("no_fight", 1);
  set("item_desc", ([ /* sizeof() == 1 */
  "zhuli" : "��Ե�����ĵط�(zhuli,zhuli1,zhuli2)�� 
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "west" : "/d/city/chatroom",
]));
  set("objects", ([
    __DIR__"npc/dog" : 1,
  ]));
  set("no_magic", 1);

  setup();
}

void init()
{
        add_action("do_zhuli", "kisszhuli");
        add_action("do_zhuli", "lovezhuli", );
        add_action("do_zhuli", "zhuli");
}

int do_love()
{       object me;
        me=this_player();
        message_vision(HIY "$N˵������֥�鿪�š�\n\n" NOR, me);
        me->move("/u/gua/workroom");
            message_vision(HIY "\��˵������֥����š�,�����˽�����\n" NOR, me);
                return 1;
}

