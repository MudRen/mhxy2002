// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "��ҵ��");
  set ("long", @LONG

        ����ǳ����֣��н��ã��ưɣ����ã����������׬���ܶ��
    Ǯ��ֻҪ��ϸɻ׬Ǯ��û�����������������һ��[1;34mĹ��[m������
    ��[1;34m�ҽ̷�������[m��

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "east": __DIR__"syroad5",
         "west": __DIR__"meirong",
          "north": __DIR__"mudi",
         "south": __DIR__"jj",
]));

        setup();
}
