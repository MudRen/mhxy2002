//  ����֮�� ������


inherit NPC;
#include <ansi.h>

void create()
{
   set_name("Ϭţ��", ({ "xiniu jing","jing" }) );
   set("race", "Ұ��");
   set("age", 1000);
   set("long", "������������������Ϭţ����\n");
   set("str", 50);
   set("max_kee",6000);
   set("kee",6000);
   set("mana",6000);
   set("max_mana",6000);
   set("max_force",6000);
   set("force",6000);
   set("dex", 36);

   set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
   set("verbs", ({ "bite", "claw" }) );
   set_skill("unarmed",300);
   set_skill("dodge",300);
   set_skill("force",300);
   set_skill("parry",300);
   set("attitude","aggressive");
   set("combat_exp",6000000);
   set_temp("apply/attack", 200);
   set_temp("apply/armor", 100);
   setup();
}

void die()
{
        object ob = this_object();
        message_vision(HIC"ֻ��$N�Ե��ڵ�!  �ã���Ҳ���Ի�ȥ�ˡ�\n"NOR,ob);
        ob->set_name("����",({"zuo qi","jing"}));
        ::die();
}
