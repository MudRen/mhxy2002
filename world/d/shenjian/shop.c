//By tianlin@mhxy for 2001.10.10
inherit ROOM;

void create ()
{
        set ("short", "��Ʒ��");
        set ("long", @LONG

    �ս��������һ�ۿ����ľ����Ǻպ����������ƣ�
[36m
                ������������������
                ��[m[41m[1;30m    ��Ʒ��    [2;37;0m[36m��
                ������������������
[m
�������Ʒʮ����ȫ,��ʽ�����Ķ���,�б���,װ��,����
��������ȫ,���Ҽ۸�ʮ�ֱ���.
LONG);

        set("exits",
        ([ //sizeof() == 4
                "south": __DIR__"road",
      ]));
      set("objects", ([
                __DIR__"npc/wupin" :1,
                ]));

      set("outdoors", "shenjian");
      set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}

