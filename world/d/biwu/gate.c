inherit ROOM;

void create()
{
	set("short", "����������");
	set("long", @LONG
���Ǳ���������ſ�,��·������ʿ�Ƽ��˴�����Ҹ���Ħȭ
���ƣ�ԾԾ���ԡ�����������һ��һ�ҵ�վ�ڴ��ſڣ�ά���ű����
������򡣹�ƽ��Ҳ���⸺������������С�Ρ��Ĵ����ϸ�����
��͢�ʵ�[0;5;37m�[5m�[5m�[5m�[0m���͵Ľ��ҡ��Ա��п����ӣ�����������ĺ���
��һ����������롡������

[35m                      ��  ��  ��  ��[0m

[35m                      ��  ��  Ϊ  ֹ[0m

LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "����д
����д
����д
����д
",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard2" : 2,
]));
	set("no_magic", 1);
	set("no_beg", 1);
	set("exits", ([ /* sizeof() == 1 */
  "enter" : __DIR__"guodao",
]));
	set("no_fight", 1);
	set("no_clean_up", 0);
        setup();
}

void init()
{
   add_action("do_quit", "quit");
}
int do_quit()
{
  write("���ڱ������ڼ䲻���˳�����������\n");
  return 1;
}

