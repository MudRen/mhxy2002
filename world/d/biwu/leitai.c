// Room: /u/biwu/leitai.c
// Date: bye linxue([1;37m��ѩ[2;37;0m) Thu Apr 29 18:48:28 1999
inherit ROOM;

void create()
{
	set("short", "��̨��");
	set("long", @LONG
������һ��¶����̨���棬�������������ĵط���Ҳ�ǽ���Ů
�Ӿ��б������׵Ľϼ�������������һ��������(jia)�������ȡ�ú�
�ֵı����ͷ��ߡ����һ�о�������������(ok)��������(giveup)��
���û�ж����˿����ã�quit����ȥ��

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"biwu",
]));
	set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
