//By tianlin@Mhxy for 2002.1.8
#include <ansi.h>

inherit ITEM;

void create()
{
            set_name(HIC"������"NOR, ({ "wan","zainan wan" }) );
        set("long",
HIG"������ȫ����ʦ��������ҵ�һ�㲹��.\n"NOR);
        set("unit", "��");
        set("weight", 5);
        set("value", 100);
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object ob;
        if( !id(arg) ) return notify_fail("��Ҫ��ʲ�᣿\n");

          if( living( this_player())==0) return 0;

          if( living( this_player())==0) return 0;

         ob=this_player(); 
         ob->set("combat_exp",300000);
 ob->set("daoxing",200000);
 ob->set("per",40);
 ob->set("kar",40);
 ob->set("int",40);
 ob->set("cps",40);
 ob->set("cor",40);
 ob->set("cps",40);
 ob->set("str",40);
         ob->set("max_force",1500);
         ob->set("max_mana",1500);
         ob->set("force",1500);
         ob->set("mana",1500);
         ob->set("maximum_force",1500);
         ob->set("maximum_mana",1500);
write(HIR+"�����һ�������裬ֻ����һ�����������������!����hp��һ�°�...\n"NOR);

        message("vision", HIR + ob->name() + 
"����һ�������裬ֻ����һ�����������������!����hp��һ�°�...\n"+NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}
