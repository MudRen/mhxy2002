// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
// Room: some place in ��ţ����
// inside2.c

#include <ansi.h>
inherit ROOM;

void create ()
{
 set ("short", "����");
  set ("long", @LONG

��˵��ʿ����赭���ԵĲ����ã�������ȴ�����ܼø���һЩƶ
��Ĵ��񣮱��ϵļ����϶����߲ˣ�һ�ڴ�ˮ������ǽ�ǣ�һ��
���ֵĵ�ʿ�����ջ�¯���������ڣ���֪���ʲô�������Ҫ
Щ(yao)�Եġ�
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"houyuan",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "bowl" : "�������������ڵİ��ӣ���Ҫ����Ҳ������Щȥ�ԣ�
",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/wanfeng" : 1,
  "/d/ourhome/obj/hulu" :1,
   __DIR__"obj/shuitong" : 1,
]));
  set("clean_up", 1);

  setup();
}
void init()
{
        add_action("do_none","get");
        add_action("do_none","put");
}
int do_none()
{
        object zm=present("zhang men");
        if(zm)
        {
        message_vision("$N��$nҡ��ҡͷ��\n",zm,this_player());
        return 1;
        }
        return 1;
}
int valid_leave()
{
        if((present("bao", this_player())))
            return notify_fail("�������������\n");
   if((present("hulu", this_player())))
       return notify_fail("�㲻�ܰѺ�«���ߣ�\n");
    if((present("shuitong",this_player()))&&this_player()->query("lingtai_quest/quest_type")!="��ˮ")
       return notify_fail(HIY"û����,�����ڲ�������ˮͰ!\n"NOR);
    return ::valid_leave();
}

