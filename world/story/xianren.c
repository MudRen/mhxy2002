//By tianlin@mhxy for 2002.1.9

#include <ansi.h>

int give_gift();

private mixed *story = ({
        "��˵"HIC"�׷�����"NOR+WHT"�·��˼䴫��ҽ�飡",
        (: give_gift :)
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

int give_gift()
{
        STORY_D->give_gift("/clone/gift/lu", 1,
                           HIM "\n��ಡ���һ��"NOR+WHT"�׷�����"HIM"������ǰ��\n\n" NOR);
    CHANNEL_D->do_channel(this_object(), "rumor", 
	    "��˵"NOR+WHT"�׷�����"+HIM+"�·��˼䣡\n");
        return 1;
}