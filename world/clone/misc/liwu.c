#include <ansi.h>;
inherit ITEM;

void create()
{
        set_name("[1;32m��[33m��[36m��[35m��[m", ({"liwu"}));
               set("unit", "��");
                set("long",
                "ף�����е�����֮���������ǿ��֣����(dakai)���ǵ�����.\n");
                set("value", 0);
                set_weight(10);
        setup();
}
void init()
{
        add_action("do_dakai", "dakai");
}

int do_dakai(string arg)
{
        object me = this_player();
        object ob ;
        if (arg == "liwu")
        {    
    ob = new("/clone/food/cake");
        ob->move(me);
tell_object(me,"[1;32m��С�ĵĲ��������������ʲô�ö����ء�[m\n");
        return 1;
        }
        if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");
}
