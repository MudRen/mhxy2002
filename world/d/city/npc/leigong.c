//By tianlin@mhxy for 2002.2.25

inherit NPC;
#include <ansi.h>

void create()
{
       set_name("�׹�", ({"lei gong", "lei", "gong"}));
       set("long", "һ������ܳ��Ĺ��ˣ����г�һ��������\n");
       set("gender", "����");
       set("age", 70);
       set("title", HIY"�칬"HIR"����"NOR);
       set("attitude", "friendly");
       set("per", 30);
       set("max_kee",8000);
       set("max_sen", 8000);
       set("force", 5000);
       set("max_force", 5000);
       set("force_factor", 80);
       set("max_mana", 1200);
       set("mana", 2300);
       set("mana_factor", 20);
       set("combat_exp", 1200000);

       set("eff_dx", 250000);
       set("nkgain", 400);
       set("class","taoist");
       set_skill("literate", 90);
       set_skill("unarmed", 120);
       set_skill("dodge", 120);
       set_skill("parry", 120);
       set_skill("stick", 120);
       set_skill("spells", 120);
       set_skill("dao", 120);
       set_skill("puti-zhi", 120);
       set_skill("wuxiangforce", 120);
       set_skill("force", 120);
       set_skill("qianjun-bang", 120);
       set_skill("jindouyun", 120);
       map_skill("spells", "dao");
       map_skill("unarmed", "puti-zhi");
       map_skill("force", "wuxiangforce");
       map_skill("stick", "qianjun-bang");
       map_skill("parry", "qianjun-bang");
       map_skill("dodge", "jindouyun");
       set("chat_chance_combat", 40);
       set("chat_msg_combat", ({
                (: cast_spell, "thunder" :),
                "�׹�ŭ�������������ҵ�������ġ�\n"
        }) );

        set("inquiry", ([
           "������" : "�����ҵı�����",
]) );

setup();
carry_object("/d/obj/cloth/xianpao")->wear();
carry_object("/d/obj/baowu/leizhu")->wear();
}
void die()
{
 int i;
 object me,*inv;
 if(objectp(me=query_temp("last_damage_from") ))
        {
            inv = all_inventory(this_object());
            for(i=0; i<sizeof(inv); i++)
            {
                if (inv[i]->query("id")=="leizhu" || inv[i]->query("id")=="lei lingzhu")
                {
                   inv[i]->move(me);
                   message_vision("$Nͷ��ð��һ����ɫ�����ӣ�$n��æһ��ץ�����\n",this_object(),me);
            message("channel:rumor",HIG+"��С����Ϣ��ĳ�ˣ���˵"HIY+me->query("name")+HIG"�õ���˵�е�"HIB"������"HIG"�ˣ�\n"+NOR,users());
         }
        }
  }
 ::die();
}

