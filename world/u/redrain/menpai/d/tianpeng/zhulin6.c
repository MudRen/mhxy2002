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
              "south" : __DIR__"zhulin5",
              "north" : __DIR__"zhulin7",
      ]));
  set("objects", ([
//        __DIR__"npc/guo"   : 1,
      ]));

  setup();
}


