// callplayer.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string file;
	file ="/log/static/CALL_PLAYER";
	seteuid(geteuid(me));
	write("CALL_PLAYER�ǵ����������¼�¼��\n");
	write("-------------------------------------------------------------------------------------------\n");
	cat(file);
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : callplayer
 
��ʾCALL_PLAYER�������ݡ�
��Ϊ�����ӱ�MUD�Ĺ�ƽ�ԡ�
�ô�����ල��ʦ��

XYX.98.6.17

HELP
    );
    return 1;
}
