// LLY@FYSY 
inherit ITEM;
void create()
{
	set_name("��", ({ "��","qi", "qipu" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "һ�ֺܾ�����壬������û�˺����£���ֻ�����Լ�һ���˴�����ס�\n");
		set("value", 70);
		set("material", "wood");
		set("no_shown",1);
		set("no_get",1);
		set("no_drop",1);
		set("skill", ([
			"name": 		"qidaoforce",	
			"exp_required":	1200000,		
			"sen_cost":		50,	
			"difficulty":	20,	
			"max_skill":	180		
		]) );
	}
}
void init()
{
   add_action("do_da","da");
}

int do_da(string arg)
{
   object me;
   me = this_player();

   if (!arg || arg != "qi") {
      tell_object(me, "��Ҫ��ʲô?\n");
      return 1;
   }
   message_vision("$Nһ�������²����Ĵ��������ס�$N���������п�����һЩʲô. . .\n",me);
   return 1;
}
