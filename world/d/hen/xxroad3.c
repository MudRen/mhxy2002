// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "��ѧ·");
  set ("long", @LONG

        ����ȫ��ѧϰ�ĵط�����ѧ�ģ�Ҳ��ѧ��ģ������ⶼ����
    ���������ȫ��Ҫ�շѵ�Ŷ��������ѧϰ[1;35m��[m�ģ�������ѧϰ[1;35m����[m�ġ�

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "east": __DIR__"xxroad4",
         "west": __DIR__"xxroad2",
          "north": __DIR__"jianshu",
         "south": __DIR__"gedou",
]));

        setup();
}
