// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "�ĵǷ�");
  set ("long", @LONG

        ������������������ߣ����ĵǷ�û��
        ������[1;31madd[m���������� 3 ����λ��[1;31msub[m���ᣳ����λ��

[m
LONG);
  set("exits", ([ /* sizeof() == 4 */
        "east": __DIR__"road7",
]));

        setup();
}

void init()
{
        add_action("do_add","add");
        add_action("do_sub","sub");
}

int do_add()
{
        object ob = this_player();

        if( ob->query("hen/money") < 1000 )
                return notify_fail("���Ǯ�������ĵǷ�����\n");
       
        ob->add("hen/weight",3);
        ob->command_function("cls");
        cat(MDF);
        cat(FATTER);
        return 1;
}
int do_sub()
{
        object ob = this_player();

        if( ob->query("hen/money") < 1000 )
                 return notify_fail("���Ǯ�������ĵǷ�����\n");

       ob->add("hen/weight",-3);
        ob->command_function("cls");
        cat(MDF);
        cat(THINNER);
        return 1;
}

        
