//stockroom.c  by wfei apr 3 2001

inherit ROOM;
#include <ansi.h>
void create ()
{
set("short","��Ʊ���򴰿�");
set("long",@LONG

�����齣����Ĳ�Ʊ����վ��������뷢�ƵĻ���
����Ի�10���ƽ���һ�Ų�Ʊ��
LONG);
set("exits", ([ /* sizeof() == 1 */
 "south" : "/d/wiz/entrance",
]));
set("chat_room",1);
      set("no_magic", 1);
  set("no_fight",1);
        set("freeze",1);
set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/stockboss" : 1,
]));
       setup();
== δ����� 51% == (ENTER ������һҳ��q �뿪��b ǰһҳ)
}
void init()
{
add_action("block_cmd", "", 1);
}
int block_cmd(string args)
{
string verb;
verb = query_verb();
    if (verb == "bian") return 1;
    if (verb == "fight") return 1;
    if (verb == "exert") return 1;
    if (verb == "cast") return 1;
    if (verb == "steal") return 1;
    if (verb == "ji") return 1;
    if (verb == "perform") return 1;
    if (verb == "smash") return 1;
    if (verb == "dest") return 1;
    if (verb == "update") return 1;
    if (verb == "kill") return 1;
    return 0;
}
>l
����Ʊ���򴰿ڡ�   - /d/city/stockroom
    
�����齣����Ĳ�Ʊ����վ��������뷢�ƵĻ���
����Ի�10���ƽ���һ�Ų�Ʊ��
    ����Ψһ�ĳ����� south��
  �齣���� ��Ʊ��&&����ע���(Stock seller)
>more stock
û�����������
>more stock seller
//stockboss.c  ��Ʊ��
//by wfei apr 18 2001

inherit F_VENDOR_SALE;
#include <ansi.h>
int check_player();
int report_num();
int do_ready();
int give_rsg();
int check_time();
int tell_num();
int del_num();
int set_up();
//int set_title();

string *num=({
     "һ","��","��","��","��",
    "��","��","��","��","��",
              });
void create()
{
    reload("stockboss");
   set_name(HIC"��Ʊ��&&����ע���"NOR, ({"stock seller", "boss","officer"}));
== δ����� 5% == (ENTER ������һҳ��q �뿪��b ǰһҳ)
   set("title",HIY"�齣����"NOR);
   set("age",19);
   set("gender","Ů��");
   set("per",40);
   set("attitude", "peaceful");
   set("long",
"�����齣����Ĳ�Ʊ����Ա���������choose <5λû���ظ����ֵĺ���>\n"
"�������Ʊ,0��ͷ�ĺ�����Ч��ÿ��ÿ����������5�š�\n"
"��ask boss about �н�����  ����ѯ���ڵ��н����롣\n"
"��ask boss about mynum  ����ѯ���ڵ������ڵĲ�Ʊ���롣\n"
"��ask boss about �н�   ���Խ����Ի��2000���ƽ�\n"
"�粻Ҫ�ƽ���ask boss about rsg   ����ȡ4���˲ι���\n"
"��ask boss about ���� ��������ǰ�ĺ��룬����������5�žͲ���������\n"
"����û������5������Ĳ������ţ��������ڵ�ʱ��ϵͳ�Զ����š�\n");
   set("chat_chance",1);
   set("chat_msg",({"�뷢�Ƶģ������ڴ����Ʊ��10GOLDһ�ţ�ÿ���쿪һ�ν��������صȽ���ÿ��2000GOLD��RSG4��!\n"}));
   setup();
   set("inquiry", ([
   "�н�":(: check_player :),
  "rsg":(: give_rsg :),
   "�˲ι�":(: give_rsg :),
   "�н�����":(: report_num :),
   "����":(: check_time :),
== δ����� 10% == (ENTER ������һҳ��q �뿪��b ǰһҳ)
   "mynum":(: tell_num :),
   "����":(: del_num :),
//   "ע��":(: set_up :),
//   "title":(: set_title :),
      ]));
   }
void init()
{
  if(wizardp(this_player())){
   add_action("do_ready","ready");}
 if(userp(this_player())){
 add_action("do_stock","choose");}
}
int do_ready()
{
   if(time()<query("start_time")||time()<query("start_time")+259200)
     return notify_fail("���Ǹտ��������ô�����ˣ������ڰɣ�\n");
  message("system",HIR"������Ԥ�㡿��Ʊ��ί����ϯ--"+BLINK HIB"������"NOR+HIR"�� ��"+to_chinese(query("stocknum"))+"�ڲ�Ʊ���۽��Ϊ"+BLINK HIY""+to_chinese(query("income"))+""NOR+HIR"���ƽ�\n"NOR,users());
message("system",HIR"����ƷԤ�桿"+BLINK HIB"������"NOR+HIR"�� ��"+to_chinese(query("stocknum"))+"�ڲ�Ʊ�ؽ���Ʒ����һ���ҽ��ģ�Ϊ��"+BLINK HIY""+to_chinese(4*query("stock_nowin"))+"���˲ι�"NOR+HIC"��"+BLINK HIY""+to_chinese(2000*query("stock_nowin"))+"���ƽ�\n"NOR,users());
  message("system",HIR"����Ʊ�������齣�����Ʊ��ί�᣺ ����׼��������ѡ��"+to_chinese(query("stocknum"))+"�ڲ�Ʊ�ؽ��н����룡\n"NOR,users());
this_object()->set("nosell_time",time());
set("start_time",time());   
set_temp("starting",1);   
== δ����� 15% == (ENTER ������һҳ��q �뿪��b ǰһҳ)
 this_object()->delete("income");
   {if(query_temp("asked"))  
    this_object()->delete_temp("asked");}
call_out("start", 60);
   return 1;
    }
void start()
{
if(!query_temp("starts")){
   message("system",HIR"����Ʊ�������齣�����Ʊ��ί�᣺ ���ڿ�ʼ��ѡ��һλ���룡\n"NOR,users());
call_out("choose",30);}
else {
message("system",HIR"����Ʊ�������齣�����Ʊ��ί�᣺ ��"+to_chinese(query_temp("starts"))+"λ������"+BLINK HIY""+query_temp("nums")+"\n"NOR,users());
if(query_temp("starts")<5){
message("system",HIR"����Ʊ�������齣�����Ʊ��ί�᣺ ���ڿ�ʼ��ѡ��"+to_chinese(query_temp("starts")+1)+"λ���룡\n"NOR,users());
call_out("choose",30);}
else {call_out("finish",30);}
}
}

void choose()
{
 int i; 
== δ����� 21% == (ENTER ������һҳ��q �뿪��b ǰһҳ)
   object me=this_object();
    string numb;
 numb=num[random(sizeof(num))];
if(numb=="һ"){set_temp("nums",1);}
if(numb=="��"){set_temp("nums",2);}
if(numb=="��"){set_temp("nums",3);}
if(numb=="��"){set_temp("nums",4);}
if(numb=="��"){set_temp("nums",5);}
if(numb=="��"){set_temp("nums",6);}
if(numb=="��"){set_temp("nums",7);}
if(numb=="��"){set_temp("nums",8);}
if(numb=="��"){set_temp("nums",9);}
if(numb=="��"){set_temp("nums",0);}
  {if(query_temp("nums")==query("number/number1")
  ||query_temp("nums")==query("number/number2")
  ||query_temp("nums")==query("number/number3")
  ||query_temp("nums")==query("number/number4")
  ||query_temp("nums")==query("number/number5"))
    { call_out("choose",2);} 
   else {
add_temp("starts",1);
{if(!me->query("number/count")){
me->set("number/number1",query_temp("nums"));
== δ����� 26% == (ENTER ������һҳ��q �뿪��b ǰһҳ)
me->add("number/count",1);}
else {
if((int)me->query("number/count")<2){
   me->set("number/number2",query_temp("nums"));
   me->add("number/count",1);}
else if((int)me->query("number/count")<3&&(int)me->query("number/count")>1){
   me->set("number/number3",query_temp("nums"));
   me->add("number/count",1);}
else if((int)me->query("number/count")<4&&(int)me->query("number/count")>2){
   me->set("number/number4",query_temp("nums"));
   me->add("number/count",1);}
else if((int)me->query("number/count")<5&&(int)me->query("number/count")>3){
   me->set("number/number5",query_temp("nums"));
   me->add("number/count",1);}
     }
}

call_out("start",30);
}
}
}

void finish()
== δ����� 31% == (ENTER ������һҳ��q �뿪��b ǰһҳ)
{
 object me=this_object(); 
  int num1,num2,num3,num4,num5,num6,num7;
num1=(int)me->query("number/number1");
num2=(int)me->query("number/number2");
num3=(int)me->query("number/number3");
num4=(int)me->query("number/number4");
num5=(int)me->query("number/number5");
me->delete("number/count");
me->delete_temp("nums");
me->delete_temp("starts");
me->delete_temp("starting");
   message("system",HIR"����Ʊ�������齣�����Ʊ��ί�᣺ 5λ�����Ѳ�����\n"NOR,users());
   message("system",HIR"����Ʊ�������齣�����Ʊ��ί�᣺ ��"+to_chinese(query("stocknum"))+"�������н�������ǣ�\n"NOR,users());
   message("system",HIR"����Ʊ�������齣�����Ʊ��ί�᣺\n\n\n"+BLINK HIW"                         "+to_chinese(num1)+to_chinese(num2)+to_chinese(num3)+to_chinese(num4)+to_chinese(num5)+"\n"NOR,users());
me->set("number/win",num1*10000+num2*1000+num3*100+num4*10+num5);
me->save();
}

int check_player()
{
object me=this_object();
  object who=this_player();
== δ����� 37% == (ENTER ������һҳ��q �뿪��b ǰһҳ)
  object ob;
  int t,stock1,stock2,stock3,stock4,stock5,win;
 win=(int)me->query("number/win");
 stock1=who->query("stock/number1");
 stock2=who->query("stock/number2");
 stock3=who->query("stock/number3");
 stock4=who->query("stock/number4");
 stock5=who->query("stock/number5");
 if(win) {
  if(stock1==win||stock2==win||stock3==win||stock4==win||stock5==win)  {
   if(who->query("stocknum")!=me->query("stocknum")){
  write("��������벻����һ�ڵģ��Ѿ�������!\n");
  who->move("/u/mudbug/policeroom");
  who->start_busy(300);
  tell_object(who,"����Ϊ�漰α���Ʊ���ݣ����о���5���ӣ���ϲ��....\n");
  message("channel:rumor",HIM"������ͨ�桿��Ʊ��ί�᣺"+who->query("name")+"("+who->query("id")+")��Ϊð�䱾���ؽ���Ʊ���ѱ�������\n"NOR,users());
  who->delete("stock");}
  else {
  if(query("stock_nowin")<1) { t=1;}
 else {t=query("stock_nowin");}
  message("system",HIR"����֪ͨ���齣�����Ʊ��ί�᣺ ��"+to_chinese(query("stocknum"))+"���ؽ�����"+who->query("name")+"("+who->query("id")+")ǰ���콱����ûƽ�"+to_chinese(t*2000)+"����\n"NOR,users());

 message_vision("$N��$nЦ�����Ĺ��ֵ�������ϲ���ƣ���\n",me,who);
message_vision("$N��$n˵������"+to_chinese(t*2000)+"���ƽ��Ѿ�������������˻�����\n",me,who);
== δ����� 42% == (ENTER ������һҳ��q �뿪��b ǰһҳ)who->add("balance",t*20000000);
  me->set("stock_nowin",0);
who->delete("stock");
 me->save();
 who->save();}
    }
 else {
message_vision("$N��$n˵��������"+to_chinese(query("stocknum"))+"���н�����Ϊ��"+me->query("number/win")+",��û�У��´κ��ˣ���\n",me,who);
who->delete("stock");}}
else {  if(query_temp("starting")){
   write("���ڿ����У����ǹ�һ����������˽�������ʰɣ�\n");}
else {write("���ڻ�û�п�����û���н����룡\n");}
      }
  return 1;
}

int do_stock(string arg)
{     object me=this_object();
      object who=this_player();
      int afford,hour,min,sec,hourl,minl,secl;  
if (!arg) return notify_fail("��������Ҫ��Ĳ�Ʊ���룬��ʽ:choose <5λ���ظ�������>\n");
 if(sizeof(arg)!=5) return notify_fail("������5λ���ظ������֡�\n");
else if(time()<(int)me->query("nosell_time")||time()<(int)me->query("nosell_time")+86400)
== δ����� 47% == (ENTER ������һҳ��q �뿪��b ǰһҳ)
    {
  hourl=(query("nosell_time")+86400-time())%3600;
  minl=hourl%60;
  secl=minl%60;
 hour=(query("nosell_time")+86400-time()-hourl)/3600;
 min=(hourl-minl)/60;
  sec=secl;
message_vision("$N��$n˵�������տ���������ʱ�����۲�Ʊ,����רְ�ҽ������š�����\n���"+to_chinese(query("stocknum")+1)+"�ڲ�Ʊ���ۻ���"+to_chinese(hour)+"Сʱ"+to_chinese(min)+"����"+to_chinese(sec)+"�룡��ӭ����ʱ���٣���\n",this_object(),this_player());}
   else {
  if(query("number")) {
     me->delete("number");
  me->add("stocknum",1);
message("system",HIR"����Ʊ����֪ͨ���齣�����Ʊ��ί�᣺ ��"+to_chinese(query("stocknum"))+"�ڲ�Ʊ���ڿ�ʼ���ۣ���ӭ��ҵ�kz u n����\n"NOR,users());
  {if(query("stock_nowin")>4)  {me->set("stock_nowin",0);}}
  me->add("stock_nowin",1);
message("system",HIR"����ƷԤ�桿"+BLINK HIB"������"NOR+HIR"�� ��"+to_chinese(query("stocknum"))+"�ڲ�Ʊ�ؽ���Ʒ����һ���ҽ��ģ�Ϊ��"+BLINK HIY""+to_chinese(4*query("stock_nowin"))+"���˲ι�"NOR+HIC"��"+BLINK HIY""+to_chinese(2000*query("stock_nowin"))+"���ƽ�\n"NOR,users());
    me->save();}
     if( !(afford=me->can_afford(100000)) )  {
       write("�����Ǯ����,10���ƽ�һ�Ų�Ʊ��\n");
           return 1;}
else if( afford == 2 )  {
      write("�ֽ��ף�������Ʊ��������ֽ𲻹���\n");
      return 1;}
== δ����� 52% == (ENTER ������һҳ��q �뿪��b ǰһҳ)
else if(who->query("stock/buys")>4){
write("���Ѿ�����5���ˣ�Ҫ����������ɣ�\n");}
  else {
if(who->query("stock/number1")==(int)arg
||who->query("stock/number2")==(int)arg
||who->query("stock/number3")==(int)arg
||who->query("stock/number4")==(int)arg)
  {    write("���Ѿ����������ˣ�\n");}
   else {   
   who->pay_money(100000);
this_object()->add("income",10);
{if(query("income")>0&&query("income")%100==0){
message("system",HIR"������Ԥ�㡿��Ʊ��ί����ϯ--"+BLINK HIB"������"NOR+HIR"�� ��"+to_chinese(query("stocknum"))+"�ڲ�Ʊ�����ڣ����۽��Ϊ"+BLINK HIY""+to_chinese(query("income"))+""NOR+HIR"���ƽ�\n"NOR,users());
message("system",HIR"����ƷԤ�桿"+BLINK HIB"������"NOR+HIR"�� ��"+to_chinese(query("stocknum"))+"�ڲ�Ʊ�ؽ���Ʒ����һ���ҽ��ģ�Ϊ��"+BLINK HIY""+to_chinese(4*query("stock_nowin"))+"���˲ι�"NOR+HIC"��"+BLINK HIY""+to_chinese(2000*query("stock_nowin"))+"���ƽ�\n"NOR,users());
message("system",HIR"����Ʊ��桿�齣�����Ʊ��ί�᣺ ��"+to_chinese(query("stocknum"))+"�ڲ�Ʊ�������ڳ��ۣ���ӭ��ҵ�kz u n����лл��ҵ�֧�֣�\n"NOR,users());}
}
   {if(who->query("stocknum")!=me->query("stocknum")){
   who->delete("stock");
 who->set("stocknum",(int)me->query("stocknum"));}}
this_object()->save();
   message_vision("$N�ó�10�����ӣ�������$n��\n",who,me);
  message_vision("$N���˵�Ǯ���ڵ����ϴ��һ�Ų�Ʊ��$n��\n",me,who);
  write("����Ĳ�Ʊ������"+arg+"\n");
== δ����� 58% == (ENTER ������һҳ��q �뿪��b ǰһҳ)
message_vision("$N��$n˵��������Ĳ�Ʊ�Ѽ���������ݣ���\n",me,who);
  {if(!who->query("stock/buys")){
 who->set("stock/number1",(int)arg);}
 else if(who->query("stock/buys")==1){
 who->set("stock/number2",(int)arg);}
else if(who->query("stock/buys")==2){
 who->set("stock/number3",(int)arg);}
else if(who->query("stock/buys")==3){
 who->set("stock/number4",(int)arg);}
else if(who->query("stock/buys")==4){
 who->set("stock/number5",(int)arg);}
    }
who->add("stock/buys",1);}
         }
    }
   return 1;
}

int give_rsg()
{
 object me=this_object();
  object who=this_player();
  object ob1,ob2,ob3,ob4;
== δ����� 63% == (ENTER ������һҳ��q �뿪��b ǰһҳ)
  int t,stock1,stock2,stock3,stock4,stock5,win,i;
 win=(int)me->query("number/win");
 stock1=who->query("stock/number1");
 stock2=who->query("stock/number2");
 stock3=who->query("stock/number3");
 stock4=who->query("stock/number4");
 stock5=who->query("stock/number5");
if(win) {
 if(stock1==win||stock2==win||stock3==win||stock4==win||stock5==win)  {
   if(who->query("stocknum")!=me->query("stocknum")){
  write("��������벻����һ�ڵģ��Ѿ�������!\n");
  who->move("/u/mudbug/policeroom");
  who->start_busy(300);
  tell_object(who,"����Ϊ�漰α���Ʊ���ݣ����о���5���ӣ���ϲ��....\n");
  who->delete("stock");
message("channel:rumor",HIM"������ͨ�桿��Ʊ��ί�᣺"+who->query("name")+"("+who->query("id")+")��Ϊð�䱾���ؽ���Ʊ���ѱ�������\n"NOR,users());}
   else {
  if(query("stock_nowin")<1) { t=1;}
 else {t=query("stock_nowin");}
   for(i=0; i<t; i++) { 
 ob1=new("/d/obj/drug/renshen-guo");
 ob2=new("/d/obj/drug/renshen-guo");
 ob3=new("/d/obj/drug/renshen-guo");
== δ����� 68% == (ENTER ������һҳ��q �뿪��b ǰһҳ)
 ob4=new("/d/obj/drug/renshen-guo");
 ob1->move(who);
 ob2->move(who);
 ob3->move(who);
 ob4->move(who);}
 message_vision("$N��$n˵���������Ȼ��Ҫ�ƽ��Ǿ͸���"+to_chinese(4*t)+"���˲ι��ɣ���\n",me,who);
 message_vision("$N��$n"+to_chinese(4*t)+"���˲ι���\n",me,who);
  message("system",HIR"����֪ͨ���齣�����Ʊ��ί�᣺ ��"+to_chinese(query("stocknum"))+"���ؽ�����"+who->query("name")+"("+who->query("id")+")ǰ���콱������˲ι�"+to_chinese(4*t)+"����\n"NOR,users());
  me->set("stock_nowin",0);
who->delete("stock");
who->save();
me->save();}
   }
 else { write("��û�н�����ô���˲ι�ѽ��\n");
  who->delete("stock");}}
else {  if(query_temp("starting")){
   write("���ڿ����У����ǹ�һ����������˽�������ʰɣ�\n");}
  else {write("���ڻ�û�п�����û���н����룡\n");}
       }
return 1;
}
int report_num()
{
== δ����� 74% == (ENTER ������һҳ��q �뿪��b ǰһҳ)
if(this_object()->query("number/win")) {
message_vision("$N����$n��������"+to_chinese(query("stocknum"))+"���ؽ��н�����Ϊ��"+this_object()->query("number/win")+",������û����\n",this_object(),this_player());
      }
else {write("���ڻ�û�п�������û���н����룡\n");  }
  return 1;
}
int check_time()
{
  int hour,min,sec,hourl,minl,secl;
if(time()>query("start_time")+259200)  {
  if(!query_temp("asked")){
message("system",HIR"����Ʊ�������齣�����Ʊ��ί�᣺ Ӧ"+this_player()->query("name")+"("+this_player()->query("id")+")��Ҫ�󣬲�Ʊϵͳ����齱����ʱ��\n"NOR,users());
    set_temp("asked",1);
    call_out("do_ready",10);}
   else {
  write("���ǲ�������?���ڲ����ڿ�����\n");}  }
else if(time()<query("nosell_time")||time()<query("nosell_time")+86400){
message_vision("$N��$n˵�������տ�����,����רְ�ҽ������š��������"+to_chinese(query("stocknum")+1)+"�ڲ�Ʊ��������Զ!��\n",this_object(),this_player());}
   else {
  hourl=(query("start_time")+259200-time())%3600;
  minl=hourl%60;
  secl=minl%60;

== δ����� 79% == (ENTER ������һҳ��q �뿪��b ǰһҳ)
 hour=(query("start_time")+259200-time()-hourl)/3600;
 min=(hourl-minl)/60;
  sec=secl;
message_vision("$N��$n˵�������������"+to_chinese(query("stocknum"))+"�ڲ�Ʊ��������"+to_chinese(hour)+"Сʱ"+to_chinese(min)+"����"+to_chinese(sec)+"�룡��\n",this_object(),this_player());
message_vision("$N��$n˵������лл������ǲ�Ʊϵͳ��֧�֣������ڻ�û������ʱ�䣬������ɣ���\n",this_object(),this_player());}
   return 1;
}
int tell_num()
{
  object who=this_player();
  int num;
  num=this_player()->query("stocknum");
    if(who->query("stock")){
   if(who->query("stock/buys")==1){
   write("�������е�"+to_chinese(num)+"�ں���һ����"+who->query("stock/number1")+"\n");}
   if(who->query("stock/buys")==2){
   write("�������е�"+to_chinese(num)+"�ں���������\n"+who->query("stock/number1")+"       "+who->query("stock/number2")+"\n");}
   if(who->query("stock/buys")==3){
   write("�������е�"+to_chinese(num)+"�ں���������\n"+who->query("stock/number1")+"      "+who->query("stock/number2")+"      "+who->query("stock/number3")+"\n");}

   if(who->query("stock/buys")==4){
   write("�������е�"+to_chinese(num)+"�ں����ĸ���\n"+who->query("stock/number1")+"   "+who->query("stock/number2")+"    "+who->query("stock/number3")+"    "+who->query("stock/number4")+"\n");}
   if(who->query("stock/buys")==5){
   write("�������е�"+to_chinese(num)+"�ں��������\n"+who->query("stock/number1")+"   "+who->query("stock/number2")+"    "+who->query("stock/number3")+"    "+who->query("stock/number4")+"     "+who->query("stock/number5")+"\n");}
== δ����� 84% == (ENTER ������һҳ��q �뿪��b ǰһҳ)             }
   else {write("������û���κκ��룡\n");}
   return 1;
}
int del_num()
{
  object me=this_object();
  object who=this_player();
  if(who->query("stock")){
if(who->query("stocknum")!=query("stocknum")){
message_vision("$N��$n˵������OK !����ǰ�Ĳ�Ʊ����ɾ���ˣ�����Լ������ˣ���\n",me,who);
 who->delete("stock");
  who->save();}
   else {
message_vision("$N��$n˵��������Ҫɾ��������һ�ڵĺ��룬����ask boss about �н�  ��������\n",me,who);}
                 }
   else {
message_vision("$N��$n˵�������㶼û�в�Ʊ����ʲô����ѽ����\n",me,who);}
  return 1;
}
int set_up()
{
       object who=this_player();
== δ����� 90% == (ENTER ������һҳ��q �뿪��b ǰһҳ)
       object me=this_object();
       mapping skill_status;
      int temp,i,nopass;
       string *sname;

     if(who->query("set_up")){
   tell_object(who,HIR"\n     ���Ѿ����齣�����ע������ˣ�\n"NOR);}
   else {
    if(who->query("combat_exp")<1000000||who->query("daoxing")<1000000){
   tell_object(who,"   �����ѧ�����̫�ͣ�\n");}
    else {
   if(mapp(skill_status = who->query_skills())){
      skill_status = who->query_skills();
     sname = keys(skill_status);
       temp = sizeof(skill_status);
     for (i = 0; i < temp; i++){
           if(who->query_skill(sname[i],1)<150)
          nopass+=1;}
     if(nopass) {
 tell_object(who,"   ����"+chinese_number(nopass)+"���û�ܴﵽ150��������ע�ᣡ\n");}
    else {
     me->add("setupnum",1);
   who->set("set_up/number",me->query("setupnum"));
== δ����� 95% == (ENTER ������һҳ��q �뿪��b ǰһҳ)
   me->save();
tell_object(who,"�����齣���������ң�����ע��������Ȼ�ˣ����Ժ���ҪΪ��վ�ķ�չ�������ײ��ǣ�\n");
message("system",HIW"������ͳ��ίԱ�᡿:��վ�����"+who->query("name")+"("+who->query("id")+")Ը�����ŵ�ԣ�\nΪ�˱�վ�Ľ�����չ���ľ������ֱ���׼Ϊ�齣�����"+to_chinese(query("setupnum"))+"λע�����\n"NOR,users());
  who->set("title",HIW"�齣����NO."+to_chinese(query("setupnum"))+"ע�����"NOR+who->query("title"));
   who->save();}
    }
      }
        }
     return 1;
}
int set_title()
{ 
       object who=this_player();
    if(who->query("set_up")){
       who->set("title",HIW"�齣����NO."+to_chinese(who->query("set_up/number"))+"ע�����"NOR+who->query("title"));
   message_vision("$N��$n˵��:��OK !��\n",this_object(),who);}
    else {
       message_vision("$N��$n˵��:������ask officer about ע��   ��ע��!��\n",this_object(),who);}
    return 1;
}
>
>hp
look
���������������������������������齣���桿����������������������������
�� ����״̬ �� ��������          �Ա�����       I D��[Dick]       ��
�ǩ�������������������������������������������������������������������
���� ��Ѫ ��200    /200     [100%]  �� ���� ��0      /0      (+   0)��
���� ���� ��250    /250     [100%]  �� ���� ��0      /0      (+   0)��
���� ʳ�� ��0      /300     [����]  �� ��ѧ ��0                     ��
���� ��ˮ ��0      /300     [����]  �� Ǳ�� ��100                   ��
���� ��ְ ��0                       �� ɱ�� ��0                     ��
���� ���� ��δ���;                                                ��
���� �ٰ� ��δ����;                                                 ��
���������������������������������齣���桿����������������������������

>����Ʊ���򴰿ڡ�   - /d/city/stockroom
    
�����齣����Ĳ�Ʊ����վ��������뷢�ƵĻ���
����Ի�10���ƽ���һ�Ų�Ʊ��
    ����Ψһ�ĳ����� south��
  �齣���� ��Ʊ��&&����ע���(Stock seller)
>more here
//stockroom.c  by wfei apr 3 2001

inherit ROOM;
#include <ansi.h>
void create ()
{
set("short","��Ʊ���򴰿�");
set("long",@LONG

�����齣����Ĳ�Ʊ����վ��������뷢�ƵĻ���
����Ի�10���ƽ���һ�Ų�Ʊ��
LONG);
set("exits", ([ /* sizeof() == 1 */
 "south" : "/d/wiz/entrance",
]));
set("chat_room",1);
      set("no_magic", 1);
  set("no_fight",1);
        set("freeze",1);
set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/stockboss" : 1,
]));
       setup();
== δ����� 51% == (ENTER ������һҳ��q �뿪��b ǰһҳ)
}
void init()
{
add_action("block_cmd", "", 1);
}
int block_cmd(string args)
{
string verb;
verb = query_verb();
    if (verb == "bian") return 1;
    if (verb == "fight") return 1;
    if (verb == "exert") return 1;
    if (verb == "cast") return 1;
    if (verb == "steal") return 1;
    if (verb == "ji") return 1;
    if (verb == "perform") return 1;
    if (verb == "smash") return 1;
    if (verb == "dest") return 1;
    if (verb == "update") return 1;
    if (verb == "kill") return 1;
    return 0;
}
