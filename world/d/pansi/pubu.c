//By tianlin@mhxy for 2002.2.25

#include <ansi.h>
inherit ROOM;
void jiang_jing(object where);
void finish_jing(object where);
void check_time(object where);
int do_hear();

void create()
{
        set("short", "�ٲ�");
        set("long", @LONG
��������ˮ�����������¡¡�����糱ˮ����һ�㣬̧ͷһ����ֻ��һ
�����ٲ����������ӵ������Ӹ�����ֱк������������������Ԩ������������
��������ͷ��������
LONG );
        set("exits", ([ /* sizeof() == 2 */
                "south" :  __DIR__"tao_out",
        ]));
                    set("objects",([
                __DIR__"npc/qingxia" : 1,
        ]));
        set("outdoors", "xiaoyao" );
        set("no_clean_up", 0);
        setup();
}
 
void init()
{
    object where=this_object();
    remove_call_out("check_time");
    check_time(where);
add_action("do_jump","jump");
    add_action("do_hear","hear");
}

int do_jump(string arg)
{
        object ob;
        int new_sen;
        ob = this_player();
        new_sen = random( ob->query("max_sen")*3 );
        if ( new_sen > ob->query("sen") ) new_sen = ob->query("sen") + 1;
        if( !arg || arg=="" ) return 0;
        if( arg != "down" )
                return notify_fail("����Ҫ������ɱ����ô�벻������\n");
        tell_object(ob, HIR"�㲻��˼��������һԾ�����������¡�������\n"NOR);
        message("vision", NOR"ֻ��" + ob->query("name") + "�����ң���������������֮�С�������\n"NOR, environment(ob), ob);
        if((ob->query_skill("dodge",1)<30)){ ob->unconcious();
        ob->receive_damage("sen",new_sen);
        ob->move(__DIR__"yanfeng");
                }else{
           ob->move(__DIR__"yanfeng");
        }
        return 1;
}
void check_time(object where)
{
   mixed *local = localtime((time()-900000000)*60);
   int t = local[2] * 60 + local[1];

   int phase=((int)(t/120));
   if(phase==5&&(!query("maren"))) jiang_jing(where);
   if(phase==6&&query("maren")) finish_jing(where);
call_out("check_time",60,where);
}
void jiang_jing(object where)
{
message("channel:chat",CYN+"��"MAG"����ɽ��˿��"CYN"��"NOR+HIM"��ϼ����[Qingxia xianzi]��"NOR+HIY"���һ��: "NOR+CYN"����ɽ��˿�����ӵ��Ӻ��ڡ�"HIR"(Hear)\n"+NOR,users());
tell_object(where,"��������ϼ����˵��: ���ǽ��......����....����.....��\n");
tell_object(where,"��������ϼ����˵�����Ǹ�����....����ð����....����.....����...��\n");
tell_object(where,"........................................\n");
   set("maren",1);
}
void finish_jing(object where)
{
   tell_object(where,"�㿴����ϼ���ӵ����������ˡ�\n");
   set("maren",0);
}
int do_hear()
{
 object yao;
   object me=this_player();

   if(me->is_busy())
      return notify_fail("����æ���ء�\n");
   if(!query("maren"))
      return notify_fail("��û�п�ʼ�ء�\n");

 if((string)me->query("family/family_name")!="��˿��")
      return notify_fail("��������ģ�\n");
   if(me->query("faith")>1000)
      return notify_fail("��ϼ���Ӷ���˵�����������������ϻ�\n");
   tell_object(me,"�㿴����ϼ���ӵ���������ʮ��ʹ�ġ�\n");
   me->start_busy(4);
   me->add("faith",1);
   me->add("combat_exp",60);
   me->add("potential",50);
   me->improve_skill("pansi-dafa",1000);  
   me->receive_damage("kee",20);
   me->receive_damage("sen",20);
   return 1;
}



