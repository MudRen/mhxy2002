//guinu.c ��ūby swagger

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("��ū", ({ "gui nu", "gui", "nu" }) );
        set("gender", "����" );
        set("title", HIR"�仨¥�ܹ�"NOR);
        set("age", 32);
        set("long", 
            "�仨¥���ܹܣ��ɾ��˱���Ϊ潵Ļ��¡�\n");
        set("str", 35);
        set("dex", 35);
        set("con", 25);
        set("int", 25);
        set("per", 10);
        set("shen_type", -1);

        set_skill("unarmed", 100);
        set_skill("force", 100);
        set_skill("dodge", 100);

        set("combat_exp", 200000);

        set("max_kee", 600);
        set("max_sen", 600);
        set("force", 600);
        set("max_force", 600);

        set("attitude", "friendly");
        set("inquiry", ([
            "name" : "���Ӿ���������ܹܣ�����С�����ҡ�",
            "here" : "��������������µĴ仨¥�ˣ�Ҫ��Ҫ�Ҹ�С��?",
            "����" : "�ð��������ǿ��Եģ��������Ǯ�ɵúú�����������",
       ]) );

        setup();
        set("chat_chance", 6);
        set("chat_msg", ({
        "��ū��Ц��˵�����������ȱС�㣬����������ţ����ã����������������\n",
        "��ū�ٺٵļ�Ц�ţ���֪��������ʲô�����ˡ�\n",
        }) );
        carry_object("/obj/cloth")->wear();
}
void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_sell","sell");
}

void greeting(object me)
{
    object * ob;
    int found,i;
    
    found = 0;
    
    if (me->query("jinu")) {
        command("say �ð���"+me->name() + "�����������ԣ����Ҳ��������ȣ�");
        return;
    }
   {
      ob = all_inventory(environment());
      for(i=sizeof(ob)-1; (i>=0) && !found; i--) {
      if( !userp(ob[i]) ) continue;
      if (ob[i]->query("jinu")) {
         found = 1;
         command ("say "+ob[i]->name() + "��û�����������ˣ�������ӭ�ӣ� ");
      }
      }   
    }
    return ;
}
int do_sell(string arg)
{
    object ob;
    int value, per, extra = 1;
   
    if (!arg || !(ob = present(arg, this_player())))
       return notify_fail("������Ҫ��˭����\n");
       
    if (!ob->is_character())
       return notify_fail("���ҿɲ�Ҫ�������������ȥ��\n");
              
//    if (!userp(ob))
//       return notify_fail("������У���ֻҪ��ҡ�\n");
       
    if (ob->query("gender")!="Ů��")
       return notify_fail("�Բ����ˣ���ԺĿǰû���������\n");
      
    if ((value = ob->query("age")) < 18)
       return notify_fail("���У���Ů�ҿɲ�Ҫ��\n");

    if ((value = ob->query("per")) < 20)
       return notify_fail("��Ҳ��̫���ˣ���������ֻ���Ȿ����Ҫ��\n");

    if (ob->query("jinu"))
       return notify_fail("������������������С�㣬������\n");
       
    if ((value = ob->query("daoxing")) < 100000)
       return notify_fail("�����Ǹ������أ��ȴ�һЩ�����ɡ�\n");

    if ((value = ob->query("combat_exp")) < 200000)
       return notify_fail("�����Ǹ������أ��ȴ�һЩ�����ɡ�\n");

    per = ob->query("per")*100;
    if( ob->query_temp("top_girl") ) {
        extra = 10 ;
        per = ob->query("per")*1000;
        command("say ��εĻ�ɫ������С��治����\n");
    }

    message_vision("$N��"+ ob->name()+"�����˴仨¥��\n", this_player());
    MONEY_D->pay_player(this_player(), (per+value)*extra);
    this_player()->set("shen",this_player()->query("shen")-(value/100));
    this_player()->set("sell_woman/" + ob->query("id"), 1);
    this_player()->set("title","�仨¥Ƥ����");
    command("admire "+this_player()->query("id"));
    command("rumor ������!��˵"+ ob->name()+"�������˴仨¥! \n");
    command ("chat ���Ǵ仨¥��������һλС�㣬��ӭ��λ��ү��ˣ�");
    command ("say �ã��ɵĲ���������Ľ��ӣ�");
    ob->move(this_object());
    ob->set("title","�仨¥С��");
    ob->set("jinu",1); 

    return 1;
}
 
int accept_object(object me, object obj)
{
  if(obj->query("money_id")) {
    if(me->query("jinu")) {
        if (obj->value()>= me->query("combat_exp")
*2)  {  
        command ("say �ðɣ���Ȼ��Ҫ������Ҳ�������ˣ���ౣ�ء�");
        command ("cry "+me->query("id"));
        me->set("title",me->query("family/family_name")+"��"+
                chinese_number(me->query("family/generation"))+
                "������");
        me->set("jinu",0); 
        command("kissbye "+me->query("id"));
        command("rumor ��˵"+me->name()+"���������˴仨¥! \n");
        return 1;
        }
        else {
        command("say лл"+me->query("nickname")+"��Ǯ��");
        command("bow "+ me->query("id"));
        return 1;
        }
    }
  }
  else return 0;
} 


