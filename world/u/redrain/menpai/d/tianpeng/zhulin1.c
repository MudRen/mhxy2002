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
              "east" : __DIR__"zhulin",
              "west" : __DIR__"zhulin2",
      ]));
  set("objects", ([
//        __DIR__"npc/guo"   : 1,
      ]));

  setup();
}


