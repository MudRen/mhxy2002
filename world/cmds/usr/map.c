// CMDS USR wherei.c
// Created by kittt@DJX2000
// Last Modified by kittt@DJX2000 5/20/2000
// �Զ���ѯ���λ�ã����������趨������

#include <ansi.h>

inherit F_CLEAN_UP;

string get_area(string area);
string remove_ansi(string str) // ȥ����ɫ�ĺ�����������
{
        int i;
        string *color = ({ BLK, RED, GRN, YEL, BLU, MAG, CYN, WHT,
                        HIR, HIG, HIY, HIB, HIM, HIC, HIW,
                        HBRED, HBGRN, HBYEL, HBBLU, HBMAG, HBCYN, HBWHT,
                        BBLK, BRED, BYEL, BBLU, BMAG, BCYN,
                        NOR, BLINK });
                        
        if( !str || !stringp(str) ) return 0;
        i = sizeof(color);
        while( i-- ) {
                str = replace_string(str, color[i], "");
        }
        return str;
}

int main(object me, string arg)      
{
        string file,here;
        object room;
        int i;

        room = environment(me);
        here = file_name(room);

        file = read_file("doc/help/maps/map-" + get_area(here)); //����map�ļ�
        if (!file || !stringp(file)) 
                return notify_fail("������ʱû�е�ͼ��\n");
        // ��ɫ���
        file = replace_string(file, remove_ansi(room->query("short")), HIY+room->query("short")+NOR);
      me->start_more(file);
 
        write(" ___________________________________________________________\n");
        write(CYN"\n��Ŀǰ������"HIM+"/adm/daemons/questd"->query_city(room)+ HIW+remove_ansi(room->query("short"))+CYN"��\n"NOR);
        return 1;
}

// modified by happ

string get_area(string area)  // ��path�ҳ�map�ļ�
{
        string* list=explode(area,"/");
        return list[sizeof(list)-2];        
}


int help(object me)
{
write(@HELP
ָ���ʽ : map
 
���ָ���������֪���������Ļ���
�ڵ�ͼ�е�λ�á�
 
HELP
    );
    return 1;
}
