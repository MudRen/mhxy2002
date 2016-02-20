//By tianlin@mhxy for 2002.2.26

#include <ansi.h>
inherit ROOM;
void jiang_jing(object where);
void finish_jing(object where);
void check_time(object where);
int do_hear();

void create()
{
	set("short", "�����");
	set("long",

"\n̫���������ڼ�λǰ�ܷ�����������ı���½�Ϊ������������������\n"+
"�����͡�����Ϊ��Щ������������һ����¥����Ի"+HIY"�������"NOR+"����\n"
"¥���ܹҽǣ�������������������������ǰ���ۿ���\n\n"
	);
	set("no_fight", 1);
	set("item_desc", ([ /* sizeof() == 1 */
  "up" : HIC"¥���������������Ǵ�����յ�����������뺨��\n"NOR,
]));
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
           __DIR__"npc/qinbing" : 2,
            "/d/jjf/npc/chengyaojin": 1,
]));
	set("light_up", 1);
	set("exits", ([ /* sizeof() == 2 */
       "up" : __DIR__"qilin2",
       "east" : "/d/city/xuanwu-n0",
]));

	setup();
	replace_program(ROOM);
}
void init()
{
    object where=this_object();
    remove_call_out("check_time");
    check_time(where);
    add_action("do_hear","hear");
}
void check_time(object where)
{
   mixed *local = localtime((time()-900000000)*60);
   int t = local[2] * 60 + local[1];

   int phase=((int)(t/120));
   if(phase==5&&(!query("jiangbing"))) jiang_jing(where);
   if(phase==6&&query("jiangbing")) finish_jing(where);
   call_out("check_time",60,where);
}
void jiang_jing(object where)
{
message("channel:chat",CYN+"��"RED"���ƽ�����"CYN"��"NOR+WHT"��ҧ��[Cheng yaojin]��"CYN"���ƽ������ڽ����䳡�����"HIR"(Hear)\n"+NOR,users());
tell_object(where,"��������ҧ�������������  .  ����   .���  . ��ˡ�\n");
tell_object(where,"��������ҧ���������ǹ�ˣ����Ǳ��ҳ�ʶ�����Ҫ�������š�\n");
tell_object(where,"........................................\n");
   set("jiangbing",1);
}
void finish_jing(object where)
{
   tell_object(where,"��ҧ��˵���������Ϣһ��ɡ�\n");
   set("jiangbing",0);
}
int do_hear()
{
 object yao;
   object me=this_player();

   if(me->is_busy())
      return notify_fail("����æ���ء�\n");
   if(!query("jiangbing"))
      return notify_fail("��û�п�ʼ�ء�\n");

 if((string)me->query("family/family_name")!="������")
      return notify_fail("��������ģ�\n");
   if(me->query("faith")>1000)
      return notify_fail("��ҧ�����˵���������ȥ��Щ�������������ˡ�\n");
   tell_object(me,"����ų�ҧ�𽲵ĶԼ��ˡ�\n");
   me->start_busy(4);
   me->add("faith",1);
   me->add("combat_exp",60);
   me->add("potential",50);
   me->improve_skill("baguazhou",1000);  
   me->receive_damage("kee",20);
   me->receive_damage("sen",20);
   return 1;
}
