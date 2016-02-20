#include <weapon.h>
#include <ansi.h>

inherit FORK;
inherit F_UNIQUE;

void create()
{
        set_name( HIB"Ѫ��"NOR,({ "xie cha", "xie", "cha", "fork"}) );
        set_weight(70000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("unique", 1);
                set("rigidity", 10);
                set("no_give", "���������Ѫ����ô������������?\n");
                set("sharpness", 9); 
                set("material", "steel");
                set("weapon_prop/parry", 5);
                set("weapon_prop/dodge", -12);
                set("treasure",1);
                set("wield_force", 1500);
                set("wield_maxforce", 2100);
                set("wield_str", 32);
                set("wield_msg", HIY"$N�˵�һ����������Ѫ�棬����Ѫ�����䣬ɱ����ã��
��Բ֮�ں�Ȼ������������ɱ��֡�\n"NOR);
                set("long", "�˲泤�߳ߣ����������������������������ޱȣ�
ɱ��ɭȻ��ʵ�����µ�һ�����\n");                
                set("unwield_msg", BLU "$N��Ѫ���ؼ��ɱ���ټ���\n" NOR);               
}
        init_fork(160);
        setup();
}
