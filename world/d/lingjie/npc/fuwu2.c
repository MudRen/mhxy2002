
inherit NPC;

void create()
{
	set_name("����Ա", ({ "waiter2", "fuwuyuan2", "yuan2" }));
	set("str", 20);
	set("gender", "����");
	set("age", 45);
	set("long", "��Ҳ��һ������Ա��\n");
	set("combat_exp", 2000);
	set("attitude", "friendly");
	setup();
}

void init()
{	
}

int accept_object(object who, object ob)
{
	int pay, value;

	if (ob->query("money_id")) {
		if (!(pay = who->query_temp("total_pay"))) {
			tell_object(who, "����Աæ������Ц�������͹����ֲ�ǷС���Ǯ���ͱ�����ͷ��Ѱ�����ˡ���\n");
			return 0;
		}
		if (!who->query_temp("to_pay")) {
			tell_object(who, "����Ա˵�������͹����Ƚ���(pay)�ٸ����\n");
			return 0;
		}
		value = ob->value();
		if (value >= pay) {
			who->delete_temp("to_pay");
			who->delete_temp("total_pay");
			if (value == pay) message_vision("����Ա��������Ц����$N����������л�͹��������ߺá���\n", who);
			else message_vision("����Ա��������Ц����$N����������л�͹�����С�ѣ��϶��������������ˣ����ߺá���\n", who);
			return 1;
		}
		else {
			pay -= value;	
			message_vision("����Ա����$N˵����������������" + chinese_number(pay) + "��Ǯ����\n", who);
			who->set_temp("total_pay", pay);
			return 1;
		}
	}
	return 0;
}

void kill_ob(object ob)
{
	ob->remove_killer(this_object());
	remove_killer(ob);
	message_vision("$N��ɥ�ط��ַ���Ա���ڸ߸ߵĹ�̨���棬��������\n", ob);
}

void unconcious()
{
	say( "����Ա��һ�������Ҳ����ˣ��������ң���\n");
	say( "����ӹ�̨�������һ��Сͯ����������Ա����������һ��ҩ������ˡ�\n");
	say( "Ƭ��֮�䣬����Ա�ָֻ��˾��񣬡��ٺ١���Ц��������\n");
	reincarnate();
	set("eff_kee", query("max_kee"));
	set("kee", query("max_kee"));
	set("eff_gin", query("max_gin"));
	set("gin", query("max_gin"));
}

void die()
{
	unconcious();
}

