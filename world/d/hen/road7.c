// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "�����ߵ�");
  set ("long", @LONG

        �����ڼ��ѵ��ߵ��ϣ��������Ǽ��е�������������һ��[1;32mҽԺ[m
    �������и�[1;32m�ĵǷ�[m��ǧ��Ҫ���Ŷ��

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "east": __DIR__"yy",
         "west": __DIR__"mdf",
          "north": __DIR__"road6",
         "south": __DIR__"jw",
  ]));

        setup();
}
