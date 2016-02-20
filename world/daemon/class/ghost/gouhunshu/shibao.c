#include <ansi.h>

inherit F_CLEAN_UP;

int cast(object me, object target)
{      
	object *ob, where;
	int i, meskill, meforce,obskill, obforce, damage; 
	
	if( !me->is_fighting() )
		return notify_fail("��ֻ����ս���в���ʹ��ʬ������\n");
	
	if( !target || !target->is_corpse() ) return notify_fail("��Ҫ����һ��ʬ��ʩ����\n");
	
	if( (int)me->query("mana") < 500 ) return notify_fail("��ķ���������\n");
	if( (int)me->query("max_mana") < 500 ) return notify_fail("��ķ���������\n");
	if( (int)me->query("sen") < 400 ) return notify_fail("�㾫���㣡\n");
	
	if((int)me->query_skill("gouhunshu",1) < 50)
		return notify_fail("��Ĺ������ļ��𻹲���!\n");
	if((int)me->query_skill("tonsillit",1) < 50)
		return notify_fail("����������ļ��𻹲���!\n");	

	message_vision(	HIR"$N�����˼������ҧ���������ϵ�$nһ�磬$n���һ�±��ѿ�����\nѪˮ������������Ϣ��ʬ���Ĵ��ɽ���\n"NOR, me, target);

	destruct(target);
	me->add("mana", -(250+random(151)));
	me->receive_damage("sen", 150+random(151));
	
	where=environment(me);
	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++) {
                if(!living(ob[i]) || ob[i]==me ) continue;
		if(!me->visible(ob[i])) continue;
             
	meskill = (me->query_skill("force")+ me->query_skill("spells"))/5;
	meforce = (me->query("max_force") + me->query("max_mana"))/5;
	obskill = (ob[i]->query_skill("force")+ ob[i]->query_skill("spells"))/50;
	obforce = (ob[i]->query("max_force") + ob[i]->query("max_mana"))/50;
             
        damage = random(meskill) + random(meforce) - random(obskill)-random(obforce);
                if( damage > 0 ) {
   ob[i]->receive_damage("kee", 10+random((me->query("max_mana")+1)/4), me);
                  tell_object(ob[i], "�㱻Ѫˮ����һ��ֻ��������һ����ģ���Ѫˮ�����ĵط��ƺ���ʼ�����ˣ�\n");
      ob[i]->apply_condition("shibao_poison",(int)ob[i]->query_condition("shibao_poison")+10+random(21));
      COMBAT_D->report_kee_status(ob[i]);}
		if( damage <= 0) 	
		tell_object(ob[i], "����æ���һ�����㿪�˷ɽ���Ѫˮ��\n");	
                if( userp(ob[i]) ) ob[i]->fight_ob(me);
                else if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);
	}
      
      me->start_busy(1+random(3));
	return 3+random(5);
}
