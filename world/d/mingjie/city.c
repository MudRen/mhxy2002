#include <ansi.h>
inherit ROOM;                                                        
                                                                     
void create ()                                                       
{                                                                    
  set ("short", HIM"���޴����"NOR);                                   
  set ("long", @LONG                                                 
�����Ǻ��޴����,��ڤ�����ڣ������ڤ���Ҫ�Ȱ�������ƻ���
��������һ�����ӣ�������������ô��(break)��                                           
LONG);                                                          
                                                                     
    set("exits", ([ /* sizeof() == 1 */                              
]));                                                                                                                          

  setup();                                                           
}

void init()
{
        add_action("do_break", "break");
}

int do_break(string arg)
{
        object room, ob;
        object me = this_player();

        if (query("exits/down"))
                return notify_fail("�����Ѿ��������ˡ�\n");
        if (!arg || (arg != "hole"))
                return notify_fail("��Ҫ����ʲô��\n");

        if(!( room = find_object(__DIR__"jin")) )
                room = load_object(__DIR__"jin");
        if(objectp(room))
        {
                room->set("long","�������ڤ�������ˡ�\n");                                      
                           set("exits/down", __DIR__"jin");
                message_vision("$N�þ�ȫ���������Ӵ��飡\n", this_player());
                write(CYN"ڤ���·�ڴ��ˣ�����ȥ�ѣ���\n");

        }

        return 1;
}