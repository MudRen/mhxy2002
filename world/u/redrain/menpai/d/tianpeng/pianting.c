
inherit ROOM;

void create ()
{
  set ("short", "ƫ��");
  set ("long", @LONG

ƫ�����õ���Ϊ���ţ�˿��û�������ϵ��������ա�һ�ź�ľ
���������и���񣬹�����˸�ʽ�������顣ǽ�Ϲ��ż����ֻ���
����������ʱ�������ֿ��Ե��鷿�á�
LONG);

  set("exits", ([ /* sizeof() == 1 */
    "north" : __DIR__"zhengting",
      "westup" : __DIR__"duchang1",
        "eastup" : __DIR__"duchang2",
]));
  set("objects", ([
        __DIR__"npc/fujiang"   : 1,
       "/d/kaifeng/npc/zhubing"   : 3,
      ]));

  setup();
}
