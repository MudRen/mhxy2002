//Cracked by Roath
// idle_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("������԰�", ({ "board" }) );
        set("location", "/d/city/misc/advise");	
       set("board_id", "idle_b");
	set("long",	"����һ������Ҹ���MUD����������԰塣\n" );
	setup();
	set("capacity", 200);
	replace_program(BULLETIN_BOARD);
}
