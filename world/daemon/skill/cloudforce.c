//By tianlin@mhxy for 2001.12.5

// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// cloudforce.c
inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return
notify_fail("�����ķ�ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}
string exert_function_file(string func)
{
        return CLASS_D("shenjian") + "/cloudforce/" + func;
}

