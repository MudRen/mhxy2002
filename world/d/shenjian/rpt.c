// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{        object con, item;

        set("short", "��ƫ��");
        set("long", @LONG
���е����ϻ�����һ����������֮�ֵĿ�ݣ�������Ǹ���
�������м��������������˸����鼮�����������ǹ�������
ǲ�ĵط��ˡ�
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"xw",
  "west" : __DIR__"dt",
]));
set("objects", ([
		__DIR__"npc/swordman" : 1,
                __DIR__"obj/bookshelf" : 1,
          	]));

        set("coor/x",-1300);

	set("coor/y",260);

	set("coor/z",10);
set("no_magic",1);
	setup();
}
void reset()
{
        object          *inv;
        object          con, item, item2, item3, item4;
        int             i;

        ::reset();
        con = present("���", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 1) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"obj/fybook");
                item2 = new(__DIR__"obj/fybook2");
                item3 = new(__DIR__"obj/fybook3");
                item4 = new(__DIR__"obj/zizhuan");
                item->move(con);
item2->move(con);item3->move(con);
	}
}
