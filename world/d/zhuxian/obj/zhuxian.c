#include <ansi.h>
#include <weapon.h>
inherit SWORD;
int do_hejian();
void create()
{
        set_name( HIR "���ɽ�" NOR, ({ "zhuxian jian", "jian", "sword", "zhuxian"}) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",

"���ɽ�\n"
);
                set("value", 0);
                set("material", "purplegold");
                set("sheenness", 50);
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�\n");
        }

init_sword(100); 
        setup();

}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int pro;
        int dam;
        pro = (int) victim->query_temp("apply/armor_vs_spells");
        dam = (int) me->query("force");

        if(dam > pro)
        {
        victim->receive_damage("sen",150);
        return HIR "���ɽ���������ĺ�⡣\n" NOR;
        }
}

int init()
{       
        add_action("do_hejian", "hesword");
        return 1;
}
int do_hejian()
{
        object xianxian,juexian,luxian;
        object me = this_player();
        object wuchen;

        if(me->is_fighting())
           return notify_fail("���������أ���������\n");
        if(me->is_busy())
           return notify_fail("����æ����!\n");
        if ("/d/zhuxian/obj/wuchen.c"->in_mud())
           return notify_fail("���������İѽ������о���ôҲ���źϲ�����һ��ȥ!\n");
        if(!xianxian = present("xianxian",me))
           return notify_fail("�㻹ȱ��"HIG"���ɽ�"NOR"�أ�\n");
        if(!juexian = present("juexian",me))
           return notify_fail("�㻹ȱ��"HIW"���ɽ�"NOR"�أ�\n");
        if(!luxian = present("luxian",me))
           return notify_fail("�㻹ȱ��"HIC"¾�ɽ�"NOR"�أ�\n");
if ((xianxian->query("equipped")!="worn") && (juexian->query("equipped")!="worn") && (luxian->query("equipped")!="worn") && (this_object()->query("equipped")!="worn"))
{        
        message_vision(HIY"$N����ȫ���"HIC"����"HIY"�����İѱ�����Ϊ��һ����������ϸһ��ԭ����ʧ���ܾõ�"HIW"�޳���"NOR+HIY"��\n",me);

        message("channel:rumor",HIW+"��"HIR"ʮ������"NOR+HIW"��"HIM"ĳ�ˣ�"NOR+YEL+me->query("name")+CYN"�õ��˴�˵�е�"HIW"�޳���"NOR+CYN"��\n"+NOR,users() );
        
        wuchen = new("/d/zhuxian/obj/wuchen.c");
        wuchen->move(me);
        destruct(xianxian);
        destruct(juexian);
        destruct(luxian);
        destruct(this_object());
        return 1;
}
return notify_fail("���������������ܺϲ���\n");
}
