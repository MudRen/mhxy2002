// Room: /d/wiz/wizroom.c

inherit ROOM;
#include <ansi.h>

int block_cmd();

void create ()
{
  set ("short","��ʦ������");
  set ("long", @LONG

��������ʦ�������۵ĵط��������ʦ��Ҫ����Ļ���Ҳ����ѡ����
����С�

��������ʦӦ���صĹ�����سͷ���������ʦִ�У���ӭ��Ҽ��Υ����ʦ��
1 ���Ӧ�������������Ӧ���صĹ涨,���й�ɱ����֮��������ؼ������ء�
2 ��ֹ��δ�� QC �ϸ�֮�������ǲ���Ŀ����������κ����������һ������������
  ��״̬�½Ӵ��õ����κη��������С��Բ���Ŀ������֮���Ӧ���ǰ����������ʦ
  ֮ͬ����ܽ�����Ҳ��ԣ������߲�Ӧ�����֮�����޸�����/���滹ԭ֮���Σ���Ϊ
   ��Σ����֮����Ӧ�ú��������������wiz����
3 ��ֹ������ʦָ������Ҳ鿴���֮���ԡ�״̬�����ܵȷ��ų�����״���������
4 ��ֹ�޸����״̬���˴�֮���״̬����������Ϊ״̬֮�ı䣬�Լ����пɴ���֮״̬
5 ��ֹʹ����ʦ�������ҽ����κ�ϵͳ������֮�˼ʹ�ϵ����ʦͽ����ӡ�
6 ���Ͻ�ֹ�������д����ߣ�������������Կ�ͷ���桢�����������ȴ��֡� 
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"system",
  "north" : __DIR__"jobroom",
  "sleeve": __DIR__"sleeveroom",
  "guest": __DIR__"guest",
  "east": __DIR__"liwu",
  "jail":__DIR__"punish",
  "south":__DIR__"newsroom",
  "kz": "/d/city/kezhan",
  "enter": "/d/wiz/outjail",
  "down": "/u/tianlin/workroom",
 ]));

  set("wiz_board",1);

  setup();
  call_other("/obj/board/wizard_b", "???");
}

void init()
{   
        if (!wizardp(this_player()))
          add_action("block_cmd","",1);   
}

int block_cmd()
{
       string verb = query_verb();

       if (verb=="say") return 0; //allow say
       if (verb=="chat") return 0;
       if (verb=="quit") return 0;
if (verb=="look") return 0;
if (verb=="post") return 0;
if (verb=="read") return 0;
       return 1;
}

