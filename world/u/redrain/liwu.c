//wuchangdan.c
#include <ansi.h>
inherit ITEM;
void setup()
{}
void init()
{
        add_action("do_eat", "eat");
}
void create()
{
string *names = ({
  HIW"�ɿ���"NOR,
 HIW "���������"NOR,
  HIW"���͵���"NOR,
  HIG"����õ����"NOR,
  HIC"�����ɿ���"NOR,
  HIG"��ü��"NOR,
  YEL"���"NOR,
  HIB"ӣ������"NOR,
  HIG"������"NOR,
  GRN"�޹���"NOR,
  HIC"�Ϻü�"NOR,
  HIR"Ϻ��"NOR,
  HIY"�ְ���"NOR,
  HIG"�ϵ¼�"NOR,
  GRN"���ٸ�"NOR,
  HIC"������"NOR,
  HIY"��������"NOR,
});
  int i = random(17)+1;
  string str;
  set_name(names[random(sizeof(names))], ({"li wu","liwu"}));

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
              set("long", "��å������������ʮ��������԰�~!\n");
        }
        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");

        if( me->query("eaten_15") )
        return notify_fail("�����Թ��˰ɣ�\n");

      me->add("combat_exp",20000 );
        me->add("potential", 30000);
        me->add("daoxing",50000 );

        tell_object(me,"����ף��ʮ����֣�\n");
        me->set("eaten_15",1);
        
        call_out("des",1);
        //destruct(this_object());
        return 1;
}
void des()
{
        destruct(this_object());
}

