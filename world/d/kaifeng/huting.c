// by cih 10/01/2002
// Room: /d/kaifeng/zhu2
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "���ͤ");
  set ("long", @LONG

���ͤ�������ǣ��Ͽ̽����ʷ�����а�����ͤ�Ӳ�������
����۷羰�ġ�����ÿ�����ǵİ˽������𳤶����õ�ʱ���
����������̾���������Թſ���ݣ��˺������޾��ڡ��ġ���
LONG);

  set("objects", ([ /* sizeof() == 1*/ 
 // "/d/bibotian/npc/table" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"zhu1",
]));
//      
        set("water", 1);
//  
  setup();
}

/* ��������λ�����������ݵ����μ�û�����������Ͱ������䡣���Ǻ� */

