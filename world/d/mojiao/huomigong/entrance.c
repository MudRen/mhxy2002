
// create by qlwy 28/06/2001
// room: maojiao/entrance.c

inherit ROOM;

void create ()
{
        set ("short", "�Թ�����");
        set ("long", @LONG

�򱱾��Ǵ�˵�еĻ��Թ��ˣ���վ�ڶ��ڶ�������
��Ϯ�ˡ��

LONG);
        set("exits", 
        ([ //sizeof() == 2
//                "south" : __DIR__"xxx", ��������
                  "north" : __DIR__"hmg0",
        ]));
        setup();
}


