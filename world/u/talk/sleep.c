// Room: /u/gua/sleep.c

inherit ROOM;

void create()
{
	set("short", "��ҹ��");
	set("long", @LONG
�������Ϲ�ר������͵���õĵط� �ٺ� ��������ɣ�
һ����������� �Ϲϻ����������� ��һ����������!
����һ��������....�ͱ��������׳�ȥ sigh
ϰ�߾ͺ��� �ʹ������� snicker��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"workroom",
]));
  set("no_fight", 1);
        set("if_bed",1); 
  set("sleep_room", 1);

	setup();
	replace_program(ROOM);
}
