inherit ROOM;
void create ()
{
  set ("short", "��ʯ·");
  set ("long", @LONG
��������·��������ԼԼ�ĸо���һ����������������
��ƵĴ̱ǵ�ζ��Ҳ��������Ũ��
LONG);

  set("exits", ([
        "west" : __DIR__"damen",
        "east" : __DIR__"road2",
      ]));
  set("outdoors", "mojiao");
  setup();
}
