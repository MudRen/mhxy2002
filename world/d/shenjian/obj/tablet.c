// Lly@FYSY
inherit ITEM;
void create()
{
	set_name("ľ��", ({ "ľ��","��ľ��", "mupai", "tablet" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "���ƿ�ľ���ϵĺڲ���¶��һ���ң�����������ǵ���:
                          
                          [37;41m*[33m   �� �� �� һ ��[37;41m   *[0m
                         
л����˵�����������Թ������������д���û���˵õ�����������л�ҵ����һֱ����������ϧ��Ҳ�ܲ�����
��Ϊ����л�ҵ������û��һ���������������֡���\n");
		set("value", 70);
		set("material", "wood");
		set("no_shown",1);
		set("no_get",1);
		set("no_drop",1);
		
	}
}
