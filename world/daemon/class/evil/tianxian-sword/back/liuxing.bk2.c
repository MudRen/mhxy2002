// zxzx.c
//write by yesi
//yeahsi@21cn.com
// modify by ken 2001/7/10
#include <ansi.h>
inherit SSERVER;

void check(object me);
void zxzx_effect(object me, object victim);
void remove_effect(object me);

int perform(object me)
{
//      object ob;
        int skill;
        int sword_skill,qixiu_skill;
        
        skill = me->query_skill("evil-force",1);
        if( skill > 250 ) skill=250;
        sword_skill= me->query_skill("sword",1);
        qixiu_skill= me->query_skill("tianxian-sword",1);
                       
        if( skill < 100 )  return notify_fail("���ħ�������Ͳ��죬��ô������ħն��\n");
        if( sword_skill < 100 )  return notify_fail("��Ļ������������죬����ħն�е����ѡ�\n");
        if( qixiu_skill < 100 )  return notify_fail("������ɽ�����û���ã��ò�����ħն��\n");
        
        if( me->query_temp("zxzx") ) 
          {remove_effect(me);return 1;}
          
        if (me->query_skill_mapped("force")!="evil-force")
            return notify_fail("���졤ħ��ն��û����ħ���Ļ��Ǻ��ѷ����ġ�\n");

//        if( !(ob = me->query_temp("weapon"))
//        ||      (string)ob->query("skill_type") != "sword"
//        ||      (string)ob->query("material") != "fire" )
//                return notify_fail("����û�л��������ħն��\n");
        
        if(me->query("family/family_name") != "ħ��")
                return notify_fail("���ֲ���ħ���޷�����Ϊħ��\n");     
        
        if( time()-(int)me->query_temp("zxzx_end") < 10 )
                return notify_fail("��ո�ʩչ����ħն�����������Ϣ�¡�\n");       
               
        
        if( (int)me->query("force") < 1000 )     
                return notify_fail("�������������\n");
 
        me->add("force", -skill);
        message_vision(HIY "$N΢һ��������Ѫħ�񹦣�ȫ��ǽڷ���һ�󱬶�������죡\n
 �漴����һ���޴��ޱȵ�ħ��\n" NOR, me);
        me->set_temp("zxzx", 1);
        me->set_temp("zxzx_time",skill);
                   
        call_out("check", 1, me);
        return 1;
}
void check(object me)
{       
        object weapon;
        
                
         if (me->query_skill_mapped("force") != "evil-force"
                 || !objectp(weapon=me->query_temp("weapon")) 
                 || (weapon->query("apply/skill_type") != "sword" 
                     && weapon->query("skill_type") != "sword" ) 
                 ||  me->query_skill_mapped("sword") != "tianxian-sword" )     
             remove_effect(me);
         else if(me->query_temp("zxzx_time")<1)
             remove_effect(me);                 
         else {  me->add_temp("zxzx_time",-1);
                call_out("check", 1, me);
              }
                     
}

void remove_effect(object me)
{
        if(!me) return;
        remove_call_out("check");
        me->delete_temp("zxzx");
        me->set_temp("zxzx_end",time());
        tell_object(me, CYN"�����ħ����Ч��ɢ���ˡ�\n"NOR);
}

void zxzx_effect(object me, object victim)
{   int damage,ini_damage_apply;
    string str;

   if ( random(2)>0 )
          { ini_damage_apply = me->query_temp("apply/damage");
            me->add_temp("zxzx",1);
            message_vision(HIY"\n$N���һ��������ħն����\n
���еĳ�������һ���޴��ޱȵĻ�����������������$n��"NOR,me,victim);
            me->add_temp("apply/damage",15);
            damage = COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));                                 
   if( damage > 0 )
          {
           message_vision(HIY"\n$N���Ʋ����ˣ��ֶ�����������������\n"NOR,me);
           me->add_temp("apply/damage",15);
           COMBAT_D->do_attack(me, victim, me->query_temp("weapon")); 
           COMBAT_D->do_attack(me, victim, me->query_temp("weapon")); 
           COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));         
           me->add_temp("zxzx",-1);
           if (victim->query("eff_kee")<0 || !living(victim) )  
                       {str="��˵"+victim->name()+"��"+me->name()+"�����ˣ�"NOR;
                        message("channel:rumor",HIM"��ҥ�ԡ�ĳ�ˣ�"+str+"\n"NOR,users());
                       }
           }             
    else me->add_temp("zxzx",-1);
    
    me->set_temp("apply/damage",ini_damage_apply);
          }
}
