#include <ansi.h>

inherit ITEM;
void create()
 {
    set_name("��ͥӰԺ", ({"vcd"}) );
    set_weight(1000);
    if( clonep() )
           set_default_object(__FILE__);
    else {
        set("unit", "̨");
        set("long", "һ̨�߼���ͥӰԺ,������play,shut,kala,stopһЩ����.\n");
         set("no_get",1);
         set("value",10000);
    }
    setup();
}

void init()
{
       add_action("do_play", "play");
}


int do_play()
{
                if (this_object()->query_temp("play")==1) return notify_fail("�������ڷ��ţ֣ã��ء�\n");
                if (this_object()->query_temp("kala")!=0) return notify_fail("���������˳������ϣ��ء�\n");
                this_object()->set_temp("play",1);
                call_out("start_play",2);
                return 1;
}

int start_play()
{
        call_out("continue_play",1,-1); 
        return 1;       
}

int continue_play(int release)
{

string *str1=({
"       ������Ϊ����ݳ�һ�׸�,ϣ�����ϲ��.\n\n",
"���ұ�Ҳ�� ���һ�Ҳ��\n",
"�޲����㶼������\n",
"���ҿ�Ҳ��\n",
"������Ҳ��\n",
"���ƮƮ�������ң\n",
"Ӣ�۲��³���̫����\n",
"��־��������Ҳ����\n",
"��Ϊһ��Ե��������\n",
"һ��һ���벶������\n",
"�మ�����춼������\n",
"��Թ����������ͷ��\n",
"�а����Ĳ��ܻ��\n",
"��������������ĺ�\n",
"���ұ�Ҳ�� ���һ�Ҳ��\n",
"�޲��슅��������\n",
"���ҿ�Ҳ��\n",
"������Ҳ��\n",
"�������쿴������Ц\n",
"������Ҳ�� ����˯Ҳ��\n",
"�ѳ��鷳�¶�����\n",
"���Ҷ�Ҳ�� ���Ҵ�Ҳ��\n",
"���ƮƮ�������ң\n",
"Ӣ�۲��³���̫����\n",
"��־��������Ҳ����\n",
"��Ϊһ��Ե��������\n",
"һ��һ���벶������\n",
"�మ�����춼������\n",
"��Թ����������ͷ��\n",
"�а����Ĳ��ܻ��\n",
"��������������ĺ�\n",
"���ұ�Ҳ�� ���һ�Ҳ��\n",
"�޲����㶼������\n",
"���ҿ�Ҳ�� ������Ҳ��\n",
"�������쿴������Ц\n",
"������Ҳ�� ����˯Ҳ��\n",
"�ѳ��鷳�¶�����\n",
"���Ҷ�Ҳ�� ���Ҵ�Ҳ��\n",
"���ƮƮ�������ң\n",
"���ұ�Ҳ�� ���һ�Ҳ��\n",
"�޲����㶼������\n",
"���ҿ�Ҳ�� ������Ҳ��\n",
"���ƮƮ�������ң\n",
"���ƮƮ�������ң\n",

"\n\n[1;32mлл���,лл��λ������!\n",
});

        if (release==0) {
                this_object()->set_temp("play",0);
                return 0;
        }
  
      if (release==-1) {
                continue_play(sizeof(str1));
                return 1;
        }
this_player()->command_function("chat "+str1[sizeof(str1)-release]);
      call_out("continue_play",1,release-1);
        return 1;
}

