//������100�����II
// xiaoer.c ƽ���ǵ�С��
//����lywin 2000/6/1 ��ͯ��

#include <ansi.h>
#include <command.h>
inherit NPC;

void consider();
int do_gongzuo();
int ask_done();
void create()
{
        set_name("��С��", ({"xiao er", "xiao"}));
        set("gender", "����");
        set("age", 25);
        set("long", 
                "���Ǵ�����ջ�ĵ�С����\n");
        set("kee", 100);
        set("max_kee", 100);
        set("sen", 100);
        set("max_sen", 100);
        set("per", 25);
        
        set("combat_exp", 1500);
        set("score", 200);
        
        set("inquiry", ([
                "����" : (: do_gongzuo :),
                "job"  : (: do_gongzuo :),
                "work" : (: do_gongzuo :),
        ]) );

        setup();
        carry_object("/d/obj/cloth/pink_cloth")->wear();
}
int do_gongzuo()
{      
        object me;
        me = this_player(); 
        
         if (me->query("daoxing")>=10000000)
    {
                tell_object(me,"�����ҿɲ�����,haha..kick\n");
               
                return 1;
    } 
    
    if (me->query("PKS")>=1)
    {
                tell_object(me,"ɱ�˷��ҿɲ�����,haha..kick\n");
               
                return 1;
    } 
    
         if (me->query("combat_exp")>=100000)
    {
                tell_object(me,"���С����ô�������Ĵ�ݡ�\n");
                return 1;
    }
    
    if (me->query("combat_exp")<=50000)
    {
                tell_object(me,"�������С���鶼��Ը�������ҿɲ�������\n");
                return 1;
    } 

    if (me->query("betrayer") || me->query("betray/count"))
        {
                tell_object(me,"����ɲ��������ѹ�ʦ���ˡ�\n");
                return 1;
        } 
    if( me->query_temp("gongzuo/xipanzi")>0)
    {
                tell_object(me,"��ȥϴ���Ӱɡ�\n");
                return 1;
    }  
    message_vision(CYN"С����$N˵�����⼸����˶࣡����ϴ����������ȥ�����ҹ���Ҫ��������ϴ�ɡ�\n"NOR,me); 
        me->set_temp("gongzuo/xipanzi", 1);
        return 1;   
}
int accept_object(object me, object ob)
{
        object ob1;
        if (me->query_temp("gongzuo/xipanzi")<1)
        {
         command("say ��û������Ҫ�������ɡ�\n");
        }
        else if ( ob->query("name") != "����" )
//        else if (strsrch(ob->query("name"), "����") < 0) 
        {
            command("say ����ϴ�õ����ӣ��㲻�ǿ���Ц�ɣ�\n");
        }
        else
        {
    message_vision(CYN"С����$N˵���������ˣ�������Ĺ�Ǯ��\n"NOR,me);
    message_vision(CYN"С���ݸ�$NһЩ���ӡ�\n"NOR,me);  
                me->delete_temp("gongzuo/xipanzi");
                me->delete_temp("gongzuo/gepanzi");
                if (me->query("combat_exp")>=200000)
                {
                  me->add("combat_exp",50);
                 me->add("potential",8);
                 me->add("daoxing",8);
                 ob1=new("/obj/money/silver");
                  ob1->move(me); 
                  call_out("destroying", 1, this_object(), ob);
                }
                else if (me->query("combat_exp")< 300000)
                {
                me->add("combat_exp",50+random(10));
               me->add("potential",6+random(10));
               me->add("daoxing",8+random(10));
             ob1=new("/obj/money/silver");
                ob1->move(me); 
                call_out("destroying", 1, this_object(), ob);
                }
            return 1;
        }
    return 0;
}

void destroying(object me, object obj)
{
//        destruct(obj);
        return;
}

