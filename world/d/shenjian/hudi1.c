// LLY@FYSY
inherit ROOM;
void create()

{
        set("short", "��ˮ������");

        set("long", @LONG
��ˮ���ĺ�ˮ�峺��������ˮ���ж��е�����������ǰ������ȥ��
LONG
        );
               set("exits", ([ 
  "north" : __DIR__"hudi3", "east" : __DIR__"hudi",

]));

	set("objects",([
			__DIR__"obj/fish" : 1,
       	]) );
  
                       set("coor/x",-1065);

	               set("coor/y",25);

	               set("coor/z",-10);

set("no_magic",1);	
setup();

}


