//By tianlin@mhxy for 2001.9.18

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "˴����");
  set ("long", @LONG

˴�����ϱ�˫��ͨ�У���������һ�����Ң���ֲ��У����������
�������ش����ֵ���һɫ��ʯ�����̳ɡ��ֵ������Ǹ��ָ����ĸ�լ
���̣�������һ���ƣ���[37m��[35m��[33m��[36mջ[2;37;0m����

LONG);

  set("exits", ([
        "southeast" : __DIR__"tieta",
        "north" : __DIR__"shun4",
        "west" : __DIR__"chunchun",
      ]));

  set("outdoors", __DIR__);

  setup();
}


