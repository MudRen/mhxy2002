//By tianlin@mhxy for 2001.9.26
//�����Ż�
inherit ROOM;

void create()
{
      set("short","�䵱�㳡");
      set("long",@LONG
����һ���ɴ�ʯ���̳ɵĹ㳡�����䵱����ѧϰ�书�ͻ����д�ĵص㡣
��Χ��������ͩ����һ������������ص���Ҷ��һ���������ĵ�ͯ���ڴ�ɨ��
�ϱ�������������
LONG);
      set("objects", ([
                __DIR__"npc/daotong" : 2,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "northdown"  : __DIR__"zixiaogate",
          "south"      : __DIR__"sanqingdian",
          "eastdown"   : __DIR__"tyroad1",
          "east"       : __DIR__"shanlu2",
      ]));
//      set("no_clean_up", 0);
      set("outdoors", "wudang");
      setup();
      replace_program(ROOM);
}
