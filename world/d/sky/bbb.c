// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "[37m������[m");
  set ("long", @LONG

һ�����Ϻõĵ�ذ��������С��,�������,���滹����һЩ
��֪������ʲô��ͼ��.�ŵ�������һ���峺��С��,�������ǵ��
������һЩ����,����ԧ���ں������е�����,ż��Ҳ�ܿ���һ��ֻ
�ɺ״����Ϸɹ�,�ŵı����������������.
LONG);

  set("exits", ([ /* sizeof() == 1 */
    "south" : __DIR__"nanmenting.c",
      "north" : __DIR__"dianmen.c",
]));


  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tong-nan" : 2,
]));

  setup();
}
