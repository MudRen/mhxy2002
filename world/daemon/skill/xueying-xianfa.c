//By tianlin@mhxy for 2001.12.14
inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
        if( (int)me->query_skill("spells", 1) < 10
        ||      (int)me->query_skill("spells", 1) <=
(int)me->query_skill("dengxian-dafa", 1) )
                return
notify_fail("��ķ�����Ϊ����������޷�ѧϰѩӰ�ɷ���\n");
        return 1;
}

string cast_spell_file(string spell)
{
        return CLASS_D("shenjian") + "/xueying-xianfa/" + spell;
}

string type() { return "magic"; }
