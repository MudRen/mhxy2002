// by cih 10/01/2001
// Room: /d/kaifeng/zlou1

inherit ROOM;

void create ()
{
  set ("short", "����¥");
  set ("long", @LONG

�����������������Ĳ������������������ģʽ������
��������ʮ����ΰ������������ͼ��ׯ�����ء�����
�������ţ��������ʯ�̻�������˵���Ͽ϶��Ǹ�����ͷ
�ˡ����ϻ���һ����(bian)���������д��ʲô��

LONG);


  set("item_desc", ([
     "bian": " ��̳ \n"
        ]));

  set("exits", ([
        "enter"    : __DIR__"zlou2",
        "south" : __DIR__"huayuan4",
      ]));

  setup();
}






