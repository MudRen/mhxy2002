// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "��ѧ·");
  set ("long", @LONG

        ����ȫ��ѧϰ�ĵط�����ѧ�ģ�Ҳ��ѧ��ģ������ⶼ����
    ���������ȫ��Ҫ�շѵ�Ŷ��������ѧϰ[1;44m����[m�ģ�������ѧϰ[1;44mħ��[m�ġ�

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "east": __DIR__"xxroad5",
         "west": __DIR__"xxroad3",
          "north": __DIR__"magic",
         "south": __DIR__"liyi",
]));

        setup();
}
