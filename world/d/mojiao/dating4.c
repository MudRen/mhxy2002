#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
     set("short",HIR"ħ���ܶ�"NOR);
     set("long",
   "                                   \n"
"                        "+HIR+"ħ���ܶ�"+NOR+"                 \n"    
"�������ħ�̵����ã�Ҳ�ǽ�����ɰ״�������ĵط�����ǰ����\n"
"һ����īɽˮ����\n"NOR
);
  set("exits", ([ /* sizeof() == 3 */
          "out": __DIR__"dating3",
          "west": __DIR__"bedroom",
          "east": __DIR__"jobroom",
          "north": __DIR__"roada",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/master" : 1,
  __DIR__"npc/tai" : 1,
  ]));
  set("valid_startroom", 1);
 setup();
  call_other("/obj/board/mj_b", "???");
      replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
   if((string)me->query("family/family_name")=="ħ��") return 1;
    if (dir == "west" ) {
        return notify_fail("�����Ƿ�ɰ׵��鷿������ñ��ȥ�ˡ�\n");
    }
return 1;
}
