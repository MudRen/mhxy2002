// link
inherit ROOM;
void create()
#include <ansi.h>
{
        set("short", "����");
        set("long", @LONG
����������Ͳ����ĳ����ˣ����Ƕ�ææµµ��������ʷ���ԱҪ����
����֮�󣬾Ϳ���������ϴ��xi���ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"hguitai",
]));
	set("valid_startroom",1);
	set("coor/x",-20);
	set("coor/y",160);
	set("coor/z",0);
	setup();
}
void init()
{
        add_action("do_xi", "xi");
        add_action("do_xi", "wash");
}
int do_xi(string arg)
{
        object me,ob,ob1;
        int i;
        me = this_player();
if (!me->query_temp("����/ϴ����")) 
return notify_fail("�㻹����ȥ����С������к��ɡ�\n"); 

if (!arg || arg != "panzi") 
return notify_fail("��Ҫϴʲô��\n"); 

if (!(ob = present("zang panzi", this_player()))) 
return notify_fail("������û�������ӣ���ô��ϴ�أ���\n"); 

if ( (int)me->query("gin")<20) 
return notify_fail("��̫���ˣ�ЪϢһ�°ɡ�\n"); 
message_vision(CYN"$Nϴ�����ã����ڽ�����ȫ��ϴ���ˡ�\n"NOR,me); 
i=ob->query_amount();
me->add("gin",-(10*i)); 
//me->add("kee",-10); 
destruct(ob); 
ob1=new (__DIR__ "npc/obj/panzi");
ob1->set_amount(i);
ob1->move(me); 
return 1; 
}