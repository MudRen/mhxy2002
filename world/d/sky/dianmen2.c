// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "[31m������[m");
  set ("long", @LONG

�������������ĵ�����,���ϸ߸߹���һ����,���������
����������ĸ�����,��Χ��һЩ����콫.����������������.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"dadian",
   "south" :__DIR__"bridge",
]));


  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tian-bing" : 3,
  __DIR__"npc/tian-jiang" : 1,
]));

  setup();
}
int valid_leave(object me, string dir)
{
   if (dir == "north" ) {
        if (objectp(present("tian jiang", environment(me))))
   return notify_fail("�콫�ȵ�:δ�ñ�������,�������!!\n");
        if (objectp(present("tian bing", environment(me))))
       return notify_fail("����������Ҽҽ������ڣ�С�˲��ҷ�����ȥ��\n");
}
       return ::valid_leave(me, dir);
}
