// LLY@FYSY
inherit ROOM;

void create()
{
        set("short", "��ˮ������");

        set("long", @LONG
��ˮ���ĺ�ˮ�峺��������������Կ������ϵİ��߾�ɫ����ˮ���ж��е�����������ǰ������ȥ��
LONG
        );
              set("exits", ([ 
  "north" : __DIR__"hudi","up" : __DIR__"sjhupan",
]));
       	set("objects",([
			__DIR__"obj/fish" : 2,
       	]) );
        set("coor/x",-1055);

	set("coor/y",15);

	set("coor/z",-10);
        set("no_magic",1);

	setup();

}


