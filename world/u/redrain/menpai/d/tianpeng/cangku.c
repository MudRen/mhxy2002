#include <ansi.h>

inherit ROOM;
void create ()
{
  set ("short", "������");
  set ("long", @LONG

����������Ĵ����ң���������˹���
���ݡ�


LONG);

  set("exits", ([
                  "east" : __DIR__"zhulin9",
      ]));
  set("objects", ([
            __DIR__"obj/guzi"   : 2,
            __DIR__"obj/maizi"   : 2,
              __DIR__"obj/gangpa"   : 2,
      ]));

  setup();
}


