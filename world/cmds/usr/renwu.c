inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int type,min,sec;
	string id,name,msg;
	int start,time,left;
	object obj;

	if(undefinedp(me->query("oldsix_quest")))
		return notify_fail("�㲢û����ȡ�κ�����\n");
	type=me->query("oldsix_quest/type");
	id=me->query("oldsix_quest/id");
	name=me->query("oldsix_quest/name");
	start=me->query("oldsix_quest/start");
	time=me->query("oldsix_quest/time");
	sec=time%60;
	min=time/60;
	msg="�����������"+chinese_number(min)+"��"+
		chinese_number(sec)+"���ڣ�";
	if(type==1)	msg+="��"+name+"("+id+")ɱ�ˡ�\n";
	else if(type==2)msg+="�ҵ�"+name+"("+id+")��\n";
	else if(type==3)msg+="�ѻ��͵�"+name+"��\n";
	else if(type==4)msg+="Ϊ�����ĽһλNPC���ڡ�\n";
	else 		msg+="Ϊ�������һ����̡�\n";
	if(type==2)	{
		obj=present(id,me);
		if(objectp(obj)&&obj->query("name")==name)	{
			me->set("oldsix_quest/over",1);
		}
		else	me->set("oldsix_quest/over",0);
	}
	if(! (int)me->query("oldsix_quest/over"))
		msg+="�������δ��ɣ�\n";
	else	msg+="��������Ѿ���ɣ�\n";
	left=time-(time()-start);
	if(left<=0)	msg+="���Ѿ���������������ˡ�\n";
	else	{
		sec=left%60;
		min=left/60;
		msg+="�뽻���ʱ�仹��";
		if(min)	msg+=chinese_number(min)+"��";
		msg+=chinese_number(sec)+"�롣\n";
	}
	write(msg);
	return 1;
}

