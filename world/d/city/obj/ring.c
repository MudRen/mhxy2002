// xiaoran 

#include <ansi.h>
#include <armor.h>
#include <command.h>
inherit FINGER;
inherit F_AUTOLOAD;

void create()
{
	set_name(HIC"��ʯ"HIY"��ָ"NOR, ({"zuanshi jiezhi","zuanjie","jiezhi","ring"}));
	set("weight", 0);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����"HIC"��Ȼ"NOR"�͸�"HIM"�����Եǳ"NOR"�Ķ�����䡣\n");
		set("value", 0);
		set("material", "gold");
		set("armor_prop/armor", 30);
		set("armor_prop/dodge", 30);
		set("no_sell",1);
		set("no_get",1);
		set("no_drop","�㻹�Ǿ��������"HIR"��"NOR"���㣬������һ�����������\n");
//		set("no_give","����������Ȼ��һ��"HIM"���ĵ�����"NOR"����ô��ý�"+this_object()->query("name")+"�����أ��㻹�Ǿ��������"HIR"������"NOR"��\n");
	}
	setup();
}	

 int query_autoload()
 {
        return 1;
 }