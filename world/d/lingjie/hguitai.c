// link
inherit ROOM;
void create()
{
        set("short", "��̨��");
        set("long", @LONG
����������Ͳ����Ĺ�̨���ˣ����Ƕ�ææµµ��������ʷ���Ա�ܹ�
Ҫ���˹���������������ķ���ԱҪ���ӣ��õ����ߵĳ�����ϴ��
LONG
        );
	set("valid_startroom",1);
        set("exits", ([ /* sizeof() == 4 */
//  "east" : __DIR__"chufang2",
  "south" : __DIR__"mdc",
]));
	set("objects", ([
		__DIR__"npc/fuwu4" : 1,
	]));
	set("coor/x",-40);
	set("coor/y",160);
	set("coor/z",0);
	setup();
}
