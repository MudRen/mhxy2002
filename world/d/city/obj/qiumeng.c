//by  xiaoran

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", HIY"����¥"NOR);
  set ("long", @LONG
�ٴ��ĵ��������ɺ�ë̺��¥��������������Ǯ��������
ʯ���Ǯ����������ɫ��Ǯ�������졣������һ��÷��ʽ
����С������������ƿ���㱸������һ�������������ӡ�
LONG);

  set("exits", ([
       "down" : __DIR__"caotang",
      ]));
  set("objects", ([
        "/d/city/npc/xianzi.c" : 1,
      ]));
  setup();
}
