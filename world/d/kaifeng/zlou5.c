// by cih 10/01/2001
// Room: /d/kaifeng/zlou2

inherit ROOM;

void create ()
{
  set ("short", "����¥");
  set ("long", @LONG

����¥�ڽṹ����������ڲ��þ������������徲����
֮�С����ܿ����贰��������¥��ֱͨ���¡������ƺ���
��ͬѰ���ĳ�����

LONG);

  set("objects", ([
        __DIR__"npc/zhubajie" : 1,
      ]));

  set("exits", ([
        "down" : __DIR__"zlou4",
      ]));

  setup();
}






