//��Է

#include <ansi.h>
inherit  ROOM;

string look_string();

void  create  ()
{
    set  ("short",  "��Է");
    set  ("long", 
"��Է�����ĸ���䣬����̸���ܵĺõط���������ϱ�����������
�����һ�����ң���ÿ�����ҵ����ⶼ����"HIY"����������"NOR"��
���ӣ��ڷ�������������ϻ�����һ������ָ��(help)��
");

  set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
         set("no_steal",1);
         set("no_magic", "1");
         set("no_perform", "1");
         set("pingan",1);
         set("no_beg",1); 	
    set("item_desc", ([
    "help" : ( : look_string : ),
    ]));

    set("exits",  ([
    "east"  :  __DIR__"qiyuan2",
    "south"  :  __DIR__"qiyuan3",
    "north"  :  __DIR__"qiyuan4",
    "west" : "/d/city/clubpoem",
    ]));

     set("objects",  ([
    __DIR__"cch"  :  1,
    ]));
   setup();
}

string look_string()
{
	string  msg  =  "[5m[1;32m��ӭ[2;37;0m[1;31m��[2;37;0m����[1;36m���壡[2;37;0m\n"  +
"
������������������������������������������������������
[1;36m�й�����[2;37;0m��cchess��
������������������������������������������������������
����   ��[1;33mmove[2;37;0m [37m<������> <������>[2;37;0m [1;33mto[2;37;0m [37m<������> <������>[2;37;0m
����      ��[1;33mreset[2;37;0m
�����о�  ��[1;33mdeploy[2;37;0m
��¼�о�  ��[1;33mcsave[2;37;0m
����      ��[1;33mtoss[2;37;0m
�ع�      ��[1;33mreview[2;37;0m
����   ��[1;33mlose[2;37;0m


";
	return  msg;
}

int valid_leave(object me, string dir)
{
        object room;
        mapping exit;

        exit = environment(me)->query("exits");

        if ( dir == "south" || dir == "north" || dir == "west" ) {
                if( !( room = find_object(exit[dir])) )
                       room = load_object(exit[dir]);
	        if( room->query_temp("action")  ==  1 )
                       return notify_fail("�Ǽ������Ѿ����˿�ʼ�����ˣ��������\n");
                }

        return ::valid_leave(me, dir);
}
