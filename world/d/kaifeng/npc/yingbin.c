inherit NPC;
#include <ansi.h>

void create()
{
  set_name(HIR"���"NOR, ({"zhu dachang", "dachang", "zhu"}));
  set("age", 28);
  set("gender","����");
  set("attitude", "peaceful");
  set("str", 40);
  set("per",11);
  set("combat_exp",30000);
  set("daoxing",30000);
  set("title",HIG"����ӭ��"NOR);
  set("chat_chance",30);
  set("chat_msg", ({
        "����૵ص����Ҿ��������ӭ���ˡ������ӭ��������--���\n",
        "��󳦵�������������ؤ�����ã������ʵ�Ҳ������\n",
        "��󳦴���������������˰˽�����������\n",
        }));



  set("max_kee", 500);
  set("max_sen", 500);
  set_skill("unarmed", 30);
  set_skill("dodge", 30);
  set_skill("parry", 30);
  setup();
  carry_object("/d/obj/cloth/bingfu")->wear();
}

void inint ()
{
  call_out ("looking",1,this_player());
}

void looking (object who)
{
  command ("look "+who->query("id"));
}
void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        say( "��������˵������λ���磬��ӭ�����������\n");
}

