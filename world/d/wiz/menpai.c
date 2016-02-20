//By tianlin@Mhxy for 2002.1.10

#include <net/dns.h>
#include <mudlib.h>
#include <room.h>
inherit ROOM;

int do_look(string arg);
void reset_long();

int *exp = ({0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0});



string *names = ({
           "����ɽ���Ƕ�����",
           "�Ϻ�����ɽ������",
           "���޵ظ���������",
           "�¹�������������",
           "��ׯ�ۡ���������",
           "�ݿ�ɽ�޵׶�����",
           "��ѩɽ����������",
           "����������������",
           "��ɽ�ɡ�������  ",
           "����˧��������  ",
           "��������������  ",
           "��ʥ�š�������  ",
           "�䵱�ɡ�������  ",
           "�����ɡ�������  ",
           "��ɽׯ������  ",
           "��˿����������  ",
           "���ƶ���������  ",
           "��ԯ��Ĺ������  ",
           "��硡������    ",
           "ħ�̡�������    ",
});

string long=@LONG

��˵���Ÿ���Ϊ�˹���ţ��������������������˲ţ�
�ϳǿ�ջ�ϰ�ר��һ������������������Ъ�š�
LONG;

void create()
{
set("short", "���͹�");


set("exits", ([
  "east"   : "/d/wiz/entrance",
]));


set("objects", ([
]));



setup();
//reset_long();
}

void init()
{
	add_action("do_look", "look");
}

int do_look(string arg)
{
	if( !arg ) {
		reset_long();
	}
	command("look");
}

void reset_long()
{
     object *list;
     int i, j, ppl_cnt;
     int pmin,fc,ptuo,hell,moon,wzg,wdd,xshan,sea,shushan,tpeng,jjf,wsheng,wdang,sl,sjian,ps,hyd,xy,ling,mo;
     string str,result;
    
     int num_temp; 
     string name_temp;

     int *num_online = ({0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0});

     pmin=0;  fc=0;  ptuo=0;   hell=0;  moon=0; 
     wzg=0;   wdd=0; xshan=0;  sea=0;   shushan=0;
     tpeng=0; jjf=0; wsheng=0; wdang=0; sl=0;
     sjian=0; ps=0;  hyd=0;    xy=0;    ling=0;
     mo=0; 

     list = users();
     ppl_cnt = 0;
     j = sizeof(list);
     while( j-- ) 
       {
        if(wizardp(list[j]))  continue;
        str = sprintf("%s\n", list[j]->query("family/family_name"));

        switch(str)
          {
           case "����ɽ���Ƕ�\n": num_online[0]++;continue;
           case "�Ϻ�����ɽ\n": num_online[1]++;continue;
           case "���޵ظ�\n": num_online[2]++;continue;
           case "�¹�\n": num_online[3]++;continue;
           case "��ׯ��\n": num_online[4]++;continue;
           case "�ݿ�ɽ�޵׶�\n": num_online[5]++;continue;
           case "��ѩɽ\n": num_online[6]++;continue;
           case "��������\n": num_online[7]++;continue;
           case "��ɽ��\n": num_online[8]++;continue;
           case "����˧��\n": num_online[9]++;continue;
           case "������\n": num_online[10]++;continue;
           case "��ʥ��\n": num_online[11]++;continue;
           case "�䵱��\n": num_online[12]++;continue;
           case "������\n": num_online[13]++;continue;
           case "��ɽׯ\n": num_online[14]++;continue;
           case "��˿��\n": num_online[15]++;continue;
           case "���ƶ�\n": num_online[16]++;continue;
           case "��ԯ��Ĺ\n": num_online[17]++;continue;
           case "���\n": num_online[18]++;continue;
           case "ħ��\n": num_online[19]++;continue;
           default:   pmin++;
          } 

        ppl_cnt++;
       }


    for (i=0;i<sizeof(names);i++)
      {
       for (j=i+1;j<sizeof(names);j++)
          {if (num_online[i]<num_online[j]) 
             {
              num_temp=num_online[i];num_online[i]=num_online[j];num_online[j]=num_temp;
              name_temp=names[i];   names[i]=names[j];  names[j]=name_temp;
             }
          }
      }
   
    result =  "\n�������ɡ���������������\n";
    for (i=0;i<sizeof(names);i++) result=result+names[i]+num_online[i]+"\n";
    result=result+"��̶���֣�������"+pmin+"\n";

    set("long",long+"\n"+result);
}



