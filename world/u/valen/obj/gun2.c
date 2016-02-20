// gun.c

#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_CLEAN_UP;

void init()
{
        add_action("do_aim","aim");
        add_action("do_fire","fire");
}

void create()
{
        set_name("�������ǹ", ({ "qiang", "gun" }) );

        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("bullet", 10000);
		set("value", 0);
                set("material", "steel");
                set("long", "����һ�Ѱ�ŵ�ù����������ǹ��\n");
                set("wield_msg", "$N�˳�һ��$n��ȡ��һ���ӵ����ڼ��ϡ�\n");
                set("unequip_msg", "$N��������$n��ȡ���ӵ��䡣\n");
        }
        init_blade(100);
        setup();
}

int do_aim(string arg)
{
        object me, obj;

        me = this_player();

        if( !arg )
                return notify_fail("����ɱ˭��\n");

        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("����û������ˡ�\n");
        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

        if(obj == me)
                return notify_fail("�� suicide ָ���ȽϿ�:P��\n");
        message_vision(HIY "\n$N�����������ǹ��ԶԶ����׼$n�����š��ˡ���һ�������ӵ����š� \n\n"NOR, 
                       me, obj);

        message_vision(HIR "\n$N��׼$n�۶��˰��������\nֻ�������ա���һ����죬$n����������һ���������ص���Ѫ���С�\n\n"NOR,
                       me, obj);

        tell_object(obj, HIR "\n���;���������հ��ʹ����־������ͷ����һƬ�հף�\n" NOR);

        obj->die();

        return 1;
}

int do_fire()
{
        object me;
        object* obj;
        string arg;
        int i;

        me = this_player();
        obj = all_inventory(environment(me));

        for(i=0; i<sizeof(obj); i++) {

         if( obj[i]==me ) continue;

         if( !obj[i]->is_character() || obj[i]->is_corpse() ) continue;

         message_vision(HIR "\n$N��׼$n�۶��˰��������\nֻ�������ա���һ����죬$n����������һ���������ص���Ѫ���С�\n\n"NOR,
                        me, obj[i]);

        tell_object(obj[i], HIR"\n����û�������հ��ʹ����ǰһ�������ð��ͷ����һƬ�հס� \n"NOR);
     	if ( wizardp(obj[i]) ) { 
		obj[i]->set("env/immortal",0);
         	obj[i]->die();
		obj[i]->set("env/immortal",1);
	}
	else obj[i]->die();
               
        }

        return 1;
}



