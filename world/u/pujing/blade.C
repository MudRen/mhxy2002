//By tianlin@mhxy for 2002.1.2.
#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name(HIG"�� "HIW"ѩ "HIC"�� "HIR"��"NOR, ({"hanxue dao","blade","dao"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIY"����һ���ꖹ֚�Č���!\n"NOR);
                set("value", 200000);
                set("material", "gold");
                set("rumor_msg",1);
                set("no_sell",1);
                set("no_get",1);
                set("no_give",1);
                set("no_drop",1);
                set("is_monitored", 1);
                set("wield_msg", CYN"һ��Ѫ������,$N"NOR+CYN"���ж��˰�$n"NOR+CYN"��\n"NOR);
                set("unwield_msg", CYN"$N"NOR+CYN"��$n"NOR+CYN"�ջص��ʣ����˲����˿�����\n"NOR);
                set("weapon_prop/courage", 15);

        }
      init_blade(100+random(100));
      setup();
}
