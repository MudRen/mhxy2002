
inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
            set_name("������Ե��չ���۰�", ({ "board" }) );
           set("location", "/d/wiz/entrance");
          set("long",     "���ǹ���ʦ����һ��ཻ������ͬ�ٽ�������Ե��չ�����۰塣\n" );
	setup();
          set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
