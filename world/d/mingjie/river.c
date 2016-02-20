/* <SecCrypt CPL V3R05> */

inherit ROOM;

void check_trigger();
void on_board();
void arrive();
void close_passage();
int do_yell(string arg);
void reset();

void create()
{
    set("short", "������");
    set("long", @LONG

              |    |    |
             )_)  )_)  )_)
            )___))___))___)\
           )____)____)_____)\\
         _____|____|____|____\\\__
---------\                   /---------
  ^^^^^ ^^^^^ ^^^^  ^^^^^^^  ^^^^^    ^^^
         ^^^^     ^^^     ^^^    ^^^    ^^^
���������˹������˹ƽԭ�ϵĺ���---�����׺���
Ҳ������ν��ڤ�ӻ��ǻ�Ȫ
LONG );
    set("exits", ([
    ]));
    set("item_desc", ([
        "boat" : "һҶ���ۣ�Ҳ��(yell)һ�����Ҿ���������\n",
    ])); 
 set("objects", ([ 
	"/d/mingjie/npc/jialu":1,
        ]));

    set("no_clean_up", 0);
    setup();
}

void init()
{
    add_action("do_yell", "yell");
}

void check_trigger()
{
    object room;

    if(!query("exits/enter") ) {
        if( !(room = find_object(__DIR__"duchuan")) )
            room = load_object(__DIR__"duchuan");
        if( room = find_object(__DIR__"duchuan") ) {
            if((int)room->query("yell_trigger")==0 ) {
                room->set("yell_trigger", 1);
                set("exits/enter", __DIR__"duchuan");
                room->set("exits/out", __FILE__);
                message("vision", "һҶ���ۻ�����ʻ�˹���������Ǽ�·��һ��̤��"
                    "����Ϻ�̲���Ա�˿�\n���¡�\n", this_object() );
                message("vision", "����Ǽ�·��һ��̤�Ű���Ϻ�̲���γ�һ������"
                    "�Ľ��ݡ�\n", room);
                remove_call_out("on_board");
                call_out("on_board", 15);
            }
            else
                message("vision", "ֻ���ú��������������������"
                    "�����æ���š�����\n",this_object() );
        }
        else
            message("vision", "ERROR: boat not found\n", this_object() );
    }
    else 
        message("vision", "����Ǽ�·˵�������������أ������ɡ�\n",
            this_object() );
}


void on_board()
{
    object room;

    if( !query("exits/enter") ) return;

    message("vision", "����Ǽ�·��̤�Ű��������������һ�㣬����������ʻȥ��\n",
        this_object() );

    if( room = find_object(__DIR__"duchuan") )
    {
        room->delete("exits/out");
        message("vision", "����Ǽ�·��̤�Ű���������˵��һ��������ඡ���"
            "���һ�㣬������\n������ʻȥ��\n", room );
    }
    delete("exits/enter");

    remove_call_out("arrive");
    call_out("arrive", 20);
}

void arrive()
{
    object room;
    if( room = find_object(__DIR__"duchuan") )
    {
        room->set("exits/out", "/d/mingjie/yi");
        message("vision", "����Ǽ�·˵���������ϰ��ɡ����漴��һ��̤�Ű�"
            "���Ϻ�̲��\n",room );
    }
    remove_call_out("close_passage");
    call_out("close_passage", 20);
}

void close_passage()
{
    object room;
    if( room = find_object(__DIR__"duchuan") ) {
        room->delete("exits/out");
        message("vision","����Ǽ�·��̤�Ű����������ѱ���ʻ�����С�\n", room);
        room->delete("yell_trigger"); 
    }
}

int do_yell(string arg)
{
    string dir;

    if( !arg || arg=="" ) return notify_fail("��Ҫߺ��ʲô��\n");

    if( arg=="boat" ) arg = "����";
    if( (int)this_player()->query("age") < 16 )
        message_vision("$Nʹ�����̵���������һ������" + arg + "��\n",
            this_player());
    else if( (int)this_player()->query("force") > 500 )
        message_vision("$N���˿�����һ����" + arg + "������������ƽ�͵�ԶԶ��"
            "�˳�ȥ��\n", this_player());
    else
        message_vision("$N������������Хһ������" + arg + "����\n",
            this_player());
    if( arg=="����")
    {
        check_trigger();
        return 1;
    }
    else
        message_vision("������ԶԶ����һ���������" + arg +
            "��������\n", this_player());
    return 1;
}

void reset()
{
    object room;

    ::reset();
    if( room = find_object(__DIR__"duchuan") )
        room->delete("yell_trigger"); 
}

