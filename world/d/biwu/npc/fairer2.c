//FY3@linxue
#include <ansi.h>
#include <net/dns.h>
inherit NPC;
void create()
{
        set_name( "��ƽ��", ({ "fairer" }) );
        set("title", HIY "������˽" NOR);
        set("gender", "����" );
        set("age", 42);
        set("int", 30);
        set("long",
                "��ƽ�ӵ�����ʦ��˭Ҳ��֪���������˲��������ˬ����\n������˽�����������ö����¶����Թ�ƽ��\n"

                );
       set("chat_chance", 2);
        set("chat_msg", ({
                "��ƽ��˵������λԶ�������������ˣ�\n",
                "��ƽ��˵����˭���������µ�һ�أ�������\n",
        }) );
        set("attitude", "peaceful");
        set_skill("unarmed", 300);
        set_skill("changquan", 300);
        set_skill("literate", 300);
        set_skill("force", 300);
        set_skill("dodge",300);
        set_skill("parry",300);
        map_skill("unarmed", "changquan");
        set("combat_exp", 9000000);
        setup();
        carry_object("/d/city/obj/cloth")->wear();
        carry_object("/d/obj/weapon/sword/changjian")->wield();
}

void init()
{
       add_action("do_gogo", "enter");
       add_action("do_allow","allow");
}

int do_gogo()
{
        object me;
        string wiz_status;
        me = this_player();
        wiz_status = SECURITY_D->get_status(me);
          if(! me->query_temp("marks/allow_biwu")&&( wiz_status != "(admin)" && wiz_status != "(arch)" ))
        {
          write(HIC"��ƽ��˵�������ڻ�û������? �𼱡�\n"NOR);
          write(HIC"��û����ȥ,���ٰ����꣬�ٵȵȰ�!! \n"NOR);

          return 1;
        }
        else
{
         return 0;
}
}

int do_allow(string arg)
{ string wiz_status;
  object me;
  object obj;

  me = this_player();
  wiz_status = SECURITY_D->get_status(me);
    if( wiz_status != "(admin)" && wiz_status != "(arch)" )        
     { return 0;}  
        if(!arg || arg=="")
        {
                write("��Ҫ��˭��ȥ��\n");
                return 1;
        }

        obj=find_player(arg);
        if (!objectp(obj)) return notify_fail("�����Ŀǰ�������ϡ�\n");
    if(!obj->query("����")) return notify_fail("���˲�δ��������\n");
        arg=obj->query("name");
        obj->set_temp("marks/allow_biwu",1);
       command("say �����ֵ�"+arg+"��������ˣ����ȥ(enter)�ɡ�");
      return 1;
 }

void die()
{
}
