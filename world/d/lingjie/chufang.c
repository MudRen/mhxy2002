
inherit ROOM;

void create()
{
        set("short", "��ħʳ��");
        set("long", @LONG
������Ǵ�˵�еĶ�ħʳ���ˡ����治ʱƮ������
����,��������ɭ�ֲ��������,�����ҵ�ʳ����
��̫��,�������Ｘ��ÿ��ûʲô����,ֻ�м�����
�õĲ�ͣ��æµ�š��ſ�����һ�����ӣ�sign����
LONG
        );
        set("exits", ([
	"out" :__DIR__ "lingjie6",
        "up" :__DIR__ "ricerm2",
        ]));

        set("item_desc",([
"sign":"����ϵͳ�Ѿ��깤����������ʹ�����·�������
	1����һ���µķ�������Ĵ������Ҫ��100Ԫ�����롰newcard��
	��ʦ���Ὣ��Ĵ����뷹��������10%�Զ���ɡ�
	2����������ֵ����ǰ�����������뼴�ɡ�\n",
]));
	set("valid_startroom",1);
        set("objects", ([
                __DIR__"npc/shifu": 1,
        ]) );
        set("coor/x",60);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}

