//creat by focus

#include <weapon.h>
#include <ansi.h>
inherit YUMAO;
void create()
{
            set_name(HIW"�׺�����"NOR, ({"baiyu yumao", "yumao"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����ѩ����Ⱦ����һ��һ�磬��������������ë.....\n");
                set("value", 5000);
 //             set("material", "crimsonsteel");
                set("wield_msg","$NС������Ĵӻ����ó�$n�������У�����ӭ�磬��ʫ����.\n");
                set("unwield_msg","����Ʈ�𣬷���$N�Ļ���........\n");
                set("weapon_prop/spi", 10);
                set("no_sell","�׺������С��ûʲô��;....\n");
              }
        
            init_yumao(80);
        setup();
}
