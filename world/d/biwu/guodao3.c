// Room: /u/biwu/guodao3.c
// Date: bye linxue([1;37m��ѩ[2;37;0m) Fri Apr 30 09:45:45 1999
inherit ROOM;

void create()
{
	set("short", "����������");
	set("long", @LONG
���Ǳ���������ſ�,��·������ʿ�Ƽ��˴�����Ҹ���Ħȭ
���ƣ�ԾԾ���ԡ�����������һ��һ�ҵ�վ�ڴ��ſڣ�ά���ű����
������򡣹�ƽ��Ҳ���⸺������������С�
Ρ��Ĵ����ϸ����ų�͢�ʵ�[0;5;37m�[5m�[5m�[5m�[0m���͵Ľ���

[35m                      ��  ��  ��  ��[0m

[35m                      ��  ��  Ϊ  ֹ[0m


LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"guodao2",
  "enter" : __DIR__"biwu",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard" : 2,
]));
	set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
