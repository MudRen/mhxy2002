#include <ansi.h>

inherit ROOM;
void create ()
{
      set ("short", HBMAG+HIY" ����ͤ "NOR);
  set ("long", @LONG

          [1;32m  ��   ��   ͤ   [2;37;0m

�������ɴ������ɵ�ͤ�ӣ�������һ��
����ׯ����С������������������������
�����������еľ�ɫ��

LONG);

  set("exits", ([
              "out" : __DIR__"zhulin7",
      ]));
  set("objects", ([
        __DIR__"npc/lan"   : 1,
        __DIR__"npc/cui"   : 1,
      ]));

  setup();
}


