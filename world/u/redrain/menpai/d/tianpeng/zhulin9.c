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
                "south" : __DIR__"zhulin8",
                  "east" : __DIR__"lu1",
                  "west" : __DIR__"cangku",
      ]));
  set("objects", ([
            __DIR__"npc/tongl"   : 1,
            "/d/kaifeng/npc/zhubing"   : 3,
      ]));

  setup();
}


