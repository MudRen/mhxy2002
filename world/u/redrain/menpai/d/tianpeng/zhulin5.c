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
              "south" : __DIR__"zhulin4",
              "north" : __DIR__"zhulin6",
              "west" : __DIR__"maowu",
      ]));
  set("objects", ([
       __DIR__"npc/zhang"   : 1,
      ]));

  setup();
}


