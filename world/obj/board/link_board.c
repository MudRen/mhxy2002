inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
          set_name("�����������԰�", ({ "board" }) );
          set("location", "/u/link/workroom");
          set("board_id", "link_board");
          set("long",     "���ǹ����������ʹ�һ��๵ͨ�����۰塣\n" );
	setup();
          set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
