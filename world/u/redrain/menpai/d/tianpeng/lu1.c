#include <ansi.h>

inherit ROOM;
void create ()
{
  set ("short", "ʯ��·");
  set ("long", @LONG

С·��������ͷ׵�ʯ���̳ɵġ�ʯ������˸��ֻ��ƣ����Ǻ�
����·�߳�����ɻ�ͤ�����ѷ�����ȥ��ֻ��ż�������ļ�����
�����������ܵ�������

LONG);
set("item_desc" , ([ /* sizeof() == 1 */
"up": "�㿴�˰��죬����ԭ�������м�ͷ���ڷ�����ȥ��\n",

])); 
  set("exits", ([
              "west" : __DIR__"zhulin9",
              "up" : __DIR__"jingge",
      ]));
  set("objects", ([
//        __DIR__"npc/guo"   : 1,
      ]));

  setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "up" && me->query("family/family_name") != "���" && !wizardp(me))
                return notify_fail("����ֻ������ĵ��Ӳ��ܹ���ȥ��\n");
        return 1;
}

