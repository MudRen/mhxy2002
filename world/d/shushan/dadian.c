//dadian.c by yushu 2000.11
inherit ROOM;
#include <ansi.h>
void init();

void create()
{
  set("short",HIR "��"HIY "����" HIR "��" NOR);
  set("long", @LONG

�߽����ͻ��һ������֮�⣬������ʮ�ֿտ����������յ
��ƣ������Ǿ�׳�彣��ʿ����ɭ�ϱ��ˡ�������һ������ǰ��
һ��̴ľ��������������һ��������
LONG);
        set("exits", 
        ([ //sizeof() == 4
               "south" : "/d/shushan/xiaoyuan",
              "northup" : "/d/shushan/dating",
               "west" : "/d/shushan/changlang1",
               "east" : "/d/shushan/changlang",
            ]));
               set("objects", 
        ([ //sizeof() == 1
               "d/shushan/npc/dizi" : 1,
               "d/shushan/npc/dizi1" : 1,
               "d/shushan/npc/songer": 1,
               "d/shushan/npc/zhangmen": 1,

    ]));       
  
        setup();
}

