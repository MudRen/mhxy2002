//by tianlin@MHXY. 2001.7.4

inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", HIR"�� "+HIY"�� "+HIB"��"NOR);
        set ("long", @LONG

�������ǳ����������ӵ�һ����ᣬ���е��˴����Щ����֮ͽ����
ɱ���٣���ѹ���գ��޶��������ٸ�ȴ����ץ���ѱ��������֮��
������������Ƥ���Σ�����λ�������ģ��Ա����˼�����Ŀ�׶�Ĵ�
�֡�
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"east" : __DIR__"beiyin2",
		"north" : __DIR__"tang",
		"west" : __DIR__"sanhua-mishi",
	//	"south" : __DIR__"tang2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/tangzhu1" : 1,
		__DIR__"npc/fei1" : 2,
		__DIR__"npc/fei2" : 2,
        ]));


        setup();
	replace_program(ROOM);
}


