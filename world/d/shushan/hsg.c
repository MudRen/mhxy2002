//shushan by yushu 2000.11
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", HIR "��" HIY "��ɽ��" HIR "��" NOR);
  set ("long", @LONG

��ɽ�ɵĺ�ɽ������������ɽ�ɾ����ش��¼��ĵط�����λ����׷���ӡ�
�����������︺���ػ�����һЩ�¿����������ǡ� 
LONG);

   set("exits", ([ /* sizeof() == 2 */
       "south" : "/d/shushan/houshan7",
       "west" : "/d/shushan/woshi",
       "east" : "/d/shushan/liangong",
  ]));
  set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/zhuiyunzi" : 1,
                __DIR__"npc/qingyunzi" : 1,  
]));


  setup();
}






