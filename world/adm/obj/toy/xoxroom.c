// Room: /d/wiz/menpai_room
inherit ROOM;

void create ()
{
  set ("short", "�λ����ι�����");
  set ("long", @LONG

   һ�����ͨ�ķ���,��������,�ط�Ҳ�ܿ�.ֻ�ǵ��ϵ���־�е�.....
�ŵ������һ�ŵ�������������һ̨С������һЩ������־�ͼ���PLAYBOY��.
ǽ����һ����˯���˵Ĵ�ˮ��,������......������.......
LONG);
/*
�λ����������������£�

�ɣ��Ϻ����ӣ�������̨����֮����ɽ
�����ݿ�ɽ�޵׶�����ѩɽ�����ɽ����ƶ�����ʯɽ�̲�̶
�У����������¹����������ظ�
*/

  set("no_fight", 1);
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"wizroom",
"south" : __DIR__"xoxroom",
]));
  set("light_up", 1);
  set("no_magic", 1);

  setup();
  call_other("/obj/board/menpai_bbs", "???");
}
> 