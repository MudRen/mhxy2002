//By tianlin@mhxy for 2001.9.27
//�����Ż�

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
������һ��Ƨ��������С·�ϣ���������ɭɭ�����֡�ֻ������ǰ�󣬵���
��������ǵص������֡���ʮ�ɸߵĴ���������һ�飬��ʵ��֦Ҷ��һ�����ɡ
��������գ��������ڵ�˿��Ҳ�ޡ���˵���ﾭ�������˳�û�����ɾ���������
�и�Сɽ��(dong)��
LONG );
        set("outdoors", "wudang1");
	set("no_sleep_room",1);
	set("exits", ([
		"south"     : __DIR__"tufeiwo2",
		"northdown" : __DIR__"wdroad10",
	]));
        set("objects", ([
                __DIR__"npc/tufei2" : 2
        ]));
//        set("no_clean_up", 0);
	setup();
}

void init()
{
        add_action("do_enter", "enter");
        add_action("do_enter", "zuan");
}

int do_enter(string arg)
{
	object me;
	mapping fam;

	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="dong" )
	{
		if( (fam = me->query("family")) && fam["family_name"] == "�ݿ�ɽ�޵׶�" ) 
		{
			message("vision",
				me->name() + "ͻȻ���һֻС�ÿ���������������,���������ꡣ\n",
				environment(me), ({me}) );
			me->move("/d/qujing/wudidong/dong");
                	message("vision",
				me->name() + "�Ӷ������˽�����\n",
                		environment(me), ({me}) );
			return 1;
		}
		else 
			return notify_fail("��ôС�Ķ�������ý�ȥ��\n");
	}
}
