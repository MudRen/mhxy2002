#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", 

"һ������ɽ���������ִ�������ɽ��͸����������\n"+
"���˲�����Щ��������ɽ��ͻ����һ���ʯ��stone),\n"+
"��ʯ�·��������֣�����ʱ��̫�ã�����Щ��ɫ��\n"+
"�����з·���Կ�����������:\n"
YEL"               ѹ  ��  ʯ       \n" NOR 
);
  
  set("item_desc", ([ /* sizeof() == 1 */
  "stone" : "
\t\t\t��
\t\t\tʯ
\t\t\tѹ
\t\t\t��
\t\t\t��
\t\t\t�� 
\t\t\t��
\t\t\t��

",
]));
  set("objects", ([ /* sizeof() == 1*/ 
  __DIR__"npc/laozhe" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
//  "enter" : __DIR__"lingjie0",
   "westup" : __DIR__"lingjie",
   "down":"/d/dntg/sky/jiashan",
]));
  set("outdoors", "lingjie");
  set("no_magic", 1);

  setup();
}

void init()
{
	add_action("open_down", "open" );
}

int open_down()
{
        object lingjie;

        if( !(lingjie = find_object(__DIR__"lingjie0")) )
                lingjie = load_object(__DIR__"lingjie0");

        if( lingjie = find_object(__DIR__"lingjie0") ) 
        {
                set("exits/enter", __DIR__"lingjie0");
                message("vision", "������ʦ�İ�? �ٺ�.. ��,�Ǿ�����ɡ�\n", this_object() );
		message("vision", "��,�������ס,����ֻ������ѽ!\n", lingjie );
        set("long", @LONG
    
�������Ѵ�,����һƬ���,��Ȼ����,�ͽ�ȥ����
��!
LONG);
	}
	
        call_out("close_down", 150);

        return 1;
}

int close_down()
{
        object lingjie;

	message("vision", "��¡һ��,ѹ��ʯ���˻ص���ԭ����\n", this_object() );
	if( lingjie= find_object(__DIR__"lingjie0")) {
	message("vision", "��¡һ��,ѹ��ʯ���˻ص���ԭ����\n", lingjie);
	lingjie->delete("exits/out");
	}

        delete("exits/enter");
        set("long", 
    
"һ������ɽ���������ִ�������ɽ��͸����������\n"+
"���˲�����Щ��������ɽ��ͻ����һ���ʯ��stone),\n"+
"��ʯ�·��������֣�����ʱ��̫�ã�����Щ��ɫ��\n"+
"�����з·���Կ�����������:\n"
YEL"               ѹ  ��  ʯ       \n" NOR 
);
return 1;
}



