inherit ROOM;

void create()
{
  set ("short", "������Ϣ��");
  set ("long", @LONG

һ�䲻̫��ķ���,ֻ��һ����ֱͦͦ��վ������,���������
���ε������ˡ�
LONG);
set("exits", ([ /* sizeof() == 4 */
"north": __DIR__"shengdian0",

]));
set("objects", ([
                __DIR__"npc/zhangmen": 1,
		
]) );
        set("no_clean_up", 0);
	set("outdoors", 0);
        setup();
}



