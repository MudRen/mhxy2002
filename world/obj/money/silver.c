// silver.c
// By tianlin 2001.5.1

inherit MONEY;

void create()
{
	set_name("[1;37m����[2;37;0m", ({"silver", "ingot", "silver_money"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "silver");
		set("long", "�׻��������ӣ��˼��˰������ӡ�\n");
		set("unit", "Щ");
		set("base_value", 100);
		set("base_unit", "��");
		set("base_weight", 37);
	}
	set_amount(1);
}

