inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIR"������"NOR);
        set("long", @LONG
��������ס�ĵط�,һ�����ﲻ���б�����,�������ĵ���
�������˿��Ե���������,Ҳ�����Ϊ���ԭ��,�����Ե�
�徻�˺ܶࡣ
LONG
        );
        set("exits", ([
                "east" : __DIR__"zoulang",
                
               ]) );
                 set("objects", ([
                __DIR__"npc/mingwang1":1,
        ]) );

        set("no_fight",1);
       set("no_sleep", 1);
       set("no_magic", 1);


        setup();
        replace_program(ROOM);
}
