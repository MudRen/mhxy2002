//By tianlin@mhxy for 2002.1.9

#include <ansi.h>

int give_gift();

private mixed *story = ({
        "[1;33m��˵���[2;37;0m[1;32m����[2;37;0m[1;33m���У�������λ���С�ģ�[2;37;0m",
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
        STORY_D->give_gift("/quest/feizei/feizei", 1,
                           HIM "\n��ಡ���һ��"HIR"����"NOR"������ǰ��\n\n" NOR);
        return 1;
}