// finger.c

#include <ansi.h>

inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	object ob;

	if( !arg ) {
		if( (int)me->query("jing") < 50 )
			return notify_fail("��ľ����޷����С�\n");
		if( !wizardp(me) )
			me->receive_damage("jing", 50);
		write( FINGER_D->finger_all() );
	} else {
		if( (int)me->query("jing") < 15 )
			return notify_fail("��ľ����޷����С�\n");
		if( !wizardp(me) )
			me->receive_damage("jing", 15);
		write( FINGER_D->finger_user(arg) );
                ob=find_player(arg);
                if (ob&&me->visible(ob)&&(me!=ob)) {
                        tell_object(ob,HIY"�㲻�ɵô���һ����ս...\n"NOR);
                        message("channel:chat", HIG +"�����ġ���....��...."+ ob->query("name")+
"����һ��������...��ˬ��.\n"NOR, users());
		}
	}
	return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : finger [ʹ��������]
 
���ָ��, ���û��ָ��ʹ��������, ����ʾ�����������������
����������. ��֮, �����ʾ�й�ĳ����ҵ�����, Ȩ�޵�����.
 
see also : who
HELP
    );
    return 1;
}
 
