// link
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIM"����"NOR);
        set("long", @LONG
��Ƭ������ͨ�����ʥ��ǰ�Ĳ�ƺ�����ϱ���������ŵ�ס���ˣ�
һ�㶼�Ƚ����壬�������Ϊâ�����ˣ���ȻƷ�ֺܲ��ζ��Ҳ
���ã��������в�����������͵͵������ժâ���ԡ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"shengdian",
  "south" : __DIR__"zmroom",
 ]));
        set("objects", ([
        __DIR__"npc/gongren" : 1,
			]) );
        set("item_desc",([
"tree":"����һ�ý���һ�����Ʋ��ӵ�â����â������\n",
]));
	set("valid_startroom",1);
        set("coor/x",-20);
	set("coor/y",60);
	set("coor/z",0);
	setup();
}
void init()
{
        add_action("do_zhai", "zhai");
        add_action("do_zhai", "ժ");
}
int do_zhai(string arg)
{
        object ob;
        object me;

        me = this_player();

 if ( !arg || ( arg != "â��" ) ) {
 return notify_fail("��Ҫժʲô��\n");
   }
 else 
 {
  if(random(10)) {
    message_vision("$N����ţ��������ժ��һ��â��������һ�����ȴ�����ˤ��������\n",me);
    me->unconcious();
    return 1;
  }
  message_vision("$N����ţ�������ժ��һ��â������\n",me);
  ob = new(__DIR__"obj/mangguo");
  ob->move(me);
  return 1;
 }
return 1;
}