// by cih 10/01/2002
// Room: /d/kaifeng/zzoulang

inherit ROOM;

void create ()
{
  set ("short","��������");
  set ("long", @LONG

�������������ڿ�������ȵľ�ͷ�ˡ���Ȼ����û���ˣ����Ǵ���
����Կ������ߵĻ�԰�ﻨ������ǳ������������֡���֪����
��ô���£��Ǹ���԰һ���ļ�����������ӡ�Ҳ�������ǲ�������
Ԫ˧����ʲô�ֽš�����
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"zketing",
  "south" : __DIR__"zzoulang2",
]));
  set("outdoors","kaifeng");
  setup();
}
