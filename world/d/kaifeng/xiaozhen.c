//by tianlin 2001.7.30

inherit ROOM;

void create ()
{
  set ("short", "����С��");
  set ("long", @LONG

������ǿ��������,��������һ��С����,����Ҳ����˽�
�����ĵط�,�����и���ͷ������վ��,��������Щʲô
LONG);

  set("exits", ([
        "north" : __DIR__"migong/mi2",
        "south" : __DIR__"xiaolu2",
      ]));
  set("objects", ([
        __DIR__"npc/laotou" :  1,
      ]));

  setup();
}


