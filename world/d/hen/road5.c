// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "�����ߵ�");
  set ("long", @LONG

        �����ڼ��ѵ��ߵ��ϣ��������Ǽ��е������������Ǹ�[1;32m��԰[m
    ����ȥɢɢ����������һ��[1;32m�˶���[m��

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "east": __DIR__"gy",
         "west": __DIR__"ydc",
          "north": __DIR__"road4",
         "south": __DIR__"road6",
]));

        setup();
}
