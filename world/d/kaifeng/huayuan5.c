// by cih 10/01/2002
// Room: /d/kaifeng/huayuan5
inherit ROOM;

void create()
{
  set("short", "��԰");
   set("long", @LONG

���ۡ��Ļ�԰�������������ʻ�����֪��Ϊʲô��������
�š����ָ����Ļ������涷�ޣ�����ǧ�������ζ����Ȼ����
÷����ĵ��һ�����£���˵��Щ���ǵ��곤��͸�С��ϲ����
�ɼ����ǿɰ�������Ǹ����������أ�
LONG
   );
   set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"huayuan4",
  "south" : __DIR__"huayuan1",
]));

   set("outdoors", "kaifeng");
   setup();
   replace_program(ROOM);
}
