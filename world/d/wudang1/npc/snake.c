//By tianlin@mhxy for 2001.9.25
//�����Ż�

inherit NPC;
#include <ansi.h>

void create()
{
	set_name(RED"��ھ���"NOR, ({ "ju mang", "snake", "mang" , "she"  }) );
	set("race", "Ұ��");
	set("age", 20);
	set("long", "һֻ��Ȼ������������������ݣ��������������԰��
����Ҫһ�ڰ������¡�\n");
	set("attitude", "aggressive");
        set("kee", 5000);
	set("max_kee", 5000);
	set("sen", 500);
	set("max_sen", 500);
	set("str", 86);
	set("cor", 80);
	set("limbs", ({ "ͷ��", "����", "�ߴ�", "β��" }) );
	set("verbs", ({ "bite" }) );

	set("combat_exp", 1000000);

	//set("chat_chance",65);
	
	set_temp("apply/attack", 85);
	set_temp("apply/damage", 80);
	set_temp("apply/armor", 88);
	set_temp("apply/defence",80);

	setup();
}

int hit_ob(object me, object ob, int damage)
{
	if( random(damage) > (int)ob->query_temp("apply/armor")
	&&	(int)ob->query_condition("snake_poison") < 10 ) {
		ob->apply_condition("snake_poison", 40);
        tell_object(ob, HIG "����ñ�ҧ�еĵط�һ����ľ��\n" NOR );
	}
}
