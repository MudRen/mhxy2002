//[4;53m[1;31mBy tianlin@mhxy for 2001.9.27[2;37;0m
//�����Ż�

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string expell_me(object me);

void create()
{
  set_name("����Ϻ��", ({"changtui xiabing","xiabing"}));
  set("gender", "����");
  set("age", 25);
  set("title", HIW"�̲�̶"HIB"��ͷ����"HIC"����"NOR);
  set("long","�̲�̶�������ͻ��ƶ����н���,�������������͵�,˳��Ҳ��Щͽ�ܡ�\n");
  set("combat_exp", 100000+random(3000));
  set("daoxing", 100000);
  set("per", 15);
  set_skill("dodge", 90);
  set_skill("parry", 90);
  set_skill("unarmed", 90);
  set_skill("force", 90);
  set_skill("spells", 90);
  set_skill("fork", 90);
  set_skill("huaxue-dafa", 90);
  set_skill("huaxue-force", 90);
  set_skill("moyun-shou", 90);
  set_skill("moshenbu", 90);
  map_skill("force", "huaxue-force");
  map_skill("spells", "huaxue-dafa");
  map_skill("unarmed", "moyun-shou");
  map_skill("dodge", "moshenbu");
  map_skill("fork", "yueya-chan");
  set("max_sen",800);
  set("max_kee",800);
  set("force", 400);
  set("max_force", 400);
  set("force_factor", 20);
  set("mana", 400);
  set("max_mana", 400);
  set("mana_factor", 20);

        set("inquiry", ([
                "��ɽ": (: expell_me :),
                "leave": (: expell_me :),
]) );

  create_family("��ʯɽ�̲�̶", 3, "��");

  setup();

  carry_object("/d/qujing/kusong/obj/tongjia")->wear();
  carry_object("d/obj/weapon/stick/mugun")->wield();


}

void attempt_apprentice(object ob)
{       ob=this_player();

        if( (string)ob->query("family/family_name") == "��ʯɽ�̲�̶") {
		command("say ���ͬ�����ˣ����ҵ������ҵ���\n");
		return;
	}
                command("grin");
                command("recruit " + ob->query("id"));
                return ;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "yaomo");
                ob->set("title", "��ʯɽ�̲�̶С��");
        }
}

string expell_me(object me)
{       me=this_player();
        if((string)me->query("family/family_name")=="��ʯɽ�̲�̶") {
                me->set_temp("betray", 1);
                return ("�����Ҫ�뿪��?��Ҫ����һЩ����,���Ը��(agree)?");
        }
        return ("��֪��");
}
void init()
{
::init();
        add_action("do_agree", "agree");
}

int do_agree(string arg)
{
        if(this_player()->query_temp("betray")) {
                message_vision("$N�����Ը�⡣\n\n", this_player());
                this_player()->add("betray/count", 1);
                this_player()->add("betray/bibotan", 1);
		this_player()->set("combat_exp", this_player()->query("combat_exp")*95/100);
                            if( this_player()->query_skill("huaxue-force") )
		  this_player()->delete_skill("huaxue-force");
                if( this_player()->query_skill("huaxue-dafa") )
		   this_player()->delete_skill("huaxue-dafa");
                            this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("title", "��ͨ����");
                this_player()->save();
                command("say ����ȥ�ɣ�\n");
                return 1;
                }
        return 0;
}

�