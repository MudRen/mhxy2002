//by tianlin 2001.7.3

inherit ROOM;

void create()
{
set("short", "�ٵ�");
set("long", @LONG
    

����һ�������Ĵ�����ᴩ�ϱ���ֱͬ�߹ء�

LONG );


set("exits", ([
  "north"   : __DIR__"guandao2",
  "west"   : "/d/kaifeng/tieta",
  "east"   : "/d/southern/shaolin/shanjiao",           
 // "southeast"   : "/d/village/wexit",
 
]));
        set("objects", 
        ([
                  "/d/shendian/babu/mohuluojia" : 1,
        ]));



set("outdoors", 1);

setup();
}
