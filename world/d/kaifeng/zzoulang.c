// by cih 10/01/2002
// Room: /d/kaifeng/zzoulang

inherit ROOM;

void create ()
{
  set ("short","��������");
  set ("long", @LONG

��������������˽�ȡ�������������������󶼹�����ˡ�����
��ȴ��Щ������ȱ�ݣ�������˧�����ر��޽�������������������
���Լ������֮����
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"zzoulang2",
  "down" : __DIR__"shuaifu",
]));

  set("outdoors","kaifeng");
  setup();
}
