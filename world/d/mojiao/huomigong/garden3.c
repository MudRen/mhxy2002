
inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG

����һ���̻Ի͵Ĵ��������������������˰������ڴ����
�롣����������һ�����������湩ٺ��һ�ѳ�����һ��Ӣ����������
��������̸Ц������
LONG
        );
        set("exits", ([ 
       "west" : __DIR__"valley",
                      ]));
        set("objects", ([
       "/d/mojiao/npc/master2": 1,
                        ]) );
        set("valid_startroom", 1);
 	  setup();
        replace_program(ROOM);
}

