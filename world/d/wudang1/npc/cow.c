//By tianlin@mhxy for 2001.9.25

#include <command.h>
#include <dbase.h>
#include <origin.h>
#include <ansi.h>

inherit NPC;

void create()
{
        set_name(YEL"���ţ"NOR, ({ "cow" }));
        set("long","һͷ���ţ��\n");
        set("race", "Ұ��");
        set("age", 5);
        set("int", 30);
        set("ridable", "1");
        set("kee", 300);
        set("max_kee", 300);
        set("sen", 100);
        set("max_sen", 100);
        set("combat_exp",50000);
        set("attitude", "peaceful");

        set("limbs", ({ "ͷ��", "����", "β��","����","ǰ��" }) );
        set("verbs", ({ "bite","hoof" }) );
        set_temp("apply/attack", 50);
        set_temp("apply/armor", 15);
        set_temp("apply/damage", 25);

        setup();
}

