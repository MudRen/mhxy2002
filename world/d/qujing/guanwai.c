// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/guanwai.c

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���ô˴��ѷǴ�����ء�������ȥֻ��Ⱥɽ���࣬һ��ɽ·
������Ⱥɽ����֮�䡣�������˼����ؾ��Ǵ��ƹ��ˡ�����
��Ρ����ΰ������һ�򵱹أ����Ī�������ơ�

LONG);
 
  set("exits", ([
        "east"      : "/d/westway/jiayu",
        "westup"   : "/d/qujing/shuangcha/shanlu1",
      ]));

  set("outdoors", __DIR__);

  setup();
}


