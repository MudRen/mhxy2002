#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"ʥ��һ��"NOR);
        set("long", @LONG
�����������ʥ����,һ����ȥ,ֻ������������ʥ���
��Χ����ʱ�м�ֻ��ֵ���ɹ���һ�����ֽУ���������
��Щë���Ȼ��
LONG
        );
        set("exits", ([
                "up" : __DIR__"shengdian2",
                "down" : __DIR__"shengdian",
        ]) );
        set("objects", ([
                __DIR__"npc/ling":1,
        ]) );
        set("coor/x",-1020);
        set("coor/y",-70);
        set("coor/z",-150);
        setup();
}

int valid_leave(object me, string dir)
{       
        object a;
//        if( wizardp(me)) return 1;

        if (dir == "up") {
                if(objectp(a=present("ling", environment(me))) && living(a) && me->query("family/family_name")!="���")
                return notify_fail("�ɲ�-�������һ�����㲻�Ǳ��ɵģ���ȥ������\n");

        return ::valid_leave(me, dir);
        }

        return 1;
}
