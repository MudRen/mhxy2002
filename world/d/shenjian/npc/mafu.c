// REDGIRL.C
#include <ansi.h>
inherit NPC;
void create()
{       
        set_name("���", ({ "mafu" }) );
        set("title", "��ɽׯ");
        set("long", "����һ�����͵�������Ĺ��������չ˿�����ͣ���������\n");
        set("age", 46);
        set("gender", "����");
        set("attitude", "peaceful");
        set("chat_chance", 10);
        set("chat_msg", ({
         "������ڸ�ʳ����ƴ����������ϡ�\n",
                        }) );
        setup();
        carry_object(__DIR__"obj/zcloth")->wear();
}
