//By tianlin@mhxy for 2002.1.23

#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void create()
{
        set_name(HIY"��"HIW"��"NOR+HIW"ʥ"HIY"��"NOR, ({"foguang shengzhang", "shengzhang", "zhang", "staff"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�������������ʥ��,�������������˼����\n");
                set("value", 0);
                set("no_sell",1);
                set("no_give",1);
                set("no_drop",1);
                set("material", "steel");
                set("is_monitored", 1);
                set("wield_msg", HIW "$Nˢ��һ��������һ��ǧ����ص�$n"NOR+HIW"�������л����˰��졣\n" NOR);
                set("unwield_msg",HIW "$N���ϵķ�����������ˣ�$n"+HIW"Ҳ��Ϊһ����ãֱ��������\n");
               set("value", 300000); 
               set("weapon_prop/cor", 1);
}
        init_staff(180);
        setup();
}
