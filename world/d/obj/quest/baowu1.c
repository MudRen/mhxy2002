//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
#include <ansi.h>
void create()
{
        set_name(HIM"�����ƹ���"NOR, ({"yunguang po", "po"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�п������֮������������֮��\n");
                set("unit", "��");
                set("lingtaibao","fake");
               set("owner_name","�϶�");
               set("owner_id","chang e");
        }
}

