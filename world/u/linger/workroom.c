// Room: /u/linger/workroom.c

inherit ROOM;

void create()
{
set("short", "Ů����");;
	set("long", @LONG

�����ǰһ�ڣ�����ʲôҲ��֪���ˣ�����
������������������֪��������
��վ��һ��Ʈ��õ�廨���ԡ����...
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "up" : "/u/valen/workroom",
  "down" : "/d/city/kezhan",
  "wiz" : "/d/wiz/wizroom",
  "tianlin" : "/u/tianlin/workroom",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
