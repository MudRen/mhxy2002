inherit ROOM;
void create ()
{
  set ("short", "ɽʯ·");
  set ("long", @LONG

������ɽ�£�����ǰһ�����ȷ�Ҳû�ˣ��Ĵ�����ïʢ
����ǰ�Ŀ���ľ�ɫ��Ȼ��ͬ��
LONG);

  set("exits", ([
        "northwest" : __DIR__"road5",
        "east" : __DIR__"gate",
      ]));
  set("outdoors", "mojiao");
  setup();
}
