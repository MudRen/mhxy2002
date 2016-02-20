// /d/guzhanchang/pomiao.c
inherit ROOM;
void create ()
{
  set ("short", "������");
  set ("long", @LONG

                             .-""-. 
                            (___/\ \ 
          ,                 (|^ ^ ) ) 
         /(                _)_\=_/  ( 
   ,..__/ `\          ____(_/_ ` \   ) 
    `\    _/        _/---._/(_)_  `\ ( 
      '--\ `-.__..-'    /.    (_), |  ) 
          `._        ___\_____.'_| |__/ 
             `~----"`   `-.........' 
 �������ڤ�������----�ڰ������󣬲�������ŭ�����������ﻥ�����
  
LONG);
 
  set("item_desc", ([ /* sizeof() == 1 */
  "mufa" : "һֻľ�����Լ�����Բľ���ɡ��㲻������(zuo)��ȥ��һ�ԡ�
",
]));
                    
set("exits", ([
            "eastup": __DIR__"san",
    
        ]));

  set("objects", ([ 
	"/d/mingjie/npc/likaao":1,

        ]));

        setup();
}

void init()
{
    add_action("do_zuo", "zuo");
    add_action("do_zuo", "sit");
}

void check_trigger()
{
    object room;

    if(!query("exits/enter") ) {
        if( !(room = find_object(__DIR__"mufa")) )
            room = load_object(__DIR__"mufa");
        if( room = find_object(__DIR__"mufa") ) {
            if((int)room->query("zuo_trigger")==0 ) {
                room->set("zuo_trigger", 1);
                set("exits/enter", __DIR__"mufa");
                room->set("exits/out", __FILE__);
                message("vision", "һֻ����ͻȻ����������ǰ��\n", this_object() );
                message("vision", "��һ����Ȼ�Ǹ�ǳ�ˡ�\n", room);
                remove_call_out("on_board");
                call_out("on_board", 15);
            }
            else
                message("vision", "����Ư�򰶱ߣ������ӻ������ĵصȵȡ�\n",this_object() );
        }
        else
            message("vision", "ERROR: mufa not found\n", this_object() );
    }
    else 
        message("vision", "���Ѿ������ˣ���ʱ������ȥ��\n",
            this_object() );
}


void on_board()
{
    object room;

    if( !query("exits/enter") ) return;

    message("vision", "һ����ͷ������������Ưȥ��\n",
        this_object() );

    if( room = find_object(__DIR__"mufa") )
    {
        room->delete("exits/out");
        message("vision", "�������Ǻ�ɫ����ɫ���죬��ɫ��ˮ��һ����ɫ������...\n", room );
    }
    delete("exits/enter");

    remove_call_out("arrive");
    call_out("arrive", 20);
}

void arrive()
{
    object room;
    if( room = find_object(__DIR__"mufa") )
    {
        room->set("exits/out", __DIR__"wu");
        message("vision", "��һ�𣬸�ǳ�ˡ���Ȼ�ǵ�½���ˣ��Ͻ���ȥ�ɡ�\n",room );
    }
    remove_call_out("close_passage");
    call_out("close_passage", 20);
}

void close_passage()
{
    object room;
    if( room = find_object(__DIR__"mufa") ) {
        room->delete("exits/out");
        message("vision","һ����ͷ������������Ưȥ��\n", room);
room->set("zuo_trigger", 0);
    }
}

int do_zuo(string arg)
{
    string dir;

    if( (arg=="mufa") || (arg=="��")){ 
        message_vision("$N���������Ϲ���\n", this_player());
        check_trigger();
        return 1;
    }
    else return notify_fail("��Ҫ����ʲô��\n");
}

void reset()
{
    object room;

    ::reset();
    if( room = find_object(__DIR__"mufa") )
        room->delete("zuo_trigger"); 
}

