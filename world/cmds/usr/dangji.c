//by tianlin 2001.5.1

#include <ansi.h>
inherit F_CLEAN_UP;

int report()
{
      write("�λ�����("HIR"����ԭ��"NOR")��");
      write(read_file("/log/static/shutdown"));
    return 1;
}

int main()
{
	report();
//          write("\n");
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : dangji
 
���ָ����������MUDΪʲô������
 
HELP
    );
    return 1;
}


