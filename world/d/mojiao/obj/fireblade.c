#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
   set_name(RED "ħ��" NOR, ({"fire blade", "blade", "dao"}));
   set_weight(5000);
   set("unit", "��");
   set("long", "һ�����ɫ�ĵ���������ȼ����һ�������һ�\n");
   set("value", 89000);
   set("material", "fire");
   set("wield_msg",
"$N��һ��$n����ʱһ�����ֱ��������\n");
   set("unwield_msg",
"$N����Ľ�$nһ�꣬������һ�Ż����������У�\n");

   init_blade(50);

   if( clonep(this_object()) ) {
     set_default_object(__FILE__);
   }
   setup();
}

void init()
{   
   remove_call_out("do_melt");
   call_out("do_melt", 1);
}

void do_melt()
{
   if(this_object()) call_out("melt", 40+random(40));
}

void melt()
{
   object env;

        if(!this_object()) return;

   env=environment(this_object());

   if( env->is_character() )
   {//a player or a NPC.
     if( (int)env->query_skill("evil-force", 1) < 120 )
     {
        message_vision("ֻ��������һ������һ�£�$N���ϱ������˼������ݡ�\n", env);
        env->apply_condition("heavy_fire_poison", 10);
        //note, �ж��ˡ�
        destruct(this_object());
        return;
     }
   }

   else if( (int)env->query_max_encumbrance() > 0 && !environment(env) )
   {//a room.
     if( (string)env->query("outdoors") != "mojiao" )
     {
        tell_object(env,"���ϵĻ������˼��±�Ϩ�ˡ�\n");
        destruct(this_object());
        return;
     }
   }

}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int pro;
        int dam;
        dam = (int) me->query("max_force");
        victim->receive_damage("kee",90);
        return HIR "$N�˾��͵�һ�����е�ħ������ʱ��������ħ��������$n��$n���յĽ�ͷ�ö����\n" NOR;
}
