//by tianlin 2001/5/1
//By tianlin@mhxy for 2001.12.29�����޸�
#include <ansi.h>
inherit ITEM;
int do_open(string arg);
void create()
{
  set_name(HIR "����" NOR,({"gift"}));
  set("long","����һ�������������Ŵ�("+HIG+"open"+NOR+")��������");
  set("unit","��");
  set("value", 0);
  setup();
}

void init()
{
   if (!wizardp(this_player())) {
    set("no_get","��������ò�������\n");
    set("no_give","��ô���Ķ��������������ˣ�\n");
    set("no_drop","��ô����Ķ��������˶��ϧѽ��\n");
    set("no_sell","�ⶫ����������\n");
   }
    if(this_player()==environment())
  add_action("do_open", "open");

}

int do_open(string arg)
{
  object yudi;
  object obj;
  object guai,bi,bonnet;
  object me=this_player();
  if (!arg && arg!="liwu") return notify_fail("��Ҫ��ʲô?\n");
  if (me->query("newbie_liwu")) return notify_fail("���Ѿ��ù������ˣ���ô����Ҫ��\n");
  message_vision(HIG"$N�����������Ĵ򿪣�һ����â���������$N�����â��ס��$N���û������������!\n" NOR,me);

  me->add("potential",100000); 
  me->add("combat_exp",80000); 
  me->add("daoxing",16000); 
  me->add("force",400);
  me->add("max_force",400);
  me->add("max_mana",400);
  me->add("mana",400);
  me->add("maximum_force",400);
  me->add("maximum_mana",400);
  me->add("bellicosity",100); 
  me->add("rsg_eaten",16);  
  me->add("faith",500);  
  me->add("weiwang",100);  
 // me->set_skill("force",40);
//  me->set_skill("dodge",40);
//  me->set_skill("parry",40);
 // me->set_skill("sword",60);
 // me->set_skill("staff",60);
 // me->set_skill("spells",40);
 // me->set_skill("stick",60);
//  me->set_skill("unarmed",60);
//  me->set_skill("literate",40);
 // me->set_skill("archery",60);
//  me->set_skill("rake",60);
 // me->set_skill("whip",60);
 // me->set_skill("zouxiao",60);
//  me->set_skill("axe",60);
 // me->set_skill("mace",60);
 // me->set_skill("spear",60);
 // me->set_skill("throwing",60);
//  me->set_skill("blade",60);
 // me->set_skill("fork",60);
 // me->set_skill("hammer",60);
 // me->add("mud_age",86400);//����Ҽ���1���mudage.by tianlin
  tell_object(me,HIW"�㱻�����ˣ�\n" +
  chinese_number(80000) + "��ʵս���顣\n"+        
  chinese_number(100000) + "��Ǳ�ܡ�\n"+
  chinese_number(16)    + "����С�\n"+ 
  chinese_number(100) + "��ɱ����\n"+
  chinese_number(100) + "������������\n"+
  chinese_number(500) + "�������ҳ϶ȡ�\n"+
  chinese_number(400) + "��������\n"+
  chinese_number(400) + "�㷨����\n"+
 // chinese_number(5) + "�ֻ������ܡ�\n"+
  "ʮ�����˲ι�,����score2�鿴��\n"NOR+BLINK+HBRED+HIW"�Լ����ַ���!����ϧʹ��.\n" NOR);
 
  me->set("newbie_liwu",1);
  yudi = new("/d/dntg/sky/npc/yuhuang.c");
  yudi->command_function("rumor ��˵һ������[37m"+me->name()+"[2;37;0m[1;35m���ˣ��õ���[1;33m�����[2;37;0m[1;35m����ʼ����������...[2;37;0m\n");
  guai = new ("/u/tianlin/wuqi/gift/guai");
  guai->move(this_player());
  bi = new ("/u/tianlin/wuqi/gift/bi");
  bi->move(this_player());
  bonnet = new ("/u/tianlin/wuqi/gift/bonnet");
  bonnet->move(this_player());
  destruct(yudi);
  destruct(this_object());
  return 1;
}

