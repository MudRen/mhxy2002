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
      "northdown": __DIR__"dian",
            "southup": __DIR__"tu4",
    
        ]));

  set("objects", ([ 
   	"/d/mingjie/npc/xipo":1,
      ]));

        setup();
}
