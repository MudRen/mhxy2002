// huifu.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;
        int length;

        if( me!=this_player(1) ) return 0;

        if( !arg || sscanf(arg, "%s", arg)!=1 )
                return notify_fail("ָ���ʽ��huifu <ʹ�ö���>\n");
        
        if( !objectp(ob = present(arg, environment(me))) )
                return notify_fail("��ֻ�ָܻ������ʹ���ߵ�״̬��\n");

        ob->remove_all_enemy();

        message_vision(GRN "$N��$n���һ������������$n�����ҿ����Ͽ����¿����ԹԵ�ͣ���ˡ�\n" NOR, me, ob);
        
      ob->setup();

        return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : ding <ĳ��>

ָֹͣ������ǰ��ս����

HELP
    );
    return 1;
}