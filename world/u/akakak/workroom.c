//changan city
// [lsg 2000/11/16]
inherit ROOM;

void create ()
{
        set ("short", "��ʦ������");
        set ("long", @LONG

����������Ϊ��ʦ����ѧϰ�޽��Ĺ����ң���ӭ�������
�����Ρ�������������Լ�����Щ����������㲻��Ϥlpc��
edit���������������ʦ�����޸ģ�����ls /doc/help/wiz/
�������ϴ����й���ʦ�Ľ̡̳�
LONG);
        set("exits", 
        ([ //sizeof() == 2
                "up" : "/d/wiz/wizroom",
                "down" : "/d/city/kezhan",
                        ]));

        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}



