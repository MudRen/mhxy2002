// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit ROOM;

void create ()
{
  set ("short", "[31m��[32m��[33m��[35m��[36m��[m");
  set ("long", @LONG

����߲˵�λ��С���·��֮��,��Ȼ���治��,������߲˹Ϲ�
��Ʒ�ֵ��ǲ���,������˴�ɩ̬�ȺͰ�,���⵹Ҳ���.

LONG);
  set("exits", ([ /* sizeof() == 2 */
        "north" : __DIR__"entrance",
]));
  set("objects",([
        __DIR__"npc/maicaide":1,
        ]));
  set("outdoors", "1");

  setup();
}
