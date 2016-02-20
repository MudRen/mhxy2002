// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */

inherit NPC;
string ask_me();
void create()
{
  set_name("����Ԫ˧", ({ "tianpeng yuanshuai","yuanshuai","shuai","zhu" }));
  set("age", 600);
  set("gender", "����");
  set("long", "�������ƹܰ˰�����ӵ�����Ԫ˧��,�����������!!\n");
  set("attitude", "peaceful");
  set("str", 50);
  set("per", 10);
  set("combat_exp", 1200000);
  set("max_kee", 2500);
  set("max_sen", 2500);
  set("max_force", 1500);
  set("force", 2500);
  set("force_factor", 150);
  set("mana_factor", 150);
  set("max_mana",2500);
  set("mana",2500);
  set_skill("unarmed", 190);
  set_skill("dodge", 160);
  set_skill("parry", 160);
  set_skill("rake", 150);
  set_skill("force", 180);
  set_skill("spells", 180);
  set_skill("baguazhou", 180);
  set_skill("yanxing-steps", 170);
  set_skill("skyriver-rake", 180);
  map_skill("force", "lengquan-force");
  map_skill("spells", "baguazhou");
  map_skill("rake", "skyriver-rake");
  map_skill("parry", "skyriver-rake");
  map_skill("dodge", "yanxing-steps");
  set("chat_chance",10);
  set("chat_msg",({
  "����Ԫ˧���������: �������������˰������,������Ϊ��ˮ�﹦���.\n",
  "����Ԫ˧�뵽�����������������϶�,����̾��:����һ�����������˶�!\n",
  "����Ԫ˧���������: ��˵��������칬����һ��������!\n",
  "����Ԫ˧��: Ҫ�����ܸ㵽ѩ����,�ǿɾͺ���!\n",
  "����Ԫ˧˵��: ��˵��������ͦ�����ݵ�,�Ҹ�������һ��Ҫ����һ��!\n",
  }));
  set("inquiry", ([
  "����": "��ƾ����������,Ҳ�����˧�Ȼ�!!\n",
  "������":  (: ask_me :),
  "�϶�": "��˵ѩ�������϶������İ�֮��,Ҫ�������ܸ㵽�ͺ���!\n",
  ]));
  setup();
  carry_object("/d/kaifeng/obj/jiuchipa")->wield();
  carry_object("/d/obj/armor/tongjia")->wear();
}
string ask_me()
{
command("say ��������δ������С��,����Ʒ���㲻��,ֻ�Ǹ�������!\n");
command("say �ҿ��㳤�ü��������,�����˵ĳ�������������!\n");
this_player()->set_temp("fight_zhu",1);
return "�Ǻ�!\n";
}
int accept_object(object who, object ob)
{
 if((string)ob->query("id") !="snowglass"){
 command("say ����ʲô�������Ⱑ!!");
 return 0;
}
else {
 command("smile");
 command("say ̫����,�����ڸ㵽ѩ������.");
 command("say ������Ҫ�����������,���ǵ�ʤ���Ҳ���!");
 this_player()->set_temp("zhu_fight", 1);
 return 1;
}
}
int accept_fight(object who)
{
 object me;
 me = this_object();
     if (!who->query_temp("fight_zhu"))
{
     command("say ��˧������ԩ�޳��,���㶯�ָ�ʲô!!\n");
     return 0;
}
     if (!who->query_temp("zhu_fight"))
{
     command("say ������������è����ʽ,Ҳ�����˧����!!\n");
         return 0;
 }

 say("����Ԫ˧��:���챾˧����������а�!\n");
  me->set("eff_kee", (int)me->query("max_kee"));
        me->set("kee", (int)me->query("max_kee"));
        me->set("eff_sen", (int)me->query("max_sen"));
        me->set("sen", (int)me->query("max_sen"));
     remove_call_out("check_fight");
     call_out("check_fight", 1, me, who);
     return 1;
}
void player_win(object me,object who)
{
  me = this_object();
 call_out("zhu_appearing",1,who);
 command("chat �Ǻǣ�");
 destruct(me);
 this_player()->delete_temp("zhu_fight",1);
 this_player()->delete_temp("fight_zhu",1);
 return ;
}
void zhu_appearing (object who)
{
  object zhu = new ("/d/sky/npc/zhu");
  zhu->announce_success (who);
  destruct (zhu);
}
void announce_success (object who)
{
  int i;

/*
  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/riverpass") == "done")
    return;
*/
  i = random(800);
  who->set("obstacle/riverpass","done");
  who->add("combat_exp",i+3000);
  command("chat "+who->query("name")+"�������,��ʤ����Ԫ˧��");
  command("chat "+who->query("name")+"˳������������һ�أ�");
  tell_object (who,"��Ӯ����"+chinese_number(3)+"��"+
               chinese_number(i/4)+"��"+
               chinese_number((i-(i/4)*4)*3)+"ʱ���ĵ��У�\n");
  who->save();
}
void player_lose (object me, object who)
{
     string msg;
     msg = RANK_D->query_respect(who);

   command("jump");
   say("����Ԫ˧Ц��:�����˵����˧�Ĺ�����һ��һ����!\n");
}
void check_fight (object me, object who)
{
     int my_kee, whos_kee;
     int my_max_kee, whos_max_kee;

   if(!who) return;
     my_kee = me->query("kee");
     whos_kee = who->query("kee");
     my_max_kee = me->query("max_kee");
     whos_max_kee = who->query("max_kee");

     if (me->is_fighting()){
         remove_call_out("check_fight");
         call_out ("check_fight",1,me,who);
         return;
     }

     if (!present(who, environment(me)))
         return;

   if ((my_kee*100/my_max_kee) <= 50)
     player_win (me, who);
   else if ((whos_kee*100/whos_max_kee) <= 50)
     player_lose (me, who);
}
