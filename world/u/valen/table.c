//Cracked by Roath
//by tianlin 2001/5/1
#include <ansi.h>
#define LAST_PAR "bc"
#define THIS_PAR "bcsf"
inherit ITEM;
void create()
{
    set_name(HIG"����̨"NOR, ({ "table"}));
    set_weight(5000000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("no_get","���̨������ʦ����ҷ�����ģ��㲻��͵��");
        set("long","һ���޴��ޱȵ�����̨����������˷�����ҵ��������ûȥ����ҿ�������(take gift)����");
        set("value", 0);
        set("material", "stone");
    }
}
void init()
{
    add_action("do_pick", "take");
}
 
int do_pick(string arg)
{
       object me,obj;
       me = this_player();
       if( !arg || arg!="gift" ) return notify_fail("��Ҫ��ʲô��\n");

 //      return notify_fail("����û�������á�\n");

       if (me->query(THIS_PAR + "_pick")) {
       tell_object(me,CYN "ˮ���µ���ӰͻȻ������һ������֮�С�\n\n");
       tell_object(me,HIR "ˮ����һ�������������ϣ�С���ѣ���Ҫ̫̰��Ŷ��ÿ��ֻ��һ�����\n\n");
       tell_object(me,CYN "ֻ��һ��������ᣬˮ���µ���Ӱ�Ѿ������ˡ�\n" NOR);
       return 1;
       }
      obj = new (__DIR__"gift");
      obj->move(me);
       message_vision("$N��[1;32m����̨[2;37;0m������һ��[1;33m�����[2;37;0m��\n",me );
//ÿ�μ���������ϴεĲ������������ӱ����õĲ����� 
       me->delete(LAST_PAR + "_pick");
       me->set(THIS_PAR + "_pick",1);
       return 1;
}

