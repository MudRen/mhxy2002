
inherit ROOM;
string *names=({
	__DIR__"tt5",
	__DIR__"tt1",
	__DIR__"tt6",
	__DIR__"tt7",
} );
void create()
{
	set("short", "��������");
	set("long", @LONG
����Щǧ���ľ�£��Ѿ����˱粻�巽���ˣ�ֻ���ý��²�����Ҷ��ɳɳ��������
LONG
	);
	setup();
}
void reset()
{
	int i,j;
	string temp;
	::reset();
	for (i=0;i<=3;i++)
	{
		j=random(4);
		temp=names[j];
		names[j]=names[i];
		names[i]=names[j];
		names[i]=temp;
	}
	set("exits", ([
		"north" : names[0],
		"south" : names[1],
		"east" : names[2],
		"west" : names[3],
	]));
}
