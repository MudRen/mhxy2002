
inherit ROOM;

void create()
{
        set("short", "�ȵ�");
        set("long", @LONG

ֻ��������Ȫ��ʯ��������ݣ�������ɽ���ƵĹȵأ���׺������������
��һ�㡣��ľ��ˮ֮�䣬��׺����ධ���ܷ�󣬼�һЩ��ɽ̨ͤ��һ��
ʯ��׺�ɵĵ�·������ͨ��ǰ����
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"hateroom",
  "east" : __DIR__"garden3",
   ]));
        set("outdoors", "mojiao");
	setup();
        replace_program(ROOM);
}

