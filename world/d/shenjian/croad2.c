// LLY@FYSY
#include <room.h>

inherit ROOM;
void create()
{
        set("short", "����С·");
        set("long", @LONG
·�Ѿ����˾�ͷ��ǰ���Ǻ��ϵ�һ��յأ�̧�۱�����ˮ���ˣ��峺
�ĺ�ˮ�е�Ӱ�Ŵ��̵�ɽӰ����������㲻�ɵ����������г�˵�ģ���
�Ʒ壬��ˮ������ɽׯ��������Ȼ����һ�ֳ�ʥ�ĸо���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"croad1",
  "west" : __DIR__"sjhupan",
   "south" : __DIR__"farm",
  "north" : __DIR__"farm1",
]));
        set("objects", ([
        __DIR__"npc/xiaotong": 1,
        __DIR__"npc/farmer": 2,
                        ]) );
        set("coor/x",-1045);

	set("coor/y",15);

	set("coor/z",0);
	setup();

}
