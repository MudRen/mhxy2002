// LLY@FYSY 
inherit ITEM;
void create()
{
	set_name("�����ķ����Ķ���", ({ "�����ķ����Ķ���","�ײ�", "guancai", "coffin" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "�������Ȼ������˵�����ĺ��⣬����ͷһֱ�䵽��ס�
����������¶�����ǿڹײģ�ո�µĹײ��ϣ��ݷ��а˾Ÿ��֡�
��ֻ�����������֣���л���塭����\n");
		set("value", 70);
		set("material", "wood");
		set("no_shown",1);
		set("no_get",1);
		set("no_drop",1);
		
	}
}
