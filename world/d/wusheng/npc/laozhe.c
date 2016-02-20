// laozhe.c

#include <ansi.h>

inherit NPC;
int rank_me();
string ask_mieyao(object me);
string ask_cancel();

void create()
{
       set_name(HIG"����"NOR, ({"lao zhe", "laozhe"}));
       set("long", "һ�����е����˼ң��������³�����\n");
       set("title", HIC"�����"NOR);
       set("gender", "����");
       set("age", 1000);
       set("class", "wusheng");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "����");
       set("looking", "Ӣ�������������ٷ磬�������Ρ�");
       set("max_kee", 1000);
       set("max_gin", 100);
       set("max_sen", 1000);
       set("force", 1000);
       set("max_force", 500);
       set("force_factor", 10);
       set("max_mana", 500);
       set("mana", 1000);
       set("mana_factor", 10);
       set("combat_exp", 500000);
       set("daoxing", 1100000);

        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("spells", 100);  
        set_skill("feisheng", 100);
        set_skill("literate", 100);
        set_skill("sword", 100);  
        set_skill("wuying", 100);
        set_skill("fumobashi", 100);  
        set_skill("mizongbu", 100);
        set_skill("dodge", 100);  
        set_skill("force", 100);   
        set_skill("xiantian", 100);

        map_skill("spells", "feisheng");
        map_skill("unarmed", "fumobashi");
        map_skill("force", "xiantian");
        map_skill("sword", "wuying");
        map_skill("parry", "wuying");
        map_skill("dodge", "mizongbu");
        create_family("��ʥ��", 2, "����");

   set("inquiry", ([
//          "����" : (: avenge :),
//		  "��������" : (: give_zui :),
           "����": (: ask_mieyao :),
           "cancel": (: ask_cancel :),
		   "ְλ": (: rank_me :),
]));
	setup();
	carry_object("/d/obj/armor/jinjia")->wear();

}
int rank_me()
{
        object me=this_player();
        int exp;
        exp=(int)me->query("combat_exp");
        if( me->query("title") == "����")
		return notify_fail("���Ѿ����������ˣ�����Ҫʲôְλ��\n");
        if( (string)me->query("family/family_name") == "��ʥ��"){
                if( exp <= 100000 ){
                        me->set("title", WHT"��ʥ��"HIG"������"NOR);
                 } else if(exp < 1000000 ){
                        me->set("title", WHT"��ʥ��"HIG"�����޺�"NOR);
                 } else if(exp < 2000000 ){
                        me->set("title", WHT"��ʥ��"HIG"���ɽ��"NOR);
                 } else if(exp < 3000000 ){
                        me->set("title", WHT"��ʥ��"HIG"��������"NOR);
                } else {
                        me->set("title", WHT"��ʥ��"HIG"�������"NOR);
                }

                tell_object(me, "���߶���˵���������"+me->query("title")+"��\n");
                tell_room(environment(me),
"���߶�"+me->query("name")+"˵���������"+me->query("title")+"��\n", ({me, me}));
         CHANNEL_D->do_channel(me,"chat","�����豾�ŵ���"+me->query("name")+""+me->query("title")+"һְ�������λ�ɳ����������");
     me->save();  
        }
        return 1;
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
string ask_mieyao(object me)
{
    me=this_player();
     if((string)me->query("family/family_name")=="��ʥ��") {
    tell_room(environment(me),"����˵��.....\n");
    return "/d/obj/mieyao"->query_yao(me);
}
     return ("�Ϸ�֪������˵Щʲô��");
}


�
