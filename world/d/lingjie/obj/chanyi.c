#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
            set_name(HIW"����"NOR, ({"chanyi sword", "sword"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����˿�����ߡ���ۡ������ı���\n");
                set("value", 5000);
 //               set("material", "crimsonsteel");
                set("wield_msg",
    "$N��ৡ���һ�����һ��$n�������У�����ƺ�����.\n");
                set("unwield_msg",
    "�׹�һ����$N���е�$n��Ȼ����........\n");
          set("weapon_prop/cor", 10);
        set("no_get","�����������������.......\n");
        set("no_give","��������������׸��ˣ�\n");
        set("no_drop","�����ն񣬲������׷������еı���...\n");
        set("no_sell","С��������ȡ��˵�е�����....\n");
        }
        
            init_sword(180);
        setup();
}
