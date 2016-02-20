// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// worker.c

inherit NPC;

void create()
{
        set_name("����", ({"chen yue"}));
        set("gender", "����" );
        set("age", 13);
   set("title", "ɽ��ӭ��");
        set("long", "һ��С��ʿ��ÿ�츺����ɽ��ӭ��Զ�������Ŀ��ˣ�\n");
        set("combat_exp", 200);
        set("attitude", "friendly");
        set_skill("dodge", 10);
        set("per", 30);
        set("max_kee", 150);
        set("max_gin", 150);
        set("max_sen", 150);
        setup();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting()
   && !this_player()->query("env/invisibility") ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
       add_action("do_volunteer","volunteer");
}

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        say( "����˵������λ" + RANK_D->query_respect(ob) +
"����ӭ������б�����Ƕ�����\n");
}

int do_volunteer()
{
        object me=this_player();
        object* ob;
        int i;

       if((string)me->query("family/family_name")!="����ɽ���Ƕ�")
        {
           command("smile");
           return notify_fail("���¶���˵���������Ǳ������ˡ�\n");
        }
    if(me->query("lingtai_quest/quest_type")!="����ɽ��")
      return notify_fail("���������Ĵ�ݣ�\n");
        if (me->query_temp("in_guard")) 
           return notify_fail("���¶���˵����ר���غ�ɽ�ţ���������ݹ���\n");
    ob=all_inventory(environment(me));
        for (i=sizeof(ob); i>0; i--)
        {
                if (ob[i-1]->query_temp("in_guard"))
                return notify_fail("���¶���˵���Ѿ�������ɽ���ˣ���һ�������ɡ�\n");
        }
        command("say �Ǻã���������һ���ɽ�Űɡ�");
        tell_room(environment(me),me->query("name")+"��ʼ�ڷ���ɽɽ��ֵ�ء�\n");
        me->set_temp("in_guard","1"); 
        me->save();
        remove_call_out("end_guard");
      call_out("end_guard",70,me);
        call_out("clone_meng",20,me);
        return 1;
}
void clone_meng(object me)
{
        object ob;
        tell_room(environment(me),"ɽ��ͻȻ������һ������󺺡�\n");
        ob=new("/d/lingtai/npc/mengmian.c");
        ob->set("combat_exp",me->query("combat_exp"));
        ob->move("/d/lingtai/gate");
        call_out("clone_meng", 20, me);
}
void end_guard(object me)
{
        int reward=me->query("combat_exp")/5000;
      object yao;
        
    tell_object(me,"��������ʾ���ĵĸ�л��\n");
    me->set("lingtai_quest/done",1);
    me->delete("in_guard");
        remove_call_out("clone_meng");
        tell_room(environment(me),me->query("name")+"�ڷ���ɽɽ��ֵ����������\n");
        command("say ���ڷ���ɽɽ��ֵ������������л�ˡ�");
      while(yao=present("dahan",environment(me)))
      {  tell_object(me,"ֻ������󺺺�Х��ȥ���ܿ���ʧ��Զ����\n");
          destruct(yao);
      }
}
void die()
{
        object *me;
        int i;

        me = users();
        for (i = 0; i < sizeof(me); i ++)
            me[i]->delete_temp("in_guard"); 

        ::die();
}

