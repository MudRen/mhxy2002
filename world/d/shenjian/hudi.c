inherit ROOM;
void create()
{
        set("short", "��ˮ������");
        set("long", @LONG
��ˮ���ĺ�ˮ�峺��������ʽ����������������ǰ������ȥ��
LONG);
set("exits", ([ 
  "west" : __DIR__"hudi1", 
  "south" : __DIR__"hudi2",
]));

set("objects",([
__DIR__"obj/fish" : 1,
]) );
setup();
}
