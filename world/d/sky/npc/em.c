// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 

inherit NPC;

void create()
{
  set_name("��ʴ��", ({"yuhuang dadi","yudi"}));
  set("gender", "����");
  set("age", 70);
  set("attitude", "friendly");
  set("combat_exp", 50000);
  set("per", 35);
  set_skill("dodge", 30);
  set_skill("force", 30);
  set_skill("parry", 30);
  set("max_sen",600);
  set("max_gee",600);
  set("max_gin",600);
  set("force",500);
  set("max_force",500);
  set("max_mana",500);
  set("force_factor",5);
  setup();

  carry_object("/d/obj/cloth/choupao")->wear();

}

void announce_success (object who)
{
    if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/sky") == "done")
    return;
  if(!who->query_temp("skypass"))
   return;
  who->set("obstacle/sky","done");
  who->add("potential", 5000);
  who->add("combat_exp", 20000);
  command("chat "+who->query("name")+"�����칬,�ٷ������ʥ��");
  command("chat "+who->query("name")+"˳������������һ�أ�");
  command("chat ����"+who->query("name")+"��ʮ�����,��ǧ��Ǳ��!");
  who->save();
}
