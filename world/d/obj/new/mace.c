// yuchangjian.c 
//creat by lixin

#include <weapon.h>
#include <ansi.h>
inherit MACE;
//inherit F_UNIQUE; 

void create()
{
        set_name(BLINK HIW"����" NOR+HIC "�" NOR, ({"jinglei jian", "jian", "mace"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "��˵�׹����õ�������\n");
                set("value", 0);
                set("no_sell",1);
                set("no_give",1);
                set("no_drop",1);
                set("no_get",1);
                set("material", "steel");
                set("is_monitored", 1);
                set("wield_msg", HIG "ֻ�������Ͼ���һ�죬$N���ж����һ��$n��\n" NOR);
                set("unwield_msg",HIG "$N���е�$n"+HIG "��Ϊ�׹���ת�ۼ���ʧ������С�\n"NOR);
               set("value", 300000); 
               set("weapon_prop/cor", 1);
}
        init_mace(120);
        setup();
}
