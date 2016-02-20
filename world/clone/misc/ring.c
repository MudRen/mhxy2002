#include <ansi.h>

#include <armor.h>
inherit FINGER;

inherit F_SAVE;
inherit F_BACKUP;

void create()
{
    set_name(HIM "�����ָ" NOR, ({"cdh","ring"}) );
     set_weight(50);
     if ( clonep() )
              set_default_object(__FILE__);
     else {
            set("long", "һ����������ɵ����˽�ָ��\n"
            "����ϸ�濴���ƺ����������� (info cdh)��\n");
            set("unit", "��");
            set("value", 5000);
            set("no_drop", 1);
            set("armor_prop/armor",200);
            set("armor_prop/dodge", 20);
            set("armor_prop/spells", 20);
            set("wear_msg", "$N��$n�������ϡ�\n");
     }
     setup();
}

void init()
{
        if( this_player()==environment() )
            add_action("do_info","info");
            add_action("do_pray","pray");
}

int do_info(string arg)
{
        if( !arg ) return notify_fail("����֪��ʲô? \n");
        write("ʹ�� (pray start) ������������ˡ�\n");
         return 1;
}

int do_pray(string arg)
{
      string name;
       name = (string)this_player()->query("name");

         if( !arg || arg!="start" ) return notify_fail("��Ҫ����ʲô? \n");
         {
         message_vision(HIG"$N�ḧ��ָ���溬΢Ц�������˳������ˡ�\n"
            HIY "���ϵĽ�ָ����һ��ϼ�⡣ $N������.... \n"NOR,this_player() );
         this_player()->receive_damage("sen",50);
         this_player()->move("/u/city/center");
          }
          return 1;
}
 int query_autoload()
{
  if (query("id") == "cdh")
    return 1;
  else return 0;
}
