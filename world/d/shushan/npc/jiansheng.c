//jiansheng.c by yushu 2000.11
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int rank_me();
string kick_back();
void create()
{
       set_name("��ɽ�ɽ�ʥ", ({"shushan jiansheng","jiansheng", "master"}));
       set("title", "��ɽ����ʦ");
       set("gender", "����");
       set("age", 120);
        set("class", "xiake");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "��ʦ��");
       set("per", 26);
       set("looking", "�������󣬲������Ʈ���𾦷ɻ��棬��Ŀ��ü�ҡ�");
       set("int", 30);
       set("max_kee", 4500);
       set("max_gin", 800);
       set("max_sen", 4500);
       set("force", 4000);
       set("max_force", 2000);
       set("force_factor", 125);
       set("max_mana", 2000);
       set("mana", 4000);
       set("mana_factor", 100);
       set("combat_exp", 2000000);
       set_skill("literate", 200);
       set_skill("dodge", 190);
       set_skill("parry", 200);
       set_skill("whip", 210);
       set_skill("fumozhang", 190);
       set_skill("unarmed", 200);
       set_skill("sword", 200);
       set_skill("songhe-sword", 200);
       set_skill("spells", 190);
       set_skill("xianfeng-spells", 210);
       set_skill("yujianshu",180);
       set_skill("shushan-force", 200);

       set_skill("force", 200);
       set_skill("zuixian-steps", 190);
         map_skill("spells", "xiaofeng-spells");
       map_skill("force", "shushan-force");
       map_skill("unarmed", "fumozhang");
       map_skill("sword", "yujianshu");
       map_skill("spells","xianfeng-spells");
       map_skill("parry", "yujianshu");
       map_skill("dodge", "zuixian-steps");
       map_skill("whip", "yirubian");
        set("inquiry", ([
        "��ȥ"    : (: kick_back :),
        "back"  : (: kick_back :),
         "ְλ": (: rank_me :),
       ]) );
       set("chat_chance_combat", 60);
       set("chat_msg_combat", ({
                  (: cast_spell, "fu" :),
                (: perform_action, "sword", "fumo" :),
        }) );
        create_family("��ɽ��", 1, "����");
        setup();

//  carry_object("/d/obj/cloth/mangpao")->wear();
// carry_object("/d/shushan/obj/jueshi")->wield();
}
string kick_back()
{
    object me=this_player();
    message_vision(HIC"$n˵�������������˵���������������\n"NOR, me, this_object());
    me->move("/d/shushan/woshi");
    message_vision(HIC"$N�����Լ��Ѿ��������������������\n"NOR, me);
    return "";
}
int rank_me()
{
        object me=this_player();
        int exp;
        exp=(int)me->query("combat_exp");
        if( me->query("title") == "��ɽ�������Ŵ�ʦ��")
		return notify_fail("���Ѿ����������ˣ�����Ҫʲôְλ��\n");
        if( (string)me->query("family/family_name") == "��ɽ��"){
                if( exp <= 100000 ){
                        me->set("title", HIC"��ɽ����"HIR"ӭ�ͽ�ͯ"NOR);
                } else if(exp <= 1000000 ){
                        me->set("title", HIC"��ɽ����"HIR"ն������"NOR);
                } else if(exp < 2000000 ){
                        me->set("title", HIC"��ɽ����"HIR"��ħ����"NOR);
                } else if(exp <= 3000000 ){
                        me->set("title", HIC"��ɽ����"HIR"���Ľ���"NOR);
                } else {
                        me->set("title", HIC"��ɽ����"HIR"ͨ�콣ʥ"NOR);
                }

                tell_object(me, "��ɽ�ɽ�ʥ����˵���������"+me->query("title")+"��\n");
                tell_room(environment(me),
"��ɽ�ɽ�ʥ��"+me->query("name")+"˵���������"+me->query("title")+"��\n", ({me, me}));
         CHANNEL_D->do_channel(me,"chat","�����豾�ŵ���"+me->query("name")+""+me->query("title")+"һְ�������λ�ɳ����������");
     me->save();  
        }
        return 1;
}
void attempt_apprentice(object ob)
{       ob=this_player();
        if( (string)ob->query("family/family_name")=="��ɽ��") {
        if ((int)ob->query("daoxing") < 200000 ) {
        command("say ��ĵ��л����������ҵ��з���������\n");
        return;
        }
       if( (int)ob->query_skill("xianfeng-spells", 1) < 160 ) {
        command("say ��λ" + RANK_D->query_respect(ob) + "����ɷ����������������,�㻹���Ҿƽ������Ű�!\n");
        command("sigh");
        return;
        }
        command("smile");
        command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձض��гɡ�");
        command("recruit " + ob->query("id") );
        return;
        }
        command("shake");
        command("say ���Ǳ��ɵ���?��" + RANK_D->query_respect(ob) + "������Ѱ���˰ɣ�\n");
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "xiake");
                ob->set("title", "��ɽ��ʥ�״�����");

}

        return 0;
}

