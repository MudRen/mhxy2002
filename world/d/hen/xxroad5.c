// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "��ѧ·");
  set ("long", @LONG

        ����ȫ��ѧϰ�ĵط�����ѧ�ģ�Ҳ��ѧ��ģ������ⶼ����
    ���������ȫ��Ҫ�շѵ�Ŷ��������ѧϰ[33m�赸[m�ģ�������ѧϰ[1;33m�滭[0m�ġ�

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "west": __DIR__"xxroad4",
          "north": __DIR__"huihua",
         "south": __DIR__"wudao",
]));

        setup();
}
