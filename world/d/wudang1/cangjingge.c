//[4;53m[1;31mBy tianlin@mhxy for 2001.9.27[2;37;0m
//�����Ż�

inherit ROOM;

string* books = ({
        "laozi1",
        "daodejing-i",
        "laozi2",
        "daodejing-i",
        "laozi8",
        "daodejing-i",
        "laozi13",
        "laozi1",
        "laozi16",
        "daodejing-i",
        "laozi18"
});

void create()
{
        set("short", "�ؾ���");
        set("long", @LONG
�����ǲؾ��󣬿�ǽ��һ����ܣ������˵��̵ĵ伮��������һ������
�εĴ����ӣ�����Ҳ�������顣һ����ͯ���������鼮��
LONG );
        set("exits", ([
                "southdown" : __DIR__"xilang",
        ]));
        set("objects", ([
                __DIR__"npc/daotong" : 3,
                "clone/book/"+books[random(sizeof(books))] : 1,
                "clone/book/"+books[random(sizeof(books))] : 1
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
