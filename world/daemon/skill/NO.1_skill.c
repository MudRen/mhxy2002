#include <ansi.h>
#include <skill.h>

inherit SKILL;


string *strong_msg= ({
HIR"$N˫��Բת��ÿһ�ж���Ȼ����̫��ʽ�������仯����΢����!!\n$N������졢�Ծ��ƶ�,���Ǿ����书��\n"NOR,
HIB"$N����һЦ�������������������˾Ÿ�ԲȦ!!\n$NĬ��"NOR+HIR"��һ��"NOR+HIB",�����ʵ��һ��������ס���ͼ�������\n"NOR,
HIY"$N�Ҽ�б������ָ����,��ʹ�Ͼ�,ȴ�Ǹ��ͣ��̿�֮�����������\n"NOR,
HIG"\nͻȻ,$N��������б���벽,���ֻ�ǵ���һ��!\n"NOR,
HIM"\n$N�����,�������������裬�������������,���ǰ������\n"NOR,
WHT"\nͻȻ,$N����б�У���������,Խ��Խ�죬����糸���У�\n"NOR,
});
string *xue_name = ({ 
"�͹�Ѩ","����Ѩ","����Ѩ","��ԪѨ","����Ѩ","�м�Ѩ","�н�Ѩ","��ͻѨ","�ٻ�Ѩ",
"����Ѩ","����Ѩ","���Ѩ","�Ϲ�Ѩ","��ԨѨ","�쾮Ѩ","��ȪѨ","����Ѩ","����Ѩ",}); 


string *hit_msg= ({
HIR"\n$Pֻ�о�һ��"NOR+HIB"��������"NOR+HIR"�������,���ɴ��һ��,ȫ��ȴ��ͬ׹�����!\n"NOR,
HIC"$N���һ��"NOR+HIB"����һ�������񽣡�"NOR+HIR"��\n"NOR,
HIW"\n$P��������ȴ����Խ��Խ�죬ͻȻ�о�����"NOR+HIB"����ָ��"NOR+HIW"�ֱ�ָ���Լ�������Ѩ"NOR+HIR"!!\n"NOR,
});
string *dodge_msg = ({
"$n����һ�����ģ���������б���벽��ǡ�������貨΢����"+HIM"���������塹"NOR+"�Ĳ��ӣ����˿�����\n",
"$nʹ��"+HIR"�������ѩ��"NOR+"����бб���˼������ƺ������·���ȴ�ڼ䲻�ݻ��Ŀ�϶�ж����$N�Ĺ��ơ�\n",
"$n����������ͻȻת��ʹ����"+WHT"�������ϡ�"NOR+"��$N�ӽ����ƣ����޷�����$nһƬ�½ǡ�\n",
"$n���һ����ʹ��"+GRN"��է��������"NOR+"����������̤��������̤ʵ֮ʱ�����������������ϡ�\n",
"$nһʽ"+HIC"���������ҡ�"NOR+"��հ֮��ǰ�������ں�$N��ʽ������$n���Ӽ��������֮�\n",
"$N����ʽ�������԰�$nΧס����֪���ģ�$nһʽ"+HIG"�����Ʊ��¡�"NOR+"��������Ȱ�Ŀ����Ȧ��\n",
"$nһʽ"+HIW"����Ѹ���ɡ�"NOR+"���ƺ��Թ��Ե�̤����������ᣬÿһ����̤�ڱ������벻�������ڡ�\n",
"$nһʽ"+HIR"��Ʈ������"NOR+"������б�����������ȼá���������δ�á������ü��������۵�$N�����\n",
});

string *sword_msg = ({
"$N�ٽ���ӣ�Ѹ���ޱȵص���$n��$l��ȴ���˿�������������ʲô��ʽ",
"$N�˽���磬��������з���$n��$l�����Ա�$n���أ��������ǡ���ħ�����ġ�����ʽ��",
"ֻ��$N���˷���������Ʈ�磬�����һʽ�������������������޶�����׽����ָ��$n��$l",
"$N�Թ�Ϊ�أ��Խ�Ϊ�ˣ�����������$n�͹����ػӳ���λ�����̩ɽ�������������",
"$NͻȻһ������$n��$l����һ��ȴ�����������ţ�$n�����޴룬��֪����Ǻ�",
"$N��$w����һ�ڣ�����$n�Լ���$wײ����������֮����ʵ�����Ѳ�",
"$N����ͻ�䣬ʹ����ɽ�ġ�һ������㡹������$n��$l����֪������;��ͻȻת�򣬴��$n����֮��",
"$N�������ߣ�����һ��������һ������$nĪ������ֲ���$N��������ʵ",
"$N����һ��ָ��$n���������$n���������ڣ��˵����������ף�����˼��",
"$n����$N��$l��$N���˷�����ʹ����ɽ���С�������롹��ɭɭ������������",
"$N������$n�ӳ���Ȫ��ܽ�ء����������ϸǡ�����ʯ�����������������������������ף�ڡ���ɽ����",
"$N������ת�������̳�ʮ�Ž�����Ȼ�ǻ�ɽ����Ůʮ�Ž��������������ʮ�Ž�����һ�У��ַ�֮�죬ֱ�Ƿ�����˼",
"$NͻȻʹ��������ɷ罣���ġ����ڤڤ�������Ƿ�λȴ����ƫ�$w����$nһ�ʣ���ͼͻ��$n�Ĺ���",
"$N����$w��ʹ��̫���������⣬�������СС������ԲȦ�������޾�ԴԴ�����ز���$n",
"$N��Ц����������ׯ�ϣ�$w��ӣ����ڡ���Ħ����Ϊһʽ������ش���$n",
"$n��׼$Nһ�л�ɽ�������з����ǡ������ƣ�׼�����з�����ȴ��$NͻȻ�鲽������ʹ�������䵱�����ѵ�ˮ����һ��",
"����$Nͦ����ϣ�$wһ����һ�з·�̩ɽ�����ġ�������Ȫ��ֱ��$n��$l",
"$N����ͻ������ɭ�ϣ�����ǧ�������۶�������ǹ��ꪣ���ɳǧ�������ɽ���ƻ���$n",
"$N����$wԽתԽ�죬ʹ�ľ�Ȼ�Ǻ�ɽ�ġ��ٱ�ǧ������ʮ��ʽ������ʽ�����ƾ���ӿ���Թ��߲��ɵ�ĿΪ֮ѣ",
"$N���ƺ��������裬�������������������ɽ����Ϊһ������$n������ȥ",
"$NͻȻ�˽����һ�ֹ���ġ������罣��������Ȼ��$n�����Ҵ�����",
"$N����ͻ��Ц�ݣ��ƺ��ѿ���$n���书��ʽ�����г����һ������$n��$l",
"$N��Ю���ƣ��󿪴��ص��ҿ�һͨ�������нԻ���$n���Ƶ�������$n���ò���",
"ȴ��$N���潣�ߣ����һ�գ��ұ�һ�䣬����Ҳ��ԽתԽ�Ӻ�����������̩ɽʮ���̡�Ϊһ������$n",
"$N���ֺὣ����$n��$l���������������е�һ��������ȴ�����$n���Կ��彣������",
"$N��ɫ���أ�$w�����������Һ�ɨ��Ю�������֮�Ʊ���$n������ħ���������¶����",
"$N������$n�ӳ���Ȫ��ܽ�ء����������ϸǡ�����ʯ�����������������������������ף�ڡ���ɽ����",
"$N������ת�������̳�ʮ�Ž�����Ȼ�ǻ�ɽ����Ůʮ�Ž��������������ʮ�Ž�����һ�У��ַ�֮�죬ֱ�Ƿ�����˼",
"$N����ͻ�䣬�����������������ڽ�ز����ʹ��ɽ�����ġ������������ع�$n",
});
string *unarmed_msg = ({
HIC"$N�ֱ۶�Ȼһ�ᣬ��$n���𹥻���������$n����һ�ߣ���������Ϊָ��ʹ�������󽣡�"NOR,
HIC"$N˫���������ﻮ��һ��Ȧ��˫��������ǰ�������Сָ��һ�С��ٳ彣��"NOR,
HIC"$N��Цһ��������Ӳ�������أ����ֺ�ն����������б�У�����ָ������һʽ���س彣��"NOR,
HIC"$Nʳָ�����������ޱȣ��񿪶Է����ƣ��������٣��綾�߳�����������״��������һ����ʹ������������"NOR,
CYN"��ָ֮�䣬���ֻ�ǵ���һ����$Nһ���ƣ��������ƣ��������������ֶ�Ȼ̽������ָһ����һ�С��г彣��"NOR,
HIW"����$N����Сָһ�죬һ��������$P�ٳ�Ѩ�м��������ָ����ǰ$n��"NOR,
WHT"$N��б������������Сָ�������������ҵ�б����ȥ��ֱ��$n$l,��������$n����һ��֮������������Ϊָ����"NOR,
HIY"$N��Цһ��������б�У�����ָ������ָ���Ѷ�׼$n��$l������һ��ǿ�ҵľ��磡"NOR,
HIY"$N����ָһ�ӣ�׾�͹��ӵĹس彣��ֱ��������˶������ش���$n��"NOR,
HIY"$N�������٣�����ʳָ�綾�߳�����������״��������һ����˫�ֻó�����ָӰ��"NOR,
YEL"$NĴָһ����ʳָ���������ˡ�������������һ�ƽ�����$n�̳���"NOR,
YEL"$Nʳָ������������������һ����һ���Ĵ̳���������Ѹ�٣������ޱȣ�"NOR,
YEL"$N��ʳָ�������ν�����ȴ��������ָ�����緶Χ��ת��������$nһ��һ����"NOR,
HIB"$N����ָ����һ̿���г彣���εض��𣬽���$P����ָ����һ���������������㿳��$n��"NOR,
HIB"����ʯ֮�䣬$Nһ���ƣ��������ƣ��������������ֶ�Ȼ̽������ָ��$nһ����"NOR,
HIB"$N��������ǰ�������Сָ��һ�С��ٳ彣�������ص���$n�������Ѩ����ָ������"NOR,
BLU"$NСָһ����ʹһ�С��ֻ���������������ͬ����һ�㣬Ʈ�����ң�"NOR,
BLU"$Nһ�С��ٳ彣����������ת������������˹���������$n��$l��"NOR,
BLU"$N����Сָһ�ӣ�һ�С��ٳ彣�����̴̣�����񻨴̻�һ�㣡"NOR,
HIM"$N��Ĵָһ����������ָ������ʹ�����ɣ������󼱣�������ŭ������ӿ������"NOR,
HIW"$N��Ĵָ���ӣ������̽�����������һ����īɽˮ���ƣ��ݺ���б���������ʣ�ȴ�ǽ�·�۾���"NOR,
WHT"$N�ġ����̽������󿪴��أ����ɺ�ΰ��ÿһ���̳�������ʯ���쾪���������֮�ƣ�"NOR,
});

mapping query_action(object me, object weapon)
{
      int i, j, damage;
      i = random(100)+100;
      damage = i;
      if (!me) me = this_object();
 if (!weapon) {                    
     if (random(me->query_skill("NO.1_skill",1)) > 200 &&
              me->query_skill("force") > 160 &&
            me->query("max_force") > 3000 && 
               me->query("force") > 3000 ) 
       {
        return ([
//                 "action":unarmed_msg[random(sizeof(unarmed_msg))]+BLU"\nȴ��$n����һ����ֻ����"NOR+HIR+xue_name[random(sizeof(xue_name))]+NOR+BLU"��ͬ������������к,$n���������Ժ�..!!"NOR,
                 "action":strong_msg[random(sizeof(strong_msg))]+"\n"+unarmed_msg[random(sizeof(unarmed_msg))],
                "damage":damage*(2+random(2)),
            "damage_type": random(10)?"����":"����", 
            "weapon": random(3)?HIW"��������"NOR:HIY"��������ָ��"NOR, 
                "dodge": -50-random(10),
                "force": i*2,
                ]);
       }
      return ([
             "action":unarmed_msg[random(sizeof(unarmed_msg))],
             "damage":damage*random(2),
            "damage_type": random(10)?"����":"����", 
            "weapon": random(3)?HIR"һ��ָ��"NOR:HIB"��ָ"NOR, 
                "dodge": -50-random(10),
             "force": i,
             ]);
        }
     if (random(me->query_skill("NO.1_skill",1)) > 200 &&
              me->query_skill("force") > 160 &&
            me->query("max_force") > 3000 && 
               me->query("force") > 3000 ) 
       {
        return ([
//                 "action":sword_msg[random(sizeof(sword_msg))]+HIC"\n�����ţ�$N����һЦ����������,$n"NOR+RED+xue_name[random(sizeof(xue_name))]+NOR+HIC"ͻȻ��ͬ���������Ĵ���!"NOR,
                 "action":sword_msg[random(sizeof(sword_msg))],
                "damage":damage*(2+random(2)),
                "damage_type": "����",
                "dodge": -50-random(10),
                "force": i*2,
                ]);
        }
      return ([
             "action":sword_msg[random(sizeof(sword_msg))],
             "damage":damage*random(2),
             "damage_type": "����",
                "dodge": -50-random(10),
             "force": i,
             ]);
}


int valid_learn(object me)
{
        if ((int)me->query("max_force") < 100)
                return notify_fail("�������������ô������\n");
        if ((int)me->query("force") < 100)
                return notify_fail("�������������ô������\n");
if ( ! wizardp(me))

        return notify_fail("��һ��ֻ������ʦѧϰ��\n");
}
int valid_enable(string usage) 
{
return (usage == "sword") || (usage == "parry") || (usage == "unarmed") || (usage == "force") || (usage == "dodge") || (usage == "spells");
}
string perform_action_file(string action)
{
        return "/u/yxm/skill/fly-king/perform/" + action;
}
string exert_function_file(string func)
{
         return "/u/yxm/skill/fly-king/exert/" + func;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
    object weapon, weapon1;     
    string name,hitmsg;
    name = xue_name[random(sizeof(xue_name))];
    hitmsg = hit_msg[random(sizeof(hit_msg))];
    weapon = me->query_temp("weapon");
    weapon1= victim->query_temp("weapon");
       if( random(me->query_skill("NO.1_skill")) > 100) {
                victim->apply_condition("cold_poison", random(2) + 2 +
                        victim->query_condition("clod_poison"));
        }
    if(weapon1 && me->query_skill("NO.1_skill", 1) > 150 
       && me->query("max_force") > 1200 && me->query("force") > 1000 
       && me->query("combat_exp") > random(victim->query("combat_exp"))){
      message_vision(HIR"\n$N���ֽ���б��,ƽ����$n"+weapon1->name()+HIM"������,��������,"+weapon1->name()+MAG"��ʱһ����\n"NOR, me,victim);
      if(random(me->query("str")) > victim->query("str")/2){    
      message_vision(HIR"$N��ʽ����ɬ�ͣ�ֻ��������"+weapon1->name()+HIR"���Ʋ��ϵ�������������һ���ѳֲ��������ַɳ���\n"NOR, victim);
           weapon1->unequip();
           me->add("force",1000);
           victim->start_busy(3);
           weapon1->move(environment(victim));
}
      else{
           message_vision(HIY"$Nһ��ʹ���������˵ò��㣬��������ת����Ȧ�ӣ�����"+weapon1->name()+HIY"һ����Щ���֣�\n"NOR, victim);
           me->add("force",1000);
           victim->start_busy(2);
           }
    }
    if(!weapon1 && random(me->query_skill("NO.1_skill", 1))> 100 
       && me->query("max_force") > 1200 && me->query("force") > 1000 
       && me->query("combat_exp") > random(victim->query("combat_exp"))){
//           message_vision(HIY"$N����Խ��Խ˳���������������裬�������������,���ǰ�������!!\n"NOR, me);
//           message_vision(HIB"$NԽ��Խ���ľ�����������书ȴ���Ӳ�����"NOR,victim);
           victim->start_busy(3);
           me->add("force",1000);
         victim->receive_damage("kee", me->query_skill("NO.1_skill")/3+damage_bonus/3);  
         victim->receive_wound("kee", me->query_skill("NO.1_skill")/4+damage_bonus/4);  
                           if (victim->query("force") <=(damage_bonus/2+30))
                victim->set("force",0);
                else
                victim->add("force",-damage_bonus/2+30);  
                               }
}

string query_dodge_msg()
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
string cast_spell_file(string spell)
{
        return "/u/yxm/skill/fly-king/cast/" + spell;
}
