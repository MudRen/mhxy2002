// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "��ѧ·");
  set ("long", @LONG

        ����ȫ��ѧϰ�ĵط�����ѧ�ģ�Ҳ��ѧ��ģ������ⶼ����
    ���������ȫ��Ҫ�շѵ�Ŷ��

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "east": __DIR__"xxroad3",
         "west": __DIR__"xxroad1",
          "north": __DIR__"shenxue",
         "south": __DIR__"junshi",
]));

        setup();
}
