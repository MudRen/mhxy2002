// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// blackthorn.c

#include <weapon.h>

inherit SWORD;
#include <ansi.h>

void create()
{
        set_name(HBRED+HIC"����˫��"NOR, ({ "doublesword","sword","jian"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
  set("long",
"һ�ԹŽ�,�����Ϸֱ����"+MAG"����۫��"NOR+"��"+HIG"��������"NOR+"����.\n"
"��������������ɫϼ������,��������һ���������.\n");
        set("no_drop","��ô�õı����ȥ�� ! ԭ���Ա���û�¸�ѽ !!!\n");
        set("no_give","��ô�õı��������? ���뵳��û��? \n");
        set("no_sell", 1);
                set("value", 9000);
                set("material", "blacksteel");
set("wield_msg",HIB"\n����ѣĿ��"HIM" �� "HIC"�� "HIB"��������,˫������,��һ������,���ɺ�������.\n\n"NOR);

set("unwield_msg",HIC"\n$Nһ����Х,˫��˲Ȼ����.\n\n"NOR);
        }
        init_sword(180);
        setup();
}

