// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//�����������衿 moondance.c
// cglaem...12/07/96.

inherit SKILL;

mapping *actions = ({
     (["dodge_action":
        "$n��ͷϸ��ȹ�ޣ���˼��������������֮���ƺ�����������ȴ��$N����һһ�������Ρ�\n",
       "dodge_power":10,]),
     (["dodge_action":
        "ֻ��$nһ��ת����Ȼ����һЦ��$Nһ��֮�£����ﻹ�����ڡ�\n",
        "dodge_power":15,]),
     (["dodge_action":
       "����$n���һЦ�����˷��������ξ���$NƮ����\n$Nֻ��һ��������ǣ���һ�о�������֮����\n",
       "dodge_power":20,]),
     (["dodge_action":
       "$n�����飬��֫��š����Ȼ�ó��߲���Ӱ��$N��һ��������ֵó����ˣ���Ӱ��\n",
       "dodge_power":20,]),
     (["dodge_action":
     "$nȹ��ƮƮ�������橣���Ȼ��$Nͷ���ɹ������Ů�����֮�ˣ��������֮�Σ�$N���ɵÿ����ˣ�\n",
       "dodge_power":25,]),
     (["dodge_action":
       "$n�Ų���ӯ��������Ȼ�����ӱ�����ˮ����Ʈ��һ���ӹ�������$N����Ϯ��������Ȼ��ȥ��\n",
       "dodge_power":30,]),
     (["dodge_action":
       "$n����΢����������磬���Ὣ$N�ľ�������һ�ԣ��������⡣\n",
       "dodge_power":35,]),
});

int valid_enable(string usage) { return (usage=="dodge"); }

int valid_learn(object me)
{
   if( (string)me->query("gender") != "Ů��" )
     return notify_fail("����������ֻ��Ů�Բ�������\n");
   if( (int)me->query("spi") < 10 )
     return notify_fail("������Բ�����û�а취�����������衣\n");

   return 1;
}

int practice_skill(object me)
{
   if( (int)me->query("sen") < 30 )
     return notify_fail("��ľ���̫���ˣ����������������衣\n");
   me->receive_damage("sen", 30);
   return 1;
}

mapping query_action()
{
        return actions[random(sizeof(actions))];
}

string perform_action_file(string func)
{
return CLASS_D("moon") + "/moondance/" + func;
}
