// yuzu.c
// cgm 28/12/1999
// idea 7/4/2000

#include <ansi.h>

inherit NPC;

string *msg_d = ({
                      "�����","�����","ɵB","�Ҳ�","����","������˯",
                      "�٣�","��!","fuck","FUCK","Fuck","���",
                      "�����̵�","����������","�����","��үү��",
                      "�������ƨ","tmd","TMD","tmmd","TMMD","������","������","������",
                      "�����","��ƨwiz","��wiz","��wiz","������",
                      "������","�����","������","�ƣգã�","F u c k"
                      ,"f u c k","������","����","��B","����","СB"
                      ,"tnnd","�����̵�"
                      });


void create()
{
        set_name("������ʹ", ({"shenshi","shenshi"}));
        set("title", HIY"������ս�Ǿ������������"NOR);
        set("gender", "����" );
        set("age", 30);
        set("per", 5);
        set("long", HIR"һ�����ص�������ʹ����������׼�������ʲô���¡�\n"NOR);
        set("combat_exp", 10000000);
        set("attitude", "peaceful");
        set("dex", 50);
        set("str", 50);
   
        set_skill("literate", 800);
        set("max_sen", 1000);
        set("max_kee", 500);
        set("max_force", 1000);
        
        set("no_clean_up",1);
        setup();

        carry_object("/obj/loginload/skirt.c")->wear();
        carry_object("/d/obj/weapon/sword/changjian")->wield();

        if( !clonep() ) CHANNEL_D->register_relay_channel("rumor");
        if( !clonep() ) CHANNEL_D->register_relay_channel("chat");
        if( !clonep() ) CHANNEL_D->register_relay_channel("muisc");
        if( !clonep() ) CHANNEL_D->register_relay_channel("xxzj");
        if( !clonep() ) CHANNEL_D->register_relay_channel("xyy");
        if( !clonep() ) CHANNEL_D->register_relay_channel("say");
        
}

void relay_channel(object criminal, string channel, string msg)
{

        int i;
        string criname,result;
        int howlong;
        if( !userp(criminal) ) return;

        for(i=0; i<sizeof(msg_d); i++)
        {
            if( strsrch(msg, msg_d[i]) >= 0)
                   {
                    message_vision(CYN"������ʹ��Ȼ���֣��ӳ����ף�һ�¾���ס$N�Ĳ��ӡ�\n$N�쳤��ͷ�����Ű��۵ر������ˡ�\n"NOR, criminal);
                    
                    criname = criminal->query("name") + "("+criminal->query("id")+")";
                    howlong=20;
                    
                    result = sprintf("%s��%sƵ��˵�໰(%s)�������� %d ��\n",
                    criname,channel,msg,howlong);
                    
                    criminal->set("qiushi/howlong",howlong);
                    criminal->set("qiushi/temp",result);
                    criminal->move("/d/wiz/qiushi");
                    
                    
                    message("channel:rumor",HIM"��ҥ�ԡ�ĳ�ˣ���˵"+criname+"�ڹ���Ƶ��ʹ�ô��������������ʹץ���ˡ�\n"NOR, users());
                    return;
                    }
        }
}
