// Lly@FYSY
inherit ITEM;
void create()
{
	set_name("ľ��", ({ "ľ��", "mujia", "shelf" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "���ƿ�ľ���ϵĺڲ���¶����ľ�ܡ�ľ������һ������
л���ﾲ����վ�������ǰ���������Ž������ͺ���������Լ��������𾴵�����\n");
		set("value", 70);
		set("material", "wood");
		set("no_shown",1);
		set("no_get",1);
		set("no_drop",1);
		
	}
}

