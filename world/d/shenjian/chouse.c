// LLY@FYSY
inherit ROOM;

void create()
{
	object con, item;

	set("short", "ũ��");
	set("long", @LONG
л�Ҵ岢����Ϊ����ɽׯ���Ź�ϵ�����󷱻��������Ӿ���֤��
һ���ˣ�ľ���������������ڿ���һ�ˣ�����Ķ����и�Ů֯����Ĺ��ߺ�
�����������Ʒ����ǽ�϶�����һ����������Ҳ����Ǻͱ��ũ�Ҳ�ͬ�ĵ�
���˰ѡ�
LONG
	);
	set("exits", ([
		"north" : __DIR__"croad",
	]));
	set("coor/x",-1025);

	set("coor/y",10);

	set("coor/z",0);
	setup();
}


