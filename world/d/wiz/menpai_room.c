// Room: /d/wiz/menpai_room
inherit ROOM;

void create ()
{
  set ("short", "����������");
  set ("long", @LONG

�����ǹ�����ս����ʦ���������ɷ�չƽ��ȸ�������ġ�
�������������������£�

�ɣ��Ϻ����ӣ�������̨
�����ݿ�ɽ�޵׶�����ѩɽ
�У����������¹����������ظ�
������ɽ
LONG);

  set("no_fight", 1);
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"jobroom",
]));
  set("light_up", 1);
  set("no_magic", 1);

  setup();
  call_other("/obj/board/menpai_bbs", "???");
}

