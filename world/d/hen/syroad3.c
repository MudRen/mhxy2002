// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "��ҵ��");
  set ("long", @LONG

        ����ǳ����֣��н��ã��ưɣ����ã����������׬���ܶ��
    Ǯ��ֻҪ��ϸɻ׬Ǯ��û�����������������һ��[1;33m����[m������
    ��һ��[1;33m����[m��

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "east": __DIR__"syroad2",
         "west": __DIR__"syroad4",
          "north": __DIR__"canting",
         "south": __DIR__"jiaotang",
]));

        setup();
}
