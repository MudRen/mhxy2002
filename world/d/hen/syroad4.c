// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "��ҵ��");
  set ("long", @LONG

        ����ǳ����֣��н��ã��ưɣ����ã����������׬���ܶ��
    Ǯ��ֻҪ��ϸɻ׬Ǯ��û�����������������һ��[1;35m��ľ��[m������
    ��ר��[1;35m�ڵ�̯�ĵط�[m��

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "east": __DIR__"syroad3",
         "west": __DIR__"syroad5",
          "north": __DIR__"famu",
         "south": __DIR__"ditan",
]));

        setup();
}
