//Cracked by Roath
//chunyang.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"�����¾���"NOR, ({"daode jing","daode","book", "jing"}));
        set_weight(1000);
        if( clonep() ) 
                set_default_object(__FILE__);
        else 
        {
                set("unit", "��");
                set("long", "һ�������¾�����\n");
                set("material", "paper");
                set("value", 1000);
                set("skill", ([
                        "name": "taoism",
                        "dx_required": 1000,
                        "sen_cost": 40,
                        "difficulty": 30,
                        "max_skill": 101,
                ]) );
        }
}



