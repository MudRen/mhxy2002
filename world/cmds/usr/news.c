// CMDS USR news.c
// Created by kittt@DJX2000
// Last Modified by kittt@DJX 6/2/2000
// XKX ������˽������Ϣһ������ Help Whatsnew
// �����ʦ�ڸ��º���Ҫ��д/doc/help/�ļ����ܲ����㡣
// �������������ϵͳ������������Ϣֻ����POSTһ����
// Ҳ������������Ķ�����Ҳ�ȽϷ��㡣
//By waiwai@2000/11/17 �����Ż�ʱ������.����ɫ��֧��.
//Last modified by waiwai@2001/07/08 ����������ʾ.
#include <ansi.h>;
#include <mudlib.h>
#include <command.h>
inherit BULLETIN_BOARD;

// create part����ͨ��BOARD���
void create()
{
set_name(HIY"�λ��������ŷ�������"NOR, ({ "newsboard"}) );
set("location", "/d/wiz/newsroom"); // ��������һ��ROOM������BOARD���򵥣����� 
set("board_id", "news_b");              // ��һ��ָ������������Ҳ���ԡ�
setup();
set("capacity", 1000);//������Ŵ浵��.�Զ������������趨Ϊ 1/100
}

// ���������������loginʱ���õġ�NEWS_D->check_news(user);
int check_news(object me)
{
int num,i,last_time_read;
mapping *notes, last_read_time;
string myid,msg="";

notes = query("notes");
last_read_time = me->query("board_last_read");
myid = query("board_id");

if( !pointerp(notes) || !sizeof(notes) ) return 1;

if(me->query("lastReadNews") < sizeof(notes))
i=sizeof(notes)-me->query("LastReadNews");
                write(HIG"\n�����ϴ��Ķ�������"NOR+((i==0)? ""HIG"û���κ�":""HIG"����"+HIY+i+NOR+HIG"��")+HIG"���ŷ�����(Ŀǰ�ܹ��� "HIR+sizeof(notes)+NOR+HIG" ������)\n\n"NOR);
if(i>6) { 
write(HIY"\n���������������������������������� "HIR"�λ�����������Ϣ"HIY
" ��������������������������������\n\n"NOR); 
write(WHT"\t\t������� "HIR"Help news "NOR WHT"���鿴�λ���������ϵͳ��ʹ�÷�����\n\n"NOR); 
write(HIY"������������������������������������������������������������������������������������ \n"NOR);
write(HBBLU HIY" ��ӭ����"+INTERMUD_NAME+"                           ��վ��ַ��qd.qdmud.com 6666\n\n"NOR);
} else
// if(userp(me)){
if( i <=6 && i>=1 ) {// С�ڵ���6�����Ų���ʾ���⣬��Ȼ��FLOOD
msg = HIY"\n���������������������������������� "HIR"�λ�����������Ϣ"HIY
" ��������������������������������   \n"NOR;

if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
num = 1;
else
for(num = 1; num<=sizeof(notes); num++)
if( notes[num-1]["time"] > last_read_time[myid] ) break;

if (mapp(last_read_time)) last_time_read = last_read_time[myid];
for(i=sizeof(notes)-1 ; i>num-2 ; i--) {
msg += sprintf("[%4d]"NOR,i+1);
msg += sprintf("     %-=35s %18s (%s)\n",
notes[i]["title"], notes[i]["author"],
                                 BJTIME_CMD->chinese_time(7, ctime(notes[i]["time"])));
}

msg += HIY"������������������������������������������������������������������������������������  \n"NOR;
msg+=HBBLU HIY" ��ӭ����"+INTERMUD_NAME+"                           ��վ��ַ��qd.qdmud.com 6666 \n"NOR;
msg+=WHT"������� "HIR"Help news "NOR WHT"���鿴�λ���������ϵͳ��ʹ�÷�����\n\n"NOR;
me->start_more(msg);
}

// }
}

int main(object me, string arg)
{
int num,i,last_time_read;
mapping *notes, last_read_time;
string myid,msg;

last_read_time = me->query("board_last_read");
myid = query("board_id");
notes = query("notes");

i=sizeof(notes)-me->query("LastReadNews");

if( !pointerp(notes) || !sizeof(notes) )
return notify_fail("�λ����� Ŀǰû���κ����ŷ�����\n"NOR);

if( !arg ) {
if(i>1 && !i<0 ) write("�����"HIR" Help news "NOR"���鿴�λ���������ϵͳ��ʹ�÷�����\n"); 
return notify_fail(
"�λ����� Ŀǰ���� "HIR+sizeof(notes)+NOR" �����ŷ���"+((i==0)? "��":"������ "HIY+
i++ +NOR" ��������δ�Ķ���")+"\n"); }

if( arg=="all") {// ��ʾ��������
msg = HIB"\n\n ���������������������������������� "HIW"�λ���������ȫ��"HIB
" ����������������������������������   \n"NOR;
notes = query("notes");

if (mapp(last_read_time)) last_time_read = last_read_time[myid];
for(i=sizeof(notes)-1 ; i>-1 ; i--) {
msg += sprintf("%s[%4d]" NOR,
notes[i]["time"] > last_time_read ? HIR"(δ��)"NOR:WHT"(�Ѷ�)"NOR, i+1);
msg += sprintf("     %-=30s %18s (%s)\n",
notes[i]["title"], notes[i]["author"],
                                   BJTIME_CMD->chinese_time(7, ctime(notes[i]["time"])));
}
msg += HIB" ���������������������������������� "HIW"�λ���������ȫ��"HIB
" ����������������������������������   \n"NOR;
me->start_more(msg);
return 1;
}
else
if ( arg=="new" || arg=="next" ) { // ��ʾ��������
if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
num = 1;
else
for(num = 1; num<=sizeof(notes); num++)
if( notes[num-1]["time"] > last_read_time[myid] ) break;

} else if( !sscanf(arg, "%d", num) )

return notify_fail("�㵽��Ҫ���ڼ�������ѽ��\n");

if( num < 1 || num > sizeof(notes) )
return notify_fail("���Ѿ����������������ˡ�\n");

num--;
me->start_more( sprintf("\n\n%s\n"HIR"�������⣺"HIY"%s\n"HIW"������ʦ��%s\n"HIG"����ʱ�䣺%s\n"NOR

WHT"����������������������������������������������������������������������������������\n"NOR,
BBLU HIG"��"HIC"�λ�����"HIG"����"+chinese_number(num + 1)+"������ "NOR, 
COLOR_D->replace_color(notes[num]["title"],1), notes[num]["author"],
             BJTIME_CMD->chinese_time(1, ctime(notes[num]["time"])))
+ COLOR_D->replace_color(notes[num]["msg"],1)+NOR
     WHT"������������������������������������������������������������������������"HIY"["HIC"�λ�����"HIY"]\n"NOR, );

if( !mapp(last_read_time) )
me->set("board_last_read", ([ myid: notes[num]["time"] ]) );
else 
if( undefinedp(last_read_time[myid]) || notes[num]["time"] > last_read_time[myid] )
last_read_time[myid] = notes[num]["time"];

if(me->query("LastReadNews") < num + 1)
me->set("LastReadNews",num+1);

return 1;
}

void init()
{
add_action("do_post", "post");
add_action("do_discard", "discard");
}

int do_post(string arg)
{
mapping note;
      object me;
      me = this_player();

if(!arg) return notify_fail("����Ҫ������Ŀ��\n");

       if(strlen(arg) > 20 ) return notify_fail("�������,�������10�������ַ����ڣ�\n");

      if (wizardp(me) &&  wiz_level(me) < wiz_level("(admin)") )
          return notify_fail("��û���������������ŵ�Ȩ����\n");//By waiwai@2001/07/08

      if(!wizardp(me)) 
          return notify_fail("ֻ����ʦ�ſ����������������š�\n");//By waiwai@2001/07/08

note = allocate_mapping(4);
note["title"] = arg;
      note["author"] = this_player()->query("name")+"("+this_player()->query("id")+")";
note["id"] = this_player()->query("id"); 
this_player()->edit( (: done_post, this_player(), note :));
return 1;
}

void done_post(object me, mapping note, string text)
{
mapping *notes;

note["time"] = time();
note["msg"] = text;
notes = query("notes");
if( !pointerp(notes) || !sizeof(notes) )
notes = ({ note });
else
notes += ({ note });

if( sizeof(notes) > query("capacity"))
notes = notes[query("capacity")/100 .. query("capacity")];

set("notes", notes);
save();
restore();
// ʹ��channel��ʾ��ʾ������������.Ϊ���ܹ����㷺�ı������֪��.channel��ò�Ҫ�趨Ϊchat.
message("channel:rumor", HIB"\n\t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T\n"NOR, users());
message("channel:rumor", HIC"\t  ��"HIB"��"HIC"��"HIG" �d�g"BLINK+HBRED+HIW"�λ�����"NOR+HIG"�d�g"HIM"���������ŷ��������� "HIR"news new"HIM" �˽���ϸ��� "NOR HIC"��"HIB"��"HIC"��"NOR, users());
message("channel:rumor", HIB"\n\t�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T\n\n"NOR, users());

tell_object(me, HIY"���ųɹ�������ϡ�\n"NOR);

return;
}

int help(object me)
{
   write(@HELP

���λ����Ρ�����ϵͳָ�� 

ָ���ʽ :
news                    �鿴���еĺ����·��������š�
news all                �λ���������һ���� 
news new                �Ķ����µ����š� 
news next               �Ķ����µ����š� 
news <���ű��>         �鿴�˱�����ŵ���ϸ���ݡ� 

HELP
   );
   return 1;
}



 