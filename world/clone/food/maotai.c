// wineskin.c  �ƴ�

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("[1;36mę́[m", ({"maotai"}));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һƿ���˰����ę́.\n");
                set("unit", "��");
                set("value", 20);
                set("max_liquid", 15);
        }

        // because a container can contain different liquid
        // we set it to contain wine at the beginning
        set("liquid", ([
                "type": "alcohol",
                "name": "�׾�",
                "remaining": 10000000,
                "drunk_supply": 6,
        ]));
}

