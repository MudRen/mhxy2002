// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */

// worker.c

inherit NPC;
#include <ansi.h>

string *msg = ({
        "���ֶ��help������help news,help task,help joball��\n",
        "���ǵ���ҳ��ַ�� http://yszz.myrice.com,��ӭ���ʣ�\n",
        "help chat�����б�MUD��cool�������ң�\n",
        "help MHXY�����й���MUD�����±仯��\n",
        "help zichuang���λ����ε��Դ��书ϵͳ\n",
        "help mieyao��Ȼ����ɱ��ϵͳ�ˡ�\n",
        "����������������˿�ʼ�� help shili ��\n"
        });

void create()
{
        set_name("�λ�����", ({"mhxy"}));
        set("gender", "����" );
        set("age", 13);
        set("title", "[1;32m�λ�����ӭ��Сͯ[m");
        set("long", "һ���ɰ���Сͯ��ÿ�츺��������ӭ��Զ�������Ŀ��ˣ�\n");
        set("combat_exp", 200);
        set("attitude", "friendly");
        set_skill("dodge", 10);
        set("per", 30);
        set("max_kee", 1500000);
        set("kee",1500000);
        set("sen",1500000);
        set("max_sen", 1500000);
        setup();
        remove_call_out("msg");
        call_out("msg",300);
}

void msg()
{
        command_function("es "+NOR+HBRED+msg[random(sizeof(msg))]+NOR);
        
        remove_call_out("msg");
        call_out("msg",300);

}
