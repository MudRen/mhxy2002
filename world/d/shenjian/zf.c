// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�ʷ�");
        set("long", @LONG
�������Ӷ����ɼ�Ӳ�Ļ���ʯ���ɵģ����а���һ��С��������
�������ʱ������������ɽׯ���ʷ��ˣ���ɽׯ�˶��ڶ࣬��֧
Ҳ�Ͳ�С�����еĿ�֧��Ҫ�������
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"rroad",
 ]));
set("objects", ([
		__DIR__"npc/xiansheng" : 1,
                __DIR__"npc/guard3" : 2,
                  __DIR__"npc/guard" : 1,
	]));
	setup();
}
