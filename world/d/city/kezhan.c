//By tianlin@mhxy for 2001.5.1
inherit ROOM;
#include <ansi.h>

int block_cmd(string);
void create ()
{
  set ("short",YEL"�ϳǿ�ջ"NOR);
  set ("long", @LONG

   [1;32m[1;35m*[2;37;0m[1;32m/. [2;37;0m   [1;35m.   .    [1;36m*     [1;35m .   [1;36m*         [1;33mף[2;37;0m
  .[1;32m\[1;35m*[2;37;0m [2;37;0m   [1;35m.    [1;33m[][2;37;0m           [1;36m*[2;37;0m [35m.__         [1;33m��[2;37;0m
? [1;32m[1;35m*[2;37;0m[1;32m/ .[2;37;0m  [1;35m.[1;31m./\~~~~~~~~~~~~'[31m\. [2;37;0m[35m| [31m��[2;37;0m         [1;33m��[2;37;0m
   [1;32m\[1;35m*[2;37;0m   [1;31m,/,.\,...........,\.[2;37;0m[35m| [31m��[2;37;0m [1;35m.       [1;33m��[2;37;0m
   [1;31m||[2;37;0m  [1;35m..[1;30m��[2;37;0m[1;34m#[2;37;0m  [1;30m��[2;37;0m[1;34m��  ��[2;37;0m [1;30m��[2;37;0m[1;30m | [1;30m��[2;37;0m[31m��[2;37;0m          [1;33m��[2;37;0m 
   [1;31m||[2;37;0m [1;32m &&[1;30m��[2;37;0m   [1;30m��[2;37;0m       [1;30m��[2;37;0m[1;30m'|'[1;30m��[2;37;0m [1;36mo [2;37;0m [1;35m..[2;37;0m  
   [1;31m||[2;37;0m [1;32m##[1;36m�����������������������{�z�y�x[2;37;0m

�����ϲ������,��ת����������ѡ�

��ҿ�ջ�������������ģ���������ǳ���¡����֮��Ǯ����������
��������ο���ŵ���ѡ��¶������߰������ӣ����̾����˵��ڴ�
�������������ﲻ�����������õ�С�������ػ��д����ķ����͡���
¥���������������ǿͷ���
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"sleep",
  "west" : __DIR__"zhuque-s1",
  "north" : "/d/city/misc/idleroom",
  "enter" : "/d/hen/room",
  "up": "/d/wiz/entrance",
   "south": "/d/city/chatroom",
]));
  set("chat_room",1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/xiaoer" : 1,
  __DIR__"npc/huangfeihong" : 1,
  "/d/ourhome/npc/bigeye" : 1,
   "/u/tianlin/npc/wukong3" : 1,
  ]));
  set("no_time",1);

   set("no_time", 1);
  set("no_fight", 1);
  set("no_magic", 1);
        set("freeze",1);
  set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));
  set("valid_startroom", 1);
  setup();
  call_other("/obj/board/nancheng_b", "???");
}

void init()
{
    add_action("block_cmd", "", 1);
       add_action("do_exert", "exert");
}

int block_cmd(string args)
{
string verb;
verb = query_verb();

    // if (verb == "bian") return 1; // by mon 7/15
    if (verb == "xiudao") return 1;
    if(! wizardp (this_player())) 
    if (verb == "who") return 1;//by tianlin 2001.9.18
    return 0;
}

int valid_leave(object me, string dir)
{
        object ob = this_player();
        object mbox,*inv;
        inv = all_inventory(me);
        if ( sizeof(inv)&& dir == "north" ) return notify_fail("��С����������Ķ���˵����λ�͹٣���������ǰ�뽫���ϵ������ա�\n");

        if ( !me->query_temp("rent_paid") && dir == "east" )
        return notify_fail("��С��������Ц�ص�ס���㣺�Բ��𣬺����ǿ��˵��Է������Ǳ���Ŀ��ˣ�������š�\n");
        if( mbox = me->query_temp("mbox_ob") ) {
                tell_object(me, "�㽫���佻�ظ��ʲ\n");
                destruct(mbox);
        }
        if (dir == "enter"){
                message_vision ("[36m��[2;37;0m[1;36mϵͳ����[2;37;0m[36m��[2;37;0m[36m(monitord): [2;37;0m[1;31m���һ�ӭ$N����������.\n"NOR,me);
        }
        return ::valid_leave(me, dir);
}
int do_exert(string arg)
{
    tell_object(this_player(), "��ȫ���ڽ�ֹ�˶���\n");
    return 1;
}

