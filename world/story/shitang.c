//By tianlin@mhxy for 2002.1.9
#include <ansi.h>

string give_gift();

private mixed *story = ({

""MAG"�����������ʳ�����������û��������"NOR"",
""YEL"�㱧Թ���˷���ȫ���ͣ���ϣ���˼۽�һ����"NOR"",
""CYN"��˵���������һ�����ƣ����������������׳��"NOR"",
"���������ڴ���רְι�����׵��������Ǻ���",
""RED"�������������Ҹ����£����ǲ�������������١�"NOR"",
""BLU"Ҫ��û��ɳ�ӡ���˿���òݣ��ŵ�������Է�����������"NOR"",
(: give_gift :),
""GRN"�������������Ҹ����£�����ʳ�����Ӭ���١�"NOR"",
""YEL"�����ǳԺ����������ܣ����֪�����ǵ�����û�������еĺá�"NOR"",

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
        STORY_D->give_gift("/clone/misc/lancao", 1,
                           HIM "\n��ž����һ��һ���òݵ�������ǰ��\n\n" NOR);
        return HIM "�ò����˼�~~~~��\n" NOR;
}
