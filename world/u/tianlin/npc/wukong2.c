//By tianlin@Mhxy for 2001.12.30
//����yudian���༭�ļ�������,�޸������û��ʦ����Ҫskills������bug
#include <ansi.h>

inherit NPC;
int call_moon();
int call_wzg();
int call_putuo();
int call_fangcun();
int call_xueshan();
int call_tiankongjie();
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
int call_mojiao();
  int call_lingjie();
int call_shushan();
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
        "tiankongjie":(:call_tiankongjie:),
            "tianpeng":(:call_tianpeng:),
            "shenjian":(:call_shenjian:),
            "pansi":(:call_pansi:),
            "wudang":(:call_wudang:),
 "shushan":(:call_shushan:),
 "mojiao":(:call_mojiao:),
           // "shaolin":(:call_shaolin:),
            "lingjie":(:call_lingjie:),
            "wzg":(:call_wzg:),
            "xueshan":(:call_xueshan:),
            "fangcun":(:call_fangcun:),
            "jjf":(:call_jjf:),
            "putuo":(:call_putuo:),
            "hell":(:call_hell:),
            "longgong":(:call_longgong:),
            "wdd":(:call_wdd:),
            "gift":(:give_dan:),
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
who->set_skill("force",60);
who->set_skill("spells",60);
who->set_skill("literate",60);
who->set_skill("dodge",60);
who->set_skill("parry",60);
who->set_skill("unarmed",60);
who->set_skill("moonforce",60);
who->set_skill("moonshentong",60);
who->set_skill("moondance",60);
who->set_skill("baihua-zhang",60);
who->set_skill("sword",60);
who->set_skill("snowsword",60);
who->set_skill("whip",60);
who->set_skill("blade",60);
who->set_skill("xuanhu-blade",60);
who->set_skill("jueqingbian",60);
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
  who->set_skill("force",60);
  who->set_skill("spear",60);
  who->set_skill("huoyun-qiang",60);
  who->set_skill("dali-bang",60);
  who->set_skill("dodge",60);
  who->set_skill("huomoforce",60);
  who->set_skill("moyun-shou",60);
  who->set_skill("parry",60);
  who->set_skill("pingtian-dafa",60);
  who->set_skill("wuyue-spear",60);
  who->set_skill("liehuo-sword",60);
  who->set_skill("sword",60);
  who->set_skill("spells",60);
  who->set_skill("stick",60);
  who->set_skill("unarmed",60);
  who->set_skill("moshenbu",60);
  who->set_skill("literate",60);
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
 who->set_skill("force",60);
 who->set_skill("spells",60);
 who->set_skill("literate",60);
 who->set_skill("dodge",60);
 who->set_skill("parry",60);
 who->set_skill("unarmed",60);
 who->set_skill("wuxiangforce",60);
 who->set_skill("dao",60);
 who->set_skill("jindouyun",60);
 who->set_skill("puti-zhi",60);
 who->set_skill("sword",60);
 who->set_skill("liangyi-sword",60);
 who->set_skill("qianjun-bang",60);
 who->set_skill("stick",60);
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
who->add("combat_exp",100000);
who->add("daoxing",164000);
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
  who->set_skill("force",60);
  who->set_skill("spells",60);
  who->set_skill("literate",60);
  who->set_skill("dodge",60);
  who->set_skill("parry",60);
  who->set_skill("unarmed",60);
  who->set_skill("jienan-zhi",60);
  who->set_skill("huadao",60);
  who->set_skill("lotusforce",60);
  who->set_skill("buddhism",60);
  who->set_skill("lotusmove",60);
  who->set_skill("staff",60);
  who->set_skill("lunhui-zhang",60);
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
 who->set_skill("force",60);
 who->set_skill("spells",60);
 who->set_skill("literate",60);
 who->set_skill("dodge",60);
 who->set_skill("parry",60);
 who->set_skill("unarmed",60);
 who->set_skill("dragonforce",60);
 who->set_skill("seashentong",60);
 who->set_skill("dragonstep",60);
 who->set_skill("dragonfight",60);
 who->set_skill("fork",60);
 who->set_skill("hammer",60);
 who->set_skill("huntian-hammer",60);
 who->set_skill("fengbo-cha",60);
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
 who->set_skill("force",60);
 who->set_skill("spells",60);
 who->set_skill("literate",60);
 who->set_skill("dodge",60);
 who->set_skill("parry",60);
 who->set_skill("unarmed",60);
 who->set_skill("huntian-qigong",60);
 who->set_skill("yaofa",60);
 who->set_skill("throwing",60);
 who->set_skill("lingfu-steps",60);
 who->set_skill("yinfeng-zhua",60);
 who->set_skill("kugu-blade",60);
 who->set_skill("qixiu-jian",60);
 who->set_skill("sword",60);
 who->set_skill("blade",60);
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
 who->set_skill("force",60);
 who->set_skill("spells",60);
 who->set_skill("dodge",60);
 who->set_skill("parry",60);
 who->set_skill("unarmed",60);
 who->set_skill("literate",60);
 who->set_skill("xiaoyaoyou",60);
 who->set_skill("throwing",60);
 who->set_skill("ningxie-force",60);
 who->set_skill("dengxian-dafa",60);
 who->set_skill("cuixin-zhang",60);
 who->set_skill("bainiao-jian",60);
 who->set_skill("sword",60);
 who->set_skill("bingpo-blade",60);
 who->set_skill("blade",60);
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
  who->set_skill("force",60);
  who->set_skill("spells",60);
  who->set_skill("dodge",60);
  who->set_skill("literate",60);
  who->set_skill("parry",60);
  who->set_skill("unarmed",60);
  who->set_skill("ghost-steps",60);
  who->set_skill("gouhunshu",60);
  who->set_skill("tonsillit",60);
  who->set_skill("kusang-bang",60);
  who->set_skill("hellfire-whip",60);
  who->set_skill("jinghun-zhang",60);
  who->set_skill("zhuihun-sword",60);
  who->set_skill("sword",60);
  who->set_skill("stick",60);
  who->set_skill("whip",60);
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
who->set_skill("force",60);
who->set_skill("spells",60);
who->set_skill("dodge",60);
who->set_skill("literate",60);
who->set_skill("parry",60);
who->set_skill("unarmed",60);
who->set_skill("baguazhen",60);
who->set_skill("taiyi",60);
who->set_skill("zhenyuan-force",60);
who->set_skill("wuxing-quan",60);
who->set_skill("kaishan-chui",60);
who->set_skill("hammer",60);
who->set_skill("fumo-zhang",60);
who->set_skill("staff",60);
who->set_skill("xiaofeng-sword",60);
who->set_skill("sword",60);
who->set_skill("yange-blade",60);
who->set_skill("blade",60);
who->set_skill("sanqing-jian",60);
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
who->set_skill("dodge",60);
who->set_skill("feisheng",60);
who->set_skill("force",60);
who->set_skill("fumobashi",60);
who->set_skill("literate",60);
who->set_skill("mizongbu",60);
who->set_skill("parry",60);
who->set_skill("spells",60);
who->set_skill("sword",60);
who->set_skill("unarmed",60);
who->set_skill("wuying",60);
who->set_skill("xiantian",60);
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
who->set_skill("bajie-force",60);
who->set_skill("chaos-steps",60);
who->set_skill("dodge",60);
who->set_skill("fofa",60);
who->set_skill("force",60);
who->set_skill("literate",60);
who->set_skill("parry",60);
who->set_skill("rake",60);
who->set_skill("skyriver-rake",60);
who->set_skill("spells",60);
who->set_skill("unarmed",60);
who->set_skill("tianpeng-zhang",60);
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
who->set_skill("dodge",60);
who->set_skill("force",60);
who->set_skill("jiuyin-xinjing",60);
who->set_skill("lanhua-shou",60);
who->set_skill("literate",60);
who->set_skill("pansi-dafa",60);
who->set_skill("parry",60);
who->set_skill("qingxia-jian",60);
who->set_skill("spells",60);
who->set_skill("sword",60);
who->set_skill("unarmed",60);
who->set_skill("whip",60);
who->set_skill("yinsuo-jinling",60);
who->set_skill("yueying-wubu",60);
who->set_skill("chixin-jian",60);
who->set_skill("qin",60);
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
who->set_skill("dodge",60);
who->set_skill("force",60);
who->set_skill("fumozhang",60);
who->set_skill("literate",60);
who->set_skill("parry",60);
who->set_skill("shushan-force",60);
who->set_skill("songhe-sword",60);
who->set_skill("spells",60);
who->set_skill("sword",60);
who->set_skill("taoism",60);
who->set_skill("unarmed",60);
who->set_skill("xianfeng-spells",60);
who->set_skill("yujianshu",60);
who->set_skill("zuixian-steps",60);
who->set_skill("yirubian",60);
who->set_skill("whip",60);
who->set_skill("canxin-jian",60);
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
 who->set_skill("force",60);
 who->set_skill("spells",60);
 who->set_skill("dodge",60);
 who->set_skill("parry",60);
 who->set_skill("unarmed",60);
 who->set_skill("literate",60);
 who->set_skill("archery",60);
 who->set_skill("bawang-qiang",60);
 who->set_skill("jinglei-mace",60);
 who->set_skill("changquan",60);
 who->set_skill("lengquan-force",60);
 who->set_skill("mace",60);
 who->set_skill("spear",60);
 who->set_skill("wusi-mace",60);
 who->set_skill("yanxing-steps",60);
 who->set_skill("baguazhou",60);
 who->map_skill("force", "lengquan-force");
 who->map_skill("spells", "baguazhou");
 message_vision("���������������������!��\n",this_object(),this_player());
         command("say ok�ˣ�");
 who->set("yudian/skills","got");
return 1;
}}
 int call_tiankongjie()
{
   object who=this_player();
        if ( (string)who->query("family/family_name")=="��ս�"){
     if (this_player()->query("yudian/skills")=="got")
{
           message_vision("$N����$n����һ����\n",this_object(),this_player());
        command("say �㲻���Ѿ�Ҫ���������𣿲����ˣ�");
return 1;
}
  who->set_skill("force",60);
 who->set_skill("spells",60);
  who->set_skill("dodge",60);
  who->set_skill("parry",60);
  who->set_skill("unarmed",60);
  who->set_skill("literate",60);
  who->set_skill("piaoyun-zhang",60);
 who->set_skill("shouya-force",60);
 who->set_skill("xiaoyao-sword",60);
 who->set_skill("sword",60);
 who->set_skill("shanbishu",60);
 who->set_skill("throwing",60);
  who->set_skill("tianlang-blade",60);
  who->set_skill("heimofa",60);
  who->set_skill("blade",60);
  who->set_skill("baimofa",60);
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


