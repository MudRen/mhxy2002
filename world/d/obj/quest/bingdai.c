//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
#include <ansi.h>
void create()
{
        set_name(HIW"����"NOR, ({"bing dai" ,"dai"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",   "һ������װ����Ĵ��ӡ�\n");
                set("unit", "��");
               set("owner_name","ͺӥ����");
               set("owner_id","tuying zunzhe");
        }
}

