// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// shangshan.c
#include <ansi.h>
inherit F_VENDOR_SALE;
string ask_me_2();
string send_me(object me);
void create()
{
        set_name(HIG"���"NOR, ({ "qing er", "qinger", "qing" }) );
        set("gender", "Ů��" );
   set("long",
     "�������ŵ�����Ѿ��,�����������Ʒ����� \n"
     "������òʤ����,��������!\n"
     "��������ʹ��,������û���˼��������˽���,��֪�������书��Ρ�\n"
   );
   set("age",20);
   set("title",HIW "����ʹ��"NOR);
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
     "name" : "СŮ��С�࣬�����ڴ˽Ӵ�������Ա��",
     "here" : "�������������, ���ھ��Ǳ��䳡�ˡ�",
     "��ȥ": (: send_me :),
     "back": (: send_me:),
     "���Ʒ�����" :     (: ask_me_2 :)
   
]) );

   setup();
   carry_object("obj/weapon/sword")->wield();
   carry_object("/d/obj/armor/jinjia")->wear();
}

string send_me(object me)
{
        me=this_player();
           if( me->is_fighting() )
     return ("���������鷳�����Ҫ���㣡\n");
        if( me->is_busy() || me->query_temp("pending/exercising"))
     return ("æ����˵�ɡ�����\n");

   message_vision("�������һЦ����$N˵������������������ȥ��\n", me);
   message_vision("С�����һ�Ű�$N������ȥ������\n", me);
        me->move("/d/changan/nbridge");
   tell_room( environment(me), "�����ˡ�һ���������ϵ��¸�������\n", ({me}));
   write("�������ˤ�����������˸��������ף�\n");
   return ("�����������������\n");
}
string ask_me_2()
{
        mapping fam, skl;
        object ob;
        string *sname;
        int i;

     skl = this_player()->query_skills();
        sname  = sort_array( keys(skl), (: strcmp :) );

        for(i=0; i<sizeof(skl); i++) {
                if (skl[sname[i]] < 100)
                return RANK_D->query_respect(this_player()) +
                "����������������ȡ���Ʒ����";
        }

        ob = new("/d/suburb/xkx/shaolin/obj/damo-ling");
        ob->move(this_player());
        message_vision("$N���һ�����ơ�\n",this_player());

        return "�ð�,ƾ�������Ʒ�����,������ɳ�����᳡��";
}
