// Room: /u/tianlin/workroom.c
inherit ROOM;
void create()
{
 set("short", "녾�");
  set ("long", @LONG

      ����������        ��������                      ��      
              ��                ��          ��      ������  ��  ��      
    ������������      ��������        ��  ��    ������  
    ��        ��        ��      ��          ��      ������  ��  ��      
      ����  ��  ����    ������������  ��  ��  ��      ��      
                                ��    ��            ���  ���  ������  
      ����������        ���������    ��      ��              
                                ��    ��      ��    ������  ������  
    ������������      ��  ����  ��      ��      ��  ��      ��  
          ��        ��      �����  ��  ���      ������  ��      ��        
      ����������              ���    ���  ��      ��  ������  
LONG
);
  set("exits", ([ /* sizeof() == fuckyou */
             "west" : __DIR__"bedroom",
       "down" : "/u/linger/workroom",
             "out" : __DIR__"guardroom",
         "kz" : "/d/city/kezhan",
          "up" : "/u/tianlin/workroom",
  ]));    

    setup();
     replace_program(ROOM);
}
