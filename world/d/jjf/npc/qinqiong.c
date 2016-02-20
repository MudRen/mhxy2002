#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int rank_me();
string ask_bad(object me);
string ask_mieyao();
string ask_cancel();
void create()
{
  set_name("����", ({ "qin qiong", "qin", "shubao", "qiong", "qin shubao", "master", "shifu" }));
  set("title", HIY"����Ԫѫ"NOR);
  set("gender", "����");
  set("age", 43);
  set("str", 30);
  set("per", 26);
  set("int", 30);
  set("cor", 50);
  set("cps", 50);
  set("long", "���屦�Ǵ��ƹ���������������һλ�������佫��\n");
  set("combat_exp", 1200000);
  set_skill("literate", 200);
  set_skill("spear", 220);
  set_skill("force", 220);
  set_skill("dodge", 280);
  set_skill("parry", 250);
  set_skill("xuanyuan-archery",280);
  set_skill("mace", 300);
  set_skill("archery", 250);
  set_skill("wusi-mace", 280);
  set_skill("yanxing-steps", 250);
  set_skill("bawang-qiang", 200);
  set_skill("lengquan-force", 220);
 set_skill("unarmed", 260);
  set_skill("changquan", 220);
  map_skill("mace", "wusi-mace");
  map_skill("force", "lengquan-force");
  map_skill("unarmed", "changquan");
  map_skill("spear", "bawang-qiang");
  map_skill("archery", "xuanyuan-archery");
  map_skill("parry", "bawang-qiang");
  map_skill("dodge", "yanxing-steps");
  set("max_sen", 2800);
  set("max_kee", 4400);
  set("force", 2000);
  set("max_force", 1800);
  set("force_factor", 80);
  set("inquiry", ([
                   "name": "�����������屦��",
                   "here": "������ǽ����������ѵ��㲻֪����",
                   "rumors": "���²��ڽ������ߺܾ��ˣ������ϵ��������¿ɲ�̫�����",
                   "cancel": (: ask_cancel :),
                   "��ħ": (: ask_mieyao :),
                   "�ӷ�": (: ask_bad :),
				            "ְλ": (: rank_me :),
                   ]) );

  create_family("������", 2, "��");
  set("chat_chance_combat", 60);
  set("chat_msg_combat", ({
                (: perform_action, "spear", "qiangjian" :),
  }) );

  setup();
  carry_object("/d/obj/weapon/spear/yinqiang")->wield();
  carry_object("/d/obj/armor/tiejia")->wear();
  carry_object("/d/obj/weapon/mace/copperjian");
}

string ask_bad(object me)
{
    me=this_player();
    if ( me->query("office_number") > 1000 )
        return ("�������ʹ�ݡ�");
    if(me->query("combat_exp") < 100000 )
        return ("����ô�ܷ�����ȥ�أ�");
    return "/d/obj/bad"->query_yao(me);
}

int accept_object(object who, object ob)
{
                object me=this_player();
int exp,qn;
      string bname = who->name()+"��"+who->query("bad/name") + "��ͷ­";
     
     if ( (string)ob->query("name") != bname )
        return notify_fail("����ŭ�����㾹�Һ�Ū�ң�\n");
        
if (!ob->query("killer") ||ob->query("killer") != who->query("id"))
       return notify_fail("�����ŭ��������ɱ��Ҳ������,С���ұ��㣡\n");

      who->add("office_number", 1);
  if(who->query("family/family_name")!="������")
{
who->add("daoxing",(1000+random(200))/2);
 who->add("potential",(100+random(250))/2);
}
else {
who->add("daoxing",1000+random(200));
 who->add("potential",100+random(250));
}
// exp=1000 + random(100);
// qn=100 + random(250);
  tell_object(me,HIR"����ӷ���ͷ­����������\n"NOR);
  tell_object(me,HIC"������ͷ���ɵĲ���Ӧ�ý�����\n");
tell_object(me,HIG"��õ���Щ���к͵�Ǳ�ܡ�\n"NOR);
      command("smile");
      command("addoil " + who->query("id"));
  message("channel:chat",HIY+"��������������(Qin qiong)��"NOR+YEL+who->query("name")+HIY"ɱ����"NOR+HIR+who->query("bad/name")+HIY"��Ϊ�����������һ�ȡ�\n"+NOR,users());
      who->delete("bad");
      return 1;
}


string ask_mieyao()
{
  object me=this_player();
  if(me->query("family/family_name")!="������")
     return ("�㲻�Ǳ������ˣ�");
  command("smile "+me->query("id"));
  return "/d/obj/mieyao"->query_yao(me);
}
int accept_fight(object me)
{
  command("say �Ϸ��δ�ͽ����˶��ֹ����ˣ�����Ҳ����������\n");
  return 0;
}
int rank_me()
{
        object me=this_player();
        int exp;
        exp=(int)me->query("combat_exp");
        if( me->query("title") == "����������")
		return notify_fail("���Ѿ����������ˣ�����Ҫʲôְλ��\n");
        if( (string)me->query("family/family_name") == "������"){
                if( exp <= 100000 ){
                        me->set("title", HIW"���ƽ�����"YEL"��Ժ�ױ�"NOR);
                  } else if(exp <= 1000000 ){
                        me->set("title", HIW"���ƽ�����"YEL"�ȷ��"NOR);
                  } else if(exp <= 2000000 ){
                        me->set("title", HIW"���ƽ�����"YEL"�س��ᶽ"NOR);
                  } else if(exp <= 3000000 ){
                        me->set("title", HIW"���ƽ�����"YEL"�����Ԫ˧"NOR);
                } else {
                        me->set("title", HIW"���ƽ�����"YEL"����Ԫѫ"NOR);
                }

                tell_object(me, "�������˵���������"+me->query("title")+"��\n");
                tell_room(environment(me),
"�����"+me->query("name")+"˵���������"+me->query("title")+"��\n", ({me, me}));
         CHANNEL_D->do_channel(me,"chat","�����豾�ŵ���"+me->query("name")+""NOR+me->query("title")+HIC"һְ�������λ�ɳ����������");
     me->save();  
        }
        return 1;
}
int attempt_apprentice(object me)
{
  string myname=RANK_D->query_respect(me);
  if ((int)me->query("combat_exp")< 100000)
    {
      command("say ��λ"+myname+"������ȥ�������ҽ��������ɣ�");
      return 0;
    }
  command("haha");
  command("say �ܺã�ʱ����������֮�ʣ�"+myname+"���Ŭ�������ձض��гɡ�\n");
  command("recruit " + me->query("id") );
  return 1;
}
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
    ob->set("class", "fighter");
}
int prevent_learn(object me, string skill)
{
  string myname=RANK_D->query_respect(me);

  if (me->query("combat_exp") < 100000)
    {
      command("emote ������üͷ��˵����"+myname+"��Ƿ�������Ϸ�����"+myname+"����������⡣");
      return 1;
    }
  return 0;
}

string expell_me(object me)
{
  me=this_player();
  if((string)me->query("family/family_name")=="������")
    {
      me->set_temp("betray", 1);
      command("sigh");
      return ("���Ҵ����ɷ���ȴ���ܷ������Ը��(agree)��");
    }
  return ("ȥ����Ԭ�����ɣ�������֪����");
}
void init()
{
  add_action("do_agree", "agree");
}
int do_agree(string arg)
{
  if(this_player()->query_temp("betray"))
    {
      message_vision("$N���������Ը�⡣\n\n", this_player());
      command("say �����ȥ�ɣ������ն񣬺���Ϊ֮������");
      this_player()->add("betray/count", 1);
      this_player()->add("betray/jjf", 1);
      this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
      this_player()->delete("family");
      this_player()->delete("class");
      this_player()->set("title", "��ͨ����");
      this_player()->set_temp("betray", 0);
      this_player()->save();
      return 1;
    }
  return 0;
}

string ask_cancel()
{
    object me=this_player();
if((int)me->query_temp("m_mieyao"))
{
      me->add("daoxing",-2000);
      me->delete_temp("m_mieyao");
      me->delete("secmieyao");
      me->delete("secmieyao/type");
      me->delete("secmieyao/location");
      me->delete("secmieyao/place");
      me->delete("secmieyao/name");
      me->delete("secmieyao/id");
     return ("û�õĶ�����");
}
else
{
     return ("���������𣿣�");
}
}


