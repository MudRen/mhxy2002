// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: some place in ��ţ����
// inside2.c

inherit ROOM;

void create ()
{
  set ("short", "[0;36m����[m");
  set ("long", @LONG

��ֻ��һǽ֮����ǰ�õ�����ȴһ��Ҳ�������ˡ����Ҷ�����
�֣�΢�紵�������з����������������ȱߵ�ľ���Ե��൱��
�ɣ�ȴһ����Ⱦ��Ҳ������ʱ����ɨ������������ľ��ͨ����
�����
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"houlang2",
  "south" : __DIR__"jingtang",
]));

  setup();
}