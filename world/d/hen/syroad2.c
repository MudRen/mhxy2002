// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "��ҵ��");
  set ("long", @LONG

        ����ǳ����֣��н��ã��ưɣ����ã����������׬���ܶ��
    Ǯ��ֻҪ��ϸɻ׬Ǯ��û�����������������һ��[1;31m�ù�[m������
    ��һ��[1;31m��ũ��[m��

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "east": __DIR__"syroad1",
         "west": __DIR__"syroad3",
          "north": __DIR__"luguan",
         "south": __DIR__"nongchang",
]));

        setup();
}
