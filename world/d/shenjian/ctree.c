// LLY@FYSY
#include <room.h>

inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
һ�ÿ��������ں��ϣ����˼�����Լ���Կ���һ��Ƭ�ӻ�������
Ʈ��һ�����š�СС�ӻ��塱�ľ��졣
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"sjhupan",
  "north" : __DIR__"jiujia",
]));
        set("coor/x",-1065);

	set("coor/y",15);

	set("coor/z",0);
set("no_magic",1);
	setup();

}
