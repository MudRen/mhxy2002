//by tianlin 2001.7.30

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", HBBLU+CYN"����С·"NOR);
  set ("long", @LONG

�������һ��ʮ�ְ����ĵط�,��������������ද��Ľ�����
ǰ����ܿ���һ������С��ĵط�,ԶԶ���ܿ��������м�����,
������˵Щʲô��

LONG);

  set("exits", ([
        "north" : __DIR__"xiaozhen",
        "east" : __DIR__"xiaolu",
      ]));

  setup();
}


