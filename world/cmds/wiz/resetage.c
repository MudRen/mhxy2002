
#include <ansi.h>
inherit F_CLEAN_UP;

int main()
{
        object *users, present;
        int i, mudage;

        seteuid(getuid());
        users = users();
        i = sizeof(users);
        while(i--) {
                mudage = users[i]->query("mud_age");
                if( mudage >= 31536000) {
                  users[i]->set("mud_age",mudage-31536000+1);
                  tell_object(users[i],HIW "������䷢�ִ����ѻָ����羫���������˳����½��룡\n\n"NOR);
                  message("channel:sys",HIG"\n��"HIW"ϵͳ"HIG"����"+users[i]->query("name")+"("+users[i]->query("id")+")"+" �����䷢�ִ���,�Ѿ��޸�!\n "NOR,users());
                }
          mudage = users[i]->query("mud_age");
          users[i]->set("age",14+(int)mudage/86400);
          users[i]->save();
        }
        write("�����޸����.\n");
        return 1;
}

int help()
{
       write( @TEXT

TEXT
       );
       return 1 ;
}

