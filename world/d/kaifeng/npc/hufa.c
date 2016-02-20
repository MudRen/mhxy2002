//by tianlin or valen 2001.7.28

#include <ansi.h>

inherit NPC;

void create()
{
	object ob1, ob2;
	
	set_name("���", ({"bing"}) );
	set("long", "����һλ���Կ���ǵ������ר�ŵ��λ���֮��\n");
	set("attitude", "friendly");

	set("max_gin", 2000);
	set("max_kee", 2000);
	set("max_sen", 2000);

	set("max_mana", 2000);
	set("max_force", 1800);
	set("force", 3000);
	set("mana", 2500);
       set("force_factor", 120);
       set("mana_factor", 140);

	set("str", 140);
	set("cor", 130);
	set("cps", 125);

	set("combat_exp", 1300000);
	set("daoxing", 456789);
	set_skill("dodge", 280);
	set_skill("parry", 280);
	set_skill("rake", 280);
	set_skill("skyriver-rake", 280);
       map_skill("rake", "skyriver-rake");


	setup();

	ob1=carry_object("/d/obj/armor/jinjia");
	ob1->wear();
	ob1->set("no_sell", "�ƹ�����һ�۵����ⶫ��һ�������ӵ�Ʒ����Ҫ����Ҫ��\n");
	ob2=carry_object("/d/kaifeng/obj/jiuchipa");
	ob2->wield();
	ob2->set("no_sell", "�ƹ�����һ�۵����ⶫ��һ�������ӵ�Ʒ����Ҫ����Ҫ��\n");
}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	message("vision",
		HIY + name() + "˵����ĩ������ү�ٻ��������Ѿ���ɻ������񣬾ʹ˸�ǣ�\n\n"
		+ name() + "����һ����⣬���������ʧ�����ˡ�\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}

void invocation(object who)
{
	int i;
	object *enemy;

	message("vision",
		HIY "ֻ���ۣ���һ����һ�Ž�ⱬ�����ֳ�һ���������ִ�ųݶ���,���������\n\n"
		+ name() + "˵����ĩ������ү�ٻ�������������\n" NOR,
		environment(), this_object() );
	enemy = who->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			kill_ob(enemy[i]);
			if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
			else enemy[i]->kill_ob(this_object());
		}
	}
	set_leader(who);
}
