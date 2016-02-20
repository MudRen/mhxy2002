// guanyin.c ��������
// By Dream Dec. 19, 1996
//BY tianlin@mhxy for 2002.1.20,�޸ļ���ȫ���ָ�����
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int rank_me();
int do_drop(object, object);

void create()
{
        set_name("��������", ({ "guanyin pusa", "guanyin", "pusa" }));
        set("title", "�ȿ���Ѵ�ȴ�");
        set("long", @LONG
��Բ�ĵ£���������ü��С�£�����˫�ǡ�����������
ޥ�԰����١���������٤ɽ�ϴȱ�������������������
LONG);
        set("gender", "Ů��");
        set("age", 35);
        set("attitude", "peaceful");
        set("rank_info/self", "ƶɮ");
        set("rank_info/respect", "��������");
        set("class", "bonze");
        set("str",24);
        set("per",100);
        set("max_kee", 5000);
        set("max_gin", 5000);
        set("max_sen", 5000);
        set("force", 4000);
        set("max_force", 2000);
        set("force_factor", 145);
        set("max_mana", 3000);
        set("mana", 6000);
        set("mana_factor", 150);
        set("combat_exp", 2000000);
        set("daoxing", 10000000);

        set_skill("literate", 180);
        set_skill("spells", 200);
        set_skill("buddhism", 200);
        set_skill("unarmed", 180);
        set_skill("blade", 200);
        set_skill("cibei-dao", 200);
        set_skill("huadao", 200);
        set_skill("jienan-zhi", 200);
        set_skill("dodge", 200);
        set_skill("lotusmove", 200);
        set_skill("parry", 200);
        set_skill("force", 180);
        set_skill("lotusforce", 200);
        set_skill("staff", 200);
        set_skill("lunhui-zhang", 300);
	map_skill("spells", "buddhism");
	map_skill("unarmed", "jienan-zhi");
	map_skill("dodge", "lotusmove");
	map_skill("force", "lotusforce");
	map_skill("blade", "cibei-dao");
	map_skill("parry", "lunhui-zhang");
	map_skill("staff", "lunhui-zhang");
        set("inquiry", ([
//        "��ȥ"    : (: kick_back :),
//        "back"  : (: kick_back :),
         "ְλ": (: rank_me :),
      "��ƿ": "ǰЩ�죬���ǽ��ҵľ�ƿ�ã�������Ҳû�л�����ȥ�����ɡ�" ]));

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: cast_spell, "bighammer" :),
        }) );
        //hehe, since guanyin was killed several times
        //let's use cast bighammer to protect her...weiqi:)
        create_family("�Ϻ�����ɽ", 1, "����");

        setup();
        carry_object("/d/nanhai/obj/jiasha")->wear();
        carry_object("/d/nanhai/obj/nine-ring")->wield();
}
int rank_me()
{
        object me=this_player();
        int exp;
        exp=(int)me->query("combat_exp");
        if( me->query("title") == "����ɽ�뷨��ʦ")
                return notify_fail("���Ѿ����������ˣ�����Ҫʲôְλ��\n");
        if( (string)me->query("family/family_name") == "�Ϻ�����ɽ"){
                if( exp <= 100000 ){
                        me->set("title", HIB"�Ϻ�����ɽ"HIY"֪��С����"NOR);
                 } else if(exp <= 1000000 ){
                        me->set("title", HIB"�Ϻ�����ɽ"HIY"����Ժ����"NOR);
                 } else if(exp < 2000000 ){
                        me->set("title", HIB"�Ϻ�����ɽ"HIY"�޺�������"NOR);
                 } else if(exp < 3000000 ){
                        me->set("title", HIB"�Ϻ�����ɽ"HIY"��������"NOR);
                } else {
                        me->set("title", HIB"�Ϻ�����ɽ"HIY"��ң����"NOR);
                }
                tell_object(me, "������������˵���������"+me->query("title")+"��\n");
                tell_room(environment(me),
"����������"+me->query("name")+"˵���������"+me->query("title")+"��\n", ({me, me}));
         CHANNEL_D->do_channel(me,"chat","�����豾�ŵ���"+me->query("name")+""+me->query("title")+HIC"һְ�������λ�ɳ����������");
     me->save();  
        }
        return 1;
}

void attempt_apprentice(object ob)
{
        if (!((string)ob->query("bonze/class") =="bonze" )) {
                command("say �ҷ�����ͨ���" + RANK_D->query_respect(ob) + "�����������������š�\n");
                write("�����ӹ�����������δ��ȳ�����Ϊ���졣\n");
                return;
        }       
        if (((int)ob->query_skill("buddhism", 1) < 100 )) {
                command("say " + RANK_D->query_respect(ob) + "���ڷ��Ͽ��ޣ������ѳ�������\n");
                return;
        }
        command("pat " + ob->query("id") );
        command("say �ã�������ҷ��ŵĺõ��ӡ�ֻҪ���Ŭ�����������������\n");

        command("recruit " + ob->query("id") );
        return; 
}
void die()
{
        int i;
        string file;
        object *inv;

        if( environment() ) {
        message("sound", "\n\n��������ҡͷ̾�����������ϣ�����ħ�ϣ����伲�࣬���˶�֮��\n\n", environment());
        command("sigh");
        message("sound", "\n�������������ƣ��ǲ�����������ȥ�ˡ�����\n\n", environment());
        inv = all_inventory(this_object());
        for(i=0; i<sizeof(inv); i++) {
                if (inv[i]->query("no_drop")) continue;
                do_drop(this_object(), inv[i]);
//              if (stringp(file = find_command("drop")) && 
//                      call_other(file, "do_drop", this_object(), inv[i])) ;
        }
        }

        destruct(this_object());
}

int do_drop(object me, object obj) {
  if (obj->move(environment(me))) {
      //d_mana>0 is for "bian". mon 11/05/97
      if((obj->query_temp("d_mana"))>0) {
            if( obj->query_temp("is_living")==1 )
                 message_vision("$N��$n�ӱ��Ϸ������������ڵ��ϡ�\n", me, obj);
            else {
                 message_vision( sprintf("$N����һ%s$n��\n",
                 undefinedp(obj->query_temp("unit"))?
                         "��":obj->query_temp("unit")
                         ), me, obj );
           }
      } else {
           if( obj->is_character() )
                  message_vision("$N��$n�ӱ��Ϸ������������ڵ��ϡ�\n", me, obj);
           else {
             message_vision( sprintf("$N����һ%s$n��\n", obj->query("unit")),
                     me, obj );
             if( !obj->query("value") && !obj->value() ) {
                tell_object(me,"��Ϊ������������ֵǮ���������ǲ�����ע�⵽���Ĵ���
                   ��\n");
                destruct(obj);
             }
           }
      }
      return 1;
  }
  return 0;
}

int accept_object(object me,object ob)
{       object who;
        me=this_object();
        who=this_player();
        if (ob->query("id")=="sheng lingzhu" ){
        if(who->query("obstacle/niulang")!="done")
         return 0;
        if(who->query("obstacle/shenglingzhu")=="done") {
                command("say "+RANK_D->query_respect(who)+ "������ȡ����ʥ���飬���������ˣ�\n");
                call_out("destroy", 1, ob);
 return 1;
        }       
                call_out("announce_success", 3, me, who);
                call_out("destroy", 1, ob);
                return 1;
        }
        return 0;
}
void destroy(object ob)
{
        destruct(ob);
        return;
}
void announce_success(object me,object who)
{//disabled announce and reward...
    int i;
  who->add("obstacle/number",1);
  who->set("obstacle/shenglingzhu","done");
  who->delete_temp("obstacle/shenglingzhu");
  i = random(800);
  who->add("daoxing",i+8000);
  command("chat "+who->query("name")+"����ȡ��ʥ���飬���ǿ�ϲ�ɺأ�");
message("channel:chat",HIY"������ն������������(guanyin pusa)��"+who->query("name")+"��������ȡ��[1;37m����ʮ�߹أ�\n"NOR,users());//this is by tianlin 2001.5.8
tell_object(who,"��Ӯ����"+chinese_number(3)+"��"+
               chinese_number(i/4)+"��"+
               chinese_number((i-(i/4)*4)*3)+"ʱ���ĵ��У�\n");
  who->save();
}


