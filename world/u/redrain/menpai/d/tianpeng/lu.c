#include <ansi.h>

inherit ROOM;
void create ()
{
  set ("short", "ʯ��·");
  set ("long", @LONG

С·��������ͷ׵�ʯ���̳ɵġ�ʯ������˸��ֻ��ƣ����Ǻ�
����·�߳�����ɻ�ͤͤ�����ѷ�����ȥ��ֻ��ż�������ļ���
�������������ܵ�������

LONG);

  set("exits", ([
              "south" : __DIR__"zhengting",
              "west" : __DIR__"zhulin",
      ]));
  set("objects", ([
//        __DIR__"npc/guo"   : 1,
      ]));

  setup();
}


