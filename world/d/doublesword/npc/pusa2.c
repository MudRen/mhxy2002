

inherit NPC;
inherit F_MASTER;

string hesword(object me);

void create()
{
   set_name("�ݹ�����", ({ "huiguang pusa", "guanyin", "pusa" }));
   set("title", "");
   set("long", @LONG
��Բ�ĵ£���������ü��С�£�����˫�ǡ�����������
LONG);
   set("gender", "����");
   set("age", 35);
   set("attitude", "peaceful");
   set("rank_info/self", "ƶɮ");
   set("rank_info/respect", "�ݹ�����");
   set("class", "bonze");
           set("str",24);
   set("per",100);//means no rong-mao description.
   set("max_kee", 5000);
   set("max_gin", 5000);
   set("max_sen", 5000);
   set("force", 4000);
   set("max_force", 2000);
   set("force_factor", 200);
   set("max_mana", 3000);
   set("mana", 6000);
   set("mana_factor", 200);
   set("combat_exp", 2000000);
   set_skill("literate", 190);
   set_skill("spells", 200);
   set_skill("buddhism", 200);
   set_skill("unarmed", 160);
   set_skill("jienan-zhi", 160);
   set_skill("dodge", 180);
   set_skill("lotusmove", 160);
   set_skill("parry", 160);
   set_skill("force", 180);
   set_skill("lotusforce", 180);
   set_skill("staff", 180);
   set_skill("lunhui-zhang", 180);
   map_skill("spells", "buddhism");
   map_skill("unarmed", "jienan-zhi");
   map_skill("dodge", "lotusmove");
   map_skill("force", "lotusforce");
   map_skill("parry", "lunhui-zhang");
   map_skill("staff", "lunhui-zhang");
   set("chat_chance_combat", 90);
   set("chat_msg_combat", ({
     (: cast_spell, "bighammer" :),
     (: cast_spell, "jinguzhou" :)
   }) );
   set("inquiry",([
      "����˫��": (: hesword :),
      "doublesword": (: hesword :),

   ]) );
   create_family("�Ϻ�����ɽ", 1, "����");

   setup();
   carry_object("/d/nanhai/obj/jiasha")->wear();
   carry_object("/d/nanhai/obj/jingu1");
   carry_object("/d/nanhai/obj/nine-ring")->wield();
}
string hesword(object me)
{
    me=this_player();
    if((string)me->query("family/family_name")!="��ׯ��")
        return ("�㲻����ׯ�۵��ӣ���Ҫ֪��������ܵ�");
    if(me->query("faith")<1000)
        return ("�ҿ������ׯ�۹����������ҳϣ�\n");
     if(me->query("sword_hesword") == 1 ) 
                       {
             message_vision("\n�ݹ������ɻ�ؿ�����......\n", me);
        return ("���Ѿ���������ѽ...\n");
                       }
    command("consider");
     if( ! me->query("sword_xiaofeng") == 1 ) 
     return ("���������½�����˲����죬��ô�õ����������\n");
     if( ! me->query("sword_sanqing") == 1 ) 
     return ("������彣����˲����죬��ô�õ����������\n");
     message_vision("\n\n�ݹ�������ͷ��$N���������������֪����!", me);
     message_vision("\n�ݹ�������ͷ���������Ȼ������ׯ�۹��������������Ҿ͸������.....", me);
          me->set("sword_hesword", 1);
     return ("\n�ݹ�����˵��:�Ͻ�Ҫ�ĳ�,.........\n");
}
