// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// songguo.c

inherit COMBINED_ITEM;

void create()
{
        set_name("ҩ��", ({"yaocai"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�����ҩ�ģ�\n");
                set("unit", "��");
                set("base_unit","��");
                set("cass","genis");
        }
        set_amount(500);
}
