// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "��������");
  set ("long", @LONG

         ����ͨ�������������������������ǿ�ս��������һչ
     ���С���ķ�ʣ�����̫�ź��ˣ���Ȼ�ˣ�������ڱ����л�ʤ
     ���д󽱵ģ�����ÿ[1;32m��[mСʱ����һ�Ρ�

LONG);

  set("outdoors", "changan");
  set("exits", ([ /* sizeof() == 4 */
         "north" : __DIR__"jw",
         "enter":__DIR__"baoming",
]));

        set("no_clean_up",1);
        setup();
}

