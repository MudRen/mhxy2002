#include <ansi.h> //������ɫ
inherit ITEM;       //��Ʒ����
int do_open(string arg); //����
void create()
{
  set_name(HIR "���" NOR,({"hong bao","bao"})); //���� id �趨
  set("long","����һ�ݺ������������Ŵ�("+HIR+"open"+NOR+")��������"); //look�趨
  set("unit","��"); //��λ
  set("value", 0); //��ֵ
  setup(); 
}
void init()
{
   if (!wizardp(this_player())) {
    set("no_get","��������ò�������\n"); //����wiz player��������������
    set("no_give","��ô���Ķ��������������ˣ�\n");
    set("no_sell","�ⶫ����������\n");
   }
    if(this_player()==environment())
      add_action("do_open", "open"); //�ж�
}
int do_open(string arg)
{
  object me=this_player();
  if (!arg && arg!="bao") return notify_fail("��Ҫ��ʲô?\n"); //�ж�Ŀ��
  if (me->query("newyear_hongbao")) return notify_fail("���Ѿ��ù��������ô����Ҫ������\n"); 
  message_vision(HIR"$N�����������Ĵ򿪣���ϲ���ƣ�����ϲ���ƣ�����\n" NOR,me); //������ʱ������
  me->add("balance",5000000);   //��rsg 1��
  tell_object(me,HIW"�㱻�����ˣ�\n" +
  "500goldǮׯ��\n" NOR); //����˵��
  me->set("newyear_hongbao",1); //�����
  destruct(this_object());
  return 1; //����

}