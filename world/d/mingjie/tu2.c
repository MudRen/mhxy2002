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
�������ڤ���֮ͼ����ͨ��ڤ��ıؾ�֮·
  
LONG);
                     
set("exits", ([
      "northdown": __DIR__"tu3",
            "southup": __DIR__"tu1",
    
        ]));

  set("objects", ([ 
 	"/d/mingjie/npc/meilusi":1,

        ]));

        setup();
}
