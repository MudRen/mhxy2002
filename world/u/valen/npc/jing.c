//BY tianlin@mhxy for 2001.12.30

inherit NPC;
#include <ansi.h>
int ask_cake();

void create()
{
         set_name(HIY"����"NOR, ({"jing ling","jingling","jing","ling"}));
    set ("long", @LONG
ĵ�����������ˣ�������ĵ��������һ������
���������ʱ,�����������Ҫ����.
(ask jing ling about ��������)
LONG);
       set("gender", "Ů��");
       set("title",HIW"����"NOR);
       set("age", 20);
       set("per", 40);
       set("attitude", "peaceful");
       set("shen_type", 1);
//     carry_object("/u/yudian/weapon/mmjian")->wield();
//     carry_object("/u/yudian/hak")->wear();
       set("inquiry", ([
            "��������" : "����������ϲ������Ŷ�����Բ����ˣ���\n", 
            "��������" : (: ask_cake :),      
]));
        setup();
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
}
}
int ask_cake()
{ 
        object ob;
        if (this_player()->query("birthday"))    {
            command("say ��ϲ��ϲ��ף�����տ��֣�\n");
          ob=new("u/tianlin/npc/obj/cake");  //�����·�����Զ��塣
          ob->move(this_player()); 
        message_vision("\n$N����$nһ�����Ƶ����յ��⡣\n",  this_object(),this_player());
        this_player()->delete("birthday"); 
         return 1;            }
      return 0;
}
void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
say(name()+"���������������,����ǵĻ�,�����������һ�������\n"NOR);

}
