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
         "east": __DIR__"xxroad2",
         "west": __DIR__"road4",
          "north": __DIR__"kexue",
         "south": __DIR__"poem",
]));

        setup();
}
