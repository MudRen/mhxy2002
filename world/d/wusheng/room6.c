// changan wusheng
// room6.c

inherit ROOM;

void create()
{
  set ("short", "������");
  set ("long", @LONG

�������ôӽ�����񡢽������ϡ�װ�޲��ֶ������ϵ��칬����
�ơ��������ܾŲ�����Χ��Ʈ�죬�����滹͸������ׯ��֮����
���������𾴡�
LONG);
set("exits", ([ /* sizeof() == 4 */
"north": __DIR__"room7",
"south": __DIR__"shijie9",
]));
set("objects", ([
        "/d/wusheng/npc/zhangmen": 1]));
        set("no_clean_up", 0);
        set("outdoors", 1);
  set("valid_startroom", 1);
        setup();
}


