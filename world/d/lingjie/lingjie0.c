#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "���");
  set ("long", @LONG

����һƬ�ڰ�,��������,�������ʧȥ���κ���ϵ,��ֻ����
���ޱ��޼ʵĺڰ��е�������,��ͣǰ���ˡ�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"lingjie1",
]));

  setup();
}

void close_up()
{
        object uproom;

        if( !query("exits/out") ) return;
	message("vision", "��¡һ��,ѹ��ʯ�ص���ԭλ��\n", this_object());


        if( uproom = find_object(__DIR__"rukou") ) 
        {
		message("vision", "��¡һ��,ѹ��ʯ�ص���ԭλ��\n", uproom);
                uproom->delete("exits/enter");
        }

        delete("exits/out");
}

