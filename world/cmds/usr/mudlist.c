//By tianlin@mhxy for 2002.1.20,�޸�

#include <net/daemons.h>
#include <net/macros.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
   mapping mud_list;
   mapping mud_svc;
   mixed *muds;
   string output, output1, output2="";
   int loop, size, pplno, total;
   int count=0;
   int show_all=0;

   if( !find_object(DNS_MASTER) )
     return notify_fail("��·���鲢û�б����룬���Ƚ���·�������롣\n");

   //   Obtain mapping containing mud data
   mud_list = (mapping)DNS_MASTER->query_muds();

   // so we recognise ourselves as a DNS mud
   mud_svc = DNS_MASTER->query_svc() + ([ Mud_name() : 0 ]);

   if(!mud_list)
     return notify_fail( MUD_NAME + "Ŀǰ��û�и���·������ Mud ȡ����ϵ��\n");

   //   Get list of all mud names within name server
   muds = keys( mud_list ) - ({ "DEFAULT" });

   //   Place mudlist into alphabetical format
   muds = sort_array(muds, 1);
     count = sizeof(muds); 
   //    If mudname provided, search server's database for a match
   //   and display its cooresponding address
if(arg && arg != "" && arg != "ALL" && arg != "ES" ) {
                arg = htonn(arg);
                if(!mapp( mud_list[arg] )) {
                        write(MUD_NAME + "��û�к���� Mud ȡ����ϵ��\n");
                        return 1;
                }
                
   /*if(arg && arg != "") {
           if(arg=="-a") 
        show_all=1;
           else {
     arg = htonn(arg);

     if(!mapp( mud_list[arg] )) {
        write(MUD_NAME + "��û�к���� Mud ȡ����ϵ��\n");
        return 1;
     }*/
  if( wizardp(me) && !me->query("env/debug") )
  printf("�й� %s ����Ѷ��\n%O\n", arg, mud_list[arg]);
   else  
                        printf("\n"HIR"�й�"HIW" %s "NOR+HIR"����Ѷ��\n"
                                HIC"�q���������������������������������������r\n"NOR
                                HIC"��"NOR+YEL"�������ƣ�"NOR+CYN"  %s\t\t        "HIC"��\n"
                                HIC"��"NOR+YEL"���ԣ�"NOR+CYN"      %s\t\t        "HIC"��\n"
                                HIC"��"NOR+YEL"�汾�� "NOR+CYN"     %s\t"HIC"��\n"
                                HIC"��"NOR+YEL"MudOS��"NOR+CYN"     %s\t        "HIC"��\n"
                                HIC"��"NOR+YEL"Mudlib��"NOR+CYN"    %s\t"HIC"��\n"
                                HIC"��"NOR+YEL"������ "NOR+CYN"     %s\t        "HIC"��\n"
                                HIC"��"NOR+YEL"�˿ڣ� "NOR+CYN"     %s\t\t"HIC"        ��\n"
                                HIC"��"NOR+YEL"״̬�� "NOR+CYN"     %s\t\t"HIC"        ��\n"
                                HIC"��"NOR+YEL"������ң�"NOR+CYN"  %s\t\t        "HIC"��\n"
                                HIC"��"NOR+YEL"����ʱ�䣺"NOR+CYN"  %s"HIC"  ��\n"
                                HIC"�t���������������������������������������s\n\n"NOR,
                                mud_list[arg]["NAME"],
                                undefinedp(mud_list[arg]["MUDNAME"])?
                                "����":mud_list[arg]["MUDNAME"],
                                undefinedp(mud_list[arg]["ENCODING"])?
                                "����":(mud_list[arg]["ENCODING"]=="GB"?"���庺��":"���庺��"),
                                undefinedp(mud_list[arg]["VERSION"])?
                                "����":mud_list[arg]["VERSION"],
                                undefinedp(mud_list[arg]["DRIVER"])?
                                "����":mud_list[arg]["DRIVER"],
                                undefinedp(mud_list[arg]["MUDLIB"])?
                                "����":mud_list[arg]["MUDLIB"],
                                mud_list[arg]["HOSTADDRESS"],
                                mud_list[arg]["PORT"],
                                mud_list[arg]["_dns_no_contact"]<1?
                                "����":"�Ͽ�",
                                undefinedp(mud_list[arg]["USERS"])?
                                "����":mud_list[arg]["USERS"],
                                undefinedp(mud_list[arg]["TIME"])?
                                "����":mud_list[arg]["TIME"],
                                );
                return 1;
        }
   output = "\n\n"+
BRED WHT+"��������          Mud    ������·λַ      �˿�      ����ʱ��     �������\n"NOR+
HIW+"��������������������������������������������������������������������������\n"NOR;
      
   total = 0;
   //   Loop through mud list and store one by one
   for(loop = 0, size = sizeof(muds); loop<size; loop++) {
           string mudname,mudtime;     
                mudname= mud_list[muds[loop]]["MUDNAME"] ; 
                if(strlen(mudname)>17) mudname=mudname[0..16];
     mudtime=mud_list[muds[loop]]["TIME"];
        output1 = sprintf(BBLU+YEL"%-17s %-6s %-16s  %-5s %15s %5s\n"NOR, 
        mudname,
              upper_case(muds[loop]),
        mud_list[muds[loop]]["HOSTADDRESS"],
        mud_list[muds[loop]]["PORT"],
             undefinedp(mud_list[muds[loop]]["TIME"])?
        "                ":
        mudtime[0..15],
        undefinedp(mud_list[muds[loop]]["USERS"]) ?
        "":""+mud_list[muds[loop]]["USERS"] );
         if (undefinedp(mud_list[muds[loop]]["USERS"]))
        pplno = 0;
         else
        sscanf(mud_list[muds[loop]]["USERS"], "%d", pplno);
               total += pplno;
         if(mud_list[muds[loop]]["MUDLIB"]=="MHXY"
               || mud_list[muds[loop]]["MUDLIB"]=="HLXY"
               || mud_list[muds[loop]]["MUDLIB"]=="XLQY"
               || mud_list[muds[loop]]["MUDLIB"]=="DTXY"
               || mud_list[muds[loop]]["MUDLIB"]=="hlxy"
               || mud_list[muds[loop]]["MUDLIB"]=="XYJ"
               || mud_list[muds[loop]]["PORTUDP"]=="6670"
               || mud_list[muds[loop]]["TCP"]=="all"
               )
           output2=output1+output2; 
                    else if(show_all==1)
           output2=output2+output1;
                   }
   output+=output2;
     output+=
HIW"��������������������������������������������������������������������������\n"NOR;
    output+="���� "YEL+ sprintf("%d", count-1) + NOR" ������ Mud ��"WHT+MUD_NAME+CYN"�ൺվ"NOR"��������վ�� "YEL+sprintf("%d",total)+NOR" λʹ���������С�\n";
   //   Display dumped mudlist output through user's more pager
   this_player()->start_more( output );

   return 1;
}

int help()
{
        write(@HELP

ָ���ʽ�� mudlist               �г������е��λ�����վ��
           mudlist -ALL          �г������е����Уͣ���
           mudlist <Mud ����>    �г�ָ���ͣ������Ϣ

HELP
   );
   return 1;
}


