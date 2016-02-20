inherit NPC;
string ask_for_leave();
#include <ansi.h>
#include "/d/obj/lquest.h"
#include "/d/lingtai/npc/zhenfa.h"


string ask_mieyao(object me);
string ask_cancel();

void create()
{
        set_name("Ӱ��", ({"shadow"}));
        set("gender", "����" );
        set("age", 1000);
        set("title",MAG"������"NOR);
        set("long", "ֻ��һ��Ӱ�ӡ�\n");
        set("combat_exp", 5000000);
        set("daoxing", 8000000);
        set("class", "lingjie");

        set("attitude", "peaceful");
        set("per", 40);
        set("max_kee", 3000);
        set("max_gin", 3000);
        set("max_sen", 3000);
        set_skill("umbrella",100);
        set_skill("lingfan-san",100);
        set_skill("parry",200);
        map_skill("umbrella", "lingfan-san");
        map_skill("parry","lingfan-san");
        set("inquiry", ([
                "��ħ": (: ask_mieyao :),
                "����" : (: ask_for_leave :),
                "leave" : (: ask_for_leave :),
                "cancel": (: ask_cancel :),
                ]) );
        setup();
        carry_object("/d/lingjie/obj/san")->wield();
        carry_object("/d/lingjie/obj/yuyi")->wear();
}

void init()
{
        add_action("do_agree", "agree");
}

string ask_cancel()
{
    object me=this_player();
if((int)me->query_temp("m_mieyao"))
{
      me->add("daoxing",-2000);
      me->delete_temp("m_mieyao");
      me->delete("secmieyao");
      me->delete("secmieyao/type");
      me->delete("secmieyao/location");
      me->delete("secmieyao/place");
      me->delete("secmieyao/name");
      me->delete("secmieyao/id");
     return ("û�õĶ�����");
}
else
{
     return ("���������𣿣�");
}
}
string ask_for_leave()
{
        object me=this_player();

        if (me->query("family/family_name") == "���" ) {
                command("dao2");
                me->set_temp("betray", 1);
                return ("���ɲ���˵������,˵�߾��ߵģ������Ը��(agree)��");
        }

        return ("��˵ʲô��...\n");
}

int do_agree(string arg)
{
        if(this_player()->query_temp("betray")) {
                message_vision("$N�����Ը�⡣\n\n", this_player());
                command("say ����������û��ǿ�����ˣ�");
                this_player()->add("betray/count", 1);
                this_player()->add("betray/moon", 1);
                this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
                this_player()->set("daoxing", this_player()->query("daoxing")*80/100);
                this_player()->delete_skill("kongming-spells");
                this_player()->delete_skill("lingfan-san");
                this_player()->delete_skill("libieyu");
                
                this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("title", "��ͨ����");
                if(this_player()->query("betray/lingjie")) this_player()->add("betray/lingjie",1);
                else this_player()->set("betray/lingjie",1);
                if(this_player()->query("betray/count")) this_player()->add("betray/count",1);
                else this_player()->set("betray/count",1);
                this_player()->save();
                command("chat "+this_player()->query("name")+"�뿪��磬�Ӵ���������޹ϸ�,���λ�ɳ�������֤��\n");
                command("say ��ס,������û�жԴ�,ֻ����Ӯ,ǿ������!\n");
                message_vision("Ӱ�����һֻ����ץס$N,˦�˳�ȥ!\n", this_player());
                this_player()->move("/d/changan/fendui");
                tell_room( environment(this_player()),"žž,"+this_player()->query("name")+"���ص�ˤ��������\n");

                return 1;
        }
        return 0;
}

string ask_mieyao(object me)
{
    me=this_player();
    if((string)me->query("family/family_name")=="���") {
//  if(me->query("faith")<100)
//      return ("�㻹���ȶ������Ϊ�");
    tell_room(environment(me),"Ӱ��̧�ֻ��˻Σ�������һ�澵�ӡ�\n");
    return "/d/obj/mieyao"->query_yao(me);
    }
    return ("�Ҳ�֪����");
}

void accept_kill(object me)
{       object ob;
        if(is_fighting()) return;
        if( query("called") ) return;

        command("idle");

        ob=present("hufa");
        if( !ob) {
                seteuid(getuid());
                ob=new("/d/lingjie/npc/hufa");
                ob->move(environment());
        }
        message_vision("\n��Ȼ��������������绤������$N��һ������ʲô�����������å��\n\n",me);        

        ob->kill_ob(me);
        ob->set_leader(me);
        me->fight_ob(ob);
        set("called", 1);
        call_out("regenerate", 300);
}
