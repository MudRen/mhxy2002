inherit NPC;
#include <ansi.h>
int query_gold_of_user(object me);
        string *banned_name = ({
        "��","��", "��", "��", "��", "����","�ְ�",
        "ѩѩ","����","������","����","үү","����","�Ϲ�",
        "���","���","����","�����","�й�","����","����",
        "��ʦ","����ͷ","����ϧ��","�ڹ�","����","����","����",
        });
void create()
{
       set_name("����", ({ "shu sheng","shu","sheng" }) );
       set("gender", "����" );
       set("age", 59);
       set("title", WHT"����ׯ�ſ�"NOR);
       set("str", 21);
       set("max_kee", 1000);
       set("kee", 1000);
       set("give_tuzi",5);
       set("long",
              "һ���ڸ���ׯ��ס������,��Ϊ���ˡ���������Ϊ����\n");
       set("combat_exp", 10000);
       set("attitude", "friendly");
       set("inquiry", ([
              "����" : "Ҫ����������,����� change <������>\n",
               ]) );
       setup();
       carry_object("/obj/cloth")->wear();
}
void init()
{
       add_action("do_gai","change");
}
int do_gai(string name)
{
        object me;
        int i;
        me = this_player();

    if( !name || sscanf(name, "%s", name)!=1 )
        return notify_fail("ָ���ʽ��gai <������>\n");
    

        message_vision(CYN"$N��ͷ�����ض�$n˵��:��Ҫ����Ϊ "BOLD+name+NOR+CYN+" ...\n\n"NOR,me,this_object());

    i = strlen(name);
    
    if( (strlen(name) < 2) || (strlen(name) > 16 ) )
        {
        command("say �Բ�������������ֱ����� 1 �� 8 �������֡�\n");
        return 1;
    }
    while(i--)
        {
        if( name[i]<=' ' )
                {
            command("say �Բ�������������ֲ����ÿ�����Ԫ��\n");
            return 1;
        }
        if( i%2==0 && !is_chinese(name[i..<0]) )
                {
            command("say �Բ������á����ġ�ȡ���֡�\n");
            return 1;
        }
    }
    if( member_array(name, banned_name)!=-1 )
        {
        command("say �Բ����������ֻ���������˵����š�\n");
        return 1;
    }
         if(me->query("class")=="bonze"||me->query("class")=="alchemist")
          {
             command("shake");
             command("say С������Ϊ�����!");
            return 1;
           }
    if ( !query_gold_of_user( me ) ) return 1;

        command("nod");
        command("say ����,��������Ѿ�������!");
        me->add("marks/gainame", 1);
        me->set("name", name);
                return 1;
}
int query_gold_of_user(object me)
{
        object gold;
        int gold_number;
        int value;
        value = 300*(me->query("marks/gainame")+1);
        gold_number=0;
        gold=present("gold_money",me);
        if (gold) {
                gold_number=gold->query_amount();
                if ( gold_number>=value ){
                     gold->set_amount(gold_number-value);
                return 1;
        }else{
            command("shake");
            message_vision(CYN"$N˵��: ������Ҫ"+chinese_number(value)+"�� "HIY"�ƽ� "NOR+CYN"����ʷ�...\n"NOR,this_object());
            return 0;
             }
        }
            command("shake");
            message_vision(CYN"$N˵��: ������Ҫ"+chinese_number(value)+"�� "HIY"�ƽ� "NOR+CYN"����ʷ�...\n"NOR,this_object());
            return 0;
}

