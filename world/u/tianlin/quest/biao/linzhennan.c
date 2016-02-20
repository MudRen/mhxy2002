// linzhennan.c ������
// modified by Jay 4/7/96

#include <ansi.h>
int potential_lv(int exp);
inherit NPC;

//#define CART_PATH "cart"
//moon,shushan,wzg,lingtai,kaifeng
string do_quest();
string* dart_area=({"/d/moon/nroom","/d/shushan/yongdao","/d/kaifeng/dangpu","/d/lingtai/room",
                    "/d/jz/in"});
string* dart_short=({"�¹�","��ɽ","����","��̨","����"});
string* dart_id=({"magu","lin yueru","xu laoban","master puti","yin wenjiao"});
string* dart_name=({"���","������","���ϰ�","������ʦ","���½�"}); 
string do_job();
string do_give();
int ask_fuwei();
int ask_yuantu();
int ask_pixie();
int ask_tong();

string daoxing(int dx)
{
        
        int day,hour;
        day = (dx) / 4;
        hour = (dx  - day * 4) * 3; 
        return day?(chinese_number(day)+"��"):""+hour?(chinese_number(hour)+"ʱ��"):"";
}

void create()
{
        set_name("������", ({ "lin zhennan", "lin", "zhennan" }));
        set("gender", "����");
        set("age", 45);
        set("title", "�����ھ�����ͷ");
        set("long", "�����ǡ������ھ֡�������ͷ���������ϡ�\n");
        set("combat_exp", 30000);
        set("shen_type", 1);
        set("max_neili", 500);
        set("force", 500);
        set("jiali", 10);
        set_skill("force", 40);
        set("per",19);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set("inquiry", ([
                "������լ" : "������˵���������Ҵ�ǰ�ڸ���ʱס�ļ�Ժ���Ѿ��ư��ˡ�\n",
                "��Զͼ" : "�����ϴ�ŭ��С������ôû��ò��ֱ���������䣡\n",
                "����" : (: do_job :),
                "��"   : (: do_job :),
                "����" : (: do_job :),
                "job"  : (: do_job :),
                "����" : (: do_give :),
                "over" : (: do_give :),
        ]) );
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 15);
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

string chinese_time(int t)
{
        int d, h, m, s;
        string time;
        s = t % 60;     t /= 60;
        m = t % 60;     t /= 60;
        h = t % 24;     t /= 24;
        d = t;
        if(d) time = chinese_number(d) + "��";
        else time = "";
        if(h) time += chinese_number(h) + "Сʱ";
        if(m) time += chinese_number(m) + "��";
        time += chinese_number(s) + "��";
        return time;
}

string do_job()
{   int n;
    object ob,cart;
    ob=this_player(); 
    n=random(sizeof(dart_area));   

//    return "���ڱ����г��˵����⣬���ھ־�������һ�£��⼸�첻�����ˡ�\n";
    
    if ( ob->query_temp("in_dart"))
       return "�㲻�ǲ�Ҫ��������\n";

    if ( (int)ob->query_condition("dart_limit" ) > 0 )
       return "�����û�������ɡ�\n";

    if ( ob->is_busy() || ob->query_temp("pending/exercising"))
                return "��������æ���ء�\n";

    if ( (int)ob->query("combat_exp") < 20000 )
       return "�����Ǽ�Σ�չ������ҿ�"+RANK_D->query_respect(ob)+"�ƺ�û����������\n";
//By tianlin@mhxy for 2002.1.24��������
    if( (int)ob->query("daoxing")+(int)ob->query("combat_exp") >= 2500000 )
       return "����С���������鷳"+RANK_D->query_respect(ob)+"��\n";

    if ( (int)ob->query_skill("force") < 20 )
       return "�����Ǽ�Σ�չ������ҿ�"+RANK_D->query_respect(ob)+"�Ļ����������㣡\n";

    if ( (int)ob->query("dart/number") > 20 && (int)ob->query("age") < 18)   
       return "��λ"+RANK_D->query_respect(ob)+"��Ȼ��λ�˲ţ������ٸ��涨18������ֻ��Ѻ20���ڣ����㳤��������ɣ�\n";
    
    if(!ob->query("dart/number")) ob->set("dart/number",1);
    else ob->add("dart/number",1);
    ob->set_temp("in_dart",1);
    ob->set_temp("dart_area",dart_area[n]);
    ob->set_temp("dart_id",dart_id[n]);
    ob->set_temp("dart_name",dart_name[n]);
    ob->set_temp("dart_area_name",dart_short[n]);
    ob->apply_condition("dart_limit", 3600);
    ob->set_temp("robber_rec",1);

    cart=new(__DIR__"cart");
    cart->set("master",ob->query("name"));
    cart->set("masterid",ob->query("id"));
    cart->move("/u/tianlin/quest/biao/biaoju");
    cart->set_leader(ob);
    command("nod");
    message_vision(CYN "������ƽ������˳�����\n" NOR,ob); 
    return "�����������͵�"+dart_short[n]+"��"+dart_name[n]+"���С�\n";
    
}

string do_give()
{
int bonus;
  object ob;
  int dh,pot,wx,money;
// int max_pot;

  ob=this_player();
//   max_pot=(int)this_player()->query("max_pot");

  if ( !ob->query_temp("in_dart"))
    return "��û�������ڰ���\n";

  if ( !ob->query_temp("over_dart") )
    return "�ڳ�û���͵���ͷ��Ī���������ˣ���\n";

    wx = random(1000)+1000;
    dh = random(1000)+5000;
    pot = random(1000)+2000;                    
    money = random(400000)+100000;
    
    ob->add("combat_exp",wx);
    ob->add("daoxing",dh);
//    ob->add("potential",pot);    
    ob->add("balance",money);
  
  message("system",HIY"���������¡�������(Lin zhennan)��"+ob->name()+"���ڳ���ȫ�˵�"+ob->query_temp("dart_area_name")+"������ڷ�"+chinese_number(money/10000)+"�����ӣ�\n"NOR,users());
  message("system",HIY"���������¡�������(Lin zhennan)��"+ob->name()+"�õ���"+daoxing(dh)+"���С�"+chinese_number(wx)+"����ѧ����Ľ�����\n"NOR,users());
  ob->delete_temp("in_dart");
  ob->delete_temp("over_dart");
  ob->delete_temp("dart_name");
  ob->delete_temp("dart_id");
  ob->delete_temp("dart_area");
  ob->delete_temp("robber_rec");

  command("pat "+ob->query("id"));
  return RANK_D->query_respect(ob)+"��Ȼ�Ƕ���֮�ţ�\n";
}

int potential_lv(int exp)
{
        int grade;
        grade = 100 + exp /500;
        return grade;
}

int accept_object(object who, object ob)
{
    int value;

        if (ob->query("money_id") && (value=ob->value()) >= 500000) 
        {
                command("sigh");
                tell_object(who, name()+
                        "˵�����ðɣ���Ȼ��Ѻ��Ū���ˣ�Ҳֻ���⳥�ˡ�\n");
                who->delete_temp("in_dart");
                who->apply_condition("dart_limit", 0);
//                take_money(value, 500000);
                return 1;
        }
        return 0;
}
