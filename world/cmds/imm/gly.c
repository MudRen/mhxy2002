//By waiwai@mszj 2000/07/20
//ħ��֮��

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
   if (!arg) return notify_fail(HIC"�����ӿո��͹���ԱƵ����Ϣ\n"NOR);
   shout(HIG "��MUD����Ա��"+me->name() +": "+ arg + "\n"NOR);
   write(HIG "��MUD����Ա��"+me->name() +": "+ arg + "\n" NOR);
   return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : gly <ѶϢ>
 
���ָ�����㽫 <����ԱѶϢ> ���ͳ�ȥ, ����������Ϸ�е��˶�
��������Ļ�,����tune���κ�����
 
HELP
    );
    return 1;
}
 
