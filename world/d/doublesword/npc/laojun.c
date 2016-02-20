



inherit NPC;
inherit F_MASTER;
string ziyingsword(object me);

void create()
{
       set_name("̫���Ͼ�", ({"taishang laojun","laojun"}));
       set("long", "�쳾һЦǣ��ţ,���˽����Ҷ���.\n");
       set("title", "��������");
       set("gender", "����");
       set("age", 100);
   set("class", "taoist");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "��ʦ��");
       set("per", 26);
   set("int", 30);
       set("max_kee", 5000);
       set("max_gin", 1000);
       set("max_sen", 5000);
       set("force", 5000);
       set("max_force", 3000);
       set("force_factor", 150);
       set("max_mana", 3000);
       set("mana", 5000);
       set("mana_factor", 150);
       set("combat_exp", 3000000);
       set_skill("literate", 150);
       set_skill("unarmed", 150);
       set_skill("dodge", 180);
       set_skill("parry", 170);
   set_skill("sword",200);
   set_skill("spells", 200);
   set_skill("taiyi", 180);
   set_skill("puti-zhi", 150);
   set_skill("wuxiangforce", 180);
   set_skill("force", 200);
   set_skill("sanqing-jian", 200);
   set_skill("jindouyun", 180);
   map_skill("spells", "taiyi");
   map_skill("unarmed", "puti-zhi");
   map_skill("force", "wuxiangforce");
   map_skill("sword", "sanqing-jian");
   map_skill("parry", "qianjun-bang");
   map_skill("dodge", "jindouyun");
   set("chat_chance_combat",80);
   set("chat_msg_combat", ({
   (: cast_spell,"zhenhuo" :),
}));
   set("inquiry", ([
    "�����«": "�����«��Ϊ��ۿ��򵤴������,��ʢ�鵤,����������.\n",
      "��": (: ziyingsword :),
      "��۫��": (: ziyingsword :),
      "ziying-sword": (: ziyingsword :),
]));

setup();

        carry_object("/d/lingtai/obj/pao")->wear();
}


string ziyingsword(object me)  
{
        object jian;
   me=this_player();
   if((string)me->query("family/family_name")!="��ׯ��") {
         message_vision("\n̫���Ͼ��������ǵ��ѣ��⽣Ҳ������...\n", me);
         return ("���ȥ��\n");
        }
    if(me->query("faith")<1000)
          command("say ����ô�������أ�");
     if( me->query("laojun_killjing") != 1 ) 
        {
          me->set("laojun_jing", 1);
          message_vision("\n̫���Ͼ����������������������أ�!\n", me);
          return ("��˵������ׯ�ۺ�԰����Ϭţ����������Ƚ����������ȥ������\n");
        }
     if( me->query("laojun_killjing") != 1 ) 
        {
          message_vision("\n̫���Ͼ����������������������أ�!\n", me);
          message_vision("̫���Ͼ���ָһ��.....\n\n", me);
          message_vision("̫���Ͼ��������ڻʹ�!\n", me);
          return ("��Ȼ��ˣ�������ȥ��\n");
        }
     if( me->query("enter") != 1 ) 
        {
          message_vision("\n̫���Ͼ����������������������أ�!\n", me);
          message_vision("\n̫���Ͼ��������ڻʹ�!�����Ժ����ѽ��\n", me);
          return ("��Ȼ��ˣ�������ȥ��\n");
        }
     if( me->query("laojun_killjingover") != 1 ) 
        {
          message_vision("\n̫���Ͼ����������������������أ�!\n", me);
          message_vision("\n̫���Ͼ��������ڻʹ�!�����Ժ����ѽ��\n", me);
          return ("��Ȼ��ˣ�������ȥ��\n");
        }

          message_vision("\n̫���Ͼ������úã�����������ѽ�Ҳ���͸����ˡ�\n", me);
          message_vision("̫���Ͼ����������������ҿ�����Ϊ��������Ī�����ĺ�������\n", me);
          message_vision("̫���Ͼ��͸���һ����۫����\n", me);
          jian = new("/d/doublesword/obj/zijian.c");
          jian->move(me);
          me->delete("laojun_trye_yes");
          me->delete("laojun_jing");
          me->delete("laojun_killjing");
          me->delete("laojun_killjingover");
          me->delete("laojun_enter");
          return ("��˵����һ�ѽ�������ĸ�ղص�...Ҳ�����������Ǽ٣���\n");
}

