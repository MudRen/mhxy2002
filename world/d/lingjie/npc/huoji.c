inherit NPC;

void create()
{
        set_name("���", ({"huoji"}));
        set("age", 28);
        set("gender", "����");
        set("long",
"����õ�����,��������,��������硣\n");
        set("attitude", "peaceful");

        set("combat_exp", 5000);
        set("shen_type", 1);
        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        setup();
        carry_object("/d/obj/cloth/linen")->wear();
}


