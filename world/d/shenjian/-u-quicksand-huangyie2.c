inherit ROOM;

void create()
{
        set("short", "��Ұ");
        set("long", @LONG
����һ���ޱߵ�ɳ���أ�ɽ�Ƶ�������ͻȻ������Ӱ���١����������
���綼��ů�ġ����ϵ�ʯ������һ�ְ������ɫ�������Ǳ���ѪȾ���һ����
һ���������۵�С������������չ��
LONG
        );
        set("exits", ([ 
  "southeast" : __DIR__"huangyie0",
  "southwest" : __DIR__"huangyie1",
  "southwest" : "/d/shenjian/road",
]));
        set("outdoors", "shenjian");
	setup();
	replace_program(ROOM);
}
