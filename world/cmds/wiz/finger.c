// finger.c
#include <ansi.h>

inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	if( !arg ) {
		if( (int)me->query("sen") < 50 )
			return notify_fail("��ľ����޷����С�\n");
   if(arg = "xiuxiu") return notify_fail("ʲô? \n");
		if( !wizardp(me) )
			me->receive_damage("sen", 50);
		me->start_more( FINGER_D->finger_all() );
//		write( FINGER_D->finger_all() );
	} else {
	    
	    // mon 9/1/98 the following chars will cause an error.
	    arg=replace_string(arg,"#"," ");
	    arg=replace_string(arg,"."," ");

		if( (int)me->query("sen") < 15 )
			return notify_fail("��ľ����޷����С�\n");
	if( time()-(int)me->query_temp("finger_end") < 1&& !wizardp(me) )
                return notify_fail("�㲻������finger ID��\n");
		if( !wizardp(me) )
			me->receive_damage("sen", 15);
		write( FINGER_D->finger_user(arg) );
		          me->set_temp("finger_end",time());
}
	return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ�� finger
           finger [ʹ����Ӣ�Ĵ���]
           finger [ʹ����Ӣ�Ĵ���]@Mudname
 
���ָ����û��ָ��ʹ��������������ʾ�����������������
���������ϡ���֮�������ʾ�й�ĳ����ҵ����ߣ�Ȩ�޵����ϡ�
 
see also : who, mudlist
HELP
    );
    return 1;
}
 
