#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
     set("short",HIW"ħ��"NOR);
     set("long",

"һ���ߴ���ɫ�Ľ������ڸ߸ߵ�ש̨�Ϻ����߱������Ӧ\n"
"��ǰ����һ���޴��ʯ����\n"



   "                                   \n"
"              "+HIY+"������������������������\n"+NOR+""
"              "+HIY+"��                    ��\n"+NOR+""
"              "+HIY+"��    ����ɽ������    ��\n"+NOR+""
"              "+HIY+"��                    ��\n"+NOR+""
"              "+HIY+"������������������������\n"+NOR+""
);
  set("exits", ([ /* sizeof() == 3 */
          "west" : __DIR__"road5",
          "enter": __DIR__"dating",
]));
   set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/yun" : 1,
 __DIR__"npc/zhangmen" : 1,
 __DIR__"npc/guard" : 3,
  ]));
 setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "enter" ) {
        if (objectp(present("zhang men", environment(me)))) {
        if((string)me->query("family/family_name")=="ħ��") {
        return ::valid_leave(me, dir);
        }
        return notify_fail("���Ŵ�ʦ�ֺȵ����������������\n");
        }
        }
        return ::valid_leave(me, dir);
}
