//by tianlin 2001.8.5

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�����ڼ����Ķ��ų�¥����ʯ��������¥̨����쳣��Ρ��
�����Ĺ��г����Ϸ�����[1;31m���ڼ�����[2;37;0m����������֡� 
LONG);

  set("exits", ([ /* sizeof() == 2 */
    "east" : __DIR__"street2",
    "west" : __DIR__"estreet",
  ]));
  set("outdoors", __DIR__"");

  setup();
}

int valid_leave (object who, string dir)
{
  if (dir != "west" && !interactive(who))
    return 0;
  return ::valid_leave(who, dir);
}
