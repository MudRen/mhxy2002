//by tianlin 2001.8.6

inherit BULLETIN_BOARD;

void create()
{
        set_name("����ɽ���԰�", ({ "board" }) );
        set("location", "/d/xuyi/nanmen.c");
        set("board_id", "xuyi_b");
        set("long", "����һ��ר�Ÿ�����ɽ���������õİ��ӡ�\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}
