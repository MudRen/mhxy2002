// Room: /d/lingtai/wuchang.c

inherit ROOM;

void create()
{
        set("short", "[0;33m���䳡[m");
        set("long", @LONG
�����Ƿ���ɽ���Ƕ������䳡����������޴�Ļ�����ʯ���̾͡�
��ǧ��Ĳ�̤��ʹ����Щʯ����ͬ���Ӱ�ƽ���⻬�����߽��ϻ�
��������ɳ�ӣ�ʮ������ʿ������ϰ���ա������������һ�侲
�ҡ�
LONG );
        set("exits", ([
                "down" : __DIR__"jingtang",
                "east" : __DIR__"xiuwu",
                "west" : __DIR__"yangxin",
        ]));
        set("outdoors", 1);
        setup();
}

