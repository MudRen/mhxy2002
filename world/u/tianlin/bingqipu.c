//By tianlin@mhxy for 2001.9.18

#include <ansi.h>
inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG

��һ���žͿ����������ϰ��Ÿ��ֱ��������ϰٽ��صĴ󵶵������
�ӵķɻ�ʯ����Ӧ�о��С�Ů�ϰ�����Ӣ������Զ��СŮ����Ҳ����
Զ�ھֶ��ϰ壬����������ü��


LONG);

        set("exits", 
        ([ //sizeof() == 4
                "north" : __DIR__"qinglong-e1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/xiaoxiao" : 1,
        ]));

	set("no_clean_up", 0);
       setup();
	//replace_program(ROOM);
}
void init()
{
        add_action("do_enter", "enter");
}
int do_enter()
{

	object me=this_player();
	me=this_player();

              return notify_fail(HIY"������ߵ겻�Ǹ������趨��\n"NOR);
       if(me->query("daoxing")<50000)
              return notify_fail(HIY"������ߵ겻�Ǹ������趨��\n"NOR);
	message_vision(HIY"$N������ĵ��ߵ���ȥ��\n"NOR, me);
       this_player()->move("/u/tianlin/wuqi/daojudian");
        return 1;
}
