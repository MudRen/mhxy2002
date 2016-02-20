// link
#include <ansi.h>
inherit ROOM;
int do_tiao(string arg);
int do_look(string arg);
int do_dao(string arg);
int do_jia(string arg);
void create()
{
	set("short", HIC"�����ϰ��"NOR);
	set("long", @LONG
���������繩�����ϰ�Ṧ�õ�ɳ�أ�shachi���ˣ������������ͨ��
����tiao��ɳ������ϰ���������������ɳ���Ļ���������������ӣ�jia��
��ɳ�ӡ�����������������ĵ�����˭Ҳ��Ը�������鷳��
LONG
	);
	set("exits", ([ 
  "north" : __DIR__"lingjie7",
  "east" : __DIR__"mdc",
  "west" : __DIR__"pool",
]));
	set("item_desc", ([
	"shachi"  :  "����һ����ɳ�أ�����������ɳ������(tiao)ȥ��\n",
	]));
	set("valid_startroom",1);
	set("coor/x",-20);
	set("coor/y",-60);
	set("coor/z",0);
	setup();
}
void init()
{
	object me=this_player();
	add_action("do_tiao", "tiao");
	add_action("do_tiao", "jump");
	add_action("do_jia", "jia");
	add_action("do_dao", "dao");
	add_action("do_look", "look");
	if(me->query_temp("run/circle"))
	call_out("do_run",6,this_player());
}
void do_run(object me)
{
	int i=random(me->query_skill("force")/2);
	if(!me || environment(me) != this_object())
                return;
	tell_object(me,"������һ������������ǰ��ȥ����\n");
	me->receive_damage("kee",i);
	if (random(3)>2) {me->improve_skill("move",random(me->query("agi"))/2);}
	me->add_temp("run/circle",-1);
	me->move(__DIR__"pdindoor");
}
int do_tiao(string arg)
{
	object me=this_player();
	int costj=random((int)me->query("con"))+1;
	int costq=random((int)me->query("str"))+1;
	int weight=me->query_temp("shachi/weight");
	if (me->is_busy()) return notify_fail("��������æ���أ�\n");
	if (me->is_fighting()) return notify_fail("������ս���У��޷�ר��������\n");
	if ( !living(me)) return notify_fail("�㷢���ˣ�\n");
	if ( !arg || arg != "shachi" ) return notify_fail("����ɳ����ı������˰��죬���˻���Ϊ�㷢�񾭣�\n");
	if (weight>(me->query("con")+me->query("str"))/5) return notify_fail("�����ٻ�Ҫȥ��"+chinese_number(weight-(me->query("con")+me->query("str"))/5)+"�����ɳ�����ö���\n");
	if ((int)me->query("gin") < costj || (int)me->query("kee") < costq){
		message_vision(RED"$N����һ���������һ������ɳ����ˤ�˸�����ʺ��\n"NOR,me);
		me->unconcious();
		return 1;
		}
	else if ((int)me->query_skill("dodge")<20&&random(10)>6||me->query("guild/name")=="�˶���"){
	if (weight){
	me->receive_damage("gin", costj+weight/2);
	me->receive_damage("kee", costq+weight/2);
	me->improve_skill("dodge",(int)(me->query("int")/4)+weight/2);
	}
	else {
	me->receive_damage("gin", costj);
	me->receive_damage("kee", costq);
	me->improve_skill("dodge",(int)(me->query("int")/4));
	}
	message_vision("$N�������ܣ�����ɳ����ȥ��\n", me);
	write(MAG"�����һԾ���н������Լ������Լ��Ļ����Ṧ������ߣ�\n"NOR);
	me->start_busy(2);
	return 1;
	}
	return notify_fail("���ˮƽ����ôǿ�˻����������������˰ɣ�\n");
}
int do_jia(string arg)
{
	object me=this_player();
	int weight;
	if (me->is_busy()) return notify_fail("��������æ���أ�\n");
	if (me->is_fighting()) return notify_fail("������ս���У��޷�ר��������\n");
	if ( !living(me)) return notify_fail("�㷢���ˣ�\n");
	if (!present("shadai",me)) return notify_fail("�㶼û��ɳ������ʲô�ӣ�\n");
	if (!arg ||sscanf(arg, "%d kilo", weight)!=1) return notify_fail("��ָ��һ����ֵ������jia 10 kilo��\n");
	if (weight <5 )	return notify_fail("���ӵ������������幫�\n");
	me->add_temp("shachi/weight",weight);
	message_vision("$N����������ɳ��������"+chinese_number(weight)+"�����ص�ɳ�ӡ�\nװ��ɳ���С�\n",me);
	return 1;
}
int do_dao(string arg)
{
	object me=this_player();
	int weight;
	if (me->is_busy()) return notify_fail("��������æ���أ�\n");
	if (me->is_fighting()) return notify_fail("������ս���У���Ͼ�˼�ɳ�������⣡\n");
	if ( !living(me)) return notify_fail("�㷢���ˣ�\n");
	if (!present("shadai",me)) return notify_fail("�㶼û��ɳ������ʲô����\n");
	if (!arg ||sscanf(arg, "%d kilo", weight)!=1) return notify_fail("��ָ��һ����ֵ������dao 10 kilo��\n");
	if ( weight <=0 )	return notify_fail("����������������һ���\n");
	if (me->query_temp("shachi/weight")<weight) return notify_fail("��ʲô��Ц��ɳ�������ܹ���û��"+chinese_number(weight)+"���\n");
//	write(weight);
	me->add_temp("shachi/weight",-weight);
	message_vision("$N���������Ӵ�ɳ���������浹����"+chinese_number(weight)+"�����ɳ�ӡ�\n",me);
	return 1;
}
int do_look(string arg)
{
	object me=this_player();
	int weight=me->query_temp("shachi/weight");
	if (arg!="shadai") return 0;
	if (weight<=0) return 0;
	write("һ��������ɳ�غͰ����ܲ���ɳ����\n");
	write("���Ǹ�����װ��"+chinese_number(weight)+"����ɳ��ɳ�����������Ӧ����������tiao��ɳ�ػ���\n�������ɳ����dao������\n");
	return 1;
}
int valid_leave(object me, string dir)
{
	if (me->query_temp("shachi")) {
	message_vision(YEL"$N����������ɳ���е�ɳ��\n" NOR,me);
	me->delete_temp("shachi");
	return 1;
	}
	else return 1;
}