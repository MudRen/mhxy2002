//By tianlin@mhxy for 2001.9.27
//�����Ż�

inherit BULLETIN_BOARD;

void create()
{
        set_name("�䵱�������԰�", ({ "board" }) );
        set("location", "/d/wudang1/sanqingdian");
        set("board_id", "wudang_b");
	 set("long", "����һ�����䵱���½��������԰塣\n");
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}

