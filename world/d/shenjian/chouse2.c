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
		"south" : __DIR__"croad1",
	]));
	set("coor/x",-1035);

	set("coor/y",20);

	set("coor/z",0);
	setup();
}


