// LLY@FYSY 
#include <ansi.h>


inherit ITEM;

void create()
{
        set_name(HIG"��ˮ��" NOR,({"fish"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",
                HIW "����������ֻ�д��Ʒ��µ���ˮ���������������˵�����м����ҩ�ü�ֵ��\n"NOR);
                set("unit","��");
                set("value", 50000);
        }
}
void init()
{
        add_action("do_eat","eat");
}
int do_eat(string arg)
{
        int m_kee;
        int m_sen;
        int m_gin;
        int m_force;
        if ( arg == "fish"){
                m_kee = this_player()->query("max_kee");
        m_sen = this_player()->query("max_sen");
        m_gin = this_player()->query("max_gin");
        m_force = this_player()->query("max_force");
        message_vision(HIR"$N��һ������ˮ�������У����̻��ʣ������ͷ�����³�����\n"NOR,this_player());
        this_player()->set("eff_kee",m_kee);
        this_player()->set("kee",m_kee);
        this_player()->set("eff_gin",m_gin);
        this_player()->set("gin",m_gin);
        this_player()->set("eff_sen",m_sen);
        this_player()->set("sen",m_sen);
        this_player()->set("force",m_force);
        this_player()->set("food",200);
        this_player()->set("water",200);
        destruct(this_object());
             return 1;
     }
     return 0; 
}
