//By tianlin@mhxy for 2001.9.25
//�����Ż�

#include <ansi.h>;
inherit NPC;

void create()
{
        set_name(HIY"�ϻ�"NOR, ({ "laohu", "tiger","hu" }) );
        set("race", "Ұ��");
        set("age", 20);
        set("long", @LONG
һֻ����ͻ�����ΰ���ˡ�

         _.-'"''--..__.("\-''-'")
 ('.__.-' (  *  ) .-'    ( @ _@'
  `-..-''.' _.'  (   _.  `(._Y_)
         `. `._`--\  \_-.._`--'.._
          `-.!))  `.(il)   ''-.(li)



LONG);
        set("attitude", "aggressive");
        set("shen_type", -1);

        set("limbs", ({ "��ͷ", "����", "ǰצ", "��ץ", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 30000);
        set("force",800);
        set("force_factor", 100);
        set("max_force",800);
        set("mana",500);
        set("max_mana",500);

       // set_temp("apply/attack", 20000);
       // set_temp("apply/defense", 30000);
       // set_temp("apply/armor", 1000);

        setup();

        set("chat_chance", 10);
        set("chat_msg", ({
                "�ϻ��ڿ�Ѳ���ŵ�����������ҳ���\n",
                "�ϻ����쳤Х������ɽ�ȣ���Ҷ��׹��\n",
        }) );
}

