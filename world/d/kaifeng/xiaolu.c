//by tianlin 2001.7.30

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", YEL"����С·"NOR);
  set ("long", @LONG

�������һ��ʮ�ְ����ĵط�,��������������ද��Ľ�����
���ڰ������ˣ�ֻ��һЩС�����ӵ�������

LONG);

  set("exits", ([
        "west" : __DIR__"xiaolu2",
        "south" : __DIR__"neishi",
      ]));

  setup();
}


