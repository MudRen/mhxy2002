//Cracked by Roath

// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
            set_name("���", ({"jie chi", "ruler" , "chi" }));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                    set("long", "Ԫ������ѵѧͯ�õĶ�����\n");
                    set("unit", "��");
                   set("owner_name","Ԫ����");
                   set("owner_id","yuan xiansheng");
        }
}