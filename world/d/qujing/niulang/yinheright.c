// By canoe 2001.03.25
inherit ROOM;
#include <room.h>
void create()
{
          set("short", "���Ӷ���");
        set("long", @LONG

��������Ӷ�����ţ�������غ���������֯Ů����������
��ϧ�м�������޷��ɹ������ӡ�
        
LONG );
        set("exits", ([ /* sizeof() == 1 */
                "west"  : __DIR__"yinhe",
              ]));
        set("objects", ([
         "/d/qujing/niulang/niulang":1,
              ]) );
        setup();
}
