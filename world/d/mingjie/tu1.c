// /d/guzhanchang/pomiao.c
inherit ROOM;
void create()
{
        set("short", "һ֮ͼ");
         set ("long", @LONG
 ,--------,'  
|    _     |   
|  .' `.   |  
|  `._.'   | 
|          
|__________\---------
                    ,-,-,-,-,
                             -,-,-,-,
                                     -,-,-==
�������ڤ��һ֮ͼ����ͨ��ڤ��ıؾ�֮·
  
LONG);
                     
set("exits", ([
      "northdown": __DIR__"tu2",
            "northup": __DIR__"ba1",
    
        ]));

  set("objects", ([ 
 	"/d/mingjie/npc/yisi":1,
       ]));

        setup();
}
