// ���񳯷�
//��ѩɽ�����Ҿ���Ӧ�÷�Ϊ����,һ��������ʹ��,����һ������Ů��ʹ��,����һ��,����ǰ�������˵�ȽϺ�,
//�е�����ҷǳ�ϲ�������޵���һ�ֳ���,�е�Ҳϲ���������޵���һ��,�����ڸ��ĳ�,���Եĵ�����,Ů��
//�ĳ������Ժ�busy��,�Ҿ���������ƽ��.�Ҹ�����ɫ����һ���޸�,�ĵĻ���,���������һ���޸ľ�����.
//by tianlin 2001.5.1
/*
requirement: sword+bainiao_jian+throwing >80 ���˰����Ľ��пɷ�����
                                         >150 ��������
damage : ��������/����   1. random ����1--10��
         ���м���      (me->a)/(target->d)*0.3
         �˺�:         ����: 20+me->query_temp("apply/damage") 
	               ����: <ոȱ>	
                       ��ȸ��: 50+me->query_temp("apply/damage") 
                       ����: me->query("force_factor")
		       ����+���� : �˺��ۼ�
          �Լ����� - me->query("force_factor")
(haven't done :P)
ֻ�������з�ѩ���������ó����콣â������0���Ž����������Ͷ�ְ���С�ܲ�������
*/
//by tianlin 2001.6.6
//�Ҹ��޸���һ�£�������chaofeng��rumor,����������KOFʱͻ������(snicker)!
#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        object weapon;

        string msg;
        string str;//����rumor�ı���
        int ii,req,num_anqi,num_hit,max_hit,hitt,damage,op,opfa,remain;
        string anqi_type,b_unit;
//added by beeby 2000.6.20
        int t;
//end add

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
           return notify_fail("��Ҫ��˭ʩչ��һ��"HIY"�����񳯷"NOR"?\n");
   /*     if( (string)me->query("gender") != "Ů��" )//���������һ�����е�ʹ�õ�һ����Ů��ʹ�õġ����ǡ�����
  return notify_fail("��һ�а��񳯷���Ů��ʹ�õ�,�������ӵĳ��\n"); */
        if(!me->is_fighting())
                return notify_fail(""HIY"�����񳯷"NOR"ֻ����ս����ʹ�ã�\n");

      weapon = me->query_temp("weapon");
      req=(int)me->query_skill("sword", 1)+(int)me->query_skill("bainiao-jian", 1)+(int)me->query_skill("throwing", 1); 


      if (weapon)  
        {
        if (weapon->query("anqi/allow") != 1) num_anqi=0;
        else num_anqi=weapon->query("anqi/now");
        }

      if (me->query_skill_mapped("force")!="ningxie-force")
                return notify_fail("���񳯷������ϱ�����Ѫ������ʹ�á�\n");
      if(req < 80)
            return notify_fail("�㽣�д����Ĺ��򻹲������\n");
      if(req < 150 && weapon->query("anqi/now") ==0)
            return notify_fail("�㽣��û�а����ɴ�\n");
       if (me->query("force")<200)
           return notify_fail("���������̣������������롣\n");
//Added by Beeby 2000.6.20
// �����񽣼���busy,����������
 	if ( ((t=(int)me->query_temp("chaofeng_time")) <= time() )
	    && (time()<t+5) )
         {  
            return notify_fail(""HIY"���񳯷�"NOR"��ʹ�Ͳ����ˡ�\n");
         }
        else me->delete_temp("chaofeng_time") ;
        me->add("force", -60);

        if(num_anqi <=0) 
           { anqi_type="����"; damage=me->query("force_factor")+10; }
        else if (req < 150)
           { anqi_type=weapon->query("anqi/type"); damage=me->query_temp("apply/damage");}
        else 
           { anqi_type=weapon->query("anqi/type")+"���Ž���";
             damage=me->query_temp("apply/damage")+me->query("force_factor")+10;}
         
        msg = MAG"ֻ��$N����[1;33m"+weapon->query("name")+MAG"[2;37;0m[35m�������ó����콣â������[2;37;0m[37m"
                 +anqi_type+MAG"�������Ͷ�ְ���$n������\n" NOR;

        if (num_anqi > 10 || num_anqi == 0) max_hit=10;
        else max_hit=weapon->query("anqi/now");
        num_hit=random(max_hit)+1;
        if (!target->is_fighting(me)) opfa=30;
        else opfa=15;
        if (target->query("combat_exp")  !=0 ) 
               op= me->query("combat_exp")*opfa/target->query("combat_exp");
        else op=10;
        hitt=0;	
        for (ii=1;ii<=num_hit;ii++)  
          {if (op > random(100)) hitt++;}


        if (weapon->query("anqi/type")=="��ȸ��") b_unit="֧";
        else b_unit="��";
        if (weapon->query("anqi/now") != 0) remain=weapon->query("anqi/now")-num_hit;
        else remain=0;
        weapon->set("anqi/now",remain);
        if (weapon->query("anqi/now") == 0) 
          {weapon->delete("anqi/type");  weapon->set("long",weapon->query("orilong"));}
        else weapon->set("long",weapon->query("orilong")+"�����Ѿ�װ��"
           +chinese_number(weapon->query("anqi/now"))+b_unit+weapon->query("anqi/type")+"��������uninstall��\n"); 

        if (hitt==0)
	  {
           msg += HIW "$n��æ����һת�����������������������컨����һ����\n"NOR;
           message_vision(msg, me, target);
              me->start_busy(1+random(0));
	  }
        else 
          {
	   damage=damage*hitt;
           target->receive_damage("kee",damage,me);
           msg += HIG "$n��������������"+chinese_number(hitt)+HIG "������[2;37;0m[37m"+anqi_type+"��\n"NOR;
           message_vision(msg, me, target);
           COMBAT_D->report_status(target); 
           if(!target->is_busy())
	       target->start_busy(8+random(8));//�Ӵ�busy
           me->set_temp("chaofeng_time",time());
           }
        msg = HIB "$n����$N����������ð����ҷŰ�����������ô��ʰ�㣡\n" NOR;     
        message_vision(msg, me, target);
        target->kill_ob(me);//ȥ�����ʹ�����������Ӻ���,fight��ʹ�ò�������killָ��,��ǰ����.(xixi)
//By tianlin@mhxy 2001.6.6
                     if (target->query("eff_kee")<0 || !living(target))  
                       {str=target->name()+"��"+me->name()+"��"HIW"��ѩɽ"NOR HIM"����[1;37m�����񳯷[2;37;0m[1;35mɱ���ˡ�����"BLINK HIC""+chinese_number(hitt)+""NOR HIM"������"HIY""+anqi_type+""NOR HIM",ʬ����������ѣ�";
	                message("channel:rumor",HIM"��ҥ�ԡ�ĳ�ˣ�"+str+"\n"NOR,users());
	               }
        return 1;
}

