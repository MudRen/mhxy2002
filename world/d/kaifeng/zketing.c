// by cih 10/01/2002
// Room: /d/kaifeng/zketing
inherit ROOM;

void create ()
{
    set ("short","����");
	set ("long", @LONG

�����������Ŀ����ˡ������м���ľ�������������°���
�ĵ񻨸��ӡ��������п��ڹ���һ�Ż�������ϸһ�����Թ�
�ɲ����ˣ������Ȼ����һ��˶�����ͷ���������·ŷ���
һ�Ű������������Ա�������̫ʦ�Ρ����ӵ����л���һ��
���Ļƽ���¯��
LONG);

	set("exits", 
	([ //sizeof() == 4
  "up" : __DIR__"zzoulang3",
  "northwest" : __DIR__"zhu1",
  "east" : __DIR__"neitang",
	]));
	
	set("objects", 
	([ //sizeof() == 1
  __DIR__"npc/zhubing" : 1,
	]));

	set("valid_startroom", 1);

	setup();
}

