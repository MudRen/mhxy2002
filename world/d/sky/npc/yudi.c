// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//created 4-8-97 pickle
inherit NPC;
int do_drop(object, object);

void create()
{
        set_name("��ʴ��", ({ "yu di", "yudi","di" }) );
        set("title", "������ʥ");        
        set("gender", "����" );
        set("long","
�����϶�����һλ����ȥ�������������,��������,ȷ��һ�����ǡ�\n");
        set("age",35);
        set("str",30);
        set("int",30);
        set("per",30);        
        set("max_kee",10000);
        set("kee",10000);
        set("max_sen",10000);
        set("sen",10000);
        set("combat_exp",3000000);
        set("force",3200);
        set("max_force",3200);
        set("mana",3000);
        set("max_mana",3000);
        set("force_factor", 80);
        set("mana_factor", 80);

        set("eff_dx", 250000);
        set("nkgain", 350);
   
        set_skill("spells", 80);
        set_skill("unarmed",80);
        set_skill("parry",80);
        set_skill("dodge",80);
        set_skill("force",80);
        set("inquiry", ([
                "name" : "���˾����ĺ���������ʴ��.",
                "here" : "��������������",
        ]) );
        set("no_ling",0);
        setup();
        carry_object("/d/obj/cloth/longpao")->wear();
        carry_object("/d/sky/obj/tianguan")->wear();
        carry_object("/d/sky/obj/yunxue")->wear();
}

void accept_kill(object me)
{ object ob1,ob2;
if (me->query("obstacle/sky","done")) return;
if( is_fighting()) return;
if( query("called")) return;
command("help!");
ob1=present("nezha santaizi");
if( !ob1) {
seteuid(getuid());
ob1=new("/d/sky/npc/nezha3");
ob2=new("/d/sky/npc/guanyin");
ob1->move(environment());
ob2->move(environment());
}
message_vision("\n���Ϻ��ش���һ��ŭ��,���˸ҵ������,����߸��Ҳ.\n\n",me);
message_vision("\n���д���һ�����:�ҷ�ȱ�!ƶ�����Ӧ���֮��ǰ����ħ.\n\n",me);
message_vision("\n��ۿ�Ц�����������������������Ͽ콵����\n\n",me);
ob1->kill_ob(me);
ob2->kill_ob(me);
ob2->set_leader(me);
ob1->set_leader(me);
me->fight_ob(ob1);
me->fight_bo(ob2);
call_out("regenerate",300);
}
int regenerate()
{
  set("called",0);
  return 1;
}

void destruct_me (object me)
{
  destruct (me);
}


void kill_ob (object ob)
{
  set_temp("no_return",1);
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}
void die()
{
   int i;
   string file;
   object *inv;
   object me = this_object();
   object ob = query_temp("my_killer");
    if(ob)  { ob->set_temp("yudi_killed",1);
             call_out ("puti_appearing",1,ob);}
    if( environment() ) {
     message("sound", "\n\n��ʴ���Ǳ������������˵Ļ����¶���������\n\n",environment());
     command("ah");
     message("sound", "\n��ʴ�۴�е����쵽����ȥ���������棡����\n\n", environment());
        inv = all_inventory(this_object());
        for(i=0; i<sizeof(inv); i++) {
        if (inv[i]->query("no_drop")) continue;
        do_drop(this_object(), inv[i]);
   }
   }
 load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);

}
void puti_appearing (object who)
{
  object puti = new ("/d/sky/npc/puti");
  puti->announce_success (who);
  destruct (puti);
}
void unconcious ()
{
  die ();
}

int accept_fight(object ob)
{

  command("say ����ʲô�ط�����������˷�����");
  return 0;
}
int do_drop(object me, object obj) {
  if (obj->move(environment(me))) {
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
