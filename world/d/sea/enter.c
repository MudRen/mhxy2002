//BY tianlin@mhxy for 2002.3.7,��������һд,hehe

inherit ROOM;

void create ()
{
  set ("short", "��������");
  set ("long", @LONG

������һ������ܴ�ĵط���һ�۾��ܿ���
����ط��Ѿ��ܳ�ʱ��û���������ˣ�����
��ʱ�㷢��һ���ǳ��Ӵ�Ķ���������Χ��
��������ʼ����������
LONG);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/sihai" : 1,
]));
        set("water", 1);
        setup();
}
