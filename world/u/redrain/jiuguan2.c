//by swagger
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "�仨¥");
  set ("long", @LONG

������ǳ����������ֵĳ���--�仨¥�ˡ��ش������������������ģ���
���������мӡ���ȭ����֮����Ц������߳�������һƬ��Ҳ�ֲ�����Щ
�����Ұ��ա���Щ������ǿ�ˡ�������˵���������߻��ӡ�
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "down" : "/u/redrain/jiuguan1",
]));
  set("objects", ([ /* sizeof() == 2 */
  "/u/redrain/guinu" : 1,
]));
  set("no_fight", 1);
  set("no_magic", 1);
  set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));
  setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "down" ) {
        if (objectp(present("gui nu", environment(me)))) {
            if (me->query("jinu")) {
        return notify_fail("��ū��Ц�˼�����û��������ܣ���ĵ�����\n");
        }
        }
        return ::valid_leave(me, dir);
}
}
