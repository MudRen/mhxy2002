//By tianlin@mhxy for 2001.10.8
//���±�д
#include <ansi.h>

inherit NPC;

string *msg_d = ({
"�����","�����","ɵB","�Ҳ�","����","������˯","�л��û��","û���᣿",
                      "�٣�","��!","fuck","FUCK","Fuck","���","��û�л��","����?","shit","SHIT","Shit",
"����������","�����","��û�д�����","CAO",
                      "�������ƨ","tmd","TMD","tmmd","TMMD","������","������","������","û���أ�",
                      "�����","��ƨwiz","��wiz","��wiz","��wiz","������","Nnd","ȥ����",
                      "������","�����","������","�ƣգã�","F u c k","f u c k","nnd","NND","SB",
                      "Sb","shabi","SHABI","MCB","danzi","����","����","���",
                      "ţ��","��ƨ","��ʺ","���ү","������","����","6mang","���","С��","caobi",
                      "����","������","����ʦ","ʲô��վ","�������衡�ɡ�ѩ",});

void punish(object);

int give_quest();

void create()
{
        set_name("��ظ", ({"zhong kui", "zhongkui", "kui"}));
        set("title", WHT"�����"NOR);
        set("gender", "����" );
        set("age", 30);
        set("per", 112);//no rongmao description.

        set("long", "���˲�֪��ץ����ɣ���������׼�������ʲô���¡�\n");
        set("class", "taoist");
        set("combat_exp", 3000000);
        set("attitude", "peaceful");
        set_skill("unarmed", 250);
        set_skill("dodge", 250);
        set_skill("parry", 250);
        set_skill("blade", 250);
        set_skill("force", 250);   
        set_skill("literate", 280);
        set_skill("spells", 250);
        set("max_kee", 1500);
        set("max_sen", 1400);
        set("force", 4000);
        set("max_force", 2400);
        set("mana", 6000);
        set("max_mana", 3000);   
        set("force_factor", 120);
        set("mana_factor", 150);
        setup();
//        if( clonep() ) CHANNEL_D->register_relay_channel("rumor");
        if( clonep() ) CHANNEL_D->register_relay_channel("chat");
        if( clonep() ) CHANNEL_D->register_relay_channel("sldh");
        if( clonep() ) CHANNEL_D->register_relay_channel("party");
        if( clonep() ) CHANNEL_D->register_relay_channel("bill");
//        if( clonep() ) CHANNEL_D->register_relay_channel("xyj");
        carry_object("/d/lingtai/obj/xiangpao")->wear();

}

void relay_channel(object ob, string channel, string msg)
{

        int i;
        if( !userp(ob) || (channel == "sys") ) return;

        for(i=0; i<sizeof(msg_d); i++)
        {
        	msg=replace_string(msg, " ", "");
        	msg=replace_string(msg, "��", "");
            if( strsrch(msg, msg_d[i]) >= 0)
                   {
                    call_out("punish",1,ob);
                    return;
                    }
        }
}

void punish(object ob)
{
        int i;
        string criname,result;
        int howlong;
      if(ob->is_fighting()||ob->is_busy())
    {
    call_out("punish", 1, ob); return; }
        command_function("chat ������ظһ��ŭ�ȣ�"+ob->query("name")+" ���������ܲ����ˡ�");
        message_vision(HIC"���з���һ�����ӣ�һ�¾���ס$N�Ĳ��ӡ�\n"NOR+CYN"$N�쳤��ͷ�����Ű��۵ر������ˡ�\n"NOR, ob);
        criname = ob->query("name") + "("+ob->query("id")+")";
        howlong=20;//��������Զ�����ʱ��,60=60����
                    
                    
        ob->set("qiushi/howlong",howlong);
        ob->set("qiushi/temp",result);
        ob->move("/d/wiz/qiushi");
        message_vision(CYN"��ظ��$N���������ҿڳ����Ի���ڴ˵�����ʵʵ���Ҷ��š�\n", ob);
        message_vision(CYN"˵�ţ�����һ�ɣ�$N�����ڵ��ϡ�\n"NOR, ob);
        message("channel:rumor",HIM"��ҥ�ԡ�ĳ�ˣ���˵ "HIR+criname+HIM" �ڹ���Ƶ��ʹ�ô����������ظ����"NOR+BLINK+HIW"20"NOR+HIM"���ӡ�\n"NOR, users());
}

