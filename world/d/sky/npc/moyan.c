// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// tianwang.c
#include <ansi.h>
inherit NPC;
string send_me(object me);
void create()
{
        set_name(HIB"Ī��"NOR, ({ "mo yan", "moyan", "mo" }) );
        set("gender", "Ů��" );
   set("long",
     "������Ӱ������,�����һ���ǻ᳡���ػ��ߡ� \n"
     "����һλ������Ů��,��ô�����ö���ɥ���ķ���ʹ���أ��� ��֪���书��������\n"
   );
   set("age",14);
   set("title",HIR "����ʹ��"NOR);
   set("attitude", "peaceful");
   set("str",40);
   set("int",30);
   set("max_kee",11000);
   set("kee",11000);
   set("max_sen",11000);
   set("sen",11000);
   set("combat_exp",10000000);
   set("force",25000);
   set("max_force",15000);
   set("mana",25000);
   set("max_mana",16000);
   set("force_factor", 180);
   set("mana_factor",180);
   set("eff_dx", 4500000);
   set("nkgain", 5000);
   set_skill("unarmed",250);
   set_skill("yingzhaogong", 250);
   set_skill("parry",250);
   set_skill("dodge",250);
   set_skill("sword",250);
   set_skill("snowsword",250);
   set_skill("force",150);
   set_skill("spells", 150);
   set_skill("moshenbu", 250);
   map_skill("dodge", "moshenbu");
   map_skill("parry", "snowsword");
   map_skill("sword","snowsword");
   map_skill("unarmed", "yingzhaogong");
   set("inquiry", ([
     "name" : "Ī�Է����ڴ˽Ӵ�������Ա��",
     "here" : "�������������, ���ھ��Ǳ��䳡�ˡ�",
     "��ȥ": (: send_me :),
     "back": (: send_me:),
   ]) );

   setup();
   carry_object("/d/obj/weapon/sword/snow_sword")->wield();
   carry_object("/d/obj/cloth/luoyi")->wear();
}

string send_me(object me)
{
        me=this_player();
           if( me->is_fighting() )
     return ("���������鷳�����Ҫ���㣡\n");
        if( me->is_busy() || me->query_temp("pending/exercising"))
     return ("æ����˵�ɡ�����\n");

   message_vision("Ī�Կ���$Nһ�ۣ���$N˵��������ͻ�ȥ�ɣ�\n", me);
   message_vision("Ī��һ�Ű�$N������ȥ������\n", me);
        me->move("/d/changan/nbridge");
   tell_room( environment(me), "�����ˡ�һ���������ϵ��¸�������\n", ({me}));
   write("�������ˤ�����������˸��������ף�\n");
   return ("�������������������\n");
}

 void init()
{
        add_action("do_enter", "enter");
}
int do_enter()
{
        object me;
        me = this_player();
            if( ! me->query("marks/���Ʒ�����"))
             {
                command("say û�����Ʒ�����κ��˲��ܽ���᳡��");
                write("�����ӵ�����Ʒ�������ܽ��� ��\n");
                return 1;
             }
            else
                return 0;
}
int accept_object(object who, object ob)
{
        if ( (string)ob->name() != "���Ʒ�����")
        command("say û�����Ʒ�����κ��˲��ܽ���᳡��");
        if ( (string)ob->name() == "���Ʒ�����")
        who->set("marks/���Ʒ�����",1);
        write(HIW"��ϲ��! ���Բμ�ˮ½�����, ���!"HIR);
        if ( ob->query("id") != "ling")
        {
                command("say ����ʲô������������͵��ȥ��ʲô��");
                return 0;
        }
        ob->destruct();
        return 1;
}

