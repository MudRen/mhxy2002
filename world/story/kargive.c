//By tianlin@mhxy for 2002.1.9

#include <ansi.h>

string give_gift();

private mixed *story = ({
        "����Ⱥ������浹ù....",
        "������˵������ʲôù��",
        "����Ⱥ������浹ù....",
        "����Ⱥ̾��һ�������������а����û���ɣ� ������û��......��",
        "�����ˣ�.........",
        "�����ˣ�" HIY "������һ�ֳ��˿��Ա���˵���ҩ��" NOR,
        "����Ⱥ��������....", 
        "�����ˣ�" HIG "���ã�����ɽ�ˣ�" NOR,
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

string give_gift()
{
        STORY_D->give_gift("/clone/gift/karwan", 1,
                           HIM "\n��ž����һ��һö�ɵ���������ǰ��\n\n" NOR);
        return 0;
}
