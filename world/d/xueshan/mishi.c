// By tianlin 2001.5.1
// Room: /d/xueshan/mishi.c

inherit ROOM;

void create()
{
  set("short", "����");
  set("long", @LONG

������ѩɽ�Ŀ�ȸ���������ĵط����������������Ѿ������ˡ�
��˵������ɽ֮������˼����
������������Ĵ���㡣����ɽ֮�ߡ�
LONG
    );
        set("item_desc", ([ /* sizeof() == 2 */
  "table" : "���϶��ǻң�ʲôҲ�����塣
",
  "��λ" : "��λ��д�ţ�ѩɽ֮�� ��ȸ����֮λ��
",
]));
        set("exits", ([ /* sizeof() == 1 */
"out" : "/d/xueshan/eroad3",
"chuansuo" :"/d/qujing/lingshan/windows",
]));

           if ("/d/xueshan/obj/pingreal.c"->in_mud())
        set("objects", ([ /* sizeof() == 1 */
  "/d/xueshan/obj/pingfake.c" : 1,
  ]));
else
          set("objects", ([ /* sizeof() == 1 */
    "/d/xueshan/obj/pingreal.c" : 1,
  ]));

          set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

