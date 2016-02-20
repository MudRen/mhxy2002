// guanjia.c
// 9-2-97 pickle

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int rank_me();
string expell_me(object me);
void create()
{
  set_name("����", ({"tian shu", "tian", "shu", "tianshu", "monster"}));
  set("gender", "Ů��");
  set("age", 23);
  set("long",
"�������޵׶��Ĵ�ܼҡ��뵱����������һ�����ɳ������Σ�\n"
"��������̫��������վ����������չ��ŵ���Ľ��飬����\n"
"�����������ⶴ�Ĺܼҡ�\n");
  set("title", "��ܼ�");
  set("cor", 25);
  set("combat_exp", 400000);
  set("daoxing", 600000);

  set("attitude", "heroic");
  create_family("�ݿ�ɽ�޵׶�", 2, "����");
  set_skill("literate", 120);
  set_skill("unarmed", 120);
  set_skill("parry", 120);
  set_skill("spells", 120);  
  set_skill("sword", 120);  
  set_skill("qixiu-jian", 120);
  set_skill("yinfeng-zhua", 120);
  set_skill("lingfu-steps", 120);
  set_skill("dodge", 120);
  set_skill("force", 120);
  set_skill("yaofa", 120);
  set_skill("huntian-qigong", 120);
  set_skill("archery", 120);
  set_skill("xuanyuan-archery", 120);
  map_skill("force", "huntian-qigong");
  map_skill("unarmed", "yinfeng-zhua");
  map_skill("spells", "yaofa");
  map_skill("sword", "qixiu-jian");
  map_skill("parry", "xuanyuan-archery");
  map_skill("dodge", "lingfu-steps");
  map_skill("archery", "xuanyuan-archery");
  
  set("str", 30);
  set("per", 30);
  set("max_kee", 900);
  set("max_sen", 900);
  set("force", 3000);
  set("max_force", 1500);
  set("force_factor", 75);
  set("mana", 3000);
  set("max_mana", 1500);
  set("mana_factor", 76);
  set("inquiry", ([
                   "����": (: expell_me :),
                   "leave": (: expell_me :),
		   "name": "������������޵׶��Ĵ��ܹܣ�",
		   "here": "��Ϲ��������������Ƕ����������ݿ�ɽ�޵׶���",
		   "rumors": "��֪�����ұ�����ȥ��",
		   "�������": "��Ϲ���������������ֲ��ǳ��ӣ�",
		   	"ְλ": (: rank_me :),
                 ]) );  
  setup();
  carry_object("/d/obj/weapon/archery/qiankun-bow")->wield();
  carry_object("/d/obj/cloth/yuanxiang")->wear();
  carry_object("/d/obj/cloth/nichang")->wear();
  carry_object("/d/obj/weapon/archery/zhentian-arrow")->wield();
}
int rank_me()
{
        object me=this_player();
        int exp;
        exp=(int)me->query("combat_exp");
        if( me->query("title") == "�ݿ�ɽ�޵׶�����")
		return notify_fail("���Ѿ����������ˣ�����Ҫʲôְλ��\n");
        if( (string)me->query("family/family_name") == "�ݿ�ɽ�޵׶�"){
                if( exp <= 100000 ){
                        me->set("title", RED"�ݿ�ɽ�޵׶�"WHT"�����"NOR);
                  } else if(exp < 1000000 ){
                        me->set("title", RED"�ݿ�ɽ�޵׶�"WHT"�������"NOR);
                  } else if(exp < 2000000 ){
                        me->set("title", RED"�ݿ�ɽ�޵׶�"WHT"��������"NOR);
                  } else if(exp < 3000000 ){
                        me->set("title", RED"�ݿ�ɽ�޵׶�"WHT"�˱�����"NOR);
                } else {
                        me->set("title", RED"�ݿ�ɽ�޵׶�"WHT"ǧ����ʥ"NOR);
                }

                tell_object(me, "���󾫶���˵���������"+me->query("title")+"��\n");
                tell_room(environment(me),
"���󾫶�"+me->query("name")+"˵���������"+me->query("title")+"��\n", ({me, me}));
         CHANNEL_D->do_channel(me,"chat","�����豾�ŵ���"+me->query("name")+""+me->query("title")+"һְ�������λ�ɳ����������");
     me->save();  
        }
        return 1;
}
int attempt_apprentice(object me)
{
  string myname=RANK_D->query_rude(me);
  string myid=me->query("id");
  command("look "+myid);
  command("consider");
  if (me->query("combat_exp")+me->query("daoxing")>400000)
  {
    command("say "+myname+"����ʲô�������������λ�ӣ�\n");
    return 1;
  }
  if (me->query("wudidong/sell_reward")<1000)
  {
    command("say "+myname+"Ҫ�����޵׶������Ἰ����ͷ��Т���ң�\n");
    return 1;
  }
  command("grin");
  command("say ���������������ˡ�"+myname+"�����˶������Ū��ԭ�ϣ�");
  command("recruit "+myid);
  return 1;
}
int prevent_learn(object me, string skill)
{
  string myname=RANK_D->query_rude(me);

}
string expell_me(object me)
{
  me=this_player();

  if((string)me->query("family/family_name")=="�ݿ�ɽ�޵׶�")
  {
    me->set_temp("wudidong/betray", 1);
    return ("ʲô����Ҫ�뿪������ͱ������ͷ���(jieshou)\n");
  }
  return ("�����������ģ�����\n");
}
void init()
{
    add_action("do_accept", "jieshou");
}
int do_accept(string arg)
{
    object me=this_player();
    if (arg) return notify_fail("��Ҫ��ʲô��\n");
    if (!me->query_temp("wudidong/betray")) return notify_fail("��Ҫ����ʲô��\n");
    message_vision("$N����������Ҫ�뿪�޵׶�������ѣ�\n", me);
    me->add("betray/count", 1);
    me->add("betray/wudidong", 1);
    me->delete("family");
    me->delete("class");
    me->set("title", "��ͨ����");
    me->set("combat_exp", me->query("combat_exp")*80/100);
    me->set("daoxing", me->query("daoxing")*80/100);
    if (me->query_skill("yaofa"))
    {
        me->delete_skill("yaofa");
	//me->set_skill("yaofa", me->query_skill("yaofa")/2);
	//if (me->query_skill("yaofa")>30) me->set_skill("yaofa", 30);
    }
    if (me->query_skill("huntian-qigong"))
    {
        me->delete_skill("huntian-qigong");
	//me->set_skill("huntian-qigong", me->query_skill("huntian-qigong")/2);
	//if (me->query_skill("huntian-qigong")>30) me->set_skill("huntian-qigong", 30);
    }
    me->save();
    return 1;
}
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob))
  {
    ob->set("class", "yaomo");
  }
}
�
