#include <ansi.h>

inherit ROOM;
void create ()
{
  set ("short", "�ؾ���");
  set ("long", @LONG

�����������Ժ�ĸ�¥��������ղص伮�ĵط�����
ǽ��һ����ܣ�����������ĵ伮��������һ��������
�Ĵ����ӣ�����Ҳ�������顣
LONG);        
 set("exits", ([
                "down" : __DIR__"lu1",
      ]));
  set("objects", ([
            "/d/obj/book/xbuddhism"   : 1,
                   "/d/obj/book/luny"   : 1,
                   "/d/obj/book/chaizhao"   : 1,
      ]));

  setup();
}


