// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "�����ߵ�");
  set ("long", @LONG

        �����ڼ��ѵ��ߵ��ϣ��������Ǽ��е���������������С��ʳ��
   �ĵط���������һ���ӻ��̡�

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "east": __DIR__"foodshop",
         "west": __DIR__"miscshop",
          "north": __DIR__"road2",
         "south": __DIR__"road4",
]));

        setup();
}
