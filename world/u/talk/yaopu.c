//by tianlin 2001.8.14�޸�ҩ�̲���ս��.

inherit ROOM;
#include <ansi.h>
void create ()
{
       set ("short","������׊ʘ���" );
        set ("long", @LONG

�@����������Á���ǲ�ʘ��ĵط����@�e�ѝM�˸��N�[��C��߀�кܶ�
߀�кܶ��ʽ�����Á���ǲ�ʘ��Ė|����
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "west" : __DIR__"workroom",
        ]));
        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/girl" : 1,
        ]));
  set("no_fight", 1);
  set("no_magic", 1);

//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}


