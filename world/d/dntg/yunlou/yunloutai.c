#include <room.h>
inherit ROOM;


void create ()
{
  set ("short", "��¥̨");
  set ("long", @LONG

���˹���һС̨��Զ���ɾ���������������ϼ������ǧ������
�̡�Զ�ϳ��ű����ɣ��칬����ӳ�ƹ⡣�����������������ɾ���
�����˼�����ࡣ
LONG);
set("no_fight", 1);
set("no_magic", 1);
  set("exits", ([ /* sizeof() == 1 */
"down": __DIR__"yunlou.c",
  ]));
  set("objects", ([ /* sizeof() == 3 */
   __DIR__"npc/litianwang":1,
]));
set("outdoors", 1);
  setup();
}


