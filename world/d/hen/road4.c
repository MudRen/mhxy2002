// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "�����ߵ�");
  set ("long", @LONG

        �����ڼ��ѵ��ߵ��ϣ��������Ǽ��е����������洫����һ�����ʵ�
    ����������������Ǹ���ҵ�֡�

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "east": __DIR__"xxroad1",
         "west": __DIR__"syroad1",
          "north": __DIR__"road3",
         "south": __DIR__"road5",
]));

        setup();
}
