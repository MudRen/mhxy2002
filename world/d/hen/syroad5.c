// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "��ҵ��");
  set ("long", @LONG

        ����ǳ����֣��н��ã��ưɣ����ã����������׬���ܶ��
    Ǯ��ֻҪ��ϸɻ׬Ǯ��û�����������������һ��[1;36m����[m������
    ��ר��[1;36m���Եĵط�[m��

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "east": __DIR__"syroad4",
         "west": __DIR__"syroad6",
          "north": __DIR__"gongdi",
         "south": __DIR__"shoulie",
]));

        setup();
}
