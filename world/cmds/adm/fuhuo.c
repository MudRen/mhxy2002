//fuhuo.c Write By Double@XHC
inherit F_CLEAN_UP;

int main(object me, string str)
{ 
  object ob;
  if (!str) return notify_fail("usage: fuhuo <id>\n");
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("���������?\n");
  if (ob->is_ghost()) {
    tell_object(ob,"�������ȫ������...\n");
    tell_object(ob,"�����ϣ����ǹ�!��Ҫ���㸴��ұ����ϴε�һ�С�\n");
    tell_object(ob,"ͻȻһ����������������𣬡������....��������\n��ʼ���ٲ��ǻ���ˡ�����ͻȻ�е�һ�����...\n");
  }
  tell_room(environment(ob),"һ�����ͻȻ��������£�������"+(string)ob->query("name")+"����Χ��\n", ob);
  ob->reincarnate_wiz();
  ob->query_temp("last_damage_from");  
  ob->add("combat_exp", (int)ob->query("combat_exp") / 40);
  if( (int)ob->query("potential") > (int)ob->query("learned_points"))
    ob->add("potential",(int)ob->query("potential") - (int)ob->query("learned_points") );
  ob->skill_death_recover();
  ob->add("daoxing",ob->query("death/dx_loss"));
  ob->set("kill/killer_name","(relive)");
  ob->add("kill/killer_die",-1);
  ob->save();
  tell_object(ob,"�ܺã����ָ����ˣ�ԭ������ʦ"+me->name(1)+"�����㣡\n");
  write("Ok.\n");
  if ( userp(ob))
  write_file("/log/static/fuhuo",sprintf("%s   ��   %s ���� on %s\n",
  me->name(1),ob->name(1), ctime(time()) ));
  return 1;    
}

int help(object me)
{
write(@HELP
ָ���ʽ : fuhuo <ĳ��>

������ĳ������������
HELP
    );
    return 1;
}
