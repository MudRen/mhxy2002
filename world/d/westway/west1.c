// create by snowcat.c 4/8/1997
// room: /d/westway/west1.c

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","��ٵ�");
  set ("long", @LONG

����һ��������ֱ�Ĵ�ٵ�������ݵ���ʮ���ۡ�����ͨ��
��ǿ����൱�ڽ��������һ����������ֱ����ƹ��������ǡ�

LONG);

  set("exits", ([
        "east" : "/d/city/ximen",
        "west" : __DIR__"west2",
        //"southwest" : "/d/emei/wdroad",

      ]));
  set("outdoors", __DIR__);

  set("objects", ([ "/d/obj/weapon/throwing/shi.c" : 1, ]));
  setup();
}






