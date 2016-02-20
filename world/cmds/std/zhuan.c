// open.c

#include <room.h>

inherit F_CLEAN_UP;

int main(object me,string arg)
{
	int exp, pot, tpot,pot_cost;
            if( !arg
        ||      !sscanf(arg, "%d", pot_cost) )
                return notify_fail("��Ҫ������Ǳ���޵���\n");

	tpot = (int) me->query("potential");
	pot = (int) me->query("potential")- (int) me->query("learned_points");
	exp = (int) me->query("combat_exp");
  if( pot < pot_cost )
                return notify_fail("�����ڵ�Ǳ��̫���ˣ��޷����������Լ������Ч����\n");
  else 
   //    if (pot_cost<-exp/2)
     if (pot_cost<0)
        return notify_fail("���޷�����ת��Ǳ�ܣ���\n");
   else	
        exp = exp+pot_cost * 1;
	me->set("combat_exp",exp );
	me->set("potential", tpot-pot_cost);	
	write("�ϣ�,��ԭ�����Ը����!\n");
	return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : transfer
 
���ָ��������㽫Ǳ��תΪ���飨��������,
Ҳ����1000��Ǳ�ܿ���ת1000����ѧ
 
HELP
    );
    return 1;
}
