
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "��ħʳ�ö���");
        set("long", @LONG
����������ò͵ĵط������ﲼ�úܼ�, ֻ����ʮ��������
��������һ������س��š�һ�������ڲ�ͣ��æµ�ţ�������
δ��ʮ���꣬��������Ҫʳ���ˮ��
LONG);
        set("exits", ([
                "down" :__DIR__"chufang",
                
        ]));

        set("objects", ([
           __DIR__"npc/shifu2" : 1,
        ]));       
	set("coor/x",60);
	set("coor/y",0);
	set("coor/z",20);
        set("no_fight", 1);
        setup();
}
int valid_leave(object me, string dir)
{
	int i;
	object *ob;
	ob = all_inventory(me);
	for(i=0; i<sizeof(ob); i++)    
        if ((dir == "down") && present("shifu", environment(me)) ){
           if(present("cocacola", environment(me)))
              return notify_fail("��ʦ����ס������㻹���Ȱѿɿڿ��ֺ������߰ɡ�\n"); 
              if (ob[i]->query("food_remaining")) {
                  switch ( random(2) ){
                      case 0: return notify_fail("��ʦ�������˵�������ס����˵�������ȰѶ������������߰ɡ�\n"); break;
                      case 1: return notify_fail("��ʦ����ס�������ʳ���ô����\n"); break;
                      }
                  }
           }
       return ::valid_leave(me, dir);
}
