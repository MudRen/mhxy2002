// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "�����ߵ�");
  set ("long", @LONG

        �����ڼ��ѵ��ߵ��ϣ��������Ǽ��е�������������С��
   ��Ϣ�ĵط���

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "east": __DIR__"rest",
          "north": __DIR__"road1",
         "south": __DIR__"road3",
]));

        setup();
}
