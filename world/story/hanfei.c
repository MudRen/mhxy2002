//By tianlin@mhxy for 2002.1.9

#include <ansi.h>

int give_gift();

private mixed *story = ({
        "��˵���"HIG"���ֺ���"NOR+WHT"���У�������λ���С�ģ�",
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
        STORY_D->give_gift("/quest/feizei/hanfei", 1,
                           HIM "\n��ಡ���һ��"HIG"���ֺ���"HIM"������ǰ��\n\n" NOR);
    CHANNEL_D->do_channel(this_object(), "rumor", 
	    "��˵"HIG"���ֺ���"+HIM+"�����ˣ����Ҷ��С�ģ�\n");
        return 1;
}