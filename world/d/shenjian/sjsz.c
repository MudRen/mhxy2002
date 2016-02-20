//By tianlin@mhxy for 2002.1.13

#include <ansi.h>
inherit ROOM;
void jiang_jing(object where);
void finish_jing(object where);
void check_time(object where);           
int do_hear();

void create()
{
        set("short", "��ɽׯ");
        set("long", @LONG
��������������˾���֪����ɽׯ���������������ٶ���ķ�����
ӿ����֤�����������������Ĳ׺�ɣ��ߴ����¥��Ժǽ��������Ϊ��
�����˽����������ɸߵ���ľ���ų����ţ���ǰ���ż�������ʯ��˨��׮
���ŵ��Ϸ��߹���һ��������ң�����Ծ�������д��:

                 [37;40m����������������������[0m
                 [37;40m��[31m   �� �� ɽ ׯ  [37;40m  ��[0m
                 [37;40m����������������������[0m

LONG
        );
        set("exits", ([ 
   "south" : __DIR__"sroad3",
   "north" : __DIR__"rroad",
]));
  set("objects", ([
		__DIR__"npc/guard4" : 4,
		__DIR__"npc/zhangmen" : 1,
              	]));
  set("outdoors", __DIR__);
  setup();
        
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
   if(phase==4&&(!query("jiangjing"))) jiang_jing(where);
   if(phase==5&&query("jiangjing")) finish_jing(where);
   call_out("check_time",60,where);
}
void jiang_jing(object where)
{
message("channel:chat",HIW+"��"HIC"��ɽׯ"NOR+HIW"��"NOR+HIY"���Ŵ����[Zhang men]:"HIG"��ɽׯ��������,���ڿ�ʼ���ڱ����������.(Hear) \n"+NOR,users());
   tell_object(where,"ѩӰ�ɷ���ν��л���崴����������ص��ɷ�.\n");
   set("jiangjing",1);
     set ("long", @LONG

��������������˾���֪����ɽׯ���������������ٶ���ķ�����
ӿ����֤�����������������Ĳ׺�ɣ��ߴ����¥��Ժǽ��������Ϊ��
�����˽����������ɸߵ���ľ���ų����ţ���ǰ���ż�������ʯ��˨��׮
���ŵ��Ϸ��߹���һ��������ң�����Ծ�������д��:

                 [37;40m����������������������[0m
                 [37;40m��[31m   �� �� ɽ ׯ  [37;40m  ��[0m
                 [37;40m����������������������[0m

LONG);
}
void finish_jing(object where)
{
   set("jiangjing",0);
}
int do_hear()
{
   object me=this_player();
   if(me->is_busy())
      return notify_fail("����æ���ء�\n");
   if(!query("jiangjing"))
      return notify_fail("��û��ʼ�ڷ���.\n");              
   if((string)me->query("family/family_name")!="��ɽׯ")
      return notify_fail(CYN"���Ŵ����˵:���ɵ��Ӳ�����������\n"NOR);
    if(me->query("faith")>400)
      return notify_fail("������Լ������������ˡ�\n");
    tell_object(me,"��ȫ���ע����������ֱ�������ԡ�\n");
   me->start_busy(3);
   me->add("faith",1);
   me->add("combat_exp",12);
   me->add("potential",3);
   me->improve_skill("xueying-xianfa",100);  
   me->receive_damage("kee",20);
   me->receive_damage("sen",20);
   return 1;
}                                                                    

