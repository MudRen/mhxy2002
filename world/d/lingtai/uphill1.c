// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// Room: some place in ��ţ����
// uphill1.c

inherit ROOM;

void create()
{
  set ("short", "[32m������[m");
  set ("long", @LONG

����ɽ��С·�������滨��ݣ��������ɡ��������ɣ����س�
���۸��أ��滨��ݣ���ʱ��л����孡�������ЪЪ�ţ�����
��ɫ�����Ż���Ҳ�Ǻܺõ����ܡ�
LONG);
set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"uphill2",
"southdown": __DIR__"hill",
]));

        set("no_clean_up", 0);
        set("outdoors", 1);
  set("objects", ([
                      "/d/qujing/kusong/npc/sctz" : 1,
    ]));       setup();
        replace_program(ROOM);
}


