// by gslxz@mhsj 1/7/2001
#include <ansi.h>
inherit NPC;

int test_player (object me);

void create()
{
  set_name("��Ԫ��", ({"li yuanba", "li", "yuanba"}));
  set("long", "�ƹ����¸����ɵ�����\n");
  set("title", HIY"�����ղ�"NOR);
  set("gender", "����");
  set("age", 36);
  set("per", 18);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 2000);
  set_skill("unarmed", 10);
  set_skill("dodge", 10);
  set_skill("parry", 10);
  set("max_gin",200);
  set("max_kee",200);
  set("max_sen",200);
  set("max_force",200);
  set("max_mana",200);
  set("force_factor",12);
  set("inquiry", ([
        "����":   (: test_player :),
        "Ǯ": (: test_player :),
        "����": (: test_player :),
      ]));

  setup();
    carry_object("/d/obj/armor/jinsijia.c")->wear();//by tianlin 2001.9.4�޸�,��Ϊgslxz�Ǹ�����,ֻ�����npc�ļ�,copy
//������,û�д���clone/armor/pao.c�ļ�,�϶��Ǹ�bug����,�����ڸ�����
}
// by gslxz@mhsj 1/7/2001

int test_player (object me)
{
  object who = this_player();

  if (who->query("weiwang")<150)
  {
  me->command_function("shake");
  me->command_function("say �����ʦ�������������ܹ���ȡ���͡�");
    return 1;
  }  

  me->command_function("nod");
  call_out ("give_money",2,me,who);
  return 1;
}

void give_money (object me, object who)
{

  object money = new ("/obj/money/gold");
  add_money("gold", 1000);
  command("give 1000 gold to " + this_player()->query("id"));
  this_player()->add("weiwang",-150);
  me->command_function ("give "+who->query("id")+" money");
 message("shout",HIY+"�������쳯����Ԫ��(Li yuanba)��"HIW+this_player()->query("name")+HIY"���Բ�����ʦ�����������ɼΣ����ϴ���ƽ�ǧ����\n"+NOR,users());
}
// by gslxz@mhsj 1/7/2001
void die()
{
  if (environment())
    message("sound", "\n\n��Ԫ�Դ�һ��:�ʵ۾���,��Ԫ���ָ����ˣ�\n\n", environment());

  set("eff_kee", 600);
  set("eff_gin", 600);
  set("eff_sen", 600);
  set("kee", 600);
  set("gin", 600);
  set("sen", 600);
  set("force", 600);
  set("mana", 600);
}

void unconcious()
{
  die ();
}
