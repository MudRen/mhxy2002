//[4;53m[1;31mBy tianlin@mhxy for 2001.9.27[2;37;0m
// ���ִ��±�д

#include <ansi.h>
inherit ROOM;

string look_shibei();

void create()
{
      set("short",YEL"����С·"NOR);
      set("long",@LONG
����ɽ�������е�С·�����߳�������ĺ�������ֻ�ܿ���һ����ա�
·���е�ʿ�ڷ������������߿ɻش����
    ·���и�ʯ��[1;32m([4;53m[1;31mshibei[2;37;0m[1;32m)[2;37;0m���ܶ��ο���Χ���ԭ��������ȥ��������
���µĽ⽣���ˣ�
LONG);
      set("outdoors", "wudang");
      set("item_desc", ([
          "shibei" : (: look_shibei :),
      ]));
      set("exits",([ /* sizeof() == 1 */
          "westup" : __DIR__"jiejianyan",
          "east"   : __DIR__"slxl1",
          "south"  : __DIR__"songlin1",
          "north"  : __DIR__"songlin2",
      ]));
      set("no_clean_up", 0);
      set_temp("wayao1",1);
      setup();
}

string look_shibei()
{
        return
        HIM"��������������������������������������������������\n"
        HIM"����������        ��������������������������������\n"
        HIM"����������        ��"NOR+HIW"[4;53m�䵱��ͨ��"NOR+HIM"    ����������������\n"
        HIM"����������                            ������������\n"
        HIM"����������    "NOR+HIY"��ǰ�����䵱ɽ�⽣�ҡ�����"NOR+HIM"����������\n"
        HIM"����������"NOR+HIY"�����˿����Ծ��⽣��аħ�����"NOR+HIM"����������\n"
        HIM"����������"NOR+HIY"��ֹ����"NOR+HIM"                ����������������\n"
        HIM"������������������                ����������������\n"
        HIM"��������������������������������������������������\n"NOR;
}
