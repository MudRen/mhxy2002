// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "�����ܲ�");
  set ("long", @LONG

        ������ճ������в����С���������ϣ����԰�С����[1;32mfang[m�����⣬
    Ҫ�����������С�����͵��������[1;33mhuhuan[m����ı����ɣ�

LONG);
  set("exits", ([ /* sizeof() == 4 */
        "east": __DIR__"room",
]));

        setup();
}

void init()
{
        add_action("do_fang","fang");
        add_action("do_huhuan","huhuan");

}
int do_fang()
{
        object ob = this_player();
        object where = this_object();
        object hen = present("zhandou ji",ob);

      if(!hen) return notify_fail("������û��,��ʲô��! \n");

        ob->command_function("kiss_hen");
        tell_room(where,ob->name()+"������С���Ǳ���*^_^*\n");
        destruct(hen);
        return 1;
}

int do_huhuan()
{
        object ob = this_player();
        object where = this_object();
        object hen = present("zhandou ji",ob);
        object newhen=new(__DIR__"npc/hen");

        if(  hen ) 
                return notify_fail("С��������������\n");

        if(! ob->query("hen") )
                return 0;

        newhen->move(ob);
        tell_room(where,"С������"+ob->name()+"��һ�¾�����"+ob->name()+"�Ļ��\n");
        return 1;
}
        
