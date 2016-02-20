// Room: /u/gua/workroom.c

#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", "������׵Ĺ�����");
          set("long", @LONG

���ƹ����������㸡���������ѩ�����Ȼ��������ɾ����������Ƕ���
�ƺ�����Խǧɽ�����������Ϣ�ҡ���������һȦ��ʣ�Χ�ż��侫�µ�С�ݡ�
����������һƬ���֡�
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj1/box" : 1,
]));
        set("exits", ([ /* sizeof() == 3 */
  "wiz" : "/d/wiz/wizroom",
  "bed" : __DIR__"sleep",
  "out" : __DIR__"damen",
  "east" : __DIR__"yaopu",
  "kz" : "/d/city/kezhan",
  "tianlin" : "/u/tianlin/workroom",
]));
	set("no_magic", 1);
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 1 */
  "bed" : "��ҹ��(gosleep,gobed,bed)�� 
",
]));
	set("no_fight", 1);

	setup();
	replace_program(ROOM);
}
