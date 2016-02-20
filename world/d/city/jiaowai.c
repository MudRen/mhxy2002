// Room: /d/city/jiaowai8.c
//����lywin4/29

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
    set("short", "С����");
    set("long", @LONG
���ǳ��������һƬС���֣���Ӣ�ͷף������裬��¶Ϧ�⣬����
��Ƣ�������ѿ�����������ʱ����ΧС���ſŽ���������������С��С
ȸ�������ϻ��裬һ��Ҳ�����ˡ������Ǹ�����da���ĺû��ᡣ
LONG );
    set("exits", ([
        "east" : "/d/kaifeng/east1",
        "west" : __DIR__"dongmen",
    ]));
    set("no_clean_up", 0);
    set_temp("wayao1",1);
    set("outdoors", "yangzhou");
    setup();
}

void init()
{
        add_action("do_da", "da");
}


int do_da()
{
        object me;
        int i, kar, cps, bb,mm;
        me = this_player();

        if(me->is_busy())
             return notify_fail("�㻹�ǵȹ�װ���˼��ٴ���ɣ�\n");

        if(me->query("kee")<10)
             return notify_fail(HIR"�㻹������Ϣһ�°ɣ����ҲҪ������Ӵ����\n"NOR);

                           me->start_busy(3);
        message_vision("$N�����ʱ��ˣ�õ�С��С������׼���ϵ�Сȸ��ȥ......\n", me);

               message_vision("$Nֻ������һ�����������\n",me);
        kar = me->query("kar");
        
        if (random(kar)>15) {
                message_vision("$N��һֻ"HIW"������\n"NOR, me);
                      if (me->query("combat_exp")>=50000)
                        tell_object(me,"���Ѿ������ô����������ˡ�\n");
                      if (me->query("potential")>=10000)
                        tell_object(me,"���Ѿ������ô����������ˡ�\n");
                else {
                        bb=(int)me->query("combat_exp");
                        me->set("combat_exp",100+bb);
                        tell_object(me,"��õ���100�㾭��\n");
                }
       me->receive_damage("kee", 10);
                bb=(int)me->query("potential");
                      if (me->query("combat_exp")>=50000)
                        tell_object(me,"���Ѿ������ô����������ˡ�\n");
                      if (me->query("potential")>=10000)
                        tell_object(me,"���Ѿ������ô����������ˡ�\n");
                else {
                        me->set("potential",40+bb);
                        tell_object(me,"��õ���40��Ǳ��\n");
                }

                return 1;
        }
        
        if (random(kar)>10) {
                message_vision("$N��һֻ"HIY"��˿ȸ��\n"NOR, me);
                      if (me->query("combat_exp")>=50000)
                        tell_object(me,"���Ѿ������ô����������ˡ�\n");
                      if (me->query("potential")>=10000)
                        tell_object(me,"���Ѿ������ô����������ˡ�\n");
                else {
                        bb=(int)me->query("combat_exp");
                        me->set("combat_exp",80+bb);
                        tell_object(me,"��õ���80�㾭��\n");
                }
       me->receive_damage("kee", 10);
                bb=(int)me->query("potential");
                      if (me->query("combat_exp")>=50000)
                        tell_object(me,"���Ѿ������ô����������ˡ�\n");
                      if (me->query("potential")>=10000)
                        tell_object(me,"���Ѿ������ô����������ˡ�\n");
                else {
                        me->set("potential",bb+30);
                        tell_object(me,"��õ���30��Ǳ��\n");
                }

                return 1;
        }
        
        if (random(kar)>8) 
            {
               message_vision("$N��һֻ"HIG"���ġ�\n"NOR, me);
                bb=(int)me->query("combat_exp");
                      if (me->query("combat_exp")>=50000)
                        tell_object(me,"���Ѿ������ô����������ˡ�\n");
                      if (me->query("potential")>=10000)
                        tell_object(me,"���Ѿ������ô����������ˡ�\n");
                        else {
                        tell_object(me,"��õ���50�㾭��\n");
                        me->set("combat_exp",50+bb);
                }
            me->receive_damage("kee", 10);  
                
                bb=(int)me->query("potential");
                      if (me->query("combat_exp")>=50000)
                        tell_object(me,"���Ѿ������ô����������ˡ�\n");
                      if (me->query("potential")>=10000)
                        tell_object(me,"���Ѿ������ô����������ˡ�\n");
                else {
                        me->set("potential",bb+20);
                       tell_object(me,"��õ���20��Ǳ��\n");
               }

               return 1;
       }

        if (random(kar)>5) 
            {
               message_vision("$N��һֻ"YEL"��ȸ��\n"NOR, me);
                bb=(int)me->query("combat_exp");
                      if (me->query("combat_exp")>=50000)
                        tell_object(me,"���Ѿ������ô����������ˡ�\n");
                      if (me->query("potential")>=10000)
                        tell_object(me,"���Ѿ������ô����������ˡ�\n");
                        else {
                        tell_object(me,"��õ���10�㾭��\n");
                        me->set("combat_exp",20+bb);
                }
            me->receive_damage("kee", 10);  
                
                bb=(int)me->query("potential");
                      if (me->query("combat_exp")>=50000)
                        tell_object(me,"���Ѿ������ô����������ˡ�\n");
                      if (me->query("potential")>=10000)
                        tell_object(me,"���Ѿ������ô����������ˡ�\n");
                else {
                        me->set("potential",bb+10);
                       tell_object(me,"��õ���20��Ǳ��\n");
               }

               return 1;
       }
        else 
           {
                me->receive_damage("kee", 10);  
                message_vision("$NʲôҲû�򵽡�\n",me );
     }

        return 1;
}

