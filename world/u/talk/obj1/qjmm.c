// keeangjian.c

#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
     object obj;// where = environment(me);
    int oexp,mexp;
    seteuid(getuid());

//    if (environment(me)->query("no_steal")||environment(me)->query("no_fight"))
//         return notify_fail("���컯��֮�£�������\n");

    if (!arg || !objectp(obj = present(arg, environment(me))))
         return notify_fail("�����ںܳ嶯������һ���޶�û�С�\n");

    if (me->query("gender") =="����")
         return notify_fail("�����Ǹ����߶�û�У�����ɺ��£�\n");

    if (me->query("gender") =="Ů��")
         return notify_fail("�ۣ�����Ů��Ҳ��ǿ������ˣ�̫�����ˣ�\n");

    if (me->query("age") < 17)
         return notify_fail("����ʮ���궼û������ѧ������\n");

    if (obj==me) return notify_fail("�Լ�ǿ���Լ��������������\n");

    if (obj->query("gender") != "Ů��")
         return notify_fail("���԰ɡ���������Ů�˰ɡ�\n");

    if (obj->query("age") < 10)
         return notify_fail("�˼һ�����Ů����\n");

    if (!obj->is_character()) return notify_fail("�ۣ����Ķ��������Ź���\n");

    if (!living(obj) )
         return notify_fail(obj->name() + "����ǿ���ˡ��ÿ�����\n");

    if( !wizardp(me) && wizardp(obj) )
         return notify_fail("ǿ����ʦ���㲻��ɱ����\n");

    if( me->is_fighting() )
         return notify_fail("һ�ߴ��һ��ɫ���ԣ������ǻ����ˣ�\n");

    if( obj->is_fighting() ) 
         return notify_fail(obj->name() + "���ڴ�ܣ��㲻�±��ˣ�\n");

    tell_object(me,"��ɫ��������һ����" + obj->name() + "�˹�ȥ�����ֱ�Ҫȥ��"
             + obj->query("name") + "���·���\n\n");
    tell_object(obj,me->name()+"�װͰ͵����˹��������־��볶������·���\n\n");
    message("vision", "ֻ��" + me->name() + "��ݺݵ�����"+obj->name()
            + "һ��ץס�����·���\n\n\n", environment(me), ({ me,obj }) );
    oexp=obj->query("daoxing");
    mexp=me->query("daoxing");

    if ((mexp<oexp)||(random(2))==1)
    {
      tell_object(me, HIR "��⣡���Ǵ����ˣ�\n\n" NOR);
      message_vision("$N����һ�壬����$n��ȵ�������ɫ�ǣ���\n", obj, me);
      if( userp(obj) ) obj->fight_ob(me);
      else obj->kill_ob(me);
      me->fight_ob(obj);
      me->start_busy(3);
    }
    else 
    {
      message_vision("$N�������ڵأ��������ȣ���ɫ�ǣ�ƴ��������\n",obj,me);
      message_vision("$nһ����Ц��������$n���¸�������\n",obj,me);
      message_vision("���ҵ������ڷ�����$N�������ˡ�\n",obj,me);
 CHANNEL_D->do_channel(this_object(),"rumor","��˵"HIR+me->name()+HIM"��"HIY+obj->name()+HIM"��ǿ���ˡ�");
      me->set("kee",me->query("eff_kee"));
      me->set("force",me->query("max_force"));
      me->add("daoxing",2);
      me->add("sen",-1000);
      me->add("max_atman",1);
      obj->add("max_atman",1);
//      me->set("couple/have_couple",1);
      me->start_busy(3);
      obj->add("eff_gin",-5);
    }
    return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : rape | keeangjian <ĳ��>

HELP
    );
    return 1;
}


