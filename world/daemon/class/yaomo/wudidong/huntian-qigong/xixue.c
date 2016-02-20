#include <ansi.h>

inherit F_CLEAN_UP;

void xixue_ok(object);

int exert(object me, object target)
{
        int meskill, obskill, meexp, obexp, mecast, obcast, damage;
object where;
 where=environment(me);
 if( where->query("no_fight") )
        return notify_fail("��ȫ���ڲ���������\n");
	if( !target
        ||  !target->is_character()
        ||   target->is_corpse()
        ||   target==me)
               return notify_fail("��Ҫ��˭��Ѫ��\n");
                
        if( (int)me->query("force") < 300 )     
                return notify_fail("�������������\n");
	if( (int)me->query("mana") < 300 )
		return notify_fail("��ķ������㡣\n");
	if( (int)me->query("sen") < 100 )
		return notify_fail("��ľ��񲻹���\n");	
	if( (int)me->query("max_force") < 300 )
		return notify_fail("�������������\n");
	if( (int)me->query("max_mana") < 300 )
		return notify_fail("��ķ������㡣\n");	
 if( (int)target->query("kee") < 10 )
        return notify_fail("����Ѿ��챻�����ˡ���\n"); 
	
	if( (int)me->query("food") >= (int)me->max_food_capacity() ) 	
	        return notify_fail("��Ե�̫���ˣ���Ҳ�������ˡ�\n");	
	        
	if( (int)me->query("water") >= (int)me->max_water_capacity() ) 
	        return notify_fail("��ȵ�̫���ˣ���Ҳ�������ˡ�\n");	       
	        
	if((int)me->query_skill("huntian-qigong",1) < 50)
		return notify_fail("��Ļ����������������\n");

        if((int)me->query_skill("yaofa",1) < 50)
		return notify_fail("�������˵�������ûѧ�ã�������Ѫ��\n");
		
	if(me->query("family/family_name") != "�ݿ�ɽ�޵׶�")
		return notify_fail("���ֲ����޵׶�����ħ����ʲôѪ��\n");	
	
	if(me->query_temp("no_xixue"))
		return notify_fail("������ʹ�Ͳ����ˣ�\n");	

        meskill =(me->query_skill("huntian-qigong",1)+me->query_skill("yaofa",1));
        obskill =(target->query_skill("force",1)+1);
        meexp =me->query("combat_exp");
        obexp =target->query("combat_exp");
        if(meexp<1000)
        mecast=1;
        else
        mecast=meexp/1000;
        if(obexp<1000)
        obcast=1;
        else
        obcast=obexp/1000;
        if((meskill-obskill)<0)
        damage=10+random(11);
        else 
        damage=random(meskill-obskill)+(meskill-obskill)*2/3;
                
        message_vision(HIG"$N�����ĸ�Ц�˼������ſ���¶����ɭɭ�����ݣ�ͻȻ����һԾ��\nѸ���ޱȵ�����$n��\n"NOR, me,target);
        me->receive_damage("sen", 10);
     me->add("force", -100);
     me->add("mana", -200); 
        me->set_temp("no_xixue",1);
        

    if(random(meexp+5)>random(obexp)){   
        	        
        message_vision(HIR"$n������������$Nһ��ҧ�ں�ͷ����Ѫ���������$N���˸������ֺ���\n"NOR, me,target);
        
   target->receive_damage("kee", (random(damage/2)+damage), me);
        
     if(damage<target->query("force")){
   target->add("force", -damage);}
        else{
        target->set("force", 0);}
      target->start_busy(1+random(2));
        
   if(me->query("kee")+damage*3/2 < me->query("max_kee")){
   me->add("kee", damage*2/3);}
else{
 me->set("kee", me->query("max_kee"));}
 if(me->query("eff_kee")+damage < me->query("max_kee")){
  me->add("eff_kee",damage);}
else{ me->set("eff_kee", me->query("max_kee"));}
        if(me->query("force") < me->query("max_force")){
        me->add("force", damage);}
        me->add("food", 10+random(16));
        me->add("water", 10+random(16));
  call_out("xixue_ok",4+random(3),me);
        return 1;
        }

        else{
        message_vision(HIR"$n��æ������$Nһ�������˸��ա�\n"NOR, me,target);
     call_out("xixue_ok",2+random(2),me);
        target->kill_ob(me);
        
        return 1;}
}

void xixue_ok(object me)
{ if (!me) return;
      me->delete_temp("no_xixue");
}         
