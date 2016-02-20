

// by happ@YSZZ 

#include <ansi.h>
#include <hen.h>

inherit NPC;
static int last_age_set;

void create()
{
        set_name("�ǿ�ս����", ({ "zhandou ji","ji" }) );
        set("race", "Ұ��");
        set("long","һֻ�ǿ�ս���������ҪΪ�������֣�����setname�ɡ�\n");
        set("deathstamp",1);            
        set("value",100000);
        set("no_drop",1);
        set("no_give",1);
        set("no_sell",1);
        set("no_steal",1);
        set("max_kee",300);
        set("weight",0);
        set("max_sen",300);
        set("limbs", ({ "ͷ��", "����", "ǰ��", "�ᱳ", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("obedience",60);
        setup();
}

void init()
{
        if( interactive(environment()) && !query("owner") )
        set("owner",environment()->query("id"));
        add_action("do_shape","shape");
        add_action("do_setname","setname");
        add_action("do_kiss","kiss_hen");
        add_action("do_diuqi","diuqi");
}
int do_diuqi()
{
        object me = this_player();
        cat(DEATH2);
        tell_object(me,"�ְֲ�Ҫ���ˣ�\n");
        me->delete("hen");
        call_out("des",1);
        return 1;
}

int do_setname (string arg)
{

  object me = this_player();
  this_object()->set("name",arg);
  tell_object(me,"���С�������־���"+arg+"��!\n");
  return 1;
}

void init_data(object owner)
{
    
        owner->set("hen/owner",owner->query("id"));
        owner->set("hen/age",0);                  
        owner->set("hen/max_life",50);
        owner->set("hen/tired",0);
        owner->set("hen/life",owner->query("hen/max_life"));
        owner->set("hen/ill",0);           // ����
        owner->set("hen/dirty",0);         // ����
        owner->set("hen/weight",30);       //30*age ���� (30*age)/3
        owner->set("hen/max_dirty",100);
        owner->set("hen/fali",0);
        owner->set("hen/max_fali",0);
        owner->set("hen/affection",1000);    // ���ӹ�ϵ 
        owner->set("hen/money",5000);      // ��Ǯ
        owner->set("hen/mold",0);          // ����
        owner->set("hen/might",0);         // ����
        owner->set("hen/love",0);          // ����
        owner->set("hen/art",0);           // ����
        owner->set("hen/ethics",0);        // ����
        owner->set("hen/homework",0);      // ����
        owner->set("hen/decorum",0);       // ����
        owner->set("hen/reflect",0);       // Ӧ��
        owner->set("hen/cook",0);          // ��ʦ
        owner->set("hen/happy",50);        // ����
        owner->set("hen/satisfy",50);      // �����
        owner->set("hen/relation",0);      // �˼ʹ�ϵ
        owner->set("hen/charm",0);         // ����
        owner->set("hen/brave",0);         // �¸�
        owner->set("hen/belief",0);        // ����
        owner->set("hen/impurity",0);      // ����
        owner->set("hen/feel",0);          // ����
        owner->set("hen/evaluation", ([
                        "combat"        :0,
                        "society"       :0,
                        "magic"         :0,
                        "homework"      :0,
                        ]));

        owner->set("hen/inventory", ([
                         "food"         :20,
                         "lingshi"      :5,
                         "dabu"         :1,
                         "lingzhi"      :1,
                         "renshen"      :1,
                         "xuelian"      :1,
                        ]));

        owner->set("hen/attack",10);
        owner->set("hen/defence",10);
        owner->set("hen/speed",10);
        owner->set("hen/anticmagic",0);
        owner->set("hen/combat_ski",0);
        owner->set("hen/magic_ski",0);
}


string condition()
{
        object owner=find_player(query("owner"));

        if( owner->query("hen/age") == 0 )
                return "����";
        
        if( owner->query("hen/age") <=3 && owner->query("hen/age") > 0 )
                return "СС��";

        if( owner->query("hen/age") <=15 && owner->query("hen/age") > 3 ) 
                return "��ͯ";

        if( owner->query("hen/age") <=30 && owner->query("hen/age") > 15 )       
                return "����";

        if( owner->query("hen/age") <=50 && owner->query("hen/age") > 30 )
                return "����";

        if( owner->query("hen/age") <=80 && owner->query("hen/age") > 50 )            
                return "����";

        if( owner->qurey("hen/age") > 80 )
                return "�ϵ���";
}
 
                          
string dirty()
{
        object owner=find_player(query("owner"));
 
       if ( owner->query("hen/dirty") > 2*owner->query("hen/max_dirty") )
                return "[31m�������![m";

        if ( owner->query("hen/dirty") >owner->query("hen/max_dirty") )
                return "[32m�е����[m";

                return "[1;37m���Ǹɾ���С��![m";
}
string tired()
{
        object owner=find_player(query("owner"));

        if( owner->query("hen/tired") > 90 )
                return "[35m��������[m";
        if( owner->query("hen/tired") > 60 )
                return "[32m�е�С��[m";
                return "";
}

string happy()
{
        object owner=find_player(query("owner"));

        if( owner->query("hen/happy") > 90 )
                return "[32m�ر����[m";

        if( owner->query("hen/happy") > 60 )
                return "[34m���鲻��[m";

        if( owner->query("hen/happy") > 30 )
                return "[33m��̫����[m";

                return "[36m�ܲ�����[m";
}
string eat()
{
        object owner=find_player(query("owner"));

        if ( owner->query("hen/max_life")/3 > owner->query("hen/life") )
                return "[33m�������[m";

        if ( owner->query("hen/max_life")/2 > owner->query("hen/life") )
                return "[32m���ӿտ�[m";

                return "[36m���ӱ���[m";
 }

string statisfy()
{

        object owner=find_player(query("owner"));

        if( owner->query("hen/satisfy") > 90 )
                return "[32m��������[m";

        if( owner->query("hen/satisfy") > 30 )
                return "[33m��̫����[m";

                return "[35m�ܲ�����[m";
}

string ill()
{
        object owner=find_player(query("owner"));

        if( owner->query("hen/ill") > 90 )
                return "[31m��Σ[m";

        if( owner->query("hen/ill") > 60 )
                return "[32m����[m";

        if( owner->query("hen/ill") > 30 )
                return "[33m������[m";
                return "";
}
int do_shape(string arg)
{ 
        object me;

       if( ! query("owner") )
                return notify_fail("��û���ǿ�ս��������ȥ��һֻ�ɣ�\n");    
        me = find_player(query("owner"));

printf(HIG+BCYN"�ǿ�ս����      [33m%10s      ����: %10s                              \n[m",name(),this_object()->query("owner"));
printf(HIG+"[״̬]:      %6s      [����]:       %3d      [��Ǯ]:  %6d    [����]: %4d\n",condition(),query("age"),me->query("hen/money"),me->query("hen/affection"));
printf(HIY+"[����]: %5d/%5d      [����]: %5d/%5d    [����]: %4d       [ƣ��]: %3d\n",me->query("hen/life"),me->query("hen/max_life"),me->query("hen/fali"),me->query("hen/max_fali"),me->query("hen/weight"),me->query("hen/tired"));
printf(HIR+"[����]:   %3d            [����]:    %2d          [����]:  %3d       [����]:  %3d\n"NOR,me->query("hen/dirty"),me->query("hen/ill"),me->query("hen/happy"),me->query("hen/satisfy"));
printf("%-16s   %-8s   %-8s      %-8s       %-6s\n",dirty(),eat(),happy(),statisfy(),ill()); 
printf("/-----------------------------------------------------------------------------\\");
printf("\n");

        if( me->query("hen/affection") < 0 )
        {
        cat(DEATH3);
        message_vision("$N��ޣ�$n��Ҫ���ˡ�����\n",this_object(),me);
        me->delete("hen");
        call_out("des",3);
        return 1;
        }

        if( me->query("hen/dirty") > 90 )
        {
        cat(DEATH1);
        message_vision("$NҪ���ˣ�$n������ϴ�衣����\n",this_object(),me);
        me->delete("hen");
        call_out("des",3);

        return 1;
        }

        if( me->query("hen/life") < 0 )
        {
        cat(DEATH1);
        message_vision("$NҪ���ˣ�$n�����ҳԷ�������\n",this_object(),me);
        me->delete("hen");
        call_out("des",3);
        return 1;
        }

        if( me->query("hen/tired") > 90 )
        {
        cat(DEATH2);
        message_vision("$NҪ���ˣ�$n��������Ϣ������\n",this_object(),me);
        me->delete("hen");
        call_out("des",3);
        return 1;
        }


        if( me->query("hen/ill") > 90 )
        {
        cat(DEATH1);
        message_vision("$NҪ���ˣ�$n�������β�������\n",this_object(),me);
        me->delete("hen");
        call_out("des",3);
        return 1;
        }

  return 1;
}

int do_kiss()
{
        object ob = this_player();
        ob->add("hen/dirty",5);

       ob->query("hen/happy") > 95 ?
        ob->set("hen/happy",100):
        ob->add("hen/happy",5+random(2));

        ob->query("hen/satisfy") > 95 ?
        ob->set("hen/satisfy",100):
        ob->add("hen/satisfy",5+random(2));
        ob->add("hen/affection",1);
        ob->command_function("cls");
        ob->command_function("shape");
        cat(KISS);
        write("����! �һ��.....\n");
        return 1;
}

void update_age()
{

        if( !last_age_set ) last_age_set = time();
        add("mud_age", time() - last_age_set);
        last_age_set = time();
        set("age", (int)query("mud_age") / 172800);
}

int heal_up()
{
        object ob;

        if( ! query("owner") )
        {
        call_out("des",3);
        return 1;
        }
/*
        ob = find_player(query("owner"));
        
        if( ! interactive(ob) )
        {
        call_out("des",3);
        return 1;
        }
        update_age();

        if( ob->query("hen/affection") < 0 )
        {
        message_vision("$N��ޣ�$n��Ҫ���ˡ�����\n",this_object(),ob);
        ob->delete("hen");
        call_out("des",3);
        return 1;
        }

        if( ob->query("hen/dirty") > 90 )
        {
        message_vision("$NҪ���ˣ�$n������ϴ�衣����\n",this_object(),ob);
        ob->delete("hen");
        call_out("des",3);
        return 1;
        }

        if( ob->query("hen/life") < 0 )
        {
        message_vision("$NҪ���ˣ�$n�����ҳԷ�������\n",this_object(),ob);
        ob->delete("hen");
        call_out("des",3);
        return 1;
        }

        if( ob->query("hen/tired") > 90 )
        {
        message_vision("$NҪ���ˣ�$n��������Ϣ������\n",this_object(),ob);
        ob->delete("hen");
        call_out("des",3);
        return 1;
        }


        if( ob->query("hen/ill") > 90 )
        {       
        message_vision("$NҪ���ˣ�$n�������β�������\n",this_object(),ob);
        ob->delete("hen");
        call_out("des",3);
        return 1;
        }

*/        set_heart_beat(1);
        return ::heal_up();
}

void des()
{
        destruct(this_object());
}
