// LLY@FYSY
inherit ROOM;
void create()

{
        set("short", "����С�ӱ�");

        set("long", @LONG
Ũ����û�ĺ����ϣ���Ȼ����һ�����������΢���𻨡����ǵƹ⣬��
¯��һҶ���ۣ�һֻСС�ĺ���¯�������Ļ�⣬������ϥ���ڴ�ͷ��
��һ�����ˡ�
LONG
        );

        set("exits", ([ 
  "enter" : __DIR__"boat",]));

                       set("coor/x",-1065);

	               set("coor/y",75);

	               set("coor/z",10);


	setup();

}


