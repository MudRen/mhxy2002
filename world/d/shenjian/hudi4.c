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
  "south" : __DIR__"hudi3", "northup" : __DIR__"river",

]));

	set("objects",([
			__DIR__"obj/fish" : 1,
       	]) );
   
                       set("coor/x",-1065);

	               set("coor/y",45);

	               set("coor/z",-10);

set("no_magic",1);	
setup();

}


