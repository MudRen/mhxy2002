inherit BULLETIN_BOARD;
void create()
{
        set_name("��ħ̨", ({ "board" }) );
        set("location", "/d/mojiao/dating4.c");
        set("board_id", "mj_b");
        set("long", "����һ���߾ųߣ����ž�����������̨��\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}
