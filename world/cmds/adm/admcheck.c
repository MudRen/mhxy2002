#include <ansi.h>
inherit F_CLEAN_UP;

int count3=0;
int if3();
int main(object me,string arg)
{
	object tempob;
       string func,tilde,type;
       int val1,val2,i,j,ppl_cnt;
	string *dir, *ppls, tempid,tempname;
	mixed info;
	int info2;
	if (!arg)
		return notify_fail("��Ҫ��ʲô��\n");
	sscanf(arg,"%s %s %s %d %d",type,func,tilde,val1,val2);
       if (!type && type != "skill" && type != "setting")
             return notify_fail("������������help check!\n");
       if ((!tilde)||((tilde!=">")&&(tilde!="<")&&(tilde!="=")&&(tilde!="<>")))
		return notify_fail("ƥ�����������help check!\n");
	if (!val1)
		return notify_fail("ȱ�ٵ�һ����������help check!\n");
	if ((!val2)&&(tilde=="<>"))
   		return notify_fail("ȱ�ٵڶ�����!����help check!\n");
	if ((val2<=val1)&&(tilde=="<>"))
   		return notify_fail("��һ���ڶ��������ô���!����help check!\n");
   message("system", "\n*** ���ڼ��Ƿ���ҵ�����**************\n",users());

seteuid(getuid());
	write("����У�\n");
	log_file("static/check_log", sprintf("-------------------------------------------------\n"));
	log_file("static/check_log", sprintf("����������[%s]%s%s%d,%d������嵥��\n",type,func,tilde,val1,val2));
       count3=0;
	ppl_cnt = 0;
	dir = get_dir(DATA_DIR + "login/");
	for(i=0; i<sizeof(dir); i++) {
		reset_eval_cost();
		write(dir[i]);
		ppls = get_dir(DATA_DIR + "user/" + dir[i] + "/");
             	ppl_cnt += sizeof(ppls);
		for(j=0; j<sizeof(ppls); j++) {
			if( sscanf(ppls[j], "%s",tempid)==1 )
                     {
	if (tempid[strlen(tempid)-2..strlen(tempid)-1]!=".o") continue;
				tempob=new("obj/user");
			tempob->set("id",tempid[0..strlen(tempid)-3]);
				if(!tempob->restore_temp())
			{
					write(tempob->save_file()+" wrong!\n");
				continue;
			}
				tempid = tempob->query("id");
				tempname = tempob->query("name");
				tempob->set("id",tempid);
				tempob->set("name",tempname);
				if (type=="skill"){
                           if (tempob->query_skill(func))
                           switch (tilde) {
                           case ">":  
                                  if (tempob->query_skill(func)>val1){
                                        log_file("static/check_log",sprintf("%s[%s] %s:%d | ",tempid,tempname,func,tempob->query_skill(func)));
                                  if3();
					}
					break;
                           case "<":
                                  if (tempob->query_skill(func)<val1) {
                                        log_file("static/check_log",sprintf("%s[%s] %s:%d | ",tempid,tempname,func,tempob->query_skill(func)));
					if3();
					}
					break;
                           case "=":
                                  if (tempob->query_skill(func)==val1){
                                        log_file("static/check_log",sprintf("%s[%s] %s:%d | ",tempid,tempname,func,tempob->query_skill(func)));
					if3();
					}
					break;
				case "<>":
                                  if ((tempob->query_skill(func)>val1) && (tempob->query_skill(func)<val2)) {
                                        log_file("static/check_log",sprintf("%s[%s] %s:%d | ",tempid,tempname,func,tempob->query_skill(func)));
					if3();
					}
					break;
				}//switch
				}//if (type=="skill")
				else{
                           if (tempob->query(func))
                           switch (tilde) {
                           case ">":  
                                  if (tempob->query(func)>val1){
                                        log_file("static/check_log",sprintf("%s[%s] %s:%d | ",tempid,tempname,func,tempob->query(func)));
                                  if3();
					}
					break;
                           case "<":
                                  if (tempob->query(func)<val1) {
                                        log_file("static/check_log",sprintf("%s[%s] %s:%d | ",tempid,tempname,func,tempob->query(func)));
					if3();
					}
					break;
                           case "=":
                                  if (tempob->query(func)==val1){
                                        log_file("static/check_log",sprintf("%s[%s] %s:%d | ",tempid,tempname,func,tempob->query(func)));
					if3();
					}
					break;
				case "<>":
                                  if ((tempob->query(func)>val1) && (tempob->query(func)<val2)) {
                                        log_file("static/check_log",sprintf("%s[%s] %s:%d | ",tempid,tempname,func,tempob->query(func)));
					if3();
					}
					break;
				}//switch
				}//else
				destruct(tempob);
                      }//if( sscanf(ppls[j], "%s",tempid)==1 )
		}//for(j=0; j<sizeof(ppls); j++) {
	}//for(i=0; i<sizeof(dir); i++) {
	
	write("\n\n�ܹ���"+ ppl_cnt + "λʹ���ߡ�\n");
	write( count3 + " ��ʹ���߷��ϼ��Ҫ��\n");
	log_file("static/check_log", sprintf("\n�˴μ����%s[%s]��%s����!\n",this_player()->query("name"),geteuid(this_player()),ctime(time())[0..15]));
	return 1;
}//main

int if3()
{
       log_file("static/check_log",sprintf("\n"));
       count3++;
       return 1;
}
