inherit ROOM;
void create ()
{
  set ("short", "���ɵ�");   
  set ("long", @LONG   
������˻�ħ��������ǰһ������Ȼ��һ�����������滹��һ���ˡ�
LONG);

    set("exits", ([ 
               "north" : __DIR__"tower1",
               "west" : __DIR__"tower2",
               "east" : __DIR__"darkhole",
               "south" : __DIR__"tower4",
                 ]));
    set("objects",([
"/d/mojiao/npc/mingwang" : 1,
                 ]));
        set("no_magic",1);
        set("no_fight",1);
    setup();
}
