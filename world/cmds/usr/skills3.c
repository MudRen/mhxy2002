//skills.c
//modified by yushu 2001/5/6
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object ob;
	mapping skl, lrn, map;
	string *sname, *mapped;
	int i;

	seteuid(getuid());

	if(!arg)
		ob = me;
	else{
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("��Ҫ�쿴˭�ļ��ܣ�\n");
	}
	if( ob!=me && ob->query("env/invisibility")&&!wizardp(me) )
		return notify_fail("��Ҫ�쿴˭�ļ��ܣ�\n");

	if( ob!=me && !wizardp(me) 
	&& !ob->is_apprentice_of(me) 
	&& !me->is_apprentice_of(ob) 
	&& getuid(ob)!=me->query("bonze/dadangid")
	&& getuid(ob)!=me->query("couple/id"))
		return notify_fail("ֻ����ʦ����ʦͽ��ϵ�����ܲ쿴���˵ļ��ܡ�\n");

	skl = ob->query_skills();
	if(!sizeof(skl)) {
		write( (ob==me ? "��" : ob->name()) + "Ŀǰ��û��ѧ���κμ��ܡ�\n");
		return 1;
	}
	sname  = sort_array( keys(skl), (: strcmp :) );
       printf( CYN"                       ����"NOR HIR" %s "HIW"��ѧ�似��"NOR  CYN" ����\n",ob->name());
       printf("�����������������������������������������������ө��������ө����ө�������\n");
       printf("��       ��               ��                  �� ��  �� ���ȼ��� �� �驧\n");
       printf("�ĩ��������������������������������������������ة��������ة����ة�������\n");
	map = ob->query_skill_map();
	if( mapp(map) ) mapped = values(map);
	if( !mapped ) mapped = ({});
	lrn = ob->query_learned();
	if( !mapp(lrn) ) lrn = ([]);
	for(i=0; i<sizeof(skl); i++) {
	printf(CYN"��"NOR"%s%s%-40s"      NOR "             %-10s %4d/   %5d"CYN"��\n"NOR, 
			(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
			(member_array(sname[i], mapped)==-1? "  ": HIG"��"HIY),
			to_chinese(sname[i]) + " (" + sname[i] + ")"NOR,
			SKILL_D(sname[i])->level_description(skl[sname[i]]),
			skl[sname[i]], (int)lrn[sname[i]],
		);
	}
	printf(CYN"������������������������������������������������������������������������\n"NOR);
	write((ob==me ? "��" : ob->name()) +"Ŀǰ������"HIR+chinese_number(sizeof(skl))+NOR"��ܡ�\n\n");
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : skills|jineng [<ĳ��>]

���ָ����������ѯ��ѧ���ļ��ܡ�

��Ҳ����ָ��һ��������ʦͽ��ϵ�Ķ����� skills ���Բ�֪�Է��ļ���״����

��ʦ���Բ�ѯ�κ��˻� NPC �ļ���״����

HELP
    );
    return 1;
}
