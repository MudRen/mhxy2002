//door.c by yushu 2000.11
inherit ROOM;
#include <room.h>
#include <ansi.h>
void create ()
{
  set ("short",HIR "��"HIY "ɽ��" HIR "��" NOR);
  set ("long", @LONG
��������ɽ����ǰ��ɽ�ţ�����ɽ��ǰ�ɴ�����ʯ�̳ɣ���Ϊ
ƽ̹�����������Զ������Щ���𡣴Դ�С�ݴ�ʯ��ķ�϶�г�
�˳������㳡��Χ�������ܵ������֣��Ľ��ϸ����˼���ʯ����
�ּ�����Ϊģ������ǰ����ǽ���ߣ��������ݣ�����һ��������
���������ߵ����ɼľ��ͭ����(door)���Ϸ�һ����ң�����
��������š���ɽ�ɡ��������֡���ǰ����������վ�ż������ӡ�
LONG);

  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 3 */
  "enter" : "/d/shushan/xiaoyuan",
  "south" : "/d/shushan/shushan4",
  ]));
    set("objects", 
        ([ //sizeof() == 1
               "d/shushan/npc/dizi" : 2,
               "d/shushan/npc/dizi1" : 2,
    ]));
 
create_door("enter", "����", "out", DOOR_CLOSED);
set("valid_startroom", 1);
setup();

}

