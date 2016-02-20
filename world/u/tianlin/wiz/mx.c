// mixian.c ����Ͳ 3/29/1997,qingyun.

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void init()
{
        add_action("do_aim","aim");
        add_action("do_pun","pun");
}

void create()
{
        set_name("����Ͳ", ({ "mi xian", "mi", "xian" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("bullet", 3);
                set("value", 50000);
                set("material", "steel");
                set("long", "����һ��ר�������������Ͳ�ӡ�\n");
                set("wield_msg", BLU"$N�ӿڴ���͵͵���ó�$n�������С�\n"NOR);
                set("unequip_msg", BLU"$N�����е�$n�Żؿڴ��С�\n"NOR);
        }
        init_sword(100);
        setup();
}

int do_aim(string arg)
{
        object me, obj;
        
        me = this_player();

        if( !arg )
                return notify_fail("������˭��\n");

        if( this_object()->query("bullet") <=0)
                return notify_fail("Ͳ����û�������ˡ�\n");

        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("����û������ˡ�\n");

        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

        if(obj == me)
                return notify_fail(RED"�в�??��������ѽ!!!��\n"NOR);

        message_vision(BLU "\n$N����$nûע�⣬͵͵�ó�����Ͳ�Ķ�׼$n�����ϻ�, ������͵͵�ļ�Ц�š�\n\n" NOR, 
                        me, obj);

        this_object()->set_temp("target", arg);

        return 1;
}

int do_pun()
{
        object me, obj;
        string arg;

        me = this_player();

        if( !(arg = this_object()->query_temp("target")) ) 
                return notify_fail("�㻹û�ж�׼���Ŀ�꣡\n");

        if( !objectp(obj = present(arg, environment(me)) ))
                return notify_fail("����Ҫ�����������ˡ�\n");

        message_vision(BLU "\n$N��׼$n�ı���, ֻ�����̴�Ͳ��ð��������\nֻ��$n��û�з�Ӧ����, ������ĵ����ˣ�\n\n" NOR,
                        me, obj);

        this_object()->add("bullet", -1);
        obj->unconcious();

        return 1;
}