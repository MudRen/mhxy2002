//by tianlin 2001.7.3

inherit ROOM;

void create()
{
  set ("short", "����ɽ");
  set ("long", @LONG

������һƬҰ���֣�ɽ�е��������˲�ժ�����ܵ����ӹ���֦
ͷ�����µ����Ѹ��ó��࣬��֪�Ѽ��˼����ꡣ
LONG);
set("exits", ([ /* sizeof() == 4 */
"eastdown" : __DIR__"lantao",
"west" : "/d/qujing/xihai/xihai",

]));

set("objects", ([ /* sizeof() == 2 */
"/d/lingtai/npc/wukong": 1]));
  
      set("no_clean_up", 0);
	set("outdoors", 1);
        setup();
        replace_program(ROOM);
}


