// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "��ҵ��");
  set ("long", @LONG

        ����ǳ����֣��н��ã��ưɣ����ã����������׬���ܶ��
    Ǯ��ֻҪ��ϸɻ׬Ǯ��û������������������[1;36m��Щ�����[mw��
    ����������Ը�����[1;36m����ķ[m��

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "east": __DIR__"road4",
         "west": __DIR__"syroad2",
          "north": __DIR__"jiawu",
         "south": __DIR__"baomu",
]));

        setup();
}
