//Cracked by Roath
inherit NPC;
#include <weapon.h>
#include <ansi.h>

inherit F_MASTER;
  string expell_me(object me);

void create()
{
  set_name("������", ({ "youxia er","er","xia", "man"}) );
  set("gender", "����");
  set("age", 10);
  set("title", HIW"��������"NOR);
  set("long","ʱ������֮�����أ���������ͷҲ�ɿ�����װ�彣���ꡣ\n\
����Ϊ�����еĽܳ�����书����Ī�⣬ϲ���������壬��ǿ������\n\
���������������ߣ�������ͨ���ռ�����Ϊʦ��\n");
  set("combat_exp", 2000000+random(3000000));
  set("daoxing", 1000000);

  set("per", 15);

  set_skill("piaoxiang", 150);
        set_skill("sword", 180);
        set_skill("force", 180);
        set_skill("spells", 180);
        set_skill("lingxiyizhi", 150);
        set_skill("tianjijue", 150);
        set_skill("wuji-force", 180);
        set_skill("tanzhishentong", 150);
        set_skill("spells", 180);
        set_skill("literate", 120);
         set_skill("baiyun-sword", 150);
           set_skill("unarmed", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
            map_skill("force", "wuji-force");
            map_skill("unarmed", "lingxiyizhi");
            map_skill("spells", "tianjijue");
            map_skill("dodge", "piaoxiang");
        map_skill("sword", "baiyun-sword");
        map_skill("parry", "baiyun-sword");
  set("max_sen",800);
  set("force", 1800);
  set("max_force", 1800);
  set("force_factor", 100);
  set("mana", 2000);
  set("max_mana", 2000);
  set("mana_factor", 100);

        set("inquiry", ([
          "leave": (: expell_me :),
//                 "leave": (: expell_me :),
]) );

   create_family("��������", 2, "��");

  setup();

  carry_object("/d/qujing/kusong/obj/tongjia")->wear();
}

void attempt_apprentice(object ob)
{       ob=this_player();

 if( (string)ob->query("family/family_name") == "��������") {;
 command("say С���˵���û������ʦ��ͬ��͸������ң�biang �Ĵ�����\n");
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
                ob->set("title", "��������");
        }
}


string expell_me(object me)
{       me=this_player();
        if((string)me->query("family/family_name")=="��������") {
                me->set_temp("betray", 1);
                return ("����Ҫ��ɽ��ȴ����ɽ��ͷ������Ը��(agree)?");
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
      if(this_player()->query_temp("betray") &&
                  this_player()->query("family/family_name")=="��������") {
                message_vision("$N�����Ը�⡣\n\n", this_player());
                this_player()->add("betray/count", 1);
                this_player()->add("betray/huoyun", 1);
                this_player()->set("combat_exp", this_player()->query("combat_exp")*95/100);
                this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("title", "��ͨ����");
                this_player()->save();
                command("say ����ȥ�ɣ�\n");
                return 1;
                }
        return 0;
}


