#include <ansi.h>

inherit ROOM;
void create ()
{
  set ("short", "����");
  set ("long", @LONG

���ﾡ��Щ�������ӣ���һ�߽���������ʧ�˷�
��ֻ��������ֻ��һƬī�̣���Χ��ɫ����һ
���ġ�

LONG);

  set("exits", ([
              "south" : __DIR__"zhulin6",
                "north" : __DIR__"zhulin8",
              "enter" : __DIR__"zhuting",
      ]));
  set("objects", ([
//        __DIR__"npc/guo"   : 1,
      ]));

  setup();
}


