// Lly@FYSY
inherit ITEM;
void create()
{
	set_name("��", ({ "��","qin", "guqin" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 2000);
                set("long", "����һ�߹�ɫ�����̴ľ��,�㲻�ɵ���ȥ�����¡�\n");
		set("material", "wood");
		set("no_shown",1);
		set("no_drop",1);
		set("skill", ([
			"name": 		"perception",	
			"exp_required":	1000000,		
			"sen_cost":		50,	
			"difficulty":	15,	
			"max_skill":	200		
		]) );
	}
}
void init()
{
   add_action("do_play","play");
}

int do_play(string arg)
{
   object me;
   me = this_player();

   if (!arg || arg != "qin") {
      tell_object(me, "��Ҫ��ʲô��\n");
      return 1;
   }
   message_vision("$Nһ���٣�����һ�������ư�����ӡ�$N�·��������������һЩʲô����. . .\n",me);
   return 1;
}
