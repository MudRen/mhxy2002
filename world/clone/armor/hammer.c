// by mhsj@gslxz 2001/3/12
#include <weapon.h>
#include <ansi.h>

inherit HAMMER;

void create()
{
    set_name(YEL"��ɽ��"NOR, ({ "kaishan chui","chui","hammer" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        set("long", "�޴�Ŀ�ɽ����\n");
                  set("value", 300000);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ��$n���������л��˼��¡�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }
          init_hammer(80);
        setup();
}
