// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

�����ĳ�������ڿ�����ڶ��������죬��·������ʯ���̳ɣ�����
���������де���ľ������ԶԶ�ɼ����⸮�ĳ��ţ�������һ���ߴ�
���������ϱ���һ�����������嵱ɽȥ��

LONG);

  set("exits", ([
        "west" : __DIR__"chen1",
        "east" : __DIR__"tieta",
        "south" : __DIR__"machang",
        "southwest" : "/d/wudang/songlin1",//lpg add wudang
      ]));

  set("outdoors", __DIR__);

  setup();
}