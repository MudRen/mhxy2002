//by tianlin 2001.5.1
inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
              set_name("���ֵ�"+HIY+"ȭ��"+NOR+"���԰�", ({ "board" }) );
            set("location", "/u/tianlin/workroom");
            set("board_id", "tianlin_b");
            set("long",     "������˲��ڼң��������ԣ�лл��\n" );
	setup();
          set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
