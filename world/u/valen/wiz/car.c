// By tianlin 2001.5.8

#include <ansi.h>
#include <weapon.h>
inherit SWORD;
string check_ip(object ob, object *user);
void create()
{
        set_name(HIG"ֱ���ɻ�"NOR, ({ "flyto" }) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 500000);
                set("long", "һ�ܾ��õ�ֱ���ɻ���\n");        
    }
        setup();
        init_sword(100);
}
void init()
{
        add_action("do_flyto","flyto");
}
int do_flyto(string arg)
{
        int flyto_inventory = 0;
        object obj,me;
        string msg;
        me=this_player();
        if( !arg ) return notify_fail("��Ҫȥ���\n");
        if( sscanf(arg, "-i %s", arg) ) flyto_inventory = 1;
        if( !arg ) return notify_fail("��Ҫȥ���\n");
        obj = find_player(arg);
        if(!obj) obj = find_living(arg);
        if(!obj || !me->visible(obj)) {
                arg = resolve_path(me->query("cwd"), arg);
                if( !sscanf(arg, "%*s.c") ) arg += ".c";
                if( !(obj = find_object(arg)) ) {
                        if( file_size(arg)>=0 )
                                return me->move(arg);
                        return notify_fail("û�������ҡ������ط���\n");
                }
        }
        if(!flyto_inventory && environment(obj))
                obj = environment(obj);
        if( !obj ) return notify_fail("������û�л������� flyto��\n");
    if( stringp(msg = me->query("env/msg_mout")) )
       {if (msg!="") message_vision(msg+"\n", me);}
        else
              message_vision(HIC"$N���һ���ѷɻ������������߿շ�ȥ!\n"NOR, me);
        me->move(obj);
                message_vision(HIC"$N���˸��ط��ѷɻ�ͣ����,�Լ���Ϣ��һ��!\n"NOR, me);
        if( stringp(msg = me->query("env/msg_min")) )
       {if (msg!="") message_vision(msg+"\n", me);}
        else
              message_vision("", me);
        return 1;
}