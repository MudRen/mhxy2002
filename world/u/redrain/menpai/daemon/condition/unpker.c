#include <ansi.h>

void pk()
{
        object ob;
           string str;
                seteuid(ROOT_UID);
                str = "/d/unpker/npc/xunbu1";
                str[strlen(str)-1] = '1'+random(3);
                ob=new(str);
                tell_room(environment(this_player()),"��Ӱһ���������˰�������֡�\n");
                message("channel:chat",HIY"�������쳯��������(Meng)���������ɳ�"+ob->name()+HIY"����"+this_player()->name()+HIY"���������Ķ����о���\n" NOR,users());
                ob->move(environment(this_player()));
               ob->kill_ob(this_player());
                tell_object(this_player(),HIW "Ѳ��ͻȻ������������\n" NOR);
}
