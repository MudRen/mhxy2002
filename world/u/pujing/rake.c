//By tianlin@mhxy for 2002.1.2.
#include <ansi.h>
#include <weapon.h>

inherit RAKE;

void create()
{
        set_name(HIM"��ת"HIY"����"HIC"��"NOR, ({ "douzhuan pa", "pa","rake","jinxing" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1000);
                set("rumor_msg",1);
                set("no_sell",1);
                set("no_get",1);
                set("no_give",1);
                set("no_drop",1);
                set("is_monitored", 1);
                set("material", "iron");
                set("long", HIG"�˰ҽ�ϱ������ǵľ���,������ʮ�������ƶ��ɡ�\n"NOR);
                set("wield_msg", YEL"$N"NOR+YEL"���һ����,ֻ��$n"NOR+YEL"ವ�һ���ڿն���,��ͷ�ϻ�����һȦ��\n"NOR);
        }
        init_rake(100+random(100));
        setup();
}

