// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "����Ԫ˧������");
  set ("long", @LONG

˧���ڵ������������з���һ�ѷʴ���غ����Ρ��ݺ���һ����̨��
�������һ�������Ľ��裬������һˮͰ��С�����ƺ���������
һ�ţ�ͨ��˧���⡣������Ԫ˧���ĳ�����

LONG);

  set("exits", ([
        "west" : __DIR__"tianpeng",
        "east" : __DIR__"zchufang",
        "up" : __DIR__"zzoulang",
      ]));
  set("objects", ([
        __DIR__"npc/yingbin" : 1,
      ]));

  setup();
}
int valid_leave(object me, string dir)
{
    if((string)me->query("family/family_name")=="Ԫ˧��") return 1;
   if((string)me->query("family/family_name")=="����˧��") return 1;


    if (dir == "east" ) {

        return notify_fail("����ֻ������˧���ĵ��Ӳ��ܽ�ȥ�׳԰׺ȣ�\n");
    }

return 1;
}


