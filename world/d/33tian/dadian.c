// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: /d/33tian/west1
inherit ROOM;

void create ()
{
  set ("short", "���ʹ�");
  set ("long", @LONG
���������춵�ʹ���.�˹�λ����ʮ����֮��,һ����̫��
�Ͼ���ס��.������һ����ҩ¯,��������ͯ������ҩ¯��ɿ��,
������������һ�ɷҷ��ĵ�ҩ��Ϣ.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"doushuai-gate",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/laojun": 1,
]));
  setup();
}
