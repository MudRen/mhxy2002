//by tianlin@mhxy.2001.7.4
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
set("short", HBRED HIY" �� �� �� �� "NOR);
set("long", @LONG
    
LONG );


set("exits", ([
  "south"   : __DIR__"qianyuangong",
//  "north"   : __DIR__"houhuayuan",
//  "west"   : __DIR__"hougong",
//  "east"   : __DIR__"hougong",
]));


set("objects", ([
  __DIR__"npc/yuhuang"   : 1,
  __DIR__"npc/wuquxingjun"   : 1,
]));



setup();
}
