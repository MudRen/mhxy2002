//modify by ken
//2001.7.7
#include <room.h>
inherit ROOM;
int can_enter=1;
void create ()
{
        set ("short", "����");
        set ("long", @LONG

��������㷢�ֳ��������Ϲ���һ�ѵ���ʲôҲû����
�����ǰѵ��ҵ�̫��..�����Ӳ��Ǻܺ��á� 
LONG);
        set("exits", 
        ([ //sizeof() == 4
                "east" : __DIR__"tower",
        ]));        
        set("no_clean_up", 1);
        can_enter=1;

        setup();
}


void init()
{
        add_action("do_hitt", "hitt");

        if( query("started") != 1 )
        {
                set("started", 1);
           call_out("generate_dan", 20000+random(80)*360);
        }
}

void generate_dan()
{
        remove_call_out("generate_dan");
        set("available", 1);
}

void reset_enter()
{
    can_enter=1;
}

int do_hitt(string arg)
{
        object me, dan;
        int sen;

        me = this_player();
notify_fail("���ǽ�ںݺݵ�����һ�š�\n");
        
        if(me->is_busy()) return 0;

        // 9/16/98 mon
        // sen cost for mo to reduce dummy flooding here.
        sen=me->query("sen");
        if(sen<110) return 0;
        sen-=100;
        me->set("sen",sen);

        // 4/2/99 mon 
        sen=(me->query("combat_exp")+me->query("max_mana"))/2;
        if(sen<10000) return 0;

        if( query("available") == 1 )
        {
                set("available", 0);
                dan = new(__DIR__"obj/ymr");
                dan -> move(this_object());
                message_vision("$N������������ǽ����һ�ţ�ֻ���˵�һ�����죬�ö��ϵ���һ�ѵ�������\n", me);

                remove_call_out("generate_dan");
                call_out("generate_dan", 36000+random(100)*360);//15 hours

                return 1;
        }
        else
        { 
                if( can_enter && 
                        (string)me->query("zhangmen/base_name") 
                        == "/d/mojiao/npc/zhangmen")
                {
                        message_vision("һ�����һ����$N�����˽�ȥ��\n", me);
                        me->move(__DIR__"tower");

                        // mon 10/19/20
                        // can only enter again after a while.
                        can_enter=0;
                        call_out("reset_enter",1200+random(1200));
                        return 1;
                }
                else return 0;
        }
}

int clean_up()
{
        return 0;
}
