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
                "��ƽ�ӵ�����ʦ��˭Ҳ��֪���������˲��������ˬ����
                 ������˽�����������ö����¶����Թ�ƽ��\n"
                );
       set("chat_chance", 2);
        set("chat_msg", ({
                "��ƽ��˵��������µı������Ҫ�����ˣ����˳����м���\n",
                "��ƽ��˵���������ᣨbiwu�����£�������\n",
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
        ::init();
        add_action("do_ask", "biwu");
        add_action("do_join", "join");
        add_action("do_decide", "decide");
        add_action("do_hold", "hold");
        add_action("do_show", "list");
        add_action("do_over", "over");
}

int do_ask()
{
        object ob;
        ob=this_player();
        command("say ���Ʊ����ἴ�����У����Ը��μӣ�(join)");
        ob->set("asking",1);
        return 1;
}

int do_join()
{    
        object ob;
        ob=this_player();
        if (ob->query("����"))  return notify_fail("���Ѿ������μӱ������ˣ���Ҫ�μӰ���\n");
        if (!ob->query("asking")) return 0;
        ob->set("joining",1);
        ob->delete("asking");
        return notify_fail("��ƽ��֣�ص�˵�����뿴�������³̣���ľ����μӣ�(decide)\n");
}

int do_decide()
{
        object ob;
        string arg;
        ob=this_player();
        if (!ob->query("joining")) return 0;
        ob->delete("joining");
        ob->set("����",1);
        arg=ob->query("name");
        command("chat ����"+arg+"�����μӱ����ᡣ");
        return notify_fail("��ƽ��΢Ц��˵���������Ѿ������μӱ������ˣ��ú�Ŭ���ɣ�\n");
}

int do_hold()
{
        object obj,*ob,*inv,me,room;
        int i,j;
        string wiz_status;
        me = this_player();
        wiz_status = SECURITY_D->get_status(me);
        if(!me->query_temp("marks/linxue_allow") && wiz_level(me)<wiz_level("(arch)"))
        {return notify_fail("����Ȩ�ٿ������ᣡ\n");}
        room = load_object("/u/biwu/gate");
        ob=users();
        command("chat ���������ڿ�ʼ������");
        for(i=0;i<sizeof(ob);i++) {
          if (ob[i]->query("����")){
             tell_object(ob[i],sprintf(HIW"��ƽ�Ӹ�����:���ڱ����Ὺʼ�ˣ��Ͽ�ȥ�ɣ�\n"NOR));
             tell_object(ob[i],sprintf(HIW"�����������ͷһ�����£�����ææ��ȥ��\n"NOR));  }
          if (!ob[i]->query("����")){
             tell_object(ob[i],sprintf(HIW"��ƽ�Ӹ�����:���ڱ����Ὺʼ�ˣ���Ȼ��û�μӣ���ȥ�����ɣ�\n"NOR));
             tell_object(ob[i],sprintf(HIW"�����������ͷһ�����£�����ææ��ȥ��\n"NOR));  }
             ob[i]->move(room);
             inv = all_inventory(ob[i]);
             for(j=0; j<sizeof(inv); j++)
                {   destruct(inv[j]);  }
          }
        return 1;
}

int do_over()
{
        object obj,*ob,*inv,me,room;
        int i,j;
        string wiz_status;
        me = this_player();
        wiz_status = SECURITY_D->get_status(me);
        if( wiz_status != "(admin)" && wiz_status != "(arch)" )
        {return notify_fail("����Ȩ�ٿ������ᣡ\n");}
        room = load_object("/d/fy/fysquare");
        ob=users();
        command("chat ���������ڽ���������");
        for(i=0;i<sizeof(ob);i++) {
             tell_object(ob[i],sprintf(HIW"��ƽ�Ӹ�����:���ڱ���������ˣ�·���ߺá�\n"NOR));
             tell_object(ob[i],sprintf(HIW"��ƽ�Ӹ�����:���˳����ٵ�¼�Ի��������Ʒ��\n"NOR));
             ob[i]->move(room);
             ob[i]->delete("����");
             inv = all_inventory(ob[i]);
             for(j=0; j<sizeof(inv); j++)
                {   destruct(inv[j]);  }
          }
        return 1;
}

int do_show()
{
        object *ob,me;
        int i;
        string arg;
        me = this_player();
        ob=users();
        tell_object(me,sprintf(HIW"��ƽ�Ӹ�����:����������Ҳμӱ�������У�\n"NOR));
        for(i=0;i<sizeof(ob);i++) {
          if (ob[i]->query("����"))
            {  arg=ob[i]->query("name");
               write(arg+"�����μӱ����ᡣ\n");
            }
          }
        return 1;
}

