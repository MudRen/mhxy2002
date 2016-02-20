// ˭������ /cmds/adm/checkemote.c��emote.o���м���
// by llm ���߾��Ϊ���䣬ʹ���������أ���������Ƶ���������������
//Ϊ��ֹ����ʹ�ø�����ǰ�����Ƚ�ԭ����emote.o���б���
//ֻҪ��һ����������ָ��Ϳ��Բ�����

inherit F_CLEAN_UP;

string *e;//һ��ȫ�ֵ����������ȡ������emote�Ĵ�

int do_soucha(int,int);

int main(object me, string arg)
{
    int j,k;

    if( !arg ||arg!="-S")
    	return notify_fail("��ȷ��Ҫ����emote��ʽ������������ -S������\n");

    e = EMOTE_D->query_all_emote();//ȡ�ؼ��ʣ���������e����ȥ��
    j = sizeof(e);//�����ܹ�emote����
    write("Ŀǰһ���� "+j+" ��emote����ʼ���ǰ40��......\n\n");
    k = 0;
    return do_soucha(k,j);
}

int do_soucha(int k,int j)
{
    int i,max;
    mapping emote;

    seteuid(getuid());

    if((j-k) > 40) max = (k+40);//ÿ������40��
   	else max = (j-k);

    for(i=k; i<max; i++)
    {
		emote = EMOTE_D->query_emote(e[i]);//ȡ������ʵ�����       	
       	write(e[i]+"\n");//��ʾһ������
       	if(emote["new"]) continue;
//��Ϊnew��������Ǳ�ϵͳ���еģ����������ʾ������д�ģ�û��Ҫ����
       	if(emote["myself"]) emote["myself"]=0;
       	if(emote["myself_self"]) emote["myself_self"]=0;
       	if(emote["myself_target"]) emote["myself_target"]=0;
       	if(emote["target"]) emote["target"]=0;                //���
       	if(!emote["updated"]) emote["updated"]="sys";
/*û��updated�����ľͼ�һ����ΪʲôҪ�ӣ���Ϊ�����emoteϵͳ�updated������ָemote������
��Ҫ������ұ༭ʱ�������ǲ��ܸġ�ɾ���˵�emote����ˣ��������е�emoteӦ�ü���һ����Ҳ���
���е����֣���sysһ���Ǵ����MUD���ֹ��ҵ�¼��ID����Ҳ����������logind.c���ֹ����õ���
��ID��
*/
       	EMOTE_D->set_emote(e[i], emote);//�洢
       	write("��������ɹ���\n");//����һ��
    }
    if(j > 40)
   	{
   		j -= 40;//����������40����ֱ��ȫ������
   		k += 40;//��һ���𲽽�ǰ��40��
		write("���������40��emote��(y/n)");
        input_to("confirm",1,k,j);
	}
	else
    	write("\n����emote���ݼ�������ϡ�\n");
    return 1;
}

int confirm(string yn,int k,int j)
{
	if(!yn) return 1;
    if( yn[0]=='y' || yn[0]=='Y' )
    {
        write("�������......\n");
    	return do_soucha(k,j);//��ʱ��j,k���仯�ˣ��ٴ�ִ��
    }
    else
        write("ֹͣ��飡\n");
    return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ��checkemote -S

��鲢����emote.o�ļ���ע�⣺��Ҫ����emoteϵͳ֧�֡�
HELP
    );
    return 1;
}