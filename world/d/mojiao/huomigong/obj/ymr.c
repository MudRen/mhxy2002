//modify by ken 2001.7.7
#include <ansi.h>
inherit F_UNIQUE;
#include <weapon.h>

inherit BLADE;

void create()
{
   set_name(HIR "��ħ��" NOR, ({"evil blade", "blade", "dao"}));
   set_weight(5000);
   set("unit", "��");
   set("long", "һ�����ɫ�ĵ����������Ƿǳ���а����������ÿ��������ѵ�ʱ
����Ҫɱ�˵�������\n");
   set("value", 89000);
   set("material", "fire");
   set("wield_msg",
"$N���͵�һ�ĵ��ʣ���ʱ��һ��ȫ��ð�������һ��ħ������һ�����ɫ�ĳ���
������$N�����У�\n");
   set("unwield_msg",
"$N����Ľ�$nһ�ģ�$n������һ�������ɽ���$N�����\n");
   set("replace_file", "/d/mojiao/obj/fireblade");

   init_blade(210);

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
     if( (int)env->query_skill("evil-force", 1) < 140 )
     {
        message_vision("ֻ��������һ������һ�£�$N���ϱ������˼������ݡ�\n", env);
        env->apply_condition("evil_fire_poison", 10);
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
        victim->receive_damage("kee",dam/10);
        return HIR "��ħ�л���������������$n��һ���ȷ�ɨ��֮��$nֻ���õ��������������\n" NOR;
}
