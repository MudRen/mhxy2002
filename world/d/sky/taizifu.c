// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
#include <room.h>
inherit ROOM;


int valid_leave();

void create ()
{
  set ("short", "[0;35m��̫�Ӹ�[m");
  set ("long", @LONG

���е�����������̫����߸���������̳����󽫡�������߸��
�������������к���ɱ֮����߸�ܶ����⻹ĸ���޹ǻ�����һ
�����Ʈ�������������磬���Ա�źΪ�ǣ���ҶΪ�£������
�������ԣ���߸���ֵ����������󽵷���ʮ������ħ���˵�����
ͨ���
LONG);

  set("exits", ([ /* sizeof() == 1 */
    "north" : __DIR__"yongdao",
  ]));
    set("objects", ([ /* sizeof()== 3 */
__DIR__"npc/nezha" : 1,
]));
set("outdoors", 1);
  setup();
}


