// Lly@FYSY
inherit ITEM;
void create()
{
	set_name("ʯͷ", ({ "ʯͷ","stone", "ĥʯ" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 2000);
                set("long", "����һ�������ܼ�����ĥ��ʯ������ȥ�ܹ⻬��Ӳ������ܾ�û�˶��������ӡ�\n");
		set("material", "stone");
		set("no_shown",1);
		set("no_drop",1);
			}
}
void init()
{
   add_action("do_pull","pull");
}

int do_pull(string arg)
{
   object me;
   me = this_player();

   if (!arg || arg != "stone") {
      tell_object(me, "��Ҫ����ʲô��\n");
      return 1;
   }
   message_vision("$N�þ�ȫ����ĥʯ���������ȵķ���ĥʯ����Ĵ�������һ�����п̳��Ĵ�ʮ��,ʮ��֮����ָ�ķ��򣬺�����Ǵ��Ʒ嶥������\n",me);
me->set_temp("looked_shizhi",1);   return 1;
}
