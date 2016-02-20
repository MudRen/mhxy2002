// spiritforce.c �� ����
//created by foc,10-6-01
//�ص㣺������������ѧϰ�������ô����Ǻܶ�ġ�ҪС��ѧϰ����ϰ
//�п��ܻ�����������

inherit FORCE;

#include <ansi.h>

int valid_enable(string usage) 
{ 
     return usage=="force"; 
}

int valid_learn(object me) 
{
        if( (int)me->query("int") < 25 || (int)me->query_skill("literate", 1 ) < 109 )
        return notify_fail("������Բ����Կ�ʼ�˽�ʲô��������\n");
        if( (int)me->query_skill("spiritforce", 1 ) > 285 )
        return notify_fail("���������Ϊ�Ѿ�����ǰ��δ�еľ��磬Ҫ�ٽ����ǲ����ܵ��ˡ�\n");
        if( (int)me->query_skill("force", 1) < 60 )
        return notify_fail("�����ڵ����ʸ���û�취��ʼ������������\n");
        if( (int)me->query_skill("force", 1) < (int)me->query_skill("spiritforce", 1) )
{
        me->receive_damage("kee", (int)me->query_skill("spiritforce", 1) * 2 );
        message_vision(HIR"$N�����ڵ�����ͻȻ��ʼ�����������ͣ�$N���ɵòҽ�һ������Ѫ��\n����ȫ�����˳�����\n"NOR,me);
        write ("��������Ļ���û�д�á�\n");
}
        if( (int)me->query("max_kee") < 350 && (int)me->query_skill("spiritforce", 1) < 60 && (int)me->query_skill("spiritforce", 1) > 30 )
        return notify_fail("�������Ѿ������������ĵڶ��׶����У�û���㹻��������û�취Ӧ���ġ�\n"); 
        if( (int)me->query_skill("force", 1)/3 > (int)me->query_skill("spiritforce", 1 ) - random((int)me->query("kar")) )
{
        me->improve_skill("spiritforce", 80000 );
        message_vision(HIC"$N�ƺ�������ʲô���������ϵ������͵ؽ����ˣ�"NOR,me);
}
        return 1;
}

int practice_skill(object me)
{
      if( (int)me->query_skill("spiritforce", 1 ) < 60 )
      return notify_fail("ͨ����ϰ�����������⣡�����ƺ����������Ϊ�������Կ�ʼ�������С�\n��ϧ�����ɣ�����������ˡ�\n");
      if( (int)me->query_skill("force", 1) < 100 )
      return notify_fail("��Ļ�������������ô��ϰ�㲻�þ��̱����ˣ�\n");
      if( (int)me->query("max_kee") < 350 && (int)me->query_skill("spiritforce", 1) < 60 && (int)me->query_skill("spiritforce", 1) > 30 )
      return notify_fail("�������Ѿ������������ĵڶ��׶����У�û���㹻��������û�취Ӧ���ġ�\n"); 
      if( (int)me->query_skill("force", 1) < (int)me->query_skill("spiritforce", 1) )
{     
      me->receive_damage("kee", (int)me->query_skill("spiritforce", 1) * 2 );
      message_vision(HIR"$N�����ڵ�����ͻȻ��ʼ�����������ͣ�$N���ɵòҽ�һ������Ѫ��\n����ȫ�����˳�����\n"NOR,me); 
      write ("û���㹻�Ļ����ɲ��������ϰ������\n");
}
      if( (int)me->query_skill("force", 1)/4 > (int)me->query_skill("spiritforce", 1) - random((int)me->query("kar")) )
{
      me->improve_skill("spiritforce", 80000 );
      message_vision(HIC"$N�ƺ�������ʲô���������ϵ������͵ؽ����ˣ�"NOR,me);
}
      if( (int)me->query_skill("spiritforce", 1 ) > 285 )
      return notify_fail("���������Ϊ�Ѿ�����ǰ��δ�еľ��磬Ҫ�ٽ����ǲ����ܵ��ˡ�\n");
      
      return 1;
}

string exert_function_file(string func)
{
      return CLASS_D("mojie") + "/spiritforce/" + func;
}


void skill_improved(object me)
{
      if((int)me->query_skill("spiritforce", 1 )==70 )
{
      me->add("str", 2 );
      message_vision(GRN"$N���ŷų���������������γ��˾޴���������У������ݲݶ��������ˣ��ۣ�\n"NOR,me);
      write ("����������˿����������Լ���������ǿ�ˡ�\n");
}
      if((int)me->query_skill("spiritforce", 1 )==140 )
{
      me->add("spi", 2 );
      message_vision(GRN"$Nȫ�������ͻȻ�Լ����˳������ڿ������γ���һ��ģ�������Ρ�\n���Ǻܿ����ʧ�ˡ�"NOR,me);
}
      if((int)me->query_skill("spiritforce", 1 )==210 )
{
      me->add("max_force", 400 );
      message_vision(GRN"$Nȫ�������ͻȻ�ͷų������γ�һ���˾޴�ķ�ˡ�$N�����Լ���������ʲô����ȴ˵��������\n"NOR,me);
}
      if((int)me->query_skill("spiritforce", 1 )==280 )
{
      me->add("con", 2);
      me->add("cps", 2);
      me->add("cor", 3);
      me->add("spi", 2);
      me->add("int", 3);
      me->add("kar", -2);
      me->add("per", 3);
      me->add("daoxing", 500000);
      me->add("combat_exp", 500000);
      me->improve_skill("segokee",10000);
      message_vision(HIY"$N��˫�۷ų����ɫ�Ĺ⣬����ȫ�������Ҳ����˴����ɫ������������ʥ�����ˣ�����\n�����涼û���ɹ����ռ�������\n"NOR,me);
      write ("������ʮ����ϲ�������뵽��������Ϊ������ʼɵĶ������������������ٺ͸�Ե�������̾�˿�����\n");
      message("channel:rumor", HIM + "��ҥ�ԡ��������棺��˵"+
     me->query("name")+"���ɴ�˵�е�ʥ�����ˣ��ۣ����������ҵ�λ�Ӱɣ�\n"NOR,users());

}

}
