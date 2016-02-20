// /feature/disaster.c
// �ƽ�ϵͳ��������
// ��ע������!����������֮�ݺ�������(202.103.98.74-5555)
// �� ���� ��С����(xhm)������ƽ(tianping)  
//By tianlin@mhxy for 2001.12.31�޸�
#include <ansi.h>

void copy_npc(int sum);
void set_status(object ob,int exp,int skill);
string query_site();
void verdict_end();
int query_children(string arg);
void verdict_time();
void set_hj_startT(int i);
int query_hj_startT();
void juedou();

string *factions=({"��ׯ��","��ѩɽ","�¹�","�ظ�","��������","�ݿ�ɽ�޵׶�","��ɽ��","��˿��"});
string faction;     //��Ź��������
int Cnpcend, count = 0;
int hj_startT = 0;
object lead;

//�ƽ�ϵͳ������������
void disaster(int sum)
{
	count = sum;
	LOGIN_D->set_dienpc(-1);
	set_hj_startT(time());
	faction = factions[count];
	message("channel:chat",HIR"��������桿������(Rulai fo):"MAG"������֯�ĵ�"+chinese_number(count+1)+"��Ŀ����Ѫϴ��"HIR+faction+MAG"����\n"NOR,users());
	message("channel:chat",HIW"��"+HIM MUD_NAME+HIW"�����ڴ�е�ǰ�������ڿ�ʼ�������״̬���κ��˲����������ӣ�\n"NOR,users());
	call_out("copy_npc",0,1);
}

//����EXP and SKILL��ָ�������ȵ�ɱ��(pker)
void copy_npc(int sum)
{
	object ob, *user;
	string site, domain;
	int i, j, exp, skill, lead_exp=0;
	int t=0;

	user = users();
	j = sizeof(user);
	Cnpcend = 0;
	for (i=0;i<j;i++) {
		if (faction!="������" && user[i]->query("family/family_name")!=faction) {
			t++;
			continue;
		}
		if (!user[i]) {t++;continue;}
		exp = (int) user[i]->query("combat_exp");
		skill = (int) user[i]->query_skill("parry",1);
		if (lead_exp < exp) {lead_exp = exp;lead = user[i];}
		if (skill < 1) skill = 5;
		if (exp < 10000)
			ob = new("/d/haojie/npc/pker1");
		else if (exp < 30000)
			ob = new("/d/haojie/npc/pker2");
		else if (exp < 50000)
			ob = new("/d/haojie/npc/pker3");
		else if (exp < 80000)
			ob = new("/d/haojie/npc/pker4");
		else if (exp < 150000)
			ob = new("/d/haojie/npc/pker5");
		else if (exp < 300000)
			ob = new("/d/haojie/npc/pker6");
		else if (exp < 500000)
			ob = new("/d/haojie/npc/pker7");
		else if (exp < 800000)
			ob = new("/d/haojie/npc/pker8");
		else
			ob = new("/d/haojie/npc/pker9");

		set_status(ob,exp,skill);
		site = query_site();
		domain = domain_file(site);
		ob->set("domain",domain);
		ob->move(site);
		message_vision("$N�����ɷ�����˹�����\n",ob);
	}

	if (t>=j) {
		message("channel:chat",HIR"����ؽ١�"MAG"����"+faction+"���¿���һ�ˣ�ħ�粻ս��ʤ��һ��������"+faction+"��\n"NOR,users());
		message("channel:chat",HIW"���λ����Ρ�ħ���������������Ц����û�뵽������׵��֣�����������Ҳ����������������һ����\n"NOR,users());
		message("channel:chat",HIW"��"+HIM MUD_NAME+HIW"��������ʱ�����ˣ����ڽ������״̬��\n"NOR,users());
		LOGIN_D->set_madlock(0);
		call_out("disaster",10,count+1);
		return;
	}
	if (sum<3)
		call_out("copy_npc",20,++sum);
	else {
		Cnpcend = 1;
		call_out("verdict_time",1800);
	}
}

//����player��EXP and SKILL����pker��EXP and SKILL
void set_status(object ob,int exp,int skill)
{
	ob->set("combat_exp",exp);
	ob->set_skill("parry",skill);
}

//���������������pker����ŵص�
string query_site()
{
	mapping sites=([
       "��ׯ��":                  ({"/d/qujing/wuzhuang/gate","/d/qujing/wuzhuang/guangchang","/d/qujing/wuzhuang/houyuan","/d/qujing/wuzhuang/baicaidi"}),
       "��ѩɽ":                  ({"/d/xueshan/binggu","/d/xueshan/xuelu","/d/xueshan/wuchang-nw","/d/xueshan/xueshan5"}),
       "�¹�":                    ({"/d/moon/ontop2","/d/moon/road1","/d/moon/wulang","/d/moon/huilang1"}),
       "�ظ�":                    ({"/d/death/new-zhaopo","/d/death/new-sifang4","/d/death/pingyang","/d/death/room9"}),
       "��������":                ({"/d/sea/under4","/d/sea/boy2","/d/sea/inside3","/d/sea/huayuan6"}),
       "�ݿ�ɽ�޵׶�":            ({"/d/qujing/wudidong/shanlu2","/d/qujing/wudidong/dong1","/d/qujing/wudidong/cave1","/d/qujing/wudidong/mishi"}),
       "��ɽ��":                  ({"/d/shushan/yongdao","/d/shushan/cangjingge","/d/shushan/xianjing","/d/shushan/zhenyaota/tower"}),
       "��˿��":                  ({"/d/pansi/pubu","/d/pansi/yandong","/d/pansi/fangjian1","/d/pansi/midao3","/d/pansi/fangjian3"}),
	]);

	return sites[faction][random(sizeof(sites[faction]))];
}

//�жϺƽ��Ƿ�ƽϢ
void verdict_end()
{
	int sum = 0;

	if ( !Cnpcend ) return;
	sum += query_children("/d/haojie/npc/pker9.c");
	sum += query_children("/d/haojie/npc/pker8.c");
	sum += query_children("/d/haojie/npc/pker7.c");
	sum += query_children("/d/haojie/npc/pker6.c");
	sum += query_children("/d/haojie/npc/pker5.c");
	sum += query_children("/d/haojie/npc/pker4.c");
	sum += query_children("/d/haojie/npc/pker3.c");
	sum += query_children("/d/haojie/npc/pker2.c");
	sum += query_children("/d/haojie/npc/pker1.c");
	if (sum > 1) return;

	if (count+1 != sizeof(factions)) {
		message("channel:chat",HIR"����ؽ١�"MAG+faction+"������"+lead->name()+"�Ĵ����£�ɱ�õ��������ɾ�����ܶ��ӣ�\n"NOR,users());
		message("channel:chat",HIW"���λ����Ρ�ħ�������������棺�����̵ģ�������Ӳ�����ȣ�\n"NOR,users());
		message("channel:chat",HIW"��"+HIM MUD_NAME+HIW"����ʱ���˵��ˣ�������Ƶõ����⣬��ʱ�������״̬��\n"NOR,users());
		call_out("disaster",20,count+1);
	}
	else {
		message("channel:chat",HIR"����ؽ١�"MAG"�������ɽӳ����ˣ���"+lead->name()+"�Ĵ����£����ڴ����ħ�����ı�������ָֻ������յ�ƽ����\n"NOR,users());
		message("channel:chat",HIW"��"+HIM MUD_NAME+HIW"���з���ܣ������ָ�ƽ�����������״̬��\n"NOR,users());
		message("channel:chat",HIW"���λ����Ρ�ħ�������������������У��Ҳ��������Ҳ����������Ҳ�����������\n"NOR,users());
		call_out("juedou",5);
	}
	LOGIN_D->set_madlock(0);

}
void juedou()
{
	object ob;
	object *user;
	int i, exp, skill, killer = 0;

	user = users();
	for(i=0;i<sizeof(user);i++)
		if (user[i]->query_temp("hj_killer") > killer) lead = user[i];

	ob = new("/d/haojie/obj/zhanshu.c");
	ob->move(lead);
	message_vision(HIY"һ��ս��Ʈ����$N����ǰ��\n"NOR,lead);
	message("channel:chat",HIM"����ؽ١�"+"��˵"+lead->name()+HIM"�õ���һ��ħ�����������������ս�顣\n"NOR,users());

	exp = lead->query("combat_exp");
	skill = lead->query_skill("parry",1);
	ob = new("/d/haojie/npc/tianshaxing.c");
	ob->set("pk_target",lead);
	set_status(ob,exp,skill);
	ob->move("/d/city/center.c");
	message_vision("$N�����ɷ�����˹�����\n",ob);
}

//ȡָ��pker������
int query_children(string arg)
{
	object *ch;
	int i,sum = 0;

	ch = children(arg);
	for(i=0;i<sizeof(ch);i++)
		if(environment(ch[i])) sum++;
	return sum;
}

//��ʱ�жϺƽٷ�����ʱ���Ƿ񳬹����ޣ������������ҳͷ�
void verdict_time()
{
	object *user;
	int i, exp, parry, force;

//���úƽٵ�����Ϊ30����(1800��)
	if( (time()-hj_startT) < 1800 ) {
		remove_call_out("verdict_time");
		call_out("verdict_time",60);
		return;
	}
	if (!LOGIN_D->get_madlock()) return;

	user = users();
	if (faction != "������")
		for(i=0;i<sizeof(user);i++) {
			if (user[i]->query("family/family_name") != faction) continue;
			if (!user[i]) continue;
//			exp = (int) user[i]->query("combat_exp") * 0.97;
			parry = (int) user[i]->query_skill("parry",1) * 0.99;
			force = (int) user[i]->query_skill("force",1) * 0.99;
//			if (exp > 1000) user[i]->set("combat_exp",exp);
			if (parry > 5) user[i]->set_skill("parry",parry);
			if (force > 5) user[i]->set_skill("force",force);
		}
	else	for(i=0;i<sizeof(user);i++) {
			if (!user[i]) continue;
			exp = (int) user[i]->query("combat_exp") * 0.97;
			parry = (int) user[i]->query("balance") * 0.75;
			if (exp > 1000) user[i]->set("combat_exp",exp);
			if (parry > 0) user[i]->set("balance",parry);
		}
	if (count+1 != sizeof(factions)) {
		message("channel:chat",HIR"����ؽ١�"MAG+faction+"������ս֮�£��������أ��Ӵ������伣��\n"NOR,users());
		message("channel:chat",HIW"���λ����Ρ�ħ�����������������һ������һ����\n"NOR,users());
		message("channel:chat",HIW"��"+HIM MUD_NAME+HIW"��������ʱ�����ˣ����ڽ������״̬��\n"NOR,users());
		call_out("disaster",10,count+1);
	}
	else {
		message("channel:chat",HIR"����ؽ١�"MAG"��Ȼ���ɷ���ɱ�У���������̫�󣬻��ǰ���������һʱ���ȷ�Ѫ�꣬����һƬ�찵��\n"NOR,users());
		message("channel:chat",HIW"��"+HIM MUD_NAME+HIW"��ħ��������ȫʤ������һƬ�ڰ������ڽ������״̬����ҿ�������!\n"NOR,users());
	}
	LOGIN_D->set_madlock(0);

}

//���úͶ�ȡ�ƽٵĿ�ʼʱ��
void set_hj_startT(int i)
{
	hj_startT = i;
}
int query_hj_startT()
{
	return hj_startT;
}
