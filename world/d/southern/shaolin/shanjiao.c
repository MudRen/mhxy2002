
inherit ROOM;

void create ()
{
	set ("short", "����ɽ����");
	set ("long", @LONG

��������ɽ���£�����һ�̣�������ˮ�����ף��ͱ�����������ֱ��������
˫�ٲ�к��������������Ծ���ݡ����ٲ�֮���Ϸ壬�㲻����������ɽ֮
���㡣
LONG);


	set("exits", 
	([ //sizeof() == 4
		"west" : "/d/southern/wutai/guandao3",
		"southup" : __DIR__"shandao1",
	]));
	
	set("objects", 
	([ //sizeof() == 1
//               __DIR__"npc/jieding" : 1,
	]));


        set("outdoors", 1);

	setup();
}


