// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "�ڵ�");
  set ("long", @LONG
���������۵ı�����,������������ʮ�ֻ���,����������ӹ�׵ĸо�,
���������ư�������,���˿��ž������һ��.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"dadian.c",
]));


  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yudi" : 1,
]));

  setup();
}

