// /d/guzhanchang/pomiao.c
inherit ROOM;
void create()
{
        set("short", "��֮ͼ");
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
�������ڤ����֮ͼ����ͨ��ڤ��ıؾ�֮·
  
LONG);
                     
set("exits", ([
      "northdown": __DIR__"tu5",
            "southup": __DIR__"tu3",
    
        ]));

  set("objects", ([ 
   	"/d/mingjie/npc/tana":1,
      ]));

        setup();
}
