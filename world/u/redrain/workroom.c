inherit ROOM;
#include <ansi.h>

void create()
{       
set("short", "�����й�");
set("long", @LONG       
                 ������й���

    ������ǹ��ǵ��й�����������˸���������ơ�������
�ơ�������������һ���ûƽ��Ƴɵĵ��������������һ̨��
�ڹ����ı��ڢ��͵��ԣ� ��������ɢɢ�ķ��������Ƭ(photo)��
�ż�(letter)��
LONG);  
set("valid_startroom",1);
set("no_steal", "1");
        set("exits", ([
                "kz" : "/d/city/kezhan",
                "out" : "/d/city/zhuque-s1",
        ]));
        set("objects", 
        ([// sizeof() == 1
//                "/u/redrain/ronger" : 1,
        ]));
set("item_desc", ([
                "photo" : HIC "\nһЩ�ǳ�Ư����Ů������Ƭ��\n" NOR,
                "letter" : HIG "\n�������е�һ���ţ����µ�����д���ǣ�\n" NOR + HIC "���ǣ��Ұ��㣬��ԸΪ�㸶��һ�У�ֻ���㲻Ҫ������........\n\n" NOR + HIC "                             �ƾ�����\n" NOR + HIC "                            06/24/2001 \n" NOR
        ]));
setup();
  call_other("/obj/board/menpai_b", "???");
}
