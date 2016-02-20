//[4;53m[1;31mBy tianlin@mhxy for 2001.9.27[2;37;0m
//�����Ż�

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("�����", ({ "yu daiyan", "yu" }));
        set("nickname", HIW"�䵱"NOR+HIR"����"NOR);
        set("long",
                "���������������ҵĵ��ӡ��䵱����֮��������ҡ�\n"
                "��һ���ɸɾ������಼������\n"
                "��������ʮ��ͷ��ͣ�˫�Ȳзϣ������������������佣��\n");
        set("gender", "����");
        set("age", 31);
        set("attitude", "peaceful");
        set("class", "swordsman");
        set("shen_type", 1);
        set("str", 28);
        set("int", 30);
        set("con", 28);
        set("dex", 28);

        set("max_kee", 3000);
        set("max_sen", 3000);
        set("force", 3500);
        set("max_force", 1500);
        set("mana", 3000);
        set("max_mana", 3000);
        set("force_factor", 90);
        set("mana_factor", 70);
        set("combat_exp", 250000);
        set("daoxing", 250000);

        set_skill("force", 100);
        set_skill("wudang-force", 140);
        set_skill("spells", 170);
        set_skill("wudang-xianfa", 100);
        set_skill("dodge", 150);
        set_skill("tiyunzong", 150);
        set_skill("unarmed", 100);
        set_skill("taiji-quan", 100);
        set_skill("parry", 110);
        set_skill("sword", 120);

        map_skill("force", "wudang-force");
        map_skill("spells", "wudang-xianfa");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");
	set("chat_chance", 1);

        set("chat_msg", ({
            "�����˵�������佣���Ƕ�ʦ����Ѫ��",
            "���������̾������λ��ʦ���κ��ҵ��ȣ���Ҳ��Ѽׯһ�١�"
        }));

        create_family("�䵱��", 2, "����");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang1/obj/bluecloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting",2 , ob);
        }
}

void greeting(object ob)
{
   int i;
   if (((int)ob->query_skill("wudang-force", 1) == 0))
   {
      message_vision(CYN"ʮ�����Ӷ�$N�����ȵ��������аħ������������佣��\n\n"NOR,ob);
      ob->set("kee",30);
      if ((int)ob->query("combat_exp") <2000) ob->set("combat_exp",1);
         else ob->add("combat_exp",-1000);
      message_vision(CYN"���佣���ʱ��������̨�Ͻ����ݺᣬ��$NΧ�����롣\n"NOR,ob);
      message_vision(CYN"ʮ���ڳ����������$N���ϻ�����ʮ�������ӣ���Ѫ���졣\n"NOR,ob);
      say(CYN"\n\n���������ŭ�ݣ���аħ�����Ҳ�Ҵ����佣�󣡡�\n");
      message_vision("����ҾӸ����£�����һ�ư�$N�����̨��\n\n\n"NOR,ob);
      ob->move("/d/wudang1/nanyangong");
      CHANNEL_D->do_channel(this_object(),"chat",sprintf("%s ˽�����佣������ɳ����ף�����һ����",ob->name(1)));
   }
}

void attempt_apprentice(object me)
{
       if ( ((int)me->query("combat_exp") < 100000)) {
         command("say " + RANK_D->query_respect(me) +
                        "�Ƿ�Ӧ�ڵ��¼��书�������Ŭ�������շ�����");
                return;
        }
        if ((int)me->query_skill("wudang-force", 1) < 30) {
                command("say ���䵱�����ڼ��书���������ڹ��ķ���");
                command("say " + RANK_D->query_respect(me) +
                        "�Ƿ�Ӧ����̫�����϶��µ㹦��");
                return;
        }
        command("say �ðɣ��Ҿ��������ˡ�");
        command("recruit " + me->query("id"));
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "wudang");
                ob->set("title", "[1;33m�䵱��[1;37m��[1;36m��[1;37m������[2;37;0m");
}
