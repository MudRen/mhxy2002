//created by vikee for xlqy-zq station Spring Holiday gift.
//2001-1-9 23:02

//˵��:��Ҫ��cheer1��cheer2���ļ��ŵ�����궨���Ŀ¼һ�µ�Ŀ¼��.

#include <ansi.h>

#define CHEER1 "/u/tianlin/cheer1" 
#define CHEER2 "/u/tianlin/cheer2"
#define CHEER3 "/u/tianlin/cheer3"
#define CHEER4 "/u/tianlin/cheer4"
#define CHEER5 "/u/tianlin/cheer5"
#define CHEER6 "/u/tianlin/cheer6"
#define CHEER7 "/u/tianlin/cheer7"


inherit ITEM;
int get_gift(string arg);
void create()
{
    set_name(HIY"����̨" NOR ,({"gift table","table"}));
  set("long","���ǹŻ�����ʦΪ���չ����ֵ�����̨����ҿ�����������(take)����(gift)��");
  set("unit", "��");
  set("value", 1000000000000);
}
void init()
{
  if (!wizardp(this_player())) 
   set("no_get","������̨�������ߣ�̫̰���˰�!\n");
  add_action("get_gift","take");
}
int get_gift(string arg)
{
  object me = this_player();
  object lw;
  
  if (!userp(me))
      return notify_fail("��ʲôҲû�õ���\n");
  if (arg!="gift")  
      return notify_fail("��Ҫ��ʲô?\n");
      
  if (me->query("yudian/newyear")) 
      return notify_fail("�������Լ��Ѿ��ù�������,�ְ������˻�����\n");
 
  //combat_exp+daoxing < 500K������
  //if (me->query("combat_exp")+me->query("daoxing")<500000)
  lw=new("/u/vikee/liwu1.c"); 
  //��������
  //else 
 // {
 //  lw=new("/u/vikee/liwu2.c");
 // }
 //���������˵Ļ���õ��ܺõ�����.
 //����:1.ԭʼkar>28 
 //     2.random(2)*random(2)*random(2)*random(2)*random(2)*random(2)=1   1/32�ĸ���.
 
// if (me->query("kar")>28 && random(2)*random(2)*random(2)*random(2)*random(2)*random(2))
 // {
 // 	  //�������gift����,��������õ���������.
 // 	  destruct(lw);
 //// 	  lw=new("/u/vikee/liwu3.c");
 // }
 
  
  //����
  write(REF);
  
  //���ӳ���,�����ʾ����ͼƬ.
  switch(random(7))
  	{
	  	case 0:
	  	cat(CHEER1);
	  	break;
	  	case 1:
	  	cat(CHEER2);
	  	break;
	  	case 2:
	  	cat(CHEER3);
	  	break;
	  	case 3:
	  	cat(CHEER4);
	  	break;
	  	case 4:
	  	cat(CHEER5);
	  	break;  	
	  	case 5:
	  	cat(CHEER6);
	  	break;  	
	  	case 6:
	  	cat(CHEER7);
	  	break;  	
  	}
  //�����͵��������.
  message_vision("$N��"HIY"����̨"NOR"��ȡ��һ�����\n"NOR, me ); 
  lw->move(me); 
  lw->set("owner",me->query("id"));
  //�����������.
  me->set("yudian/newyear",1);
  return 1;
}

