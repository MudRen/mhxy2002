// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// hengha.c
#include <ansi.h>

inherit SSERVER;

void end_cast(object me,object target);
void cast_person(object me,object target);

int cast(object me, object target)
{
        string msg;
        int howlong;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩ����\n");

//        if((int)me->query_skill("bihai-spells") < 160)
//            return notify_fail("�����С�����뷭��������\n");
	if( me->query_temp("cast_daohai"))
	        return notify_fail("���Ѿ���ʩ�����ˣ�\n");        

        if((int)me->query("mana") < 2000 )
                return notify_fail("��ķ���������\n");
        if((int)me->query("sen") < 500 )
                return notify_fail("���޷����о�����\n");

        me->add("mana", -1000);
        me->receive_damage("sen", 100);
        if( random(me->query("max_mana")) < 600 ) {
                write("���ã�û��������\n");
                return 1;
        }
        
	msg = HIC
	"\n$N�������˾����ģ�˫�ֳ��죬���һ���������Ľ�ˮ���������Ĵ󺣰��������ҳ��У�
\nֻ����Χ�����׹�������$N�Ѿ���ʧ�����ˡ�!\n"NOR;
	message_vision(msg,me,target);
	me->set("env/invisibility", 1);
	howlong=me->query_skill("bihai-spells")/6;
	if(howlong>40)howlong=40;
	me->set_temp("cast_daohai",1);
    cast_person(me,target);
	call_out("end_cast",howlong,me,target);
    environment(me)->set("oldlong",environment(me)->query("long"));
  environment(me)->set("long", environment(me)->query("oldlong")+"\n��Χ�����һƬ�����......\n\n");
	
       if( !target->is_fighting(me) ) {
       if( living(target) ) {
             if( userp(target) ) target->fight_ob(me);
             else
		target->kill_ob(me);
             }
                me->kill_ob(target);
        }

	
        me->start_busy(1);
        return 3+random(5);
}

void cast_person(object me,object target)
{
  int ap,dp,damage;
  string msg;

  if(!target||environment(target) != environment(me)||!me->is_fighting(target)){
  	remove_call_out("cast_person");
  	remove_call_out("end_cast");
  	end_cast(me,target);
  	return;
  }
if (target)     target->delete_temp("no_move");
  if(random(2)){
    msg = HIC
         "\n��ˮ���ڣ�$N˫��һ�룬һƬ��ˮ��Ϊһ��ˮ����һ���伲����$n��\n"NOR;
    ap = me->query_skill("spells");
    ap = ( ap * ap * ap / (4 * 400) ) * (int)me->query("sen");
    ap += (int)me->query("combat_exp");
    dp = target->query("combat_exp");
    if( random(ap + dp) > dp ) {
       damage = (int)me->query("max_mana") / 10 +
           random((int)me->query("eff_sen") / 5);
       damage -= (int)target->query("max_mana") / 10 +
           random((int)target->query("eff_sen") / 5);                   
       damage+=(int)me->query("mana_factor")-random((int)target->query("mana_factor"));
       if( damage > 0 ) {
           msg +=  HIR "\n������͡���һ����ˮ����$n����͸���������\n" NOR;
          target->set_temp("no_move",1);
           damage +=random((damage*(int)me->query_skill("spells"))/200);
                        target->receive_damage("kee", damage/2, me);
                        target->receive_wound("kee", damage/6, me);
         }else msg += "\n������͡���һ����ˮ��������Ϣ��������£�û�����á�\n";
    }else msg += "\n���ˮ��������Ϣ��������£�û�����á�\n";     
    message_vision(msg, me, target);
  }else {
     msg = HIC
     "\n����д�������$N�Ӻ�ˮ������˫�ֲֳ棬����ˮ��������$nӭ�������\n" NOR;

     ap = me->query_skill("spells");
     ap = ( ap * ap * ap / (4 * 400) ) * (int)me->query("sen");
     ap += (int)me->query("combat_exp");
     dp = target->query("combat_exp");
     if( random(ap + dp) > dp ) {
         damage = (int)me->query("max_mana") / 10 +
            random((int)me->query("eff_sen") / 5);
         damage -= (int)target->query("max_mana") / 10 +
	    random((int)target->query("eff_sen") / 5);                   
         damage+=(int)me->query("mana_factor")-random((int)target->query("mana_factor"));
         if( damage > 0 ) {
            msg +=  HIR "\n$nһ�������񣬱��̵�Ѫ�����棡\n" NOR;
             target->set_temp("no_move",1);
             damage +=random((damage*(int)me->query_skill("spells"))/200);
            target->receive_damage("kee", damage/2, me);
            target->receive_wound("kee", damage/6, me);
          }else msg += "\n���Ǳ�$n�㿪�ˡ�\n";
      }
      else msg += "\n���Ǳ�$n�㿪�ˡ�\n";
      message_vision(msg, me, target);
  }
  call_out("cast_person",5,me,target);    	
}

void end_cast(object me,object target)
{
    string msg;
    	
    msg = HIC
     "\nˮ������ɢȥ�ˣ�¶����$N����Ӱ��\n" NOR;
    message_vision(msg,me);
    me->set("env/invisibility", 0);
if (target)     target->delete_temp("no_move");
    if(environment(me)->query("oldlong"))
       environment(me)->set("long",environment(me)->query("oldlong"));
    me->delete_temp("cast_daohai");
    remove_call_out("cast_person");	
}
