// cast caozi
// by mhsj@gslxz 2001/6/12
#include <ansi.h>

inherit F_CLEAN_UP;

int cast(object ob,string arg)
{
        object me;
        int shiwu, yinshui, jin, qi;
          if (!arg)  me = ob;

	if((int)this_player()->query_skill("spells") < 30
	 || (int)this_player()->query_skill("xbuddhism",1) < 40)
		return notify_fail("�㻹ûѧ��ʳ�����\n");

	if( (int)this_player()->query("eff_kee") < (int)this_player()->query("max_kee") / 2 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

	if( (int)this_player()->query("eff_sen") < (int)this_player()->query("max_sen") / 2 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

	if( (int)this_player()->query("mana") <4*(int)this_player()->query_skill("spells"))
		return notify_fail("��ķ��������ˣ�\n");

        if(this_player()->query("family/family_name") != "���")
                return notify_fail("ֻ������ĵ��Ӳ���ʹ�ô����\n");

	if( random(this_player()->query("max_mana")) < 200 ) {
		this_player()->add("mana",-(int)me->query_skill("spells"));
		this_player()->receive_damage("sen",10);
		message("vision", "����ʲôҲû�з�����\n", environment(me));
		return 1;
	}

          if (!me) return notify_fail("�㲻�ܶԱ���ʹ��ʳ�ۣ�\n");
   
          jin = this_player()->query("max_sen");
          qi = this_player()->query("max_kee");
   
            shiwu = this_player()->max_food_capacity();
             yinshui = this_player()->max_water_capacity();

            this_player()->set("eff_sen", jin);
            this_player()->set("eff_kee", qi);

             this_player()->set("food", shiwu*3);
            this_player()->set("water", yinshui*3);

	     this_player()->add("mana", -300);

          write(HIC"ʳ��ʹ�óɹ���\n"NOR);
          return 1;
}
