// REDGIRL.C
#include <ansi.h>
inherit NPC;
void create()
{       
        set_name("��Ů", ({ "shinu" }) );
        set("title", "��ɽׯ");
        set("long", "����һ�������崿����Ů��\n");
        set("age", 16);
        set("gender", "Ů��");
        set("attitude", "peaceful");
        set("chat_chance", 10);
        set("chat_msg", ({
         "��Ů������Ц��Ц��¶���������˵�С���ѡ�\n",
	(: random_move :),
                        }) );
        setup();
        carry_object(__DIR__"obj/ncloth")->wear();
}
