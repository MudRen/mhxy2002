//famu.c �䵱��ľ��ʿ

inherit NPC;

void create()
{
        set_name("��ľ��ʿ", ({ "famu", "fa mu"}));
        set("long",
                "�����䵱ɽ�ķ�ľ��ʿ��\n");
        set("gender", "����");
        set("age", 20);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("class", "taoist");

        set("str", 20);
        set("int", 20);
        set("con", 22);
        set("dex", 25);

        set("max_kee", 150);
        set("max_sen", 100);
        set("force", 150);
        set("max_force", 150);
        set("mana", 150);
        set("max_mana", 150);

        set("combat_exp", 2000);
        set("daoxing", 3000);

        set_skill("force", 30);
        set_skill("dodge", 20);
        set_skill("unarmed", 20);
        set_skill("parry", 20);
        set_temp("apply/attack", 15);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 5);

        create_family("�䵱��", 4, "����");

        setup();

        carry_object("/d/wudang1/obj/greyrobe")->wear();
}
