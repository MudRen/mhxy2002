// by cih 10/01/2002
// Room: /d/kaifeng/zzoulang

inherit ROOM;

void create ()
{
  set ("short","��������");
  set ("long", @LONG

�������������ɱ����Ϲᴩ������ۡ������Ԫ˧����һ�ж�������
�ɡ�����������ȥ����������һ������ͤ����������������Ԫ˧��
�ϸ���鷿�ˡ�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"zzoulang3",
  "south" : __DIR__"zzoulang",
]));

  set("outdoors","kaifeng");
  setup();
}
