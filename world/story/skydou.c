//By tianlin@mhxy for 2002.1.9

#include <ansi.h>

string give_gift();

private mixed *story = ({
        "��ʦ��������"
        "���꣺û���������ˣ���ҿ��԰��շֹ�ȥ�����ˡ�"
        "�］������!",
        "����ʦ��Ȼ.",
        "�］�����֣���ϲ��ͷ������ķ���Ů����",
        "���֣���Ȼ��ϲ����",
        "�］���Ǳ��ӱ�ƽ������С�۾���Ů����ô����",
        "���֣�����������ܡ�",
        "�］��������ϲ���пڳ���Ů�˰ɣ�",
        "���֣�����Ц����û�и���������",
        "�］�͵�ץס���ֵ����죬�����ȵ�����Ȼ��ˣ���Ϊʲô��Ҫ�����ҵ�����!",      
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
        STORY_D->give_gift("/clone/gift/obj/qnd", 1,
         HIM "\n��ž����һ��һ��Ǳ�ܵ���������ǰ��\n" NOR);
        return HIM "��˵һЦ�ı�����䷲�䡣\n" NOR;
}

