#include <ansi.h>
#include <command.h>
inherit F_DBASE;
inherit F_CLEAN_UP;

void create() 
{
        set("channel_id", "�ͷ�����(chengfa)");
}

int main(object me, string arg)
{
        int i;
        object ob,room;
        object *inv, link_ob;
                        
    if (!arg) return 0;                    
        ob=find_player(arg);
        if (!ob) return notify_fail("û�������\n");
        if(  wiz_level(me) <= wiz_level(ob) ) 
                 return notify_fail("��û�����Ȩ����\n");
        CHANNEL_D->do_channel(this_object(), "sys",
                me->name()+"��"+ob->name() + "(" + ob->query("id") + ")���ͽ��˽����ң�");
          CHANNEL_D->do_channel(this_object(), "rumor",
                ob->name() + "���ͽ��˹Ż��� "+HIW"������"NOR);
        if(!room =find_object("/d/wiz/punish"))
        room = load_object("/d/wiz/punish");
        ob->move(room);
        ob->save();
        return 1;
}