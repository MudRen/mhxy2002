inherit ROOM;

void create()
{
        set("short", "���֮��");
        set("long", @LONG
���ﴫ˵��������ߴ�,Ҳ�����Ψһ�������,
����������û������,��,��,Ψһ�е�ֻ�����ˡ�
LONG
        );
        set("no_clean_up", 0);

        set("exits",([
        "east" : "d/city/kezhan",
        "eastdown" : __DIR__"rukou",
]));
        setup();
        replace_program(ROOM);
}
