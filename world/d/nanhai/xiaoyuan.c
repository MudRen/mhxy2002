//By tianlin@mhxy for 2002.3.6

#include <ansi.h>
void jiang_jing(object where);
void finish_jing(object where);
void check_time(object where);
int do_hear();

inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "СԺ");
  set ("long", @LONG

����һ��СԺ��Ժ�б鲼�滨��ݣ����������Ժ��������
������ʵʵ����һ����������֮���ڡ�
LONG);

  set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/tidu" : 1,
]));
  set("outdoors", "/d/nanhai");
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"guangchang",
  "west" : __DIR__"zoulang",
  "south" : __DIR__"gate",
  "east" : __DIR__"zoulang2",
]));

create_door("south", "ʯ��", "north", DOOR_CLOSED);
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
   if(phase==5&&(!query("nianjing"))) jiang_jing(where);
   if(phase==6&&query("nianjing")) finish_jing(where);
   call_out("check_time",60,where);
}
void jiang_jing(object where)
{
message("channel:chat",CYN+"��"HIY"�Ϻ�����ɽ"NOR+CYN"��"NOR+WHT"���ɮ(Tidu seng)��"CYN"�о�ʱ�䵽��,���ӵ����ٵ���Ժ�о���ϰ�𷨣���(Hear)\n"+NOR,users());
tell_object(where,"���������ɮ����� @@~$%%~~~&~@@#~$% ��\n");
tell_object(where,"........................................\n");
   set("nianjing",1);
}
void finish_jing(object where)
{
   tell_object(where,"���ɮ˵���������Ϣ�ɡ�\n");
   set("nianjing",0);
}
int do_hear()
{
 object yao;
   object me=this_player();

   if(me->is_busy())
      return notify_fail("����æ���ء�\n");
   if(!query("nianjing"))
      return notify_fail("���ɮ��û�п�ʼ�о���ϰ�𷨡�\n");

 if((string)me->query("family/family_name")!="�Ϻ�����ɽ")
      return notify_fail("���ɵ��Ӳ�����������\n");
   if(me->query("faith")>1000)
      return notify_fail("���ɮ����˵���������ȥ��Щ�������������ˡ�\n");
   tell_object(me,"��������ɮ�Ŀ��������Ķ��š�\n");
   me->start_busy(5);
   me->add("faith",1);
   me->add("combat_exp",30);
   me->add("potential",5);
   me->improve_skill("buddhism",300);  
   me->receive_damage("kee",20);
   me->receive_damage("sen",20);
   return 1;
}
