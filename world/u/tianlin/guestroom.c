// Room: /u/tianlin/workroom.c
inherit ROOM;
void create ()
{
    set ("short", "�ͷ�");
  set ("long", @LONG

����һ��ͷ�����ʰ�øɸɾ�����
�����и�����Ů��ȫ��ȫ��Ϊ���Է���
LONG);

     set("exits", ([
               "west" : "/u/tianlin/workroom",
     ]));    
  set("outdoors", 0);
set("no_fight",1);
set("no_magic",1);
set("no_time",1);
  set("valid_startroom", 1);
    set("objects", ([
                     __DIR__"npc/elva" : 1,
    ]));           
  setup();
}
