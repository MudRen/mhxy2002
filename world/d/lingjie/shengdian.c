// link
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIG"��ƺ"NOR);
        set("long", @LONG
���������ʥ��ǰһƬ���̵Ĳ�ƺ����ƺ�������ż��ò�֪�����ȴ�
ֲ�ɢ�ҵķ��ż���ʯͷ��������ϧ��Ϊ������������������ú�
�ˡ�����ò�Ҫ����ȥ���ݵ��ϻ�ͣ�ż�ֻС��Ҳ���Ѿ���ľ�˰ɣ�
���ǲ������ˡ�
LONG
        );
	set("valid_startroom",1);
        set("exits", ([ 
  "west" : __DIR__"shengdian0",
  "north" : __DIR__"swimrm",
  "up" : __DIR__"shengdian1",
  "out":__DIR__"rukou"
]));
        set("objects", ([
        __DIR__"npc/bird" : 1,
                        ]) );

	set("coor/x",20);
	set("coor/y",40);
	set("coor/z",0);
	setup();
}