//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
#include <ansi.h>
void create()
{
       set_name(HIY"��"NOR,({"big axe", "axe"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("long","���ǳ�ҧ��Ĺ��ñ�����\n");
                set("unit", "��");
          set("owner_name", "��ҧ��");
          set("owner_id", "cheng yaojin");
        }
}

