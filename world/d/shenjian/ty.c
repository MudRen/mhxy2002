// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ͥԺ");
        set("long", @LONG
�߳���������������һ��ͥԺ����������һ��Ƭ�Ĺ���
��̧����ȥ��ֻ����������������Ҷ�̳ɵ�·���ϣ����ܶ�
�Ǻ�ɭɭ��,���ǲ�Ҫ�����ˡ�
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"hy",
  "south" : __DIR__"dt",
  "east" : __DIR__"tt6",
  "west" : __DIR__"tt2",
]));
	setup();
}
