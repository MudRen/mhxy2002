inherit ITEM;

void wakeup(object,object);

void create()
{
    set_name("˯��", ({ "sleepbag" }) );
        set_weight(1500);
        set_max_encumbrance(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
          set("unit", "ֻ");
          set("long",
"����һֻ��ͨ����֯˯����������ʿ��������Ұ��¶�ޡ�\n");
          set("value", 1000);
        }
}

int is_container()      {return 1;}

int init()
{
    add_action("do_sleep", "sleep");
}

int do_sleep()
{
        int rnd;
        object me = this_player();
        object where = environment(me);

        if (me->is_busy())
                return notify_fail("����æ���أ�\n");
        if( me->is_fighting() )
                return notify_fail("ս���в���˯����\n");
        where->set("no_fight", 1);
        where->add_temp("sleeping_person", 1);


message_vision("$Nչ��һֻ˯�������˽�ȥ����һ����ͽ��������㡣\n",this_player());

        rnd = 10 + random((100 - me->query_con()) / 3);

        me->set("no_get", 1);   
        me->set("no_get_from", 1);      
        
        if (!(where->query("hotel"))) 
                me->set_temp("sleeped",1);
        else
                me->delete_temp("rent_paid");

        me->disable_player(" <˯����>");

        if ( rnd < 1 ) rnd = 0;
        call_out("wakeup", rnd + 10, me, where);
        
        return 1;
}

void wakeup(object me,object where)
{
        me->set("qi",    me->query("eff_qi"));
        me->set("jing",  me->query("eff_jing"));
        me->add("neili", me->query("max_neili")/2 - me->query("neili")/2
);
        me->enable_player();
  
        message_vision("$Nһ����������������ػ��һ�½�ǡ�\n",me);
        me->set_temp("block_msg/all", 0);
        write("��һ��������ֻ���������档�ûһ���ˡ�\n");

        if (!where->query("sleep_room") && !where->query("hotel"))
                where->delete("no_fight");
     
        where->add_temp("sleeping_person", -1);
        me->delete("no_get");   
        me->delete("no_get_from");      
 
}