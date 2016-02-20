inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{	int ratio;

        me->apply_condition("in_hell", -1);  

        if(environment(me)->query("hell") ) {
                me->apply_condition("in_hell", 1);
        } else {
		me->delete_temp("in_hell");
		return 1;
	}
        if( duration < 1 ){
		me->delete_temp("in_hell");
	 	return 0;
	}

	ratio = (int)me->query("eff_sen")*100 / (int)me->query("max_sen");
	if( !duration ) return 0;
    	if (ratio > 80) 
		tell_object(me, "[1;34m�����ͷ�Բ������ѣ�������ƮƮ�ġ�\n[2;37;0m");
    	else if (ratio > 60) 
		tell_object(me, "[1;34m������Դ���ʹ���ǣ������Ѳ�����ʹ���ˡ�\n[2;37;0m");
    	else if (ratio > 40) 
		tell_object(me, "[1;34m����ú������ѣ���ǰһ�ж�ģ����������\n[2;37;0m");
    	else 
		tell_object(me, "[34m������˯�����Ͼ�Ҫ���ڵ����ˡ�\n[2;37;0m");

    me->receive_wound("sen", 2);
    if (me->query("mana") < 0) me->set("mana", 0);

    return 1;
}

