// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "С��");
        set("long", @LONG
�������Ĵ����������ģ����������ȴ�ǻ��������һ
�������������һ����ľ�ƣ�һ��ľ�ܣ������ſ���У�
�Եø���ɭ��š�ľ���ỹ�м��úڲ����ŵĶ�����һ����
���ķ����Ķ�����
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"rpt",
]));
set("objects",([
  __DIR__"npc/master1" : 1,
  __DIR__"obj/coffin" : 1,
  __DIR__"obj/tablet" : 1,
  __DIR__"obj/shelf" : 1,
       	]) );
	setup();
}
