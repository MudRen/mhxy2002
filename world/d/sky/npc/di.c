// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//created 4-8-97 pickle
inherit NPC;
string give_me();
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
               "������" : (: give_me :),
        ]) );
        set("no_ling",0);
        setup();
        carry_object("/d/obj/cloth/longpao")->wear();
        carry_object("/d/sky/obj/tianguan")->wear();
        carry_object("/d/sky/obj/yunxue")->wear();
}
string give_me()
{
object me = this_player();
if( query("no_ling") == 0)
{
 object ob;
ob=new("/d/sky/obj/baiyu-ling");
command("fear");
say("���˵��:������������ƹ�������������֮��,���������Ҫ!!\n");
set("no_ling",1);
say("���˵��:�������ɼ�Ȼ��Ҫ�Ļ�,�޽���͸�����!\n");
ob->move(me);
message_vision("��۸���$nһ֧������!\n");
command("hehe");
if( environment() ) {
message("sound","\n\n��ʴ�ۻŻ����ŵؼ���һ�����,���Ϸ���ȥ....\n\n
�����ɵķ���,������ֱ���Ϻ�����ɽ....\n\n", environment());
}
ob=new("/d/nanhai/npc/guanyin");
ob->move(environment());
message_vision("\n���д���һ�����:�ҷ�ȱ�!ƶ�����Ӧ���֮��ǰ����ħ.\n\n",me);
ob->kill_ob(me);
ob->set_leader(me);
me->fight_ob(ob);
destruct(this_object());
return "����!\n";
}

  else {
return "���˵��: ��������ʲ����Ѿ����˱���,��λ��еڶ�֧����!!\n";
}
}
void accept_kill(object me)
{ object ob;
if( is_fighting()) return;
if( query("called")) return;
command("help!");
ob=present("nezha santaizi");
if( !ob) {
seteuid(getuid());
ob=new("/d/sky/npc/nezha");
ob->move(environment());
}
message_vision("\n���Ϻ��ش���һ��ŭ��,���˸ҵ������,����߸��Ҳ.\n\n",me);
ob->kill_ob(me);
ob->set_leader(me);
me->fight_ob(ob);
call_out("regenerate",300);
}
int regenerate()
{
  set("called",0);
  return 1;
}
