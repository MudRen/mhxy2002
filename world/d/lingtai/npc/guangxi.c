// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// guang.c

inherit NPC;
inherit F_MASTER;
int borr_me(object ob);
void create()
{
        set_name("������", ({"guang xizi", "guang"}));
        set("title", "�����ܹ�");
        set("gender", "����" );
        set("age", 53);
        set("long", "һ����������ü��Ŀ�ĵ�ʿ��������һ��������ţ�\n");
   set("class", "toaist");
        set("combat_exp", 180000);
        set("attitude", "friendly");
      set("faith",1000);
   set("force", 400);
   set("max_force", 400);
   set("force_factor", 40);
   set("max_mana", 400);
   set("mana", 400);
   set("mana_factor", 30);
   set("max_kee", 800);
   set("max_sen", 800);

        set("eff_dx", 60000);
        set("nkgain", 250);

   set_skill("dodge", 80);
   set_skill("parry", 80);
   set_skill("puti-zhi", 80);
   set_skill("jindouyun", 80);
   set_skill("unarmed", 80);
   set_skill("jindouyun", 80);
   set_skill("literate", 100);
   map_skill("dodge", "jindouyun");
   map_skill("unarmed", "puti-zhi");
        set("per", 30);
   set("str", 25);
        create_family("����ɽ���Ƕ�", 2, "����");

   set("inquiry", ([
                "book": "�����������ǵ��̾��䣬Ҳ��Щƽ���鼮��",
            "���¾�": (: borr_me :),
        ]) );
        setup();
carry_object("/d/lingtai/obj/xiangpao")->wear();
   carry_object("/d/lingtai/obj/daoguan")->wear();
}
int borr_me(object ob)
{       object m;
        ob = this_player();
        if ((string)this_player()->query("family/family_name")=="����ɽ���Ƕ�") {
     if( (int)this_player()->query_skill("literate", 1) < 10 ) {
        message_vision("$N��$n˵�������д��̫���������Ҳ����������\n", this_object(), ob);
        return 1;
     }
     if ( (int)this_object()->query("daode") ) {
        message_vision("$Nһ���֣�˵���ս��ȥ�����������ɣ�\n", this_object());
        return 1;
     }
                m=new("/d/lingtai/obj/daode");
                m->move(ob);
     this_object()->set("daode", 1);
     message_vision("$N�Ӽ������±������ݸ�$n��˵���������ڷܵķ��ϣ��ͽ����ɣ�\n", this_object(), ob);
                return 1;
        }
   message_vision("$N˵������������鲻��裡\n", this_object());
   return 1;
}

void init()
{
  ::init();
  if(this_player()->query("lingtai_quest/quest_type")=="����"){
    command("say ̫���ˣ���λ�����ɷ��æ���ϻ�����һ�ݣ�(agree yes/no)");
    this_player()->set_temp("chao_jing",1);
    add_action("do_agree","agree");
  }
}

int do_agree(string arg)
{
  object me=this_player();
  if(!me->query_temp("chao_jing"))return 1;
  me->delete_temp("chao_jing");
  if(arg=="no")return 1;
  if(arg=="yes"){
    command("say �����һ��ׯ���ϻ�������ȥ���ҳ�������");
    message_vision("$N��һ�����������£�����ë�ʣ��۾�����س���������\n",me);
    me->start_busy(5);
    call_out("finish_chaojing",5,me);
    return 1;
  }
}

void finish_chaojing(object me)
{
  message_vision("$N������ã����ڽ�һ�������ˣ�����һ������ֻ�����ֱ�����\n",me);
  command("thank "+me->query("id"));
  me->set("lingtai_quest/done",1);
}
