// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "[33m�ڵ�[m");
  set ("long", @LONG
���������۵ı�����,������������ʮ�ֻ���,����������ӹ�׵ĸо�,
���������ư�������,���˿��ž������һ��.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"dadian.c",
]));


  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yudi" : 1,
]));

  setup();
}


void init()
{
    add_action("block_cmd", "", 1);
}

int block_cmd(string args)
{
string verb;
verb = query_verb();

    if (verb == "fight") return 1;
    if (verb == "pray") return 1;
    if (verb == "ji") return 1;
    if (verb == "cast") return 1;    
    return 0;
}
