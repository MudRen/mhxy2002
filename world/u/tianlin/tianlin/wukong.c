//By tianlin@Mhxy for 2001.12.30
//����yudian���༭�ļ�������,�޸������û��ʦ����Ҫskills������bug
#include <ansi.h>

inherit NPC;
int call_moon();
int call_wzg();
int call_putuo();
int call_fangcun();
int call_xueshan();
int call_huoyundong();
int call_longgong();
int call_wdd();
int call_hell();
int call_jjf();
int call_wusheng();
int call_tianpeng();
int call_shenjian();
int call_pansi();
int call_wudang();
int call_shushan();
int call_lingjie();
int call_mojiao();
//int call_shaolin();
int give_bonnet();
int give_dan();

void create()
{
       set_name(HIW"�����"NOR, ({"sun wukong","sun", "wukong"}));
       set ("long", @LONG

  һ��������ߣ����ݸɸɣ������ë�������
�Դ�ȡ���澭���������ҷ�������,��ҿ���
(ask)��(����:ask sun about gift,ask sun about wdd,
ask sun about fangcun,....�ȵ�!���г����Ҫ����ǰ
����Ȱ�ʦ!��һ�����������ȡbonnet,ask sun about bonnet)
LONG);
       set("gender", "����");
       set("title",HIG"��ս"HIY"ʥ��"NOR);
       set("nickname",HIR"�����ʥ"NOR);
       set("age", 1000);
       set("per", 40);
       set("combat_exp", 2600000);
       set("daoxing", 4121410);
       set("max_force", 5500);
       set("max_mana", 5000);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("inquiry", ([
            "moon":(:call_moon:),
            "huoyundong":(:call_huoyundong:),
            "wusheng":(:call_wusheng:),
            "tianpeng":(:call_tianpeng:),
            "shenjian":(:call_shenjian:),
            "pansi":(:call_pansi:),
            "wudang":(:call_wudang:),
            "shushan":(:call_shushan:),
           // "shaolin":(:call_shaolin:),
            "wzg":(:call_wzg:),
            "xueshan":(:call_xueshan:),
            "fangcun":(:call_fangcun:),
            "jjf":(:call_jjf:),
            "putuo":(:call_putuo:),
            "lingjie":(:call_lingjie:),
            "mojiao":(:call_mojiao:),
            "hell":(:call_hell:),
            "longgong":(:call_longgong:),
            "wdd":(:call_wdd:),
           // "gift":(:give_dan:),
            "faguan":(:give_bonnet:),
            "bonnet":(:give_bonnet:),
]));
        setup();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
}
}

int call_moon()
{
  object who=this_player();
        if ( (string)who->query("family/family_name")=="�¹�") {
           if (this_player()->query("yudian/skills")=="got")
 {
           message_vision("$N����$n����һ����\n",this_object(),this_player());
        command("say �㲻���Ѿ�Ҫ���������𣿲����ˣ�");
return 1;
}
who->set_skill("force",100);
who->set_skill("spells",100);
who->set_skill("literate",100);
who->set_skill("dodge",100);
who->set_skill("parry",100);
who->set_skill("unarmed",100);
who->set_skill("moonforce",100);
who->set_skill("moonshentong",100);
who->set_skill("moondance",100);
who->set_skill("baihua-zhang",100);
who->set_skill("sword",100);
who->set_skill("snowsword",100);
who->set_skill("whip",100);
who->set_skill("blade",100);
who->set_skill("xuanhu-blade",100);
who->set_skill("jueqingbian",100);
who->map_skill("spells", "moonshentong");
who->map_skill("force", "moonforce");
message_vision("���������������������!��\n",this_object(),this_player());
         command("say ok�ˣ�");
who->set("yudian/skills","got");
return 1;
}
}

int call_huoyundong()
{
   object who=this_player();
        if ( (string)who->query("family/family_name")=="���ƶ�"){
            if (this_player()->query("yudian/skills")=="got")
  {
            message_vision("$N����$n����һ����\n",this_object(),this_player());
         command("say �㲻���Ѿ�Ҫ���������𣿲����ˣ�");
 return 1;
}
  who->set_skill("force",100);
  who->set_skill("spear",100);
  who->set_skill("huoyun-qiang",100);
  who->set_skill("dali-bang",100);
  who->set_skill("dodge",100);
  who->set_skill("huomoforce",100);
  who->set_skill("moyun-shou",100);
  who->set_skill("parry",100);
  who->set_skill("pingtian-dafa",100);
  who->set_skill("spells",100);
  who->set_skill("stick",100);
  who->set_skill("unarmed",100);
  who->set_skill("moshenbu",100);
  who->set_skill("literate",100);
  who->map_skill("spells", "pingtian-dafa");
  who->map_skill("force", "huomoforce");
  message_vision("���������������������!��\n",this_object(),this_player());
          command("say ok�ˣ�");
 who->set("yudian/skills","got");
 return 1;
 }
}

int call_fangcun()
 {
    object who=this_player();
        if ( (string)who->query("family/family_name")=="����ɽ���Ƕ�"){
             if (this_player()->query("yudian/skills")=="got")
   {
            message_vision("$N����$n����һ����\n",this_object(),this_player());
         command("say �㲻���Ѿ�Ҫ���������𣿲����ˣ�");
return 1;
  }
 who->set_skill("force",100);
 who->set_skill("spells",100);
 who->set_skill("literate",100);
 who->set_skill("dodge",100);
 who->set_skill("parry",100);
 who->set_skill("unarmed",100);
 who->set_skill("wuxiangforce",100);
 who->set_skill("dao",100);
 who->set_skill("jindouyun",100);
 who->set_skill("puti-zhi",100);
 who->set_skill("sword",100);
 who->set_skill("liangyi-sword",100);
 who->set_skill("qianjun-bang",100);
 who->set_skill("stick",100);
 who->map_skill("force", "wuxiangforce");
 who->map_skill("spells", "dao");
 message_vision("���������������������!��\n",this_object(),this_player());
          command("say ok�ˣ�");
 who->set("yudian/skills","got");
return 1;
}}


int give_dan()
{
object dan;
object who=this_player();
         if (this_player()->query("yudian/gift")=="got")
{
          message_vision("$N����$n����һ����\n",this_object(),this_player());
       command("say ����ֻ��һ�ݣ�����Ͳ����ˣ�");
  return 1;
}
//    dan=new("/u/yudian/obj/new_dan");
//    dan->move(who);
//message_vision("$N����������������!\n$N��$nһ�����ɾ�����ң����\n",this_object(),this_player());
who->add("combat_exp",10000);
who->add("daoxing",10000);
who->add("potential",200000);
message_vision("$N����������������!\n$N��һָ��$nֻ����������Ѫ���ڣ��ƺ���ѧ�����ж�����������\n",this_object(),this_player());
     who->set("yudian/gift","got");
return 1;
}


int call_putuo()
   {
     object who=this_player();
        if ( (string)who->query("family/family_name")=="�Ϻ�����ɽ"){
              if (this_player()->query("yudian/skills")=="got")
   {
            message_vision("$N����$n����һ����\n",this_object(),this_player());
        command("say �㲻���Ѿ�Ҫ���������𣿲����ˣ�");
return 1;
    }
  who->set_skill("force",100);
  who->set_skill("spells",100);
  who->set_skill("literate",100);
  who->set_skill("dodge",100);
  who->set_skill("parry",100);
  who->set_skill("unarmed",100);
  who->set_skill("jienan-zhi",100);
  who->set_skill("huadao",100);
  who->set_skill("lotusforce",100);
  who->set_skill("buddhism",100);
  who->set_skill("lotusmove",100);
  who->set_skill("staff",100);
  who->set_skill("lunhui-zhang",100);
  who->map_skill("spells", "buddhism");
  who->map_skill("force", "lotusforce");
  message_vision("���������������������!��\n",this_object(),this_player());
           command("say ok�ˣ�");
  who->set("yudian/skills","got");
return 1;
}
}

int call_longgong()
    {
       object who=this_player();
        if ( (string)who->query("family/family_name")=="��������"){
                if (this_player()->query("yudian/skills")=="got")
    {
             message_vision("$N����$n����һ����\n",this_object(),this_player());
        command("say �㲻���Ѿ�Ҫ���������𣿲����ˣ�");
 return 1;
    }
 who->set_skill("force",100);
 who->set_skill("spells",100);
 who->set_skill("literate",100);
 who->set_skill("dodge",100);
 who->set_skill("parry",100);
 who->set_skill("unarmed",100);
 who->set_skill("dragonforce",100);
 who->set_skill("seashentong",100);
 who->set_skill("dragonstep",100);
 who->set_skill("dragonfight",100);
 who->set_skill("fork",100);
 who->set_skill("hammer",100);
 who->set_skill("huntian-hammer",100);
 who->set_skill("fengbo-cha",100);
 who->map_skill("force", "dragonforce");
 who->map_skill("spells", "seashentong");
     message_vision("���������������������!��\n",this_object(),this_player());
            command("say ok�ˣ�");
 who->set("yudian/skills","got");
 return 1;
}}
void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
  say(name()+"���ص�˵������Ҫ���������Ұ�����������ֻ��һ�λ���Ŷ����������\n");
}


int call_wdd()
 {
   object who=this_player();
        if ( (string)who->query("family/family_name")=="�ݿ�ɽ�޵׶�"){
            if (this_player()->query("yudian/skills")=="got")
  {
            message_vision("$N����$n����һ����\n",this_object(),this_player());
         command("say �㲻���Ѿ�Ҫ���������𣿲����ˣ�");
return 1;
 }
 who->set_skill("force",100);
 who->set_skill("spells",100);
 who->set_skill("literate",100);
 who->set_skill("dodge",100);
 who->set_skill("parry",100);
 who->set_skill("unarmed",100);
 who->set_skill("huntian-qigong",100);
 who->set_skill("yaofa",100);
 who->set_skill("throwing",100);
 who->set_skill("lingfu-steps",100);
 who->set_skill("yinfeng-zhua",100);
 who->set_skill("kugu-blade",100);
 who->set_skill("qixiu-jian",100);
 who->set_skill("sword",100);
 who->set_skill("blade",100);
 who->map_skill("spells", "yaofa");
 who->map_skill("force", "huntian-qigong");
 message_vision("���������������������!��\n",this_object(),this_player());
        command("say ok�ˣ�");
 who->set("yudian/skills","got");
 return 1;
}}


int call_xueshan()
 {
   object who=this_player();
        if ( (string)who->query("family/family_name")=="��ѩɽ"){
            if (this_player()->query("yudian/skills")=="got")
  {
            message_vision("$N����$n����һ����\n",this_object(),this_player());
          command("say �㲻���Ѿ�Ҫ���������𣿲����ˣ�");
  return 1;
 }
 who->set_skill("force",100);
 who->set_skill("spells",100);
 who->set_skill("dodge",100);
 who->set_skill("parry",100);
 who->set_skill("unarmed",100);
 who->set_skill("literate",100);
 who->set_skill("xiaoyaoyou",100);
 who->set_skill("throwing",100);
 who->set_skill("ningxie-force",100);
 who->set_skill("dengxian-dafa",100);
 who->set_skill("cuixin-zhang",100);
 who->set_skill("bainiao-jian",100);
 who->set_skill("sword",100);
 who->set_skill("bingpo-blade",100);
 who->set_skill("blade",100);
 who->map_skill("force", "ningxie-force");
 who->map_skill("spells", "dengxian-dafa");
 message_vision("���������������������!��\n",this_object(),this_player());
          command("say ok�ˣ�");
 who->set("yudian/skills","got");
 return 1;
}}


int call_hell()
  {
    object who=this_player();
        if ( (string)who->query("family/family_name")=="���޵ظ�"){
            if (this_player()->query("yudian/skills")=="got")
  {
            message_vision("$N����$n����һ����\n",this_object(),this_player());
        command("say �㲻���Ѿ�Ҫ���������𣿲����ˣ�");
return 1;
}
  who->set_skill("force",100);
  who->set_skill("spells",100);
  who->set_skill("dodge",100);
  who->set_skill("literate",100);
  who->set_skill("parry",100);
  who->set_skill("unarmed",100);
  who->set_skill("ghost-steps",100);
  who->set_skill("gouhunshu",100);
  who->set_skill("tonsillit",100);
  who->set_skill("kusang-bang",100);
  who->set_skill("hellfire-whip",100);
  who->set_skill("jinghun-zhang",100);
  who->set_skill("zhuihun-sword",100);
  who->set_skill("sword",100);
  who->set_skill("stick",100);
  who->set_skill("whip",100);
  who->map_skill("force", "tonsillit");
  who->map_skill("spells", "gouhunshu");
  message_vision("���������������������!��\n",this_object(),this_player());
         command("say ok�ˣ�");
  who->set("yudian/skills","got");
return 1;
}

}
int call_wzg()
{
  object who=this_player();
        if ( (string)who->query("family/family_name")=="��ׯ��"){
           if (this_player()->query("yudian/skills")=="got")
{
           message_vision("$N����$n����һ����\n",this_object(),this_player());
         command("say �㲻���Ѿ�Ҫ���������𣿲����ˣ�");
 return 1;
  }
who->set_skill("force",100);
who->set_skill("spells",100);
who->set_skill("dodge",100);
who->set_skill("literate",100);
who->set_skill("parry",100);
who->set_skill("unarmed",100);
who->set_skill("baguazhen",100);
who->set_skill("taiyi",100);
who->set_skill("zhenyuan-force",100);
who->set_skill("wuxing-quan",100);
who->set_skill("kaishan-chui",100);
who->set_skill("hammer",100);
who->set_skill("fumo-zhang",100);
who->set_skill("staff",100);
who->set_skill("xiaofeng-sword",100);
who->set_skill("sword",100);
who->set_skill("yange-blade",100);
who->set_skill("blade",100);
who->set_skill("sanqing-jian",100);
who->map_skill("force", "zhenyuan-force");
who->map_skill("spells", "taiyi");
message_vision("���������������������!��\n",this_object(),this_player());
          command("say ok�ˣ�");
who->set("yudian/skills","got");
return 1;
}}

int call_wusheng()
{
  object who=this_player();
        if ( (string)who->query("family/family_name")=="��ʥ��") {
           if (this_player()->query("yudian/skills")=="got")
 {
           message_vision("$N����$n����һ����\n",this_object(),this_player());
        command("say �㲻���Ѿ�Ҫ���������𣿲����ˣ�");
return 1;
}
who->set_skill("dodge",100);
who->set_skill("feisheng",100);
who->set_skill("force",100);
who->set_skill("fumobashi",100);
who->set_skill("literate",100);
who->set_skill("mizongbu",100);
who->set_skill("parry",100);
who->set_skill("spells",6100);
who->set_skill("sword",100);
who->set_skill("unarmed",100);
who->set_skill("wuying",100);
who->set_skill("xiantian",100);
who->map_skill("spells", "feisheng");
who->map_skill("force", "xiantian");
message_vision("���������������������!��\n",this_object(),this_player());
         command("say ok�ˣ�");
who->set("yudian/skills","got");
return 1;
}}

int call_tianpeng()
{
  object who=this_player();
        if ( (string)who->query("family/family_name")=="����˧��") {
           if (this_player()->query("yudian/skills")=="got")
 {
           message_vision("$N����$n����һ����\n",this_object(),this_player());
        command("say �㲻���Ѿ�Ҫ���������𣿲����ˣ�");
return 1;
}
who->set_skill("bajie-force",100);
who->set_skill("chaos-steps",100);
who->set_skill("dodge",100);
who->set_skill("fofa",100);
who->set_skill("force",100);
who->set_skill("literate",100);
who->set_skill("parry",100);
who->set_skill("rake",100);
who->set_skill("skyriver-rake",100);
who->set_skill("spells",100);
who->set_skill("unarmed",100);
who->set_skill("tianpeng-zhang",100);
who->map_skill("spells", "fofa");
who->map_skill("force", "bajie-force");
message_vision("���������������������!��\n",this_object(),this_player());
         command("say ok�ˣ�");
who->set("yudian/skills","got");
return 1;
}}

int call_shenjian()
{
  object who=this_player();
        if ( (string)who->query("family/family_name")=="��ɽׯ") {
           if (this_player()->query("yudian/skills")=="got")
 {
           message_vision("$N����$n����һ����\n",this_object(),this_player());
        command("say �㲻���Ѿ�Ҫ���������𣿲����ˣ�");
return 1;
}
who->set_skill("force",60);
who->set_skill("spells",60);
who->set_skill("literate",60);
who->set_skill("dodge",60);
who->set_skill("parry",60);
who->set_skill("unarmed",60);
who->set_skill("cloudforce",60);
who->set_skill("xueying-xianfa",60);
who->set_skill("shadowsteps",60);
who->set_skill("shenji-blade",60);
who->set_skill("sword",60);
who->set_skill("lianhuan-zhang",60);
who->set_skill("duo-sword",60);
who->set_skill("blade",60);
who->set_skill("qingfeng-jian",60);
who->map_skill("spells", "xueying-xianfa");
who->map_skill("force", "cloudforce");
message_vision("���������������������!��\n",this_object(),this_player());
         command("say ok�ˣ�");
who->set("yudian/skills","got");
return 1;
}}

int call_pansi()
{
  object who=this_player();
        if ( (string)who->query("family/family_name")=="��˿��") {
           if (this_player()->query("yudian/skills")=="got")
 {
           message_vision("$N����$n����һ����\n",this_object(),this_player());
        command("say �㲻���Ѿ�Ҫ���������𣿲����ˣ�");
return 1;
}
who->set_skill("dodge",100);
who->set_skill("force",100);
who->set_skill("jiuyin-xinjing",100);
who->set_skill("lanhua-shou",100);
who->set_skill("literate",100);
who->set_skill("pansi-dafa",100);
who->set_skill("parry",100);
who->set_skill("qingxia-jian",100);
who->set_skill("spells",100);
who->set_skill("sword",100);
who->set_skill("unarmed",100);
who->set_skill("whip",100);
who->set_skill("yinsuo-jinling",100);
who->set_skill("yueying-wubu",100);
who->set_skill("chixin-jian",100);
who->set_skill("qin",100);
who->map_skill("spells", "pansi-dafa");
who->map_skill("force", "jiuyin-xinjing");
message_vision("���������������������!��\n",this_object(),this_player());
         command("say ok�ˣ�");
who->set("yudian/skills","got");
return 1;
}}

int call_wudang()
{
  object who=this_player();
        if ( (string)who->query("family/family_name")=="�䵱��") {
           if (this_player()->query("yudian/skills")=="got")
 {
           message_vision("$N����$n����һ����\n",this_object(),this_player());
        command("say �㲻���Ѿ�Ҫ���������𣿲����ˣ�");
return 1;
}
who->set_skill("force",60);
who->set_skill("spells",60);
who->set_skill("literate",60);
who->set_skill("dodge",60);
who->set_skill("parry",60);
who->set_skill("unarmed",60);
who->set_skill("wudang-force",60);
who->set_skill("wudang-xianfa",60);
who->set_skill("taiji-quan",60);
who->set_skill("taiji-jian",60);
who->set_skill("wudang-jian",60);
who->set_skill("sword",60);
who->set_skill("tiyunzong",60);
who->set_skill("liangyi-jian",60);
who->map_skill("spells", "wudang-xianfa");
who->map_skill("force", "wudang-force");
message_vision("���������������������!��\n",this_object(),this_player());
         command("say ok�ˣ�");
who->set("yudian/skills","got");
return 1;
}}

int call_shushan()
{
  object who=this_player();
        if ( (string)who->query("family/family_name")=="��ɽ��") {
           if (this_player()->query("yudian/skills")=="got")
 {
           message_vision("$N����$n����һ����\n",this_object(),this_player());
        command("say �㲻���Ѿ�Ҫ���������𣿲����ˣ�");
return 1;
}
who->set_skill("dodge",100);
who->set_skill("force",100);
who->set_skill("fumozhang",100);
who->set_skill("literate",100);
who->set_skill("parry",100);
who->set_skill("shushan-force",100);
who->set_skill("songhe-sword",100);
who->set_skill("spells",100);
who->set_skill("sword",100);
who->set_skill("unarmed",100);
who->set_skill("xianfeng-spells",100);
who->set_skill("shushan-jianfa",100);
who->set_skill("zuixian-steps",100);
who->set_skill("yirubian",100);
who->set_skill("whip",100);
who->map_skill("spells", "xianfeng-spells");
who->map_skill("force", "shushan-force");
message_vision("���������������������!��\n",this_object(),this_player());
         command("say ok�ˣ�");
who->set("yudian/skills","got");
return 1;
}}
/*
int call_shaolin()
{
  object who=this_player();
        if ( (string)who->query("family/family_name")=="������") {
           if (this_player()->query("yudian/skills")=="got")
 {
           message_vision("$N����$n����һ����\n",this_object(),this_player());
        command("say �㲻���Ѿ�Ҫ���������𣿲����ˣ�");
return 1;
}
who->set_skill("force",60);
who->set_skill("spells",60);
who->set_skill("literate",60);
who->set_skill("dodge",60);
who->set_skill("parry",60);
who->set_skill("unarmed",60);
who->set_skill("sword",60);
who->set_skill("blade",60);
who->map_skill("spells", "moonshentong");
who->map_skill("force", "moonforce");
message_vision("���������������������!��\n",this_object(),this_player());
         command("say ok�ˣ�");
who->set("yudian/skills","got");
return 1;
}}

*/

int call_jjf()
  {
   object who=this_player();
        if ( (string)who->query("family/family_name")=="������"){
            if (this_player()->query("yudian/skills")=="got")
   {
            message_vision("$N����$n����һ����\n",this_object(),this_player());
        command("say �㲻���Ѿ�Ҫ���������𣿲����ˣ�");
return 1;
 }
 who->set_skill("force",100);
 who->set_skill("spells",100);
 who->set_skill("dodge",100);
 who->set_skill("parry",100);
 who->set_skill("unarmed",100);
 who->set_skill("literate",100);
 who->set_skill("archery",100);
 who->set_skill("bawang-qiang",100);
 who->set_skill("jinglei-mace",100);
 who->set_skill("changquan",100);
 who->set_skill("lengquan-force",100);
 who->set_skill("mace",100);
 who->set_skill("spear",100);
 who->set_skill("wusi-mace",100);
 who->set_skill("yanxing-steps",100);
 who->set_skill("baguazhou",100);
 who->map_skill("force", "lengquan-force");
 who->map_skill("spells", "baguazhou");
 message_vision("���������������������!��\n",this_object(),this_player());
         command("say ok�ˣ�");
 who->set("yudian/skills","got");
return 1;
}}

int call_lingjie()
  {
   object who=this_player();
        if ( (string)who->query("family/family_name")=="���"){
            if (this_player()->query("yudian/skills")=="got")
   {
            message_vision("$N����$n����һ����\n",this_object(),this_player());
        command("say �㲻���Ѿ�Ҫ���������𣿲����ˣ�");
return 1;
 }
 who->set_skill("force",100);
 who->set_skill("spells",100);
 who->set_skill("dodge",100);
 who->set_skill("parry",100);
 who->set_skill("unarmed",100);
 who->set_skill("literate",100);
 who->set_skill("fengtian-steps",100);
 who->set_skill("guangming-force",100);
 who->set_skill("guangming-shouyin",100);
 who->set_skill("kongming-spells",100);
 who->set_skill("lingfan-san",100);
 who->set_skill("umbrella",100);
 who->map_skill("force", "guangming-force");
 who->map_skill("spells", "kongming-spells");
 message_vision("���������������������!��\n",this_object(),this_player());
         command("say ok�ˣ�");
 who->set("yudian/skills","got");
return 1;
}}

int call_mojiao()
  {
   object who=this_player();
        if ( (string)who->query("family/family_name")=="ħ��"){
            if (this_player()->query("yudian/skills")=="got")
   {
            message_vision("$N����$n����һ����\n",this_object(),this_player());
        command("say �㲻���Ѿ�Ҫ���������𣿲����ˣ�");
return 1;
 }
 who->set_skill("force",100);
 who->set_skill("spells",100);
 who->set_skill("dodge",100);
 who->set_skill("parry",100);
 who->set_skill("tigerfight",100);
 who->set_skill("unarmed",100);
 who->set_skill("blade",100);
 who->set_skill("literate",100);
 who->set_skill("dimo-steps",100);
 who->set_skill("evil-force",100);
 who->set_skill("tianxian-sword",100);
 who->set_skill("tianmo-blade",100);
 who->set_skill("tianmo",100);
 who->set_skill("nature",100);
 who->map_skill("force", "evil-force");
 who->map_skill("spells", "tianmo");
 message_vision("���������������������!��\n",this_object(),this_player());
         command("say ok�ˣ�");
 who->set("yudian/skills","got");
return 1;
}}

int give_bonnet()
 {
 object bonnet;
 object who=this_player();
          if (this_player()->query("yudian/bonnet")=="got")
 {
           message_vision("$N����$n����һ����\n",this_object(),this_player());
          command("say �ϴθ���Ļ�û���أ������ˣ�");
   return 1;
  }
      bonnet=new("/d/lingtai/obj/faguan");
  bonnet->move(who);
  message_vision("$N����������������!����ձ��һ����ʦ���ڡ�\n$N��$nһ����ʦ���ڡ�\n",this_object(),this_player());
         //  command("say �����˼ǵû���Ŷ�������´β����ˣ�");
 return 1;
  }


