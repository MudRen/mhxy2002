//By tianlin@mhxy for 2002.2.1
#include <weapon.h>
#include <ansi.h>
inherit YUMAO;
void create()
{
        set_name(HIM"��"HIC"��"HIY"��"HIW"��"NOR, ({"baiyu yumao", "yumao"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����ѩ����Ⱦ����һ��һ�磬��������������ë.....\n");
                set("value", 5000);
                set("rumor_msg",1);
                set("no_sell",1);
                set("no_get",1);
                set("no_give",1);
                set("no_drop",1);
                set("is_monitored", 1);
                set("wield_msg","$NС������Ĵӻ����ó�$n�������У�����ӭ�磬��ʫ����.\n");
                set("unwield_msg","����Ʈ�𣬷���$N�Ļ���........\n");
                set("weapon_prop/spi", 10);
                set("no_sell","�׺������С��ûʲô��;....\n");
              }
        
        init_yumao(100+random(100));
        setup();
}
