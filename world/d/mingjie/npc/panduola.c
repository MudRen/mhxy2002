// lao ren, 9-28-97 pickle

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string kick_back();

void create()
{
  set_name("�˶���", ({ "panduo la", "la" }));

  set("gender", "Ů��");
  set("age", 100);

  set("str", 20);
  set("per", 130);
  set("cor", 30);
  set("cps", 75);
  set("kar", 100);
  set("int", 40);
  set("con", 40);
  set("spi", 40);

  set("long","
����Ǵ�ħ�е��˶�����");
  set("title", "ħŮ");
  set("combat_exp", 2000000);
  set("daoxing", 2000000);


  set_skill("literate", 150);
  set_skill("unarmed", 100);
  set_skill("force", 100);
  set_skill("lengquan-force", 100);
  set_skill("axe", 150);
  set_skill("sword", 100);
  set_skill("dodge", 100);
  set_skill("parry", 100);
  set_skill("sanban-axe", 180);
  set_skill("xiaofeng-sword", 100);
  set_skill("spells", 160);
  set_skill("baguazhou", 160);
  set_skill("yanxing-steps", 100);
  map_skill("force", "lengquan-force");
  map_skill("spells", "baguazhou");
  map_skill("axe", "sanban-axe");
  map_skill("parry", "sanban-axe");
  map_skill("dodge", "yanxing-steps");
  map_skill("sword", "xiaofeng-sword");

  set("max_sen", 4500);
  set("max_kee", 3500);
  set("force", 1500); 
  set("max_force", 1500);
  set("force_factor", 40);
  set("max_mana", 3000);
  set("mana", 3000);
  set("mana_factor", 50);

  set("inquiry", ([
           	"���־���"  : (: kick_back :),
           	"jingtu"  : (: kick_back :),
]) );


  setup();
}

string kick_back()
{
    object me=this_player();

    message_vision(CYN"$n˵�������ܴ��������ǲ����װ����Ҵ���ȥ���־�������һ��ҪΪ�ұ��𰡣�\n"NOR, me, this_object());
    message_vision(CYN"�˶�������һ�����������Ԫ�ռ�...��\n"NOR, me);
    me->move("/d/mingjie/jingtu");
    message_vision("$N������ ..\n", me);
    return "";
}
int accept_fight(object me)
{
  command("say ����ô������");
  return 0;
}

void init()
{
        add_action("do_none","perform");
        add_action("do_none","cast");
        add_action("do_none","ji");
}
int do_none()
{
        object me = this_object();
        message_vision("����ô������\n",me);
        return 1;
} 

