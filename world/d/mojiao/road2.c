inherit ROOM;
void create ()
{
  set ("short", "��ʯ·");
  set ("long", @LONG
��������·��������ԼԼ�ĸо���һ����������������
��ƵĴ̱ǵ�ζ��Ҳ��������Ũ��
LONG);

  set("exits", ([
        "west" : __DIR__"road1",
        "east" : __DIR__"road3",
      ]));
  set("outdoors", "mojiao");
  setup();
}
