
#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(RED"ɱ����"NOR, ({"shaqi wan","wan","shaqi"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����Գ�ɱ��������ҩ�衣\n");
                set("value", 3000);
        }
        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");
        if((int)this_player()->query("bellicosity") > 900 )//by tianlin@mhxy for 2002.2.25��������
        return notify_fail("�����,ɱ�����ߵ��ˣ�\n");

this_player()->add("bellicosity",100);
        message_vision("$N����һ��"RED"ɱ����"NOR"��ʱ�е��Լ����Ծ���!\n", this_player());
            destruct(this_object());
        return 1;
}


