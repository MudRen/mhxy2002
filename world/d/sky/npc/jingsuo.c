// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// tianwang.c
#include <ansi.h>
inherit F_VENDOR_SALE;

string send_me(object me);
void create()
{
        set_name(HIG"����"NOR, ({ "jinsuo", "jin", "suo" }) );
        set("gender", "Ů��" );
   set("long",
     "������΢������Ѿ��,������۱����볡�� \n"
     "������òʤ����,��������!\n"
     "�书�˵�, ��Ҫ���׺ͽ�����\n"
   );
   set("age",20);
   set("title",HIY "����Ӷ�ʹ"NOR);
   set("attitude", "peaceful");
        set("vendor_goods", ([
                "�볡��": "/obj/example/juan",
        ]) );
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
     "name" : "СŮ�ӽ����������ڴ˽Ӵ�������Ա��",
     "here" : "�������������, ���ھ��Ǳ��䳡�ˡ�",
     "��ȥ": (: send_me :),
     "back": (: send_me:),
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

   message_vision("��������һЦ����$N˵����������������ȥ��\n", me);
   message_vision("����������Ű�$N������ȥ������\n", me);
        me->move("/d/changan/nbridge");
   tell_room( environment(me), "�����ˡ�һ���������ϵ��¸�������\n", ({me}));
   write("�������ˤ�����������˸��������ף�\n");
   return ("�Ϸ��������������\n");
}

