inherit ITEM;
#include <ansi.h>
int query_autoload() { return 1; }
void create()
{
    object me
;
  me = this_player();
  if (me->query("id")!="super")
  set_name("�����͸�"+me->query("id")+"�ļ���",({"jita"}));
  else
  set_name(HIB"���ǵļ�į����"NOR,({"jita"}));
  set("long","��������ר�õĵ缪��������Ե���(play)����\n");
  set("no_give","���������������Ҹ��˵ģ�\n");
  set("no_drop","���������������Ҷ��ģ�\n");
  setup();
}
void init()
{
  add_action("do_play","play");
}
int do_play(string arg)
{
      int i;
    object me;
    me = this_player();
    if (!arg||arg!="jita")
    return notify_fail("���뵯ʲô��\n");
    message_vision(HIG"$N����ĵ����˼��������������ĳ�����������һ��������������~~~~~~~����\n"NOR,me);
   for(i=0; i<sizeof(all_inventory(environment(this_player()))); i++) {
if ( !living(all_inventory(environment(this_player()))[i]) || all_inventory(environment(this_player()))[i]==this_player() ) continue;
tell_object(all_inventory(environment(this_player()))[i], HIR"���������ǵĸ�����ֻ����ȫ���ʱ���������������泩�ò����ˣ�\n"NOR);
 all_inventory(environment(this_player()))[i]->set("env/immortal",0);
}
return 1;
}
