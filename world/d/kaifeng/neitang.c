// by cih 10/01/2002
// Room: /d/kaifeng/neitang

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

��Ȼ˵���������ã����������Ӿ�û�б���ˡ���������Ҳû�С�����
������λ�����˼���������ڳ���������������ʵ����������С·
�����ð˽�Ϊʲô�����ⱱ����԰�����鷿��·�ĳɷ��ӣ���

LONG);

  set("exits", ([
        "west" : __DIR__"zketing",
        "southeast" : __DIR__"zshufang",
        "northwest" : __DIR__"huayuan1",
      ]));
  set("objects", ([
        "/d/obj/misc/tables" : 3,
      ]));

  setup();
}


