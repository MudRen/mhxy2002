//By tianlin@Mhxy for 2002.3.11
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", HBRED+HIY"������");
  set ("long", 

"\n��ǽΡ�룬�������������ܻ���������"HIY"�������š�"NOR"����\n"
"����ǻʹ������ˣ�һ��İ��յ��˽�Ȼֹ��������������\n"
"Խ�ʼҽ��ء�\n\n"
);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/weishi" : 2,
  ]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/city/xuanwu-n1",
"north" : __DIR__"damen",
// "east" : "/d/city/datang",
]));

  setup();
}


