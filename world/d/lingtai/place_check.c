inherit F_DBASE;

void create()
{
  seteuid(getuid());
}

void check_kill(object who,object ob)
{
   object hufa;
   
   if(ob->query("class")=="taoist"){
      tell_room(environment(who),"ͻȻ��ⶸ�֣������������һ���Ʋʣ��߳���λ��������ȵ���\n");
      tell_room(environment(who),"�󵨿�ͽ�����ڷ���ɽɱ�����ŵ��ӣ����Ҵ��˵ط���\n");
      hufa=new(__DIR__"npc/hufa");
      hufa->move(environment(who));
      hufa->set_hushan();
      hufa->kill_ob(who);
      who->kill_ob(hufa);
      
      hufa=new(__DIR__"npc/hufa");
      hufa->move(environment(who));
      hufa->set_hushan();
      hufa->kill_ob(who);
      who->kill_ob(hufa);
   }
}
