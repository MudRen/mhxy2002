//By waiwai@mszj 2000/08/25
 
#include <ansi.h>

#include <command.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

void create() 
{
        seteuid(getuid());
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
                me->name()+"��"+ob->name() + "(" + ob->query("id") + ")���ͽ������Σ�");
          CHANNEL_D->do_channel(this_object(), "rumor",
                ob->name() + "����������ͽ��,�ؽ����λ�����"+HIW"����"NOR);
        if(!room =find_object("/d/wiz/punish"))
        room = load_object("/d/wiz/punish");
        ob->move(room);
        ob->save();
        return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : chufen <ID>

���ָ��ὫMUD�в�����Ϸ�������ҹؽ�������.

HELP
    );
    return 1;
}


