// Room: /u/tianlin/workroom.c
#include <ansi.h>
inherit ROOM;
void create ()
{
    set ("short", HIC"�ֻ���Ϸ��"NOR);
  set ("long", @LONG

������һ�����Ľֻ���Ϸ����,������������浽ȭ��һ��Ľֻ���Ϸ,
���������м����һλ��Ů���ۣ�������������������ǩ����
�㻹�ܿ����и���ʦ���ں���������!
�²���˭,ѽ!��tianlin���ں���˵����!
LONG);

     set("exits", ([
             "west" : __DIR__"bedroom",
                 "down" : "/u/valen/workroom",
               "east" : __DIR__"guestroom",
             "out" : __DIR__"guardroom",
          "kz" : "/d/city/kezhan",
          "linger" : "/u/linger/workroom",
           "up" : "/d/wiz/wizroom",
             "guest" : "/d/wiz/guest",
     ]));    
  set("outdoors", 0);
// set("no_fight",1);
set("no_magic",1);
set("no_time",1);
  set("valid_startroom", 1);
      set("objects", ([
//            "/u/yudian/npc/zhinu" : 1,
//            "/u/vikee/table" : 1,
//              "/d/wiz/npc/welcome" : 1,
      ]));     
//            __DIR__"/npc/zhangbz" : 1,
//                __DIR__"/npc/jing" : 1,
//                 __DIR__"/npc/banxian" : 1,
//      ]));           
  setup();
      call_other("/obj/board/tianlin_b", "???");
}
