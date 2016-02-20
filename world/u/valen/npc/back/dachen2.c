#include <ansi.h>
inherit NPC;

string * degree_desc = ({
       GRN "�Ӿ�Ʒ�� ���ִꪳ���" NOR,
       YEL "�Ӿ�Ʒ�� ������" NOR,
       RED "�Ӿ�Ʒ�� ���ָ�ξ" NOR,
       GRN "�Ӿ�Ʒ�� ������" NOR,
       CYN "�Ӿ�Ʒ�� ����Уξ" NOR,
       CYN "����Ʒ�� ������" NOR,
       GRN "����Ʒ�� ����ִꪳ���" NOR,
       CYN "����Ʒ�� ���¸�ξ" NOR,
       RED "����Ʒ�� ����Уξ" NOR,
       GRN "����Ʒ�� ������" NOR,
       YEL "�Ӱ�Ʒ�� ������" NOR,
       MAG "�Ӱ�Ʒ�� ���˾��" NOR,
       CYN "�Ӱ�Ʒ�� ���긱ξ" NOR,
       RED "�Ӱ�Ʒ�� �з���" NOR,
       GRN "�Ӱ�Ʒ�� ����Уξ" NOR,
       YEL "����Ʒ�� ������" NOR,
       MAG "����Ʒ�� ����˾��" NOR,
       CYN "����Ʒ�� ���ڸ�ξ" NOR,
       RED "����Ʒ�� ������" NOR,
       GRN "����Ʒ�� ����Уξ" NOR,
       YEL "����Ʒ�� ������" NOR,
       MAG "����Ʒ�� ����к�" NOR,
       CYN "����Ʒ�� ��⸱ξ" NOR,
       RED "����Ʒ�� ��ɢ��" NOR,
       GRN "����Ʒ�� ���Уξ" NOR,
       RED "����Ʒ ����ξ" NOR,
       YEL "����Ʒ�� ������" NOR,
       MAG "����Ʒ�� �����к�" NOR,
       CYN "����Ʒ�� �¹���ξ" NOR,
       RED "����Ʒ�� ������" NOR,
       GRN "����Ʒ�� �¹�Уξ" NOR,
       GRN "����Ʒ ����ξ" NOR,
       YEL "����Ʒ�� ֱͨ��" NOR,
       MAG "����Ʒ�� ���˾��" NOR,
       CYN "����Ʒ�� ������ξ" NOR,
       RED "����Ʒ�� ������" NOR,
       GRN "����Ʒ�� ����Уξ" NOR,
       YEL "����Ʒ ����ξ" NOR,
       YEL "����Ʒ�� ������" NOR,
       MAG "����Ʒ�� ����˾��" NOR,
       CYN "����Ʒ�� ���丱ξ" NOR,
       RED "����Ʒ�� ������" NOR,
       GRN "����Ʒ�� ����Уξ" NOR,
       MAG "����Ʒ ����ξ" NOR,
       YEL "����Ʒ�� ��ɢ���" NOR,
       MAG "����Ʒ�� ����ɽ�" NOR,
       CYN "����Ʒ�� �λ�����" NOR,
       RED "����Ʒ�� ������" NOR,
       GRN "����Ʒ�� ���ｫ��" NOR,
       CYN "����Ʒ  �ﶼξ" NOR,
       YEL "����Ʒ�� ������" NOR,
       MAG "����Ʒ�� �����ɽ�" NOR,
       CYN "����Ʒ�� ��Զ����" NOR,
       RED "����Ʒ�� ��ɢ���" NOR,
       GRN "����Ʒ�� ��Զ����" NOR,
       RED "����Ʒ ���ﶼξ" NOR,
       YEL "����Ʒ�� �д��" NOR,
       MAG "����Ʒ�� ������ɽ�" NOR,
       CYN "����Ʒ�� ��������" NOR,
       RED "����Ʒ�� ̫�д��" NOR,
       GRN "����Ʒ�� ��������" NOR,
       MAG "����Ʒ �ᳵ��ξ" NOR,
       YEL "����Ʒ�� ͨ����" NOR,
       MAG "����Ʒ�� �������ɽ�" NOR,
       CYN "����Ʒ�� ׳�佫��" NOR,
       RED "����Ʒ�� ������" NOR,
       GRN "����Ʒ�� ���佫��" NOR,
       CYN "����Ʒ  ���ᳵ��ξ" NOR,
       YEL "����Ʒ �����»���" NOR,
       MAG "����Ʒ�� ��´󽫾�" NOR,
       CYN "����Ʒ�� ���⽫��" NOR,
       MAG "����Ʒ  ��  ��" NOR,
       GRN "����Ʒ�� ��½���" NOR,
       RED "����Ʒ�� ��������" NOR,
       MAG "����Ʒ  �ϻ���" NOR,
       YEL "����Ʒ ���Ϲ�»���" NOR,
       MAG "����Ʒ�� �����󽫾�" NOR,
       CYN "����Ʒ�� �ھ��󽫾�" NOR,
       MAG "�Ӷ�Ʒ  ��  ��" NOR,
       RED "�Ӷ�Ʒ ��»���" NOR,
       GRN "�Ӷ�Ʒ ����󽫾�" NOR,
       YEL "����Ʒ ��  ��" NOR,
       MAG "����Ʒ ������" NOR,
       MAG "����Ʒ �����󽫾�" NOR,
       CYN "��һƷ ������ͬ��˾" NOR,
       RED "��һƷ ����󽫾�" NOR,
       HIR "��������" NOR,
       HIG "��������" NOR,
       HIY "�����ز�" NOR,
       HIB "�����غ�" NOR,
       HIC "�����ع�" NOR,
       HIR "��������" NOR,
       HIG "��    ��" NOR,
       HIY "��    ��" NOR,
       HIW " ������ " NOR,
});

#include <obstacle.h>
int ask_for_officer();
int ask_for_leave();

void create()
{
  set_name("��ï��", ({ "xu maogong", "xu", "maogong", "da chen" }));
  set("title", "��");
  set("gender", "����");
  set("age", 60);
  set("per", 30);
  set("combat_exp", 300000);
  set_skill("force", 80);
  set_skill("spells", 80);
  set_skill("unarmed", 80);
  set_skill("dodge", 80);
  set_skill("parry", 80);
  set("gin", 3000);
  set("max_gin", 3000);
  set("kee", 3000);
  set("max_kee", 3000);
  set("sen", 3000);
  set("max_sen", 3000);
  set("force", 1000);
  set("max_force", 1000);
  set("mana", 1000);
  set("max_mana", 1000);
  set("force_factor", 80);
  set("inquiry", ([
                "����"     : (: ask_for_officer :),
                "����"     : (: ask_for_officer :),
                "����"     : (: ask_for_officer :),
                "��λ"     : (: ask_for_officer :),
                "��ְ"     : (: ask_for_leave :),
                "���ϻ���" : (: ask_for_leave :),
                "����"     : (: ask_for_leave :),
        ]) );
  setup();
  carry_object("/d/obj/cloth/jinpao")->wear();
}

int ask_for_officer()
{

        int lv,size1;
        object ob=this_player();
        lv = ob->query("office_number")/10;
        size1 = sizeof(obstacles);
        
        if (lv >= sizeof(degree_desc)) lv = sizeof(degree_desc)-1;


         if ( ob->query("office_number") == 0 )
        {
         command("say "+ob->query("name")+"�㻹����ȥ���î�ɡ�\n");
        return 1;
        }

        if ( time() - ob->query_temp("last_time/officer") < 120 )
	{
        command("say "+ob->query("name")+"���㷳��������\n");
        return 1;
        }
        //if ( ob->query("obstacle/number") < size1)
        //{
        //command("say "+ob->query("name")+"���㻹����ȥȡ�꾭��������Ҳ���ٰ���\n");
        //return 1;
        //}

        ob->set_temp("last_time/officer",time());
ob->set("bang/name", degree_desc[lv]);
        command("nod");
        command("smile");
message("channel:chat",HIY+"��ʥּ����ï��(xu maogong)�����ʵ���ּ���ӷ�"+ob->query("name")+"Ϊ"+degree_desc[lv]+HIY"���մˣ�\n"+NOR,users());
        return 1;
}

int ask_for_leave()
{
        object ob = this_player();

        if( !ob->query("office_number") )
        {
        command("say �󵨵��񣬾�Ȼ��ϷŪ���󳼣���");
        return 1;
        }

        if( ob->query("office_number") < 400 )
        {
        command("? "+ob->query("id"));
        command("say ����������;����֮ʱ��Ϊ��Ҫ�ǹ��أ�");
        command("say ���������ȣ�");
        return 1;
        }
        command("say "+ob->name()+"���Ҵ��Ʋ��ɶ�õ��˲İ���");
         command("say �����Ҫ����");
        write("(yes/no)��");
        input_to("check",ob);
        return 1;
}
void check(string 
arg, object ob)
{
        int i=ob->query("office_number");
        if( arg=="yes" )
        {
               command("sigh");
                command("say ��Ȼ��Ҫ�ߣ���Ҳ�Ͳ�ǿ���ˣ�");
                command("chat "+ob->name()+"�����˳��ٳ���ȥ�����ˣ�");
                command("say �������Ǯׯ������˵���ӣ������������ˡ�");
                ob->add("balance",i*10000);
ob->delete("bang/name");
                ob->delete("office_number");
                ob->set("title","��ʿ");
                return ;
        }

        else
        {
                command("angry");
                command("say �����ҿ��ĺò��ã�����");
                command("say ë����");
                return ;
         }

        input_to("check",ob);
        return ;
}