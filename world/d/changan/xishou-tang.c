#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","ϴ�ֳ�");
        set("long", @LONG
�����Ǳ�����ս��������ϴ��ĵط�������ϴȥɱ��֮����
���õúܼ򵥣��м�һ��ˮ�أ�����ð������ˮ������������ˣ�
���������Ķ���ԹԹ��ֻ��������ϴ��[2;37;0m[5m[1;31m(xi)[2;37;0m,�Ϳ��Խ���ɱ����
�������г�ҡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : "/d/changan/nanchengkou",
]));
	set("no_fight",1);
	set("no_magic",1);
	set("NONPC",1);
        
	setup();
}

void init()
{
	add_action("do_xi", "xi");
}

int do_xi()
{
	this_player()->remove_all_killer();
	message_vision(HIY"$N���ڵأ�����������ǰ���еĳ�ҡ�\n"NOR,this_player());
	this_player()->set("bellicosity",0);
	message_vision(HIW"��������ɱ��֮��ȫ����ʧ�ˣ�\n"NOR,this_player());
	return 1;

}
