//by tianlin 2001.8.7

inherit ROOM;

void create ()
{
        set ("short", "ɽ·");
        set ("long", @LONG

��̧ͷ�����ŵ������������ⷢ����ɫ�Ĺ�â������ס�ϵ����ŵ�
��Ů�񵻸棡�ٻ�ͷʱ����ʮ�����Ѿ���û���ƺ�֮�С�

LONG);


        set("exits", ([
        "up"    :       __DIR__"palace",
            "down"  :       __DIR__"topalace2",
        ]));

  set("objects", ([
                __DIR__"npc/huang": 1 ]) );

  // set("outdoors", __DIR__);//by tianlin 2001.8.7.��Ϊ�ұ���,������Щ��������Ϊ�������ǽ����ͳ���ȥ��,����������仰(snicker)

  setup();
}

int valid_leave (object me, string dir)
{
        if (dir == "up" ) {
        if (objectp(present("huang", environment(me))))
        return notify_fail("���а�! ��ͭʥ��ʿ��\n");
        }
        if (dir == "down" ) {
        if (objectp(present("huang", environment(me))))
        return notify_fail("���а�! ��ͭʥ��ʿ��\n");
        }
  return 1;
}
