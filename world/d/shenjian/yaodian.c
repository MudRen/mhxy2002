//By tianlin@mhxy for 2001.10.10
inherit ROOM;

void create ()
{
        set ("short", "ҩ��");
        set ("long", @LONG

�������Ʒʮ����ȫ,��ʽ�����Ķ���,�б���,װ��,����
��������ȫ,���Ҽ۸�ʮ�ֱ���.
LONG);

        set("exits",
        ([ //sizeof() == 4
                "north": __DIR__"cunkou",
      ]));
      set("objects", ([
                __DIR__"npc/yaoren" :1,
                ]));

      set("outdoors", "shenjian");
      set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}

