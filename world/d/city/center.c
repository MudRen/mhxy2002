//changan city
//by tianlin@mhxy 2001/9/3
//�趨һ���Ѷ�,����˵���Լ���climb��Ҫ��,ʲôdodge 100������...�ȵ�
//������wx<���ٲ�����һ���,��������ô��������Ҫ��Ϊ�˺���,�е����ʸ�
//���ڴξ�ֻ��һ��wx��Ҫ���,��ҿ��Բο�����һ���޸�,���벻Ҫ�����ߵ�����
//лл!!!!!!
inherit ROOM;
#include <room.h>
#include <ansi.h>

void create ()
{
  set ("short","ʮ�ֽ�ͷ");
        set ("long", @LONG

������ǳ����ǵ����ģ�������ֽ����ڴˡ�һ��Ρ��ߴ����¥��
����ǰ��������Щ���ơ�ÿ���峿�����������������ŵ���������
�򳤰��ǵĴ��С�·�ڳ�ˮ�����������˳����ϡ�·�߲�֪ʲô
ʱ������һ��[1;32m������[2;37;0m[1;33m(tree)[2;37;0m���̸���ڣ��Ѿ�����һ����ʷ�ˡ�
LONG);
set("item_desc", ([ /* sizeof() == 2 */
  "tree" : "һ�øߴ��ޱȵĴ���,�������ȥ����"HIG"(climb tree)"NOR"\n",
  "up": HIY"�����������ƣ�ʲôҲ���������\n"NOR,
]));

        set("exits", 
        ([ //sizeof() == 4
//		"enter" : "/d/biwu/biwu.c",
		"south" : __DIR__"zhuque-s1",
              "north" : __DIR__"xuanwu-n0",
"up" : "/d/liwu/happyjie",
               "west" : __DIR__"baihu-w1",
               "east" : __DIR__"qinglong-e1",
               "down" : __DIR__"droproom",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/libai" : 1,
                __DIR__"npc/paimaishi" : 1,
               // __DIR__"npc/vikee" : 1,
              "/d/qujing/wuzhuang/npc/zhangguolao": 1,
                "/u/tianlin/table" : 1,
                "/u/tianlin/bei":1,
        ]));

       set("outdoors", "changan");
	set("no_clean_up", 0);
       setup();
	//replace_program(ROOM);
       }
void init()
{
	add_action("do_climb", "climb");
}

int do_climb(string arg)
{
	object me=this_player();
	
	if( !arg || (arg!="tree" && arg!="��") )
		return notify_fail(HIG"��Ҫ��ʲô��\n"NOR);
	if(me->is_busy())
		return notify_fail(YEL"���æ����ʲôѽ��\n"NOR);
       if(me->query("combat_exp")<20000)
              return notify_fail(HIC"��ƾ�����ڵı���Ҳ������ȥ.\n�������������!\n"NOR);
	message_vision(HIY"$N��������������ȥ,һ��һ��С��ǰ��... \n"NOR, me);
	me->start_busy(3);

	if( (int)me->query("kee") < 500 || (int)me->query("sen") < 500) {
		call_out("faila", 3, me);
		return 1;
	}

	call_out("success", 3, me);
	return 1;
}
int success(object me)
{
	message_vision(CYN"$NԽ��Խ�ߣ�ͻȻ����һ������ ... \n"NOR, me);
	me->move("/d/city/jiuguan1");
	message_vision(WHT"$N����������������\n"NOR, me);
	return 1;
}

/*
int valid_leave (object who, string dir)
{
  if (dir == "up")
    return notify_fail (HIR"�㿴�˿�,�����߲���ȥ��,ֻ������ȥ���е�����ԡ�\n"NOR);
  return ::valid_leave(who,dir);
}
*/



