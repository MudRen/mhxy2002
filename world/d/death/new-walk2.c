//By tianlin@mhxy for 2001.12.30����

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "�����");
  set ("long", @LONG

���������һ�ķ���̨��̨�Ͽ��������ǳ���ɽ����ӵ�ͼ�ڡ�̨
�ϵ�ͭ����ż�������������ܵ����׻�������ð���⡣������
һ������¥�󹬵������Ҳ�൱�ĸ����ûʣ����м���������
��˾��������ȥ��
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"new-walk3",
  "west" : __DIR__"new-walk4",
  "north" : __DIR__"new-walk5",
  "south": __DIR__"new-zhaopo",
]));
  set("hell", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhangmen" : 1,
]));
  set("valid_startroom", 1);

  setup();
}

void init()
{
        add_action("do_enter", "enter");
}
int do_enter()
{
	object me=this_player();
	me=this_player();
       if ( (string)me->query("family/family_name")=="���޵ظ�"){
       if(me->query("combat_exp")<2000000)
              return notify_fail(HIY"��û���ʸ��ȥ��ڤ��.\n"HIC"�����ȥ��,ڤ��Ҳ��������\n"NOR);
       if(me->query("daoxing")<2000000)
              return notify_fail(HIY"��û���ʸ��ȥ��ڤ��.\n"HIC"�����ȥ��,ڤ��Ҳ��������\n"NOR);
	message_vision(HIY"$N����˫�ۣ���ǽ������˹�ȥ��\n"NOR, me);
       this_player()->move("/d/death/mishi");
	message_vision(HIM"$N�������ǽ,������˵������ϲ�á�\n"NOR, me);
       me->set_temp("mingwang_tianlin");
        return 1;
}}
