// LLY@FYSY 
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("л����", ({ "master xie", "master", "xie wangsun"}) );
        set("nickname", YEL "ĺɫ��Ϧ" NOR);
        set("gender", "����" );
        set("age", 51);
        set("agi",30);
        set("str", 60);
        set("per", 35);
        set("int",30);
        set("attitude","friendly");
        set("max_force", 3000);
        set("force", 3000);
        set("max_mana", 3000);
        set("mana", 3000);
        set("force_factor", 120);
        set("max_atman", 3000);
        set("long",
"����˲������⡣���Ǹ������ˣ�Ҳ������껹��Щ�����������Ѱߣ���ɫ����
¶�������ƣ�롣�����ú����أ�һ����������Ь���ࡣ�������������������
�ţ����������������վ�����������Ϊ��̫ƽ����ƽ���þ�����������ĺɫ
��������ſ�����������������Ҳ���翴����Ϧĺɫһ��������ֻ��о�����ƽ��
�����������������������һ��㾪��Ϳ־壬������ͣ�����ƽ�׵��ˣ�������
����Ȼ����̫�ϣ�������������ȴ�ѵ��˻ƻ裬�����������Ļƻ��ƽ��������
�������Ѳ�����ʲ��������ĵ��¡�\n"
        );
        create_family("��ɽׯ", 4, "ǰ��ׯ��");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
        (: perform_action,"sword", "jianqizongheng" :),
        }) );
        set("chat_chance", 10);
        set("chat_msg", ({
                "л��������������֣�΢Ц�������ò��Ž����Լ�����֪���㡣\n",
                "л��������������������ҵĿ���,���ׯ��ȥ�ɡ�\n",
                "л����΢Ц�ŵ����ܹ�������õ��������һ��������������ɢɢ��������
�죬ʵ���Ǽ���͵����¡�\n",
		 }) );
        set("combat_exp", 13000000);
        set("daoxing", 13000000);
        set_skill("parry",320);
        set_skill("dodge", 220);
        set_skill("force", 240);
        set_skill("literate", 260);
        set_skill("unarmed",180);
        set_skill("shadowsteps",220);
        set_skill("qingfeng-jian",320);
        set_skill("cloudforce",200);
        set_skill("sword",320);
        map_skill("dodge", "shadowsteps");
        map_skill("force", "cloudforce");
        map_skill("parry","qingfeng-jian");
        map_skill("sword", "qingfeng-jian");    
        setup();
        carry_object(__DIR__"obj/sword")->wield();
        carry_object(__DIR__"obj/sjcloth")->wear();
}

void attempt_apprentice(object me)
{
	switch(random(3)) {
		case 0:
message_vision("$N��$n�ʵ���ʲô���Ľ���\n", this_object(),me);
			break;
		case 1:
message_vision("$N��$n�ʵ�����Ľ���ʲô�ط���\n", this_object(),me);		
			break;
		case 2:
message_vision("$N��$n�ʵ�����������߾�����ʲô��\n", this_object(),me);
			break;
	}
                        return;

}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "shenjian");
}


