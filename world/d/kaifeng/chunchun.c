//By tianlin@mhxy for 2001.9.18�����޸�
inherit ROOM;

void create ()
{
  set ("short", "������ջ");
  set ("long", @LONG
��ջ����˼��ź�ľ���ӣ�Χ�����ӷ��˼������ʡ��˴�����������
����Ʈ�Ų��㡣��ǽ�ǹ�̨����������˴�С��ͬ�Ĳ�Ͳ��ޡ�����
����ͨ���ͷ������ǰ����һ��СС������[1;33m��paizi��[2;37;0m��
LONG);

  set("objects", ([ /* sizeof() == 1 */
   __DIR__"npc/chaniang" : 1,
    __DIR__"npc/xiaoer" : 1,
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "���꼱�蹤����Ա����������������Ӵ���[����]���¡�
             ������ʾ:[1;32m1.[1;33mask xiao er about job[2;37;0m
                      [1;32m2.[1;33mask guan shi about panzi[2;37;0m 
                      [1;32m3.[1;33mGo ���� xi ������[2;37;0m
                      [1;32m4.[1;33mgive panzi to xiao er[2;37;0m 
                      [1;32m5.[1;33m���ڲ��й�[2;37;0m
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"shun5",
  "west" : __DIR__"sleeproom",
 "north" : __DIR__"chufang",
]));
  set("pingan", 1);
  set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
  set("no_dazuo", 1);
  set("no_kill", 1);
  set("valid_startroom", 1);

  setup();
//  replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
        object *inv,kicker;
        int sizeinv,n,tt;
        
        if (dir =="west")
        {
                if ( me->query("PKS") >= 3)
                return notify_fail("��ɱ��̫�����ң��������ӭ�㣡\n");        
        
                inv=all_inventory(me);
                sizeinv=sizeof(inv);
        
                while (sizeinv--)
                {
                        if (inv[sizeinv]->is_character())  
                                return notify_fail("�����ȥ�����˿ڣ�\n");
                
                }
                
        }

        return ::valid_leave(me, dir);
}

