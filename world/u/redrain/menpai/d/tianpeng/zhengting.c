#include <ansi.h>

inherit ROOM;
void create ()
{
  set ("short", HBRED" ������� "NOR);
  set ("long", @LONG

���ﲼ�õ���Ϊ���ţ������ҽ�վ�����ԣ�Ҳ������Ϊû
����˵�������ϵ����պ����ࡣ

              [1;37m  ��    ��    ��    ��[2;37;0m

LONG);

  set("exits", ([
          "north"   : "/d/tianpeng/lu",
        "west"   : "/d/kaifeng/shuaifu",
               "south" : __DIR__"pianting",
      ]));
  set("objects", ([
        __DIR__"npc/zhangmen"   : 1,
      ]));

  setup();
}


