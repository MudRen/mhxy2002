inherit ROOM;
void create()
{
  set ("short", "�鷿");
  set ("long", @LONG

�����Ƿ�ɰ׵��鷿��Ҳ������Ϣ�ĵط�����˵����Ҳ������
���˵Ļ�����������úõ�˯һ����

LONG);
set("exits", ([ /* sizeof() == 4 */
"east": __DIR__"dating4",
]));
        set("no_clean_up", 0);
        set("sleep_room",1);
        set("if_bed",1);
        setup();
        replace_program(ROOM);
}
