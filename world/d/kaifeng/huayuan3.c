// by cih 10/01/2002
// Room: /d/kaifeng/huayuan3
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
  "southeast" : __DIR__"huayuan2",
  "northeast" : __DIR__"huayuan4",
]));

   set("outdoors", "kaifeng");
   setup();
   replace_program(ROOM);
}
