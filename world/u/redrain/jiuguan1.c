//by swagger
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "�仨¥");
  set ("long", @LONG

������ǳ����������ֵĳ���--�仨¥�ˡ��ش������������������ģ���
���������мӡ�����С�������������ĺͿ��˴������Ρ���ȭ�Ⱦơ��ϰ�
���������е���Ʊ����͵͵��Ц��
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "southwest" : "/d/city/zhuque-s1",
  "up" : "/u/redrain/jiuguan2",
]));
  set("objects", ([ /* sizeof() == 2 */
  "u/redrain/laobao" : 1,
]));
  set("no_fight", 1);
  set("no_magic", 1);
  set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));
  setup();
}


