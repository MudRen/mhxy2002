// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// rewritten by snowcat on 4.12.1997

inherit NPC;

void create()
{
  set_name("������ʦ", ({"puti", "master puti", "puti"}));
  set("gender", "����");
  set("age", 100);
  set("attitude", "friendly");
  set("combat_exp", 1250000);
  set("per", 25);
  set_skill("dodge", 180);
  set_skill("force", 180);
  set_skill("parry", 180);
  set_skill("spells",180);
  set_skill("dao", 180);
  set_skill("puti-zhi", 180);
  set_skill("jindouyun", 180);
  map_skill("unarmed", "puti-zhi");
  map_skill("dodge", "jindouyun");
  map_skill("spells", "dao");
  set("max_sen",1800);
  set("max_gee",1800);
  set("max_gin",1800);
  set("force",1800);
  set("max_force",1800);
  set("max_mana",1800);
  set("force_factor",125);
  setup();

  carry_object("/d/obj/cloth/changpao")->wear();

}

  void announce_success (object who)
  {

  if (who->query("combat_exp") < 100000)
    return;
  if (who->query("obstacle/sky") == "done")
    return;
if (! who->query_temp("zhanyao_asked"))
    return;
  if (! who->query_temp("yudi_killed"))
    return;
  who->set("obstacle/sky","done");
  who->add("combat_exp",300000);
  who->add("potential", 10000);
  command("chat "+who->query("name")+"�����칬����ȡ�𵤣���ɨ�������");
  command("chat "+who->query("name")+"���������ͬ�٣�������ͬ�ԣ�");
  tell_object (who,"��Ӯ���˰�����У����Ǳ�ܣ�\n");
  who->save();
}

