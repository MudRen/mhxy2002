// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */

// blackthorn.c

#include <weapon.h>
inherit SWORD;
#include <ansi.h>

int do_hesword();

void create()
{
       set_name(HIC"������"NOR, ({ "qingsuo-sword","sword"}));
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
  set("long",
"һ���Ž�,�����Ͽ���"+HIC"��������"NOR+"����,������һ��������������.\n");
                set("value", 9000);
                set("material", "gold");
        set("no_drop","��ô�õı����ȥ�� ! ԭ���Ա���û�¸�ѽ !!!\n");
        set("no_give","��ô�õı��������? ���뵳��û��? \n");
        set("no_sell", 1);
                set("female_only", 1);
set("wield_msg",
HIY"һ����������,"HIC"����"HIY"�������,����$N����.\n"NOR);

set("unwield_msg","$N�����һ��,"+HIC"������"NOR+"�����зɻ�����.\n");
        }
    init_sword(180);
        setup();
}
int init()
{
        add_action("do_hesword", "hesword");
        return 1;
}
int do_hesword()
{
        object who = this_player();
        object ziyingjian,qingsuojian;
        object doublesword;
        if(!ziyingjian = present("ziying-sword",who))
           return notify_fail("�㻹ȱ��"+HIM "��۫��" NOR +",��ô["+HIR"˫���ϱ�"NOR+"]��?\n");
        if(!qingsuojian = present("qingsuo-sword",who))
           return notify_fail("�㻹ȱ��"+HIC "������" NOR +",��ô["+HIR"˫���ϱ�"NOR+"]��?\n");
     if( ! who->query("sword_hesword") == 1 ) 
           return notify_fail("ûѧ˫���Ͻ�֮����ô�ҺϽ���?\n");
message_vision("$N���Ὣ˫������,�������� !\n\nͻȻ,һ����������,"+MAG"����"NOR+"�Զ�����,���������� \n�������һ��,һ����������,"+HIC"����"NOR+"�������,����������\n\n������һ��"+HIC"��"NOR+"����"+MAG"��"NOR+"����������.�ҽ����ں� !!\nһ����Х,�����ж��һ��"+HBRED"����˫��\n\n"NOR,who);
        message("channel:rumor",HIR+"��ҥ�ԡ�ĳ�ˣ�"+who->query("name")+"�õ� ["+HBRED"����˫��"NOR+HIR"] �ˣ�\n"+NOR,users() );
         doublesword = new("/d/obj/weapon/sword/doublesword");
       doublesword->move(who);
        destruct(qingsuojian);
        destruct(ziyingjian);
           return notify_fail("�㲻�ɵĵ���һЦ......\n");
        destruct(this_object());
}
