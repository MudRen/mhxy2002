// LLY@FYSY
inherit ROOM;

void create()
{
	set("short", "��ջ");
	set("long", @LONG
һ������ͨ�Ŀ�ջ����ǰһ��һ�ɸߵ���ˣ����������������
����д����л�������Ǵ���Ψһ��һ����ջ����ջ���Ǻܴ�װ��
��Ҳ����������������ȴ�ܲ�����Ϊһ���ļ������ϵ��н�����
�˾������ȥ��ɽׯ��սл���塣
LONG
	);
	set("exits", ([ 
		"north" : __DIR__"croad1",
	]));
        set("objects", ([
                __DIR__"npc/waiter1" : 1,
        ]) );
	set("coor/x",-1035);

	set("coor/y",10);

	set("coor/z",0);
	setup();
replace_program(ROOM);

}
