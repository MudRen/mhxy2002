inherit ROOM;

void create ()
{
  set ("short", "����ɽ��");
  set ("long", @LONG

����ɽ�ֳ�̫��ɽ���೤���ǰ�ʮ������С������������
����֮˵���ݴ���������ɽ�н�����������ٵ���Խ����ɽ�ڣ�
����������ƣ�ȴ������֮·������ɽ��
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : "/d/wusheng/shijie1",
  "south" : __DIR__"broadway2",
  "north" : __DIR__"broadway1",
]));
  set("outdoors", 2);

  setup();
}






