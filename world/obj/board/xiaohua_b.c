//Cracked by Roath
// idle_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("Ц�����", ({ "board" }) );
	set("location", "/d/city/misc/lqbz");
	set("board_id", "xiaohua_b");
	set("long",
		"����һ��Ц�������\n" );
	setup();
	set("capacity", 200);
	replace_program(BULLETIN_BOARD);
}
