
//by fly
// 2000-10-20

#include <ansi.h>
#include <command.h>
string change_color(object me);
int do_colorname(string arg,object me);
int accept_object(object me, object ob);

inherit NPC;
void create()
{
        set_name(HIG"��"NOR+HIR"�Ʒ���"NOR+HIG"��"NOR,({ "yun feiyang","fly","king" }));
    set("title", HIW"--�������ң--"NOR);
        set("gender", "����" );
        set("per", 30);
        set("age", 180);
        set("long",
HIM"\n�����ǵ����һ���֣�������������ңɽׯ��
��˵���������Ҫ��ΪһЩ��Ǯ���޸���ɫName������
ͨ�������뻯�����˲���һ��������һ����Ҳ���������ҡ�\n"NOR);
        set("combat_exp", 20000000);
        set("attitude", "friendly");
        set("inquiry", ([
            "��ɫ": (: change_color :),
            "�任��ɫ": (: change_color :),
            "�Ķ���ɫ": (: change_color :),
            "�޸���ɫ": (: change_color :),
            "��ɫ�޸�": (: change_color :),
            "��ɫ�Ķ�": (: change_color :),
            "��ɫ�任": (: change_color :),
        ]) );
        setup();
}

void init()
{
        object ob,me;
        add_action("do_colorname","color_name");
}

int accept_object(object me, object ob)
{
       int i,p;
        i=(int)me->query("marks/color_times");
        p=i*i;
    if ( !me->query_temp("marks/color_ask"))
              {
      command("?");
            return notify_fail(HIB"����Ǯ����?�ٺ٣���\n"NOR);
           }
        if( ob->query("money_id") && ob->value() >= (p*2000000+1000000))
        {
        command("nod");
        command("say �ðɣ�"+me->query("name")+"�������("HIR" color_name xxx "HIG"),���޸����������ɫ��\n"NOR);
       me->delete_temp("marks/color_ask");
        me->set_temp("marks/change_color",1);
        return 1;
        }
       else {
        command("heng");
        command("say �ٺ٣�"+me->query("name")+"�㵹�󵨣���Ϸˣ�����ˣ�\n");
        return 1;
        }
}
int do_colorname(string arg,object me)
{
}
string change_color(object me)
{
   int p,i;
  me=this_player();   
 if ( me->query_temp("marks/change_color"))
        {
      command("?");
            return HIR"Ǯ"NOR+HIC"Ҳ���ˣ��챨����Ҫ�Ķ���"NOR+HIR"��ɫ"NOR+HIC"���Ҹ��ľ����ˣ�\n"NOR;
         }
    if ( me->query_temp("marks/color_ask"))
        {
      command("?");
            return HIG"���ǿ���"NOR+HIR"Ǯ"NOR+HIG"�������ˣ�û"NOR+HIR"Ǯ"NOR+HIG"��̸������ô������\n"NOR;
        }
    if ( !me->query("marks/color_times",1))
        {
      command("oh");
      command("say �ǵ�һ��������Ķ���....���ɣ�ֻ��"+HIR"100"NOR+HIY"gold"NOR+"�����ˣ���");
        }
else {
                 i=(int)me->query("marks/name_times");
              p=i*i*100;
                  p=p*2+100;
        message_vision(HIR"�Ʒ���ٺ�һ��"NOR+HIG":"NOR+CYN"����θĶ��ҿ�����Ҳ�� "NOR+p+HIY"gold"NOR+CYN" ����\n"NOR,me);
          }
        me->set_temp("marks/color_ask",1);
        return HIB"Ը��λ��������!!!"NOR;
}

