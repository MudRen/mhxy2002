// force_book.c �ڹ��ķ�

inherit ITEM;

void create()
{
	set_name("[1;33m̫��[1;36mʮ��[1;37m��[2;37;0m", ({ "taiji shisanshi", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����װ�飬������������Ļ��˲��ٴ������ŵ����ơ�\n");
		set("value", 500);
              set("no_get",1);
              set("no_put",1);
              set("no_drop",1);
		set("material", "paper");
		set("skill", ([
			"name":	"force",	// name of the skill
			"exp_required":	0,	// minimum combat experience required
			"gin_cost":	30,	// jing cost every time study this
			"difficulty":	10,	// the base int to learn this skill
			"max_skill":	109,	// the maximum level you can learn
			"min_skill":	10	// the maximum level you can learn
		]) );
	}
}
