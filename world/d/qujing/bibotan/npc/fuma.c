// By tianlin 2001.5.1
inherit NPC;
#include <ansi.h>
inherit F_MASTER;

void create()
{
       set_name("��ͷ����", ({"jiutou fuma","fuma"}));

        set("long","��ͷ����ԭ�ڱ�ڤ����������������Ϊ����\n");
       set("gender", "����");
       set("age", 20);
 	set("title", "[1;34m��ͷ��[2;37;0m");
        set("int", 25);
       set("attitude", "heroism");
        set("combat_exp", 1200000);
  set("daoxing", 1500000);


        set("eff_dx", -500000);
        set("nkgain", 500);

       set("class","yaomo");
       set("per", 10);
	set("str", 30);
       set("max_kee", 1600);
       set("max_sen", 1600);
       set("force", 3000);
       set("max_force", 2700);
       set("force_factor", 100);
       set("max_mana", 3600);
       set("mana", 3600);
       set("mana_factor", 80);
	set_skill("huaxue-dafa", 160);
	set_skill("huaxue-blade", 160);
        set_skill("unarmed", 160);
      	set_skill("dodge", 160);
      	set_skill("blade", 160); 
      	set_skill("force", 160);
      	set_skill("parry", 200);
      	set_skill("spells", 160);
      	set_skill("stick", 120);  //�е���ҿ�����ʦ��ѧstick
	set_skill("fork", 200);
 	set_skill("yueya-chan", 160);
	set_skill("moshenbu", 160);
	set_skill("huaxue-force", 160);
	map_skill("dodge", "moshenbu");
            map_skill("spells", "huaxue-dafa");
            map_skill("force", "huaxue-force");
            map_skill("blade", "huaxue-blade");
	map_skill("parry", "yueya-chan");
	map_skill("fork", "yueya-chan");
	create_family("��ʯɽ�̲�̶", 2, "����");

        setup();
	carry_object("/d/qujing/bibotan/obj/moonstaff")->wield();
        carry_object("/d/qujing/bibotan/obj/zhanpao")->wear();
}

int attempt_apprentice(object me)
{
  string myname=RANK_D->query_respect(me);
  command("pat "+me->query("id"));
  command("say �ܺã�ʱ����������֮��"+myname+"���Ŭ�������ձض��гɡ�");
  command("recruit " + me->query("id") );
message("system", HIY"��ʯɽ�̲�̶�ֶ���һ������  "+this_player()->name()+HIW"
           ��ʯɽ�̲�̶��������ǿ�ˡ�\n"NOR,users());
  return 1;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "yaomo");
               // ob->set("title", "��ʯɽ�̲�̶С��");
                ob->set("kusong/Teach_Fuma", 1);
        }
}

�
