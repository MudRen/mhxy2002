//by yushu 2001.1
#include <ansi.h> //������ɫ
inherit ITEM;       //��Ʒ����
int do_open(string arg); //����
void create()
{
  set_name(HIR "����" NOR,({"gift"})); //���� id �趨
  set("long","����һ�������������Ŵ�("+HIR+"open"+NOR+")��������"); //look�趨
  set("unit","��"); //��λ
  set("value", 0); //��ֵ
  setup(); 
}
void init()
{
   if (!wizardp(this_player())) {
    set("no_get","��������ò�������\n"); //����wiz player��������������
    set("no_give","��ô���Ķ��������������ˣ�\n");
    set("no_drop","��ô����Ķ��������˶��ϧѽ��\n");
    set("no_sell","�ⶫ����������\n");
   }
    if(this_player()==environment())
      add_action("do_open", "open"); //�ж�
}
int do_open(string arg)
{
  object me=this_player();
  if (!arg && arg!="liwu") return notify_fail("��Ҫ��ʲô?\n"); //�ж�Ŀ��
  if (me->query("young_liwu")) return notify_fail("���Ѿ��ù������ˣ���ô����Ҫ��\n");
  message_vision(HIR"$N�����������Ĵ򿪡�\n" NOR,me); //������ʱ������
  me->set("combat_exp",20000);
  me->set("daoxing",16000);
  me->set("balance",10000); 
  me->set("young_liwu",1);
  destruct(this_object());
  return 1; //����

}
