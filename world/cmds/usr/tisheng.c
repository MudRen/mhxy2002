inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string banghui,someone,something,skl;
	int i,money,exp,level;
	object ob;
	
	if(! arg)	return notify_fail("��ʹ��help tisheng���鿴�����\n");
	if(sscanf(arg,"%s %s",something,someone)!=2)
		return notify_fail("��ʹ��help tisheng���鿴�����\n");
	if(something=="-skl")	{
		if(sscanf(someone,"%s %s",skl,someone)!=2)
			return notify_fail("��ʹ��help tisheng���鿴�����\n");
	}
	if(something!="-skl"&&something!="-exp"&&something!="-zc")
		return notify_fail("��ʹ��help tisheng���鿴�����\n");
	if(! ob=present(someone,environment(me)))
		return notify_fail("���û����ô���ˡ�\n");
	if(! ob->is_character())
		return notify_fail("����������������\n");
	if( userp(ob))
		return notify_fail("��ֻ����������NPC���ڵļ��ܡ�\n");
	if( !living(ob))
		return notify_fail("����Ȱ�"+ob->query("name")+"Ū����˵��\n");
	if(me->is_fighting()||me->is_busy())
		return notify_fail("����æ���ء�\n");
	if(ob->is_fighting()||ob->is_busy())
		return notify_fail(ob->query("name")+"��æ���ء�\n");
	if(! stringp(banghui=me->query("banghui")))
		return notify_fail("��û�вμ��κΰ�ᣬ�޷������κ�NPC��\n");
	if( banghui!=(string)ob->query("banghui"))
		return notify_fail("��ֻ������������ڵ�NPC���ڡ�\n");
	if(sizeof(children(base_name(ob)+".c"))>2)
		return notify_fail(ob->query("name")+"�ƺ����ڲ���������������\n");
	if(! ob->query("zhengzhao"))
		return notify_fail("���޷�����"+ob->name()+"��\n");
	if(something=="-skl")		{
		level=(int)ob->query_skill(skl,1);
		if(! level)
			return notify_fail(ob->query("name")+"�����������书��\n");
		if(level>=200)
			return notify_fail(ob->query("name")+"�������书��ѧ�����ˡ�\n");
		money=level*level*10;
		if((int)me->query("balance")<money)	{
		return notify_fail("�����ϵ�Ǯ������"+ob->query("name")+
		"�������书����һ������Ҫ"+MONEY_D->money_str(money)+"��\n");
		}
		ob->set_skill(skl,level+1);
		me->add("balance",-money);
		me->save();
		ob->save();
		write("�㻨��"+MONEY_D->money_str(money)+"����"+
		ob->query("name")+"��"+to_chinese(skl)+"������һ����\n");
	}
	else if(something=="-exp")	{
		if((int)ob->query("combat_exp")>=2000000)
			return notify_fail(ob->query("name")+"��ʵս�����Ѿ������ˡ�\n");
		money=10000;
		if(me->query("balance")<10000)
			return notify_fail("�����ϵ�Ǯ������"+ob->query("name")+
			"��ս����������1000����Ҫһ���ƽ�\n");
		me->add("balance",-money);
		me->save();
		ob->add("combat_exp",1000);
		ob->save();
		write("�㻨��һ���ƽ𣬽�"+ob->query("name")+
		"��ս������������һǧ�㣡\n");
	}
	else if(something=="-zc")	{
		money=10000;
		if(me->query("balance")<10000)
			return notify_fail("�����ϵ�Ǯ������"+ob->query("name")+
			"���ҳ϶�����һ����Ҫһ���ƽ�\n");
		if((int)ob->query("zhongcheng")>=(int)ob->query("max_zhongcheng"))
			return notify_fail(ob->query("name")+"���ҳ϶��Ѿ��ﵽ��󣬲���Ҫ���������ˡ�\n");
		me->add("balance",-money);
		me->save();
		if((int)ob->query("zhongcheng")+10>=(int)ob->query("max_zhongcheng"))
			ob->set("zhongcheng",(int)ob->query("max_zhongcheng"));
		else	ob->add("zhongcheng",10);
		ob->save();
		write("�㻨��һ���ƽ𣬽�"+ob->query("name")+
		"���ҳ϶�������ʮ�㣡\n");
	}
	return 1;
}


int help(object me)
{
        write(@HELP

ָ���ʽ��tisheng <-skl> <�书����> <npc id>
          tisheng <-zc> <npc id>
          tisheng <-exp> <npc id>

����ָ��������������������NPC���书�ȼ�(skills)��
ս������(exp)���ҳ϶�(zhongcheng)������������ĳ��
NPC��Ϊ���������ս�������ҳ϶ȣ���Ҫ������Ǯ��
�����������
�书�ȼ�����ָ�����书����һ��(���Ϊ200��)
          ����Ǯ�����NPC�ĵ�ǰ�书�ȼ��йء�
ս�����飺ÿ��������ս�����鳤һǧ��(���Ϊ2M)
          ����Ǯ��Ϊһ���ƽ�
�ҳ϶ȣ�  ÿ���������ҳ϶ȳ�ʮ�㣬ֱ���ﵽ����ҳ϶ȡ�
          ����Ǯ��Ϊһ���ƽ�
HELP
        );
        return 1;
}
