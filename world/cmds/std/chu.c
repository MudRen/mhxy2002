// by tianlin 2001.7.3
#include <dbase.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object room,obj;
	int argg;

	seteuid( geteuid(me) );

	if( me->is_busy() ) return notify_fail("������û�пգ�\n");

	if( !arg )
		return notify_fail("ָ���ʽ��chu <����>\n");

	sscanf(arg,"%d",argg);
//����ʦ���õ�·��
	if( !(room=find_object("/d/city/center")) )
		room= clone_object("/d/city/center");
	
	if( !(obj=present("paimai shi",room)) )
	{
		obj=new("/d/city/npc/paimaishi");
		obj->move("/d/city/npc/paimaishi");

		return notify_fail("����ʦ������ʮ�ֽ�ͷ����û����������\n");
	}

	else
	{
		if( !(obj->query("on_paimai")) ) 
			return notify_fail("����û����������\n");
	}

//	if( me->query("id") == obj->query("forbid") )
//		return notify_fail("�����ڱ���ֹ���뾺�ġ�\n");
	
	if( argg <= obj->query("value")*21/20 )
	{
		tell_object(me,"�����̫�͡�\n");
		return notify_fail("������"+chinese_number(obj->query("value"))+"�����ӣ�\n");
	}

	if( argg*105 > me->query("balance") )
		return notify_fail("��û����ô��Ĵ�\n");

	obj->report_paimai(me,argg,obj->query("number"));
	tell_object(me,"�����"+chinese_number(argg)+"�����ӣ�\n");

	me->start_busy(2);

	return 1;

}

int help(object me)
{
   write( @HELP
ָ���ʽ: chu <����> 

��һָ��������Բ���Ͷ�꣬��λΪ �����ӡ�
HELP
   );
   return 1;
}
 