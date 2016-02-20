//Creat by waiwai@2000/12/22 ���½���.
//By waiwai@2001/03/06 ���ý�ֹ,����ɫ��֧��.
//���õ���Ұ������������ɾ�����԰������
//������ʦ�������������ǲ��ܱ�ɾ����
//������Ұ������԰�ְλת�θ����ˡ�
//������Ұ������Է����Լ��İ���ְλ��
// ����ת�Ź���
//Last modified by waiwai@2001/06/28
#include <ansi.h>
#include <mudlib.h>
#include <command.h>

#define BOARD_CAPACITY query("capacity")
#define MAILBOX "/obj/mailbox"

inherit ITEM;
inherit F_SAVE;
string query_master();

void setup()
{
       string loc;

       if( stringp(loc = query("location")) ) move(loc);
       set("no_get", 1);

       restore();
}

void init()
{
       add_action("do_post", "post");
       add_action("do_read", "read");
       add_action("do_discard", "discard");
       add_action("do_appoint","banzhu");
       add_action("do_demit","bamian");
       add_action("do_lock", "lockb");
       add_action("do_unlock", "unlockb");
       add_action("do_forward", "zhuanxin");
}

string query_save_file()
{
       string id;

       if( !stringp(id = query("board_id")) ) return 0;
       return DATA_DIR + "board/" + id;
}

string query_master()
{
       if( query("master") )
               return query("master");
       else
               return "��δ����";
}

string short()
{
       mapping *notes;
       int i, unread, last_read_time;

       notes = query("notes");
       if( !pointerp(notes) || !sizeof(notes) )
               return ::short() + " ["CYN" û���κ�����   "CYN"���������"HIY+query_master()+NOR" ]";

       if( this_player() ) {
               last_read_time = (int)this_player()->query("board_last_read/" + (string)query("board_id"));
               for(unread = 0, i=sizeof(notes)-1; i>=0; i--, unread ++)
                       if( notes[i]["time"] <= last_read_time ) break;
       }
       if( unread )
return sprintf("%s"NOR" ["HIR" %d"NOR+CYN" �����ԣ�"HIC"%d"NOR+CYN" ��δ��   "CYN
"���������"HIY+query_master()+NOR" ]", ::short(), sizeof(notes), unread);
       else
    return sprintf("%s"NOR" [ "HIR"%d"NOR+CYN" ������   "CYN"���������"HIY+query_master()+NOR
" ]", ::short(), sizeof(notes));
}

string long()
{
  mapping *notes;
  int i, last_time_read;
  string msg, myid;

  notes = query("notes");
  msg=sprintf(HBBLU HIY" ���������%-10s                                        %-20s \n"NOR,
               query_master(),query("name"));
  msg+="[1;44m���   ��ȡ      �� �� ʱ ��       ������                    ��  ��  ��  ��       [m\n";

  if( !pointerp(notes) || !sizeof(notes) ) return query("long");

  last_time_read = this_player()->query("board_last_read/" + (string)query("board_id"));

  for(i=sizeof(notes)-1; i>=0; i--)
    msg += sprintf("[%3d] %4s  [%s] %-20s ����� %s\n",
      i+1, ( notes[i]["time"] > last_time_read ? HIR"(δ��)"NOR: WHT"(�Ѷ�)"NOR),
BJTIME_CMD->chinese_time(7, ctime(notes[i]["time"])),
notes[i]["author"], notes[i]["title"]);
  msg+="[1;44m���   ��ȡ      �� �� ʱ ��       ������                    ��  ��  ��  ��       [m\n";
msg+=HBBLU HIY" ��ӭ����"+INTERMUD_NAME+"                        ��վ��ַ��211.97.194.141 6666     \n"NOR;

  return msg;
}

//By waiwai@2001/03/05 changed.
int do_appoint(string arg)
{
       object me = this_player();

  if( (string)SECURITY_D->get_status(this_player(1)) != "(admin)"
   && (string)SECURITY_D->get_status(this_player(1)) !="(arch)"
 //  && me->query("id")!="gslxz"
 //  && me->query("id")!="waiwai"
 //  && me->query("id")!="suannai"
 && query("master")!=this_player(1)->query("id"))
   return notify_fail("��û��ί�ΰ�����Ȩ��!\n");
   
   if( wizardp(me) ) {
   if( !arg)
       return notify_fail("��Ҫί��˭Ϊ���������\n");
} else {
   if( !arg)
       return notify_fail("��Ҫ���������ְλת�θ�˭��\n");
}
   if( !present(arg,environment(me) ) )
       return notify_fail("��Ҫ��������Ҳ�������ط���\n");

//    if(this_object()->query("master") )
//                return notify_fail("������Ѿ��а����ˣ�\n");

   if( ! wizardp(me) && userp(me) ) {

}
   this_object()->set("master",arg);

   if( wizardp(me) ) 
   message("system",HIR"���������桿"+me->query("name")+"���� "HIG+arg+HIR" Ϊ "HIW+this_object()->name()+HIR" ������\n"NOR,users());
else
   message("system",HIR"���������桿����"+this_object()->name()+HIR"����"+me->query("name")+"������ְλת�θ�"+arg+"��\n"NOR,users());

    log_file("static/zhuanren",sprintf("%s(%s)��%s����ְλת�θ�%s ʱ����: (%s) \n",
me->name(1),geteuid(me),this_object()->name(),arg,
COLOR_D->clean_color(BJTIME_CMD->chinese_time(7, ctime(time()) )  ))); 

   save();      
 return 1;
}

//By waiwai@2001/03/05 changed.
int do_demit()
{
       object me = this_player();

  if( (string)SECURITY_D->get_status(this_player(1)) != "(admin)"
   && (string)SECURITY_D->get_status(this_player(1)) !="(arch)"
 //  && me->query("id")!="gslxz"
 //  && me->query("id")!="waiwai"
 //  && me->query("id")!="suannai"
&& query("master")!=this_player(1)->query("id"))

   return notify_fail("��û�а��������Ȩ��!\n");

   if(!this_object()->query("master") )
               return notify_fail("����汾����û�а�����\n"); 

   if( wizardp(me) ) 
   message("system",HIR"���������桿"+me->query("name")+"������ "HIW+this_object()->name()+HIR" ���� "+                   this_object()->query("master") +" ��\n"NOR,users());
else
   message("system",HIR"���������桿"+me->query("name")+"������ "HIW+this_object()->name()+HIR" ������ְλ ��\n"NOR,users());

   this_object()->delete("master");
   save();
 return 1;
}

void done_post(object me, mapping note, string text)
{
            mapping m;
       mapping *notes;
       int i;
       string msg="";

       note["time"] = time();

      if (me->query("signature")) {
               note["msg"]=COLOR_D->replace_color(text+HIB"\n
�������� �� ���� �� ���� ǩ ���� �� ��������\n\n"NOR+me->query("signature"),1);
       }
       else note["msg"]=COLOR_D->replace_color(text,1);  

       notes = query("notes");
       if( !pointerp(notes) || !sizeof(notes) )
               notes = ({ note });
       else
               notes += ({ note });

       if( sizeof(notes) > BOARD_CAPACITY )
               notes = notes[BOARD_CAPACITY / 4 .. BOARD_CAPACITY];//�Զ�ɾ����ĿΪ1/4.

       set("notes", notes);
       save();
  for(i=sizeof(notes)-1; i>=0; i--)

       note["msg"] = HIG"���� "+HIR + ::short() + HIY+"  ��������:\n\n" NOR+ text;
//       this_player()->edit( (: done_post, this_player(), note :));
//       "/obj/board/post_b"->done_post(me, note);
       restore();
       tell_object(me, HIC"������ϡ�\n"NOR);
message("channel:sys", HIW"��ϵͳ��"+me->name()+"("+me->query("id")+")�ո���"HIG+::short()+HIW
"������һ�����ӡ�\n\n"NOR, users());

       return;
}

int do_post(string arg)
{
       mapping note;
       object me;
       me = this_player();

  //By waiwai@2001/02/26 ���ý�ֹ(post_limit�����Ժ����滻Ϊwiz_board)
  if(!wizardp(me) && environment(me)->query("post_limit"))
     return notify_fail("ֻ����ʦ�ſ������������ԡ�\n");

  if(!wizardp(me) && environment(me)->query("wiz_board"))
     return notify_fail("ֻ����ʦ�ſ������������ԡ�\n");

  if(!arg) return notify_fail("������ָ��һ�����⡣\n");
  if(strlen(arg) > 20 ) return notify_fail("���������\n");

  if( me->query("no_board") && !wizardp(me)) //By waiwai@2001/06/28
        return notify_fail("���Ѿ������������κ����԰����Ե��ʸ�\n");

   //By waiwai@2001/03/06 ���ý�ֹ
   if((int)me->query_skill("literate",1) < 30 && !wizardp(me))
 return notify_fail("��Ķ���ʶ��С��30,û������������Ե�Ȩ����\n");

   if ( time() - me->query_temp("last_time/post") < 600 && !wizardp(me))
 return notify_fail("��ֻ�����ϴ�����10�����Ժ�ſ��������ԡ�\n");

      me->set_temp("last_time/post",time());

      note = allocate_mapping(4);
      note["title"] = arg;
note["author"] = this_player()->query("name")+
"("+capitalize(this_player()->query("id"))+")";//By waiwai@2001/03/05 changed.
       this_player()->edit( (: done_post, this_player(), note :));
       return 1;
}

int do_read(string arg)
{
       int num;
       mapping *notes, last_read_time;
       string myid;

       last_read_time = this_player()->query("board_last_read");
       myid = query("board_id");
       notes = query("notes");

       if( !pointerp(notes) || !sizeof(notes) )
               return notify_fail("���԰���Ŀǰû���κ����ԡ�\n");

       if( !arg ) return notify_fail("ָ���ʽ��read <���Ա��|new|next>\n");
       if( arg=="new" || arg=="next" ) {
               if( !mapp(last_read_time) || undefinedp(last_read_time[myid]) )
                       num = 1;
               else
                       for(num = 1; num<=sizeof(notes); num++)
                               if( notes[num-1]["time"] > last_read_time[myid] ) break;

       } else if( !sscanf(arg, "%d", num) )
               return notify_fail("��Ҫ���ڼ������ԣ�\n");

       if( num < 1 || num > sizeof(notes) )
               return notify_fail("�Ѿ�û��δ���ĸ������ԡ�\n");
       num--;
       this_player()->start_more( sprintf("\n\n%s\n"HIM"�������⣺ %s\n"HIY"�� �� �ˣ� %s\n"
HIW"����ʱ�䣺 %s\n"NOR WHT
       "������������������������������������������������������������������������������������\n"NOR,
               BBLU HIG+query("name")+NOR HIG" �� "HIR+chinese_number(num + 1)+HIG" ������"NOR, 
               notes[num]["title"], notes[num]["author"],
BJTIME_CMD->chinese_time(1, ctime(notes[num]["time"])))
               + notes[num]["msg"]+NOR
       WHT"��������������������������������������������������������������������������"HIY"["HIC"�λ�����"HIY"] \n"NOR, );

       if( !mapp(last_read_time) )
               this_player()->set("board_last_read", ([ myid: notes[num]["time"] ]) );
       else 
               if( undefinedp(last_read_time[myid]) || notes[num]["time"] > last_read_time[myid] )
                       last_read_time[myid] = notes[num]["time"];

       return 1;
}

//By waiwai@2001/03/05 changed.
int do_discard(string arg)
{
mapping *notes;
int num;
object me = this_player();
int n_start,n_end=0;
if( !arg || (sscanf(arg, "%d to %d", n_start,n_end)!=2 
  && sscanf(arg,"%d",n_start)!=1))
return notify_fail("ָ���ʽ��discard <���Ա��>\n");
notes = query("notes");
if (n_end==0) n_end=n_start;
if( !arrayp(notes) || n_start < 1 || n_end > sizeof(notes) )
return notify_fail("û���������ԡ�\n");
num=n_end;
while(num>=n_start) {
num--;
if( notes[num]["author"] != 
 (string) this_player(1)->query("name")+
 "("+capitalize(this_player(1)->query("id"))+")"
&& query("master")!=this_player(1)->query("id")
//&& me->query("id")!="gslxz"
//&& me->query("id")!="waiwai"
//&& me->query("id")!="suannai"
&& (string)SECURITY_D->get_status(this_player(1)) != "(admin)" ) {
      write(sprintf("��"HIR"%d"NOR"�����Բ�����д��,���ֲ��ǰ�����\n",num));
return 1;
}
}

       if(notes[num]["lock"]){
               return notify_fail("�������Ա�������,���Ƚ��� "HIR"(unlockb) \n"NOR);
       }

if (n_start >1)
            notes = notes[0..num-1] + notes[n_end..sizeof(notes)-1];
       else
         notes =notes[n_end..sizeof(notes)-1];
set("notes", notes);
save();
write("ɾ���� " HIR+ (n_start) +NOR " �ŵ��� "HIR+(n_end)+NOR" ������....Ok��\n");
log_file("static/POSTING", COLOR_D->clean_color(BJTIME_CMD->chinese_time(7,ctime( time()) ))+": "
               +me->query("name")+"("+me->query("id")+")"
+" ɾ����"+::short()+"�ĵ�"+(n_start)+"��"+(n_end)+"�����ԡ�\n");
 CHANNEL_D->do_channel(this_object(),"sys",this_player(1)->name()+"("+this_player(1)->query("id")+")"+" ɾ����"+::short()+"�ĵ�"+(n_start)+"��"+(n_end)+"�����ԡ�\n",);
   write("ɾ���� " + (num+1) + " ������....Ok��\n");

return 1;
}

//By waiwai@2001/04/25 added.
int do_lock(string arg)
{
       mapping *notes;
       int num;
       
       if( !arg || sscanf(arg, "%d", num)!=1 )
               return notify_fail("ָ���ʽ��lockb <���Ա��>\n");
       notes = query("notes");
       if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
               return notify_fail("û���������ԡ�\n");
       num--;
       if(notes[num]["lock"]){
               return notify_fail("���������Ѿ������ˡ�\n");
       }
       if( !wizardp( this_player(1)) ) return notify_fail("��ûȨ������\n");
       notes[num]["lock"]=1;
       set("notes", notes);
       save();
       write("����...�� " HIR+ (num+1) +NOR " ������....�ɹ���\n");
       return 1;

}

//By waiwai@2001/04/25 added.
int do_unlock(string arg)
{
       mapping *notes;
       int num;
       
       if( !arg || sscanf(arg, "%d", num)!=1 )
               return notify_fail("ָ���ʽ��unlockb <���Ա��>\n");
       notes = query("notes");
       if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
               return notify_fail("û���������ԡ�\n");
       num--;
       if(!notes[num]["lock"]){
               return notify_fail("��������û�м�����\n");
       }
       if( !wizardp( this_player(1)) ) return notify_fail("��ûȨ������\n");
       notes[num]["lock"]=0;
       set("notes", notes);
       save();
       write("����...�� " HIR+ (num+1) +NOR " ������....Ok��\n");
       return 1;
}

//By waiwai@2001/05/01 added.
int do_forward(string arg)
{
       mapping *notes;
       mapping m;
       int num;
       string dest;
       object me;
       me = this_player();
       
if((int)me->query_skill("literate",1) < 30 && !wizardp(me))
 return notify_fail("��Ķ���ʶ��С��30,��û��ת�ŵ�Ȩ����\n");

        if ( time() - me->query_temp("last_time/zhuanxin") < 1800 && !wizardp(me))
 return notify_fail("��ֻ�����ϴ�ת��30�����Ժ�ſ����ٴ�ת�š�\n");

       me->set_temp("last_time/zhuanxin",time());

       if( !arg || sscanf(arg, "%d %s", num, dest)!=2 )
            return notify_fail("��Ҫ����һ������ת�ĸ����ˣ�"HIR"( ��ʽ��zhuanxin ���Ա�� �Է�id )\n"NOR);

       notes = query("notes");
       if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
               return notify_fail("û���������ԡ�\n");
       num--;

       m = ([]);
       m["title"] = notes[num]["title"];
       m["text"] = notes[num]["msg"];
       m["time"] = notes[num]["time"];
       m["from"] = "/��Ϣ��Դ��"+::short()+",ת����" + this_player()->query("name")+"("+this_player()->query("id")+")";
       m["to"] = dest;
       MAILBOX->send_mail( dest, m );
       write("OK!\n");
   //By waiwai@2001/06/05 ���Ӽ���Լ�log.
    log_file("static/zhuanxin",sprintf("%s(%s)��ת���ż�����ת��"+::short()+"
����Ϊ"+m["title"]+"�����Ը�"+m["to"]+"  ʱ����: (%s) \n",
me->name(1),geteuid(me),COLOR_D->clean_color(BJTIME_CMD->chinese_time(7, ctime(time()))) ) ); 
message("channel:sys", HIW"������֮�ۡ�"+me->name()+"("+me->query("id")+")����ת��"HIG+::short()+HIW"����Ϊ
\t\t\t  "HIR+m["title"]+HIW" �����Ը�"HIY+m["to"]+"\n"NOR, users());

       return 1;
}


