// By tianlin 2001.5.1
// edit.c
#include "/doc/help.h"
#include <ansi.h>
inherit F_CLEAN_UP;
mixed query(string arg)
{
    if (arg && arg=="channel_id")
      return  RED"���߱༭(Edit)";
    return 0;
}
int main(object me, string file)
{
    string filename;
    if( !file ) return notify_fail("ָ���ʽ��edit <����>\n");
    if( in_edit(me) ) return notify_fail("���Ѿ���ʹ�ñ༭���ˡ�\n");
    filename=resolve_path(me->query("cwd"), file);
    if (!(int)SECURITY_D->valid_write(filename,me,"write"))
            return notify_fail("��û���㹻�Ķ�дȨ����\n");
    foreach (object user in users())
        if (filename == "/"+in_edit(user) )
            return notify_fail("�����ͻ��"+user->name(1)+"("+capitalize(user->query("id"))+")"+"���ڱ༭���ļ�("+filename+")��\n");
    printf("�༭�ļ���%s\n",filename);
CHANNEL_D->do_channel(this_object(),"sys",sprintf("%s(%s)�����߱༭(%s)��"
,me->name(1),capitalize(me->query("id")),filename));
    log_file("edit/"+geteuid(me), sprintf("edit %s %s\n", resolve_path(me->query
("cwd"), file), ctime(time())) );
    seteuid(geteuid(me));
    ed(resolve_path(me->query("cwd"), file));
    me->set("cwf",filename);
    return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : edit <����>, edit here
���ô�һָ���ֱ�������ϱ༭������
[36m/ ǰ���������������ŵ��ַ�������/�ƴ�
? �����������������ŵ��ַ�
= ��ʾ��ǰ���ǵڼ���
a �ڵ�ǰ�к�������һ��
A ����'a'������ǽ���ת�Զ�����ģʽ
c ����ǰ�����ݸ��ǵ������±༭����
d ɾ��ָ����Χ����
e �˳���ǰ����, ��ʼ�༭��һ��(�����ı��δ������Ч)
E ����'e'��������ļ����޸Ĺ�Ҳ��Ч
f ��ʾ��ı��ļ���
g ����ƥ���в�����ִ����Ӧ����
h �����ļ�(������ʾ�����ڿ�������Щ��Ϣ��������Ӣ��)
i �ڵ�ǰ��ǰ�����һ��
I �Ű��������� (Qixx version 1.0)
j �ϲ��У�ϵͳĬ���ǽ����������ӵ���ǰ��
k ��ǵ�ǰ��- later referenced as 'a
l ��ʾָ����(����ʾ�����ַ�)
m �ƶ�ָ����(����)��ָ��λ��
n �к���ʾ�л�����
O ͬ����'i'
o ͬ����'a'
p ���ָ����Χ��
q �˳��༭��
Q �˳��༭������ʹ�ļ��Ѿ����޸���δ����
r ���ļ�β��ָ���к������һ�ļ�
s ���Ҳ��滻(ֻ�Ե�ǰ�е�һ�����ҵ��ַ��������滻)
set ��ѯ���ı�ͱ���༭�����趨ֵ
t ����ָ���е�ָ��λ��
v �������Բ�ƥ����ִ��ָ������
x �����ļ����˳�
w ���༭������д����ǰ�ļ���ָ�����ļ���
W ����'w'��������ǽ��༭�����ݸ��ӵ�ָ����ǰ�ļ���
z ��ʾ20�У����ò��� . + -
Z ��ʾ40�У����ò��� . + -[2;37;0m[4;53m[1;37m[5m��Щ�ǽ̻�����ôʹ��editָ��.[2;37;0m
[4;53m[41m[1;33mBy tianlin 2001.5.1[2;37;0m
HELP
    );
    return 1;
}
