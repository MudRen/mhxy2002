// LLY@FYSY
inherit ROOM;void create()

{
        set("short", "һҶ����");

        set("long", @LONG
����Ʈ��һ�����ɬ�������ķ��㣬¯�Ϲ��������Ҳ��֪�ǲ衢����ҩ��
һҶ���ۣ�һ¯����һ���¶������ˡ�����˵�������������еı�����ϣ�
��ض��ѳ��˹��۵����̡�
LONG
        );

        set("exits", ([ 
  "out" : __DIR__"river1",]));

	set("objects",([
			__DIR__"npc/yan" : 1,
       	]) );
        set("item_desc", ([
                "����": "һ�����ɬ�������ķ���Ʈ�����㲻�����볢����drink)��������Ķ�����\n",
                "jar": "һ�����ɬ�������ķ���Ʈ�����㲻�����볢����drink)��������Ķ�����\n",
                      ]) );
        set("coor/x",-1065);

	               set("coor/y",75);

	               set("coor/z",10);

set("no_magic",1);
	setup();

}



void init()
{

add_action("do_drink","drink");
}
int do_drink(string arg)
{
        object room;
        object me;
                me = this_player();
		message_vision("$N�Ӵ������ó�һ������,��������Ķ�����������һ�ھͺ�����ȥ����\n", me);
message_vision("$N��Ȼ������ָ��żⶼ����ȫ��ľ���������ڽ����������ӣ�ֻ����ȫ��������һ�����أ������˺��\n", me);
                
          room = load_object(__DIR__"sjhupan");
	      me->move(room);
              me->unconcious();
		 return 1;		
		 // return notify_fail("");		
        }
