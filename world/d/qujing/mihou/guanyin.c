// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// guanyin.c ��������
// By Dream Dec. 19, 1996

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

int do_drop(object, object);
string ask_me();

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
   set("per",100);//means no rong-mao description.
   set("max_kee", 5000);
   set("max_gin", 5000);
   set("max_sen", 5000);
   set("force", 4000);
   set("max_force", 2000);
   set("force_factor", 145);
   set("max_mana", 3000);
   set("mana", 6000);
   set("mana_factor", 150);
   set("combat_exp", 4000000);
   set_skill("literate", 250);
   set_skill("spells", 400);
   set_skill("buddhism", 400);
   set_skill("unarmed", 350);
   set_skill("jienan-zhi", 350);
   set_skill("dodge", 380);
   set_skill("lotusmove", 360);
   set_skill("parry", 350);
   set_skill("force", 380);
   set_skill("lotusforce", 380);
   set_skill("staff", 350);
   set_skill("lunhui-zhang", 300);
   set_skill("spear", 300);
   map_skill("spells", "buddhism");
   map_skill("unarmed", "jienan-zhi");
   map_skill("dodge", "lotusmove");
   map_skill("force", "lotusforce");
   map_skill("parry", "lunhui-zhang");
   map_skill("staff", "lunhui-zhang");
   set("chat_chance_combat", 80);
   set("chat_msg_combat", ({
     (: cast_spell, "bighammer" :),
   }) );
   set("inquiry", ([
	"��ħ"     : (: ask_me :),
   ]));

   //hehe, since guanyin was killed several times
   //let's use cast bighammer to protect her...weiqi:)
   create_family("�Ϻ�����ɽ", 1, "����");

   set("no_clean_up", 1);
   setup();
   carry_object("/d/nanhai/obj/jiasha")->wear();
   carry_object("/d/nanhai/obj/nine-ring")->wield();
}

//add by lpg

string ask_me()
{
        object obj;
   if((int)this_player()->query("combat_exp") < 280000 )
     return "���ǵ���л����ħ��\n";
   message_vision("������$NЦ��������howdo����Ե��\n", this_player());
   return "����...";
}

void init()
{
   add_action("do_how", "howdo");

   if( query("started") != 1 )
   {
     set("started", 1);
     call_out("generate_book", 36000);//10 hours
   }
}

void generate_book()
{
   remove_call_out("generate_book");
   set("available", 1);
}

int do_how(string arg)
{
   object me, book;

   me = this_player();

   if( query("available") == 1 )
   {
     set("available", 0);
     book = new("/d/obj/book/forcebook2");
     book -> move(this_player());
     message_vision("����Ե�����㡣\n", me);
     command("chat "+this_player()->query("name")+"��Ե���õ�����ħɽ�ľ��¾���");

     remove_call_out("generate_book");
     call_out("generate_book", 36000);//10 hours

     return 1;
   }
   else return
     notify_fail("�����Ĳ���ʱ��\n");
}

int clean_up()
{
   return 0;
}
//end.lpg

void attempt_apprentice(object ob)
{
   if (!((string)ob->query("bonze/class") =="bonze" )) {
     command("say �ҷ�����ͨ���" + RANK_D->query_respect(ob) + "�����������������š�\n");
     write("�����ӹ�����������δ��ȳ�����Ϊ���졣\n");
     return;
   }   
   if (((int)ob->query_skill("buddhism", 1) < 80 )) {
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
//     if (stringp(file = find_command("drop")) && 
//        call_other(file, "do_drop", this_object(), inv[i])) ;
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


void unconcious()
{
   die();
}
//LPG 19990925 ���������
void announce_success (object who)
{
  int i;

  if (who->query("obstacle/liuer-mihou") == "done")
    return;
  if (! who->query_temp("obstacle/liuer-mihou/liuer-mihou_killed"))
    return;
  i = random(600);
  who->add("obstacle/number",1);
  who->set("obstacle/liuer-mihou","done");
  who->add("combat_exp",i+4000);
  command("chat "+who->query("name")+"ʶ�Ƽٺ�����ȡ�ذ�����");
  command("chat "+who->query("name")+"˳������������һ�أ�");
  tell_object (who,"��Ӯ����"+chinese_number(4)+"��"+
               chinese_number(i/4)+"��"+
               chinese_number((i-(i/4)*4)*3)+"ʱ���ĵ��У�\n");
  who->save();
}
