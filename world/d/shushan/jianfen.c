//jianfen.c by yushu 2000.11

inherit ROOM;
#include <ansi.h>
void init();

void create ()
{
  set ("short",HIR "��"HIY "����" HIR "��" NOR);
  set ("long", @LONG
ɽ·�ƹ�һ����Ȼ�����ɽ����������Ƶ�ƽ������������ɽ��
�Ľ��ء�����ȫ�����ϵľ����ý�����ϧȫ�����ˣ������Ӹ���
�������
LONG);

         set("exits", ([ 
               "up"   : __DIR__"shushan2",
      ]));
  set("objects", ([
        __DIR__"npc/lingyunzi"   : 1,
      ]));
     setup();
}



