// LLY@FYSY 
inherit ITEM;
void create()
{
	set_name("��", ({ "��","shu", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1000);
		set("material", "paper");
                set("long", "����һ�����¶����˶������ġ��ټ��ա�,���¿�����ʱ����Կ�����������ĥʱ�䡣\n");
		set("no_shown",1);
		set("no_drop",1);
		set("skill", ([
			"name": 		"sword",	
			"exp_required":	0,		
			"sen_cost":		40,	
			"difficulty":	30,	
			"max_skill":	200		
		]) );
	}
}
void init()
{
   add_action("do_kan","kan");
}

int do_kan(string arg)
{
   object me;
   me = this_player();

   if (!arg || arg != "shu") {
      tell_object(me, "��Ҫ��ʲô��\n");
      return 1;
   }
   message_vision("$N���𡶰ټ��ա����ݲݵķ��˼�ҳ��$N�������е�С����ɵĺ�����һЩ����. . .\n",me);
   return 1;
}
