// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��ɽ·");
        set("long", @LONG
ת������������ɽ·�ߵ������Ѿ����˾�ͷ������һ����ǿ��
�ĺ����˹�������ǰ����ˮ������ô�Ĺ�������ô���峺�������
�ͱڱ�һ�����۴ֵ����ٲ�����ֱ���������߱���Ƭ�����ֵ���
����ʵʵ��
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "southdown" : __DIR__"cyf3",
]));
        set("item_desc", ([
      		"����": "�ͱ���Ȼֱ����������˳�����٣��ƺ�����������(climb)��ȥ��\n",
      		"�ͱ�": "�ͱ���Ȼֱ����������˳�����٣��ƺ�����������(climb)��ȥ��\n",
      		"up": "�ͱ���Ȼֱ����������˳�����٣��ƺ�����������(climb)��ȥ��\n",
        ]) );
         set("coor/x",-1025);

	set("coor/y",55);

	set("coor/z",20);
set("no_magic",1);
	setup();
}
void init()
{
	add_action("do_climb", "climb");
}

int do_climb(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        if( arg == "�ͱ�" || arg == "����" || arg == "up")
        {
        me = this_player();
        message_vision("$Nץ���������������ͱ�������ȥ��\n", me);
        me->move(__DIR__"cyfd.c");
        return 1;
        }
        else
        {
                write("�㲻������"+arg+"\n");
                return 1;
        }
}

