#include <armor.h>
#include <armor.h>
#include <ansi.h>
 
inherit SURCOAT;
 
void create()
{
        set_name(HIR"��õ��"NOR, ({ "rose"}) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "leather");
                set("unit", "��");
                set("long", "����һ���ɫ��õ�塣\n"
"��������    ����    ������������������������    ����  ��������������  ��\n"
"������      ����    ����  ������������������    ����  ������  ������  ��\n"
"  ����      ����    ����  ����������������      ������������  ������  ��\n"
"������      ����    ����  ����������������      ������  ����  ������  ��\n"
"��������    ����������������������  ��������      ����  ����������������\n"
"��������    ����������������  ����  ��������      ����  ����������������\n"NOR);

                set("value", 0);
                set("armor_prop/armor", 10);
set("armor_prop/dodge", 5);
        }
        setup();
}

