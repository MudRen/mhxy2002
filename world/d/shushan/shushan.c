//shushan.c by yushu 2000.11
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", HIR "��" HIG "��üɽ" HIR "��" NOR);
  set ("long", @LONG
������ͨ����ɽ�ɵ�ɽ·��·��᫲�ƽ���Ա߾���ɽ�£�
����һ�������ɵ�ͷ��Ŀѣ����Ͻ������۾�������һ������
��ˤ�÷�����ǡ�
LONG);

  set("outdoors", 2);
  set("exits", ([ /* sizeof() == 2 */
  "westup" : "/d/shushan/shushan1",
     "west" : "/d/kaifeng/wutaishan/door", 
]));

  setup();
}






