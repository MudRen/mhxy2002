inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
          set_name("�й���"+HIW+"ʮǿ��"+NOR+"���԰�", ({ "board" }) );
          set("location", "/d/city/zhuque-s1");
          set("board_id", "football_board");
          set("long",     "�й����ߴγ�����籭�����ͣ��й���\n" );
        setup();
          set("capacity", 1000);
        replace_program(BULLETIN_BOARD);
}
