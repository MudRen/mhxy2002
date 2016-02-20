//modify by ken
#include <weapon.h>
inherit SWORD;
#include <ansi.h>
inherit F_UNIQUE;

void create()
{
   set_name(HIR"����"NOR, ({"world sword", "sword","jian"}));
   set_weight(5000);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("long", "���������¡�\n");
     set("value", 50000);
     set("material", "steel");
     set("replace_file","/d/obj/weapon/sword/qingfeng");
     set("wield_msg", HIR"$N��������һ�ӣ���ʱһƬ���ֱ��������\n"NOR);
     set("unwield_msg", HIR"���һ�������·ɻ���$N�����С�\n"NOR);
   }
   init_sword(200);
   setup();
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int pro;
        int dam;
        dam = (int) me->query("force");
        victim->receive_damage("kee",dam/20);
        victim->start_busy(1);
                switch(random(7)) {
                        case 0: return HIR "����һ�¾��ҵ���$n�Ŀ��£����һ�����У���ʹ��Խ��$n���͵ļ��ޣ�$n��˵��ڵ���ʹ�ధ����\n" NOR;
                        case 1: return HIW "�������������$n�Ŀ���һ�£��������ص�һ����$n�����˵��ϣ�������һ����ʹ��\n" NOR;
                        case 2: return HIB "���µĵ���ɨ����$n����ۣ�һ�°�$n����۴���ˣ�ֻʣ��һЩƤ�����ŶϹǡ�\n" NOR;
                        case 3: return HIC "$N������������$n���ұۣ���һ�°�$n����������ˣ���$n�����ִ���˲м���\n" NOR;
                        case 4: return HIR "$N˳���������´���$n���۾����������$n�Ĵ��̫���ˣ���Ϊ$n���۾������ˡ�\n" NOR;
                        case 5: return RED "$N������������$n�����ȣ������׾Ͱ�$n�����ȴ����ˣ����$n���ŽŲ�ͣ�ĲҺ���\n" NOR;
                        case 6: return RED "$N�������¶���$n���ҽţ�һ�󽹳�����$n�ܾ���ķ�������һ���ȸ���˵���ټ���\n" NOR;
                     }        
}
