// menpai_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("�������Ա�", ({ "board" }) );
        set("location", "/u/swagg/workroom");
        set("board_id", "menpai_b");
        set("long",     "�������Ա������Լ���������ʲô����ͺõĽ�������ڴ����ԡ�\n" );
        setup();
        set("capacity", 200);
        replace_program(BULLETIN_BOARD);
}

