// pofengblade.c

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name(CYN"�Ʒ�ն" NOR, ({ "pofeng blade", "pofengblade","dao", "blade" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        set("value", 30000);
      
    set("no_give","�������Ҫ���������ͺ���˵�����˵������ô֪������Ҫ�أ�\n");
                set("material", "gold");
                set("no_drop", "�Ʒ�ն�Ǳ������ô�������أ��ҵ�С������ô�죿�����Ҳ���С���ѣ��ҵ������ݲ�Ҳ�����\n");
                
                set("long", "��������֮һ���ݿ��������굱�����ã���˵��������綼���п������ԽС��Ʒ�ն����\n");
                set("wield_msg", "$N���һ�����������ң�ȴ��ϼ��һ�������к�Ȼ���һ��$n��\n");
                set("unwield_msg", "$N���һ�����ߣ�$n��$N����ϼ��һ������Ȼ�����ˡ�\n");
        }
        init_blade(180);
        setup();
}

