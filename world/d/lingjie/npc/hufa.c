inherit NPC;
#include <ansi.h>

void create()
{
        set_name("��绤��", ({ "hufa","hu", "fa" }));
        set("title", HIR "�������" NOR);
        set("gender", "����");
        set("age", random(20) + 20);
        set("str", 50);
        set("con", 30);
        set("spi", 40);
        set("dex", 40);
        set("int", 40);
        set("long", "���������ݣ�ɱ�����ڣ��������ı���������\n");
        set("combat_exp", 2500000);
        set("daoxing", 2500000);
        set("class", "hufa");
        set("attitude", "herosim");
        set_skill("unarmed", 150);
        set_skill("force", 160);
        set_skill("umbrella", 180);
        set_skill("dodge", 150);
        set_skill("parry", 170);
        set_skill("lingfan-san", 200);
        map_skill("umbrella", "lingfan-san");
        map_skill("parry", "lingfan-san");
        set("max_kee", 2000);
        set("max_sen", 2000);
        set("force", 3000); 
        set("max_force", 2500);
        set("force_factor", 200);
        set("max_mana", 2500);
        set("mana", 3000);
        set("mana_factor", 210);
        setup();
        carry_object("/d/lingjie/obj/hufa")->wield();
        carry_object("/d/obj/armor/jinjia")->wear();
}

int accept_fight(object me)
{
        message_vision("��绤����$N����һ�ɣ��ȵ����㣬��������������\n\n", me);
        return 0;
}

int heal_up()
{

        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{
        object stone;

        this_object()->add("time", 1);
        if( (int)this_object()->query("time") >= 3 ) {
        message("vision",name() + "ĥ��ĥ����������´α�б���ү������
��绤�����˳�ȥ��\n", environment(),this_object() );
        destruct(this_object());

        }
        return;
}

void die()
{

        object ob;
        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
        if (ob){
        CHANNEL_D->do_channel(this_object(),"chat",sprintf("%s��Ǯɱ��,���ĵ���Ҫ��Ϊ���Ǳ���Ϊ����ѽ��",ob->name(1)));
        ::die();}

    
}

