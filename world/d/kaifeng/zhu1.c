// by cih 10/01/2002
// Room: /d/kaifeng/zhu1

inherit ROOM;

void create ()
{
  set ("short", "��·");
  set ("long", @LONG

һ��С·���ź����������ƣ����ߵĺ�ˮ����һ�㣬�紵����ˮ����
����΢�����ں�ˮ�ϻζ��ų����ĵ�Ӱ����ʱ��ݺ����������������
�����Ŀ���������ʵ���ǰ˽�Ϊ�˻����ڸ���ׯ�͸�С����һ�����
��˽�԰ѿ��ⶫ��Ȧ��һ�������޳ɵġ���ȡ��Ϊ�ⲻ�ײ������·��

LONG);

  set("exits", ([
        "north" : __DIR__"zhu2",
  "west" : __DIR__"huting",
        "southeast" : __DIR__"zketing",
        "southwest" : __DIR__"zhu3",
      ]));
  set("objects", ([
        __DIR__"npc/zhangmen" :  1,
      ]));

  set("outdoors", "kaifeng");

  setup();
}


