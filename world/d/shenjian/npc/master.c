//By tianlin@mhxy for 2002.1.7

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
       set_name("л����", ({"xiexiao feng", "master xie", "master","xie"}));
       set("long", "л��������ѧ��,ʮ���꽣��,ʮ����ܻ�����,һ�����ϸ�����ὣ��������˫
��������������,��������Ľ����ݶ����,����һ����ծ����\n");
       set("nickname", HIG"����"NOR);
       set("title", HIW"��ɽׯ"BLINK+HIR"����"NOR);
       set("gender", "����");
       set("age", 20);
       set("class","shenjian");
       set("attitude", "friendly");
       set("rank_info/respect", "����");
       set("cor", 30);
       set("per", 21);
       set("max_kee", 4000);
       set("max_gin", 1000);
       set("max_sen", 4000);
       set("max_force", 5600);
       set("force", 5600);
       set("max_mana", 6000);
       set("mana", 6000);
       set("force_factor", 100);
       set("mana_factor", 150);
       set("combat_exp", 3000000);
       set("daoxing", 2000000);
       set_skill("literate", 140);
       set_skill("unarmed", 185);
       set_skill("dodge", 185);
       set_skill("force", 195);
       set_skill("parry", 185);
       set_skill("sword", 200);
       set_skill("spells", 185);
       set_skill("blade", 185);
       set_skill("lianhuan-zhang", 185);
       set_skill("duo-sword", 210);
       set_skill("qingfeng-jian", 190);
       set_skill("cloudforce", 200);
       set_skill("shadowsteps", 185);
       set_skill("xueying-xianfa", 185);
       set_skill("shenji-blade", 185);
       map_skill("spells", "xueying-xianfa");
       map_skill("unarmed", "lianhuan-zhang");
       map_skill("force", "cloudforce");
       map_skill("sword", "duo-sword");
       map_skill("parry", "qingfeng-jian");
       map_skill("dodge", "shadowsteps");
       map_skill("blade", "shenji-blade");
       set("chat_chance_combat", 50);
       create_family("��ɽׯ", 1, "��");
       setup();

        if ("/d/shenjian/obj/jueshijian.c"->in_mud())
            carry_object("/d/obj/weapon/sword/qinghong")->wield();
        else carry_object("/d/shenjian/obj/jueshijian.c")->wield();
//carry_object("/d/ourhome/obj/shoes")->wear();
}
void attempt_apprentice(object ob)
{
   if ( (string)ob->query("family/family_name")=="��ɽׯ") {
   if (((int)ob->query("daoxing") < 500000 )) {
   command("say " + RANK_D->query_respect(ob) +
"�ĵ��в��������Щ��ѧ�ط�������������\n");
   return;
   }
        command("pat "+ob->query("id"));
        command("say �ã�ϣ��" + RANK_D->query_respect(ob) +
"���Ŭ������������ɽׯ������\n");
       command("recruit " + ob->query("id") );
           ob->set("title", HIW"��ɽׯ"HIG"л����"HIY"�����״�����"NOR);
             ob->set("class", "shenjian");
ob->set("baishi-xie", 1);
   return;
   }
   command("shake");
   command("say " + RANK_D->query_respect(ob) +
"������ȥѧЩ��������ɡ�\n");
        return;
}
/*
int accept_fight(object me)
{
   return 0;
}
*/

