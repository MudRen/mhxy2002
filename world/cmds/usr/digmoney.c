//By tianlin@Mhxy for 2002.1.7

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me,string arg)
{
	object room,ob;
	mapping baobiao_path;
	int value,number;

	if(me->is_busy()) return notify_fail("����һ��������û����ɣ�\n");
	room=environment(me);
        message_vision("$N�ڵ��Ͼ���һ�����,ʲôҲû�ҵ�,ֻ�ðѿ�����ƽ��!\n",me);
        me->receive_damage("kee",random(10)+5);
        me->start_busy(3+random(3));
	if( !(baobiao_path=room->query("dig_money")) ) return 1;
	if( !mapp(baobiao_path) || random(4) ) return 1;

	if(!(value=baobiao_path["value"])) return 1;
	if(!(number=baobiao_path["number"])) return 1;
	room->delete("dig_money");	

	ob=new("/obj/money/gold");
	if(!ob) return 1;
	message("channel:chat",HIR"��Ѱ�����顿ĳ�ˣ�"+"��˵"+me->query("name")+HIR"�ҵ��˲���ү�����˼�ı�����\n"NOR,users());
	message_vision(CYN"ͻȻ���������䣬��$N�ڵ���һ�޲Ʊ�����ϸһ������Ȼ��"+chinese_number(value)+"���ƽ�\n"NOR,me);
	ob->set_amount(value);
	"/adm/daemons/moneyd"->del_log(""+number);
	ob->move(room);
	return 1;
}
