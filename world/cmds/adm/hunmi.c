 
#include "/doc/help.h"
#include <ansi.h>

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	if (!arg) return notify_fail("ָ���ʽ: smash <living>\n");
	ob = present(arg, environment(me));
	if (!ob) return notify_fail("�Ҳ���������\n");
	message_vision(HIR + "�����һ�����ٿȻ������ס��$n��$nӦ��ˤ���ڵ��ϣ���\n" + NOR,me,ob);
	ob -> unconcious();
	return 1;
}
 
int help(object me)
{
   write(@HELP

ָ���ʽ: hunmi <id>
 
ʹĳ�����̻��Բ���

HELP
   );
   return 1;
}
