//by tianlin 2001.7.30

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", HIG"ǽ��"NOR);
  set ("long", @LONG

�����ǿ����ǽ��,���ﲻ����������,ͻȻ�㷢��
һ������ֵ���վ������,���Ļ�ͦ����˽��.
LONG);

  set("exits", ([
        "��ǽ" : __DIR__"zhu2",
      ]));
  set("objects", ([
        __DIR__"npc/zhuxiaojie" :  1,
        __DIR__"obj/jingangpa" :  1,
      ]));

  setup();
}

