//by tianlin 2001.8.7
//BY tianlin@mhxy for 2001.12.31,����վ��ʦdick�Ľ��������޸� 
inherit NPC;
 
void create()
{
        set_name("�̻�", ({"huang"}));
        set("long", "��˵�е�а��Ľ̻�.\n");
        set("gender","����");
        set("title", "����ħ����");
        set("age",999);
        set("con",12);
        set("per",30);
        set("str",12);
        set("int",12);
        set("combat_exp",3100000);
        set("daoxing",3100000);
        set("chat_chance",20);
        set("chat_msg", ({
                "�̻�˵������ƾ������ͭʥ��ʿҲ���ʮ������\n"   
        }));
        set_skill("dodge", 400);
        set_skill("force", 400);
        set_skill("parry", 400);
        set_skill("unarmed", 400);
        set_skill("sword", 400);
        set_skill("westsword",400);
        set_skill("boxing",400);
        set_skill("balei",400);
        set_skill("spells",400);
        set_skill("yaofa", 400);
        map_skill("unarmed","boxing");
        map_skill("spells","yaofa");
        map_skill("dodge","balei");
        set("max_force", 5000);
        set("force", 5000);
        set("max_mana",4000);
        set("mana",6000);
        set("mana_factor", 130);
        set("force_factor", 100);
        set("max_kee", 2000);
        set("max_gin", 2000);
        set("max_sen", 2000);

        setup();
}
 
