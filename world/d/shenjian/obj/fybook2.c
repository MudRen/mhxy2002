// Lly@FYSY
inherit ITEM;
void create()
{
	set_name("����־", ({ "fybook" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "һ�����صĹ��飬��ҳ�Ѿ������ˣ�����Ժúÿ���(kan)��\n");
		set("value", 0);
		set("material", "paper");
		
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

   if (!arg || arg != "fybook") {
      tell_object(me, "��Ҫ��ʲô��\n");
      return 1;
   }
   tell_object(me, "���ǵĹ�â��̴٣������ϻ���ʲô���ܱ��������ã��Ի͡�

    �����ǳ��ֵ�ʱ�򣬾��������㲻���������Ҳ�᲻ȥ���Ĺ�ԡ�

    �����������Ǵ��������������޵Ļ���������

    ��������Զ�ǻ��ڴ����

    �������������ɣ������衣

    ����������̴�ȴ�ҷ���

    ֻ�н����űȽϽӽ����㡣

    һ�����͵Ĺ�â�������������������������ŵĽ��ϣ�

    ������Ҳ���飬���Ĺ�â�Ƿ�Ҳ�ͻ��ú�����һ���̴١�\n");
   return 1;
}
