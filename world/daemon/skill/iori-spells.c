// buddhism.c

inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
        if( (int)me->query_skill("spells") <= (int)me->query_skill("iori-spells") )
                return notify_fail("��ķ�����Ϊ����������޷�ѧϰ��ʸ֮��\n");
        if( (int)me->query("bellicosity") < 100 )
                return notify_fail("���ɱ��̫�ͣ��޷�������ʸ֮����\n");
        return 1;
}

string cast_spell_file(string spell)
        {
return CLASS_D("kof") + "/iori-spells/" + spell;

        }

string type() { return "magic";}


