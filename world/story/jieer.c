//By tianlin@mhxy for 2002.1.9

#include <ansi.h>

string give_gift();

private mixed *story = ({
        "����������������MM����",
        "ͻȻһ�����޵�������������������",
        "����������Ƥ������ȥ��",
        "ߴ�Fһ���ҷ�֮�������Ķ���",
        "���ǿ�ʼ����MM�����ӣ�",
        "���֣��װ��ģ��㳤��ʲô������",
        "MM����������ͷ����ͦ�ݵģ�168��",
        "���֣��ܲ�����˵��ϸ�㣬̫�����ˡ�",
        "MM������ϸ�˰���",
        "���֣����ǡ������������",
        "MM�����ʲô��",
        "���֣����������������һ��168���ϰѣ�Ҳ�Ǻ�����˵�İ���",
        "MM�����ˣ�",
        "������֮�󡭡������������ſڱ���Χס�ˡ���",
        "@%^$&%^*^&(",
        "����������һ�������",
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
    STORY_D->give_gift("/d/obj/misc/crystalball", 1,
     HIM "\n��ž����һ��һ��ˮ�����������ǰ��\n" NOR);
 return HIM "��˵���ֵı���ˮ������ʧ�ˡ�\n" NOR;
}

