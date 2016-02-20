// dobusy.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;
        int length;

        if( me!=this_player(1) ) return 0;

        if( !arg || sscanf(arg, "%s", arg)!=1 )
                return notify_fail("ָ���ʽ��dobusy <ʹ�ö���>\n");
        
        if( !objectp(ob = present(arg, environment(me))))
                return notify_fail("��ֻ�ܸı������ʹ���ߵķ�Ӧ����ʱ�䡣\n");

        ob->start_busy(5000);
        
        message_vision(HIM "$N��$n��<��Ӧ����ʱ��>���ĳ����ޣ�$n���ڽ����벻���ж�״̬��\n" NOR, me, ob);
        
ob->setup();

        return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : dobusy <ĳ��>

�����޸�ĳʹ���ߵķ�Ӧ����ʱ�䣬����䲻�ܲ�ȡ�κ��ж���
һ����������ʵ��ʱ���Լ60���ӵ�Busy Time��

HELP
    );
    return 1;
}