// ip.c by happ

inherit F_CLEAN_UP;

int main(object me,string arg)
{

        string from;
        if( ! arg ) return notify_fail("������һ��ip��ַ\n");

        from="/adm/daemons/ipd"->seek_ip_address(arg);
        tell_object(me,"�������" +arg+ "���� "+from+" \n");
        return 1;
}
