// block.c
// modified by mon 7/25/97

#include "/doc/help.h"
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj;
	string option, target;

	if( !arg) {
         CHANNEL_D->do_channel(me,"chat*",sprintf("���Ž����Ĵ�����,��������˭�����ϱȽϺ��ʡ�"));
         return notify_fail("��Ҫ�ص������˭��Ƶ����\n");
          }
        if( sscanf(arg, "%s %s", option, target)!=2 ) target = arg;
	if ( option != "-s" && option != "-u" ) target = arg;

	obj = find_player(target);
        if(!obj) return notify_fail("û������ˣ�����\n");

	if(option=="-s") {  // say, tell, reply, emote and whisper,chat
	  if( wizardp(obj)) return notify_fail("�б�Ҫ��\n");
	  obj->set("channel/tell_block",time()+86400);
          obj->set("channel/chat_block",time()+86400);
	  tell_object(obj, "�������Ƶ������ʱ�ر��ˣ�\n");
	  CHANNEL_D->do_channel(me,"chat*",sprintf("�����ܻ���˵,�����С������,��Ȼ������ô��ϻ�,�����������ǲ�����!!!"));
          CHANNEL_D->do_channel(me,"chat*",sprintf("˵��,�ӹ��������ó�һ��齺��,��"+obj->query("name")+"�������������ʵʵ��"));  
        } else if(option=="-u") { // open channel
          obj->delete("channel/tell_block");
          obj->delete("channel/chat_block");
	  tell_object(obj, "���Ƶ�������ˣ�\n");
	  CHANNEL_D->do_channel(me,"chat*", sprintf("��ݺݵ�˵,�����Ժ󻹸Ҳ�����˵����,Ȼ���" + obj->query("name") + "���ϵĽ���˺��������"));
          CHANNEL_D->do_channel(me,"chat", sprintf(obj->query("name")+"��Ȼ�лڹ����µ��뷨,����ʱ����ͷ��ɡ�"));
	} else {  // chat and rumor
	  // block chat and rumor for 24 hours. (24*3600 sec).
	  if( wizardp(obj)) return notify_fail("�б�Ҫ��\n");
          obj->set("channel/chat_block",time()+86400);
	  tell_object(obj, "��Ĺ���Ƶ������ʱ�ر��ˣ�\n");
          CHANNEL_D->do_channel(me,"chat*",sprintf("�ӹ�������ȡ��һ�齺��,����"+obj->query("name")+"���ϡ�")); 
          CHANNEL_D->do_channel(me,"chat",sprintf( obj->query("name")+ "�ϻ�̫��,�������˼��!\n"));
        }

	return 1;

}

int help(object me)
{
   write(@HELP
ָ���ʽ�� block <ĳ��>     ��ʱ�ص�ĳ�˵�chat��rumorƵ����
           block -s <ĳ��>  ��ʱ�ص�ĳ�˵�say��reply��emote��tell��whisper��
           block -u <ĳ��>  �ָ�ĳ�˵�����ͨ����

HELP
   );
   return 1;
}
