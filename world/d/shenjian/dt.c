// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
һ����������ɿ������������������Ϲ������鳤ľ���������飺
[37m
		   ��	     һ
		   ��	     ��
		   ��	     ��
		   ��	     ��
		   ��	     ʮ
		   ��	     ��
		   ��	     ��
[0m
�������м�ƫ��ĵط��������˵���λ���������������ż�ʮ���޺��Σ�
�����ñ��͵���λ�������к�̺�̵أ��Ĵ����ǹ��棬�������������磬
ֻ�����ڲ�ͬ�ĵط����Ǻ������ƺ�����һ�����Ƶġ�
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"ty",
  "south" : __DIR__"qhuayuan",
  "east" : __DIR__"rpt",
  "west" : __DIR__"lpt",
]));
  set("outdoors", __DIR__);
              set("coor/x",-1310);

	set("coor/y",260);

	set("coor/z",10);
	setup();
}
