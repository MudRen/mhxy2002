inherit BULLETIN_BOARD;

void create()
{
  set_name("ˮ½������Բ�", ({"board"}) );
  set("location", "/d/kaifeng/gate");
  set("board_id", "sldh_b");
  set("capacity", 100);
  set("long", "ˮ½�������Բ�������ʦ֪ͨ����ұ��������á�\n");
  setup();
  replace_program(BULLETIN_BOARD);
}

