
// create by qlwy 28/06/2001
// room: maojiao/hmg6.c

inherit ROOM;

void create ()
{
        set ("short", "���Թ�");
        set ("long", @LONG

���Թ����Ȼ���,�ҽ�,����,����������ڶ���
�����ˡ�

LONG);
        set("exits", 
        ([ //sizeof() == 4
                "south" : __DIR__"hmg"+sprintf("%d", random(7)),
                "west"  : __DIR__"hmg8",
                "north" : __DIR__"hmg"+sprintf("%d", 6+random(7)),
                "east"  : __DIR__"hmg"+sprintf("%d", random(7)),
]));
        setup();
}

void init()
{
        object me=this_player();
        me->set_temp("hmg6",1);
        if( me->query_temp("hmg0")
         && me->query_temp("hmg1")
         && me->query_temp("hmg2")
         && me->query_temp("hmg3")
         && me->query_temp("hmg4")
         && me->query_temp("hmg5")
         && me->query_temp("hmg6")
         && me->query_temp("hmg7")
         && me->query_temp("hmg8")
         && me->query_temp("hmg9") 
         && me->query_temp("hmg10")
         && me->query_temp("hmg11")
         && me->query_temp("hmg12"))
        me->set_temp("hmg_ready_out",1);
}

