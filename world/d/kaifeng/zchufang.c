// Room: /d/kaifeng/zchufang
// by cih 10/01/2002
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "˧������");
  set ("long", @LONG

����������Ԫ˧�����˵����ǳԷ��ĳ�������ΪԪ˧����
���Ӷ��ر���ܳԣ�����������Ÿ��ָ�����ʳ�����
Ԫ˧���ĵ��ӿ�����ʱ��ص����ԡ�

            [1;37m������������������������[2;37;0m
            [1;37m��                    ��[2;37;0m
            [1;37m��[2;37;0m      [1;33m��ʳ�͹�[2;37;0m[1;37m      ��[2;37;0m
            [1;37m��                    ��[2;37;0m
            [1;37m������������������������[2;37;0m

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"shuaifu",
]));
  set("objects", ([ /* sizeof() == 4 */
  "/d/obj/food/bao3" : 3,
  "/d/obj/food/baozi" : 3,
  "/d/obj/food/chahu" : 3,
]));
  set("light_up", 1);
  set("no_fight", 1);
  set("no_magic", 1);
  set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));

  setup();
}
int valid_leave()
{
        if((present("bao", this_player())))
            return notify_fail("Ԫ˧���Ϊ������ӵĽ�����ֻ�ܳ��������ߣ�\n");
    return ::valid_leave();
}
