// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "�����ߵ�");
  set ("long", @LONG

        �����ڼ��ѵ��ߵ��ϣ��������Ǽ��е������������Ǹ�[1;32m�羰��[m
    ����ȥɢɢ���������и�[1;32mKTV����[m��

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "east": __DIR__"fjq",
         "west": __DIR__"ktv",
          "north": __DIR__"road5",
         "south": __DIR__"road7",
]));

        setup();
}
