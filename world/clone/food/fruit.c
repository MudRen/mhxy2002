
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
  "[33m��ӣ��[m",
  "[31m��÷��[m",
  "[32m������[m",
  "[33m����֦[m",
  "[34m��ͷ��[m",
  "[35m������[m",
  "[36m����[m",
  "[31m����[m",
  "[32m��÷[m",
  "[33m����[m",
  "[35m����[m",
  "[36mʯ��[m",
  "[31m����[m",
  "[32mҬ��[m",
  "[1;33m����[m",
});

string *ids = ({
    "la yingtao",
    "shu meizi",
    "xian longyan",
    "huo lizhi",
    "tutou li",
    "jixin zao",
    "xiang tao",
    "li zi",
    "yang mei",
    "xi gua",
    "shi zi",
    "shi liu",
    "pu tao",
    "ye zi",
    "ju zi",
});

  int i = random(sizeof(names));
  set_name(names[i], ({ids[i]}));
  set("unit","��");
  set("value",50);
  setup();
}

int do_eat(string arg)
{
      object me = this_player(), ob = this_object();
        if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");
    me->set("food",me->max_food_capacity());
    me->set("water",me->max_water_capacity());
        message_vision(HIC"$N����һ��"+ob->query("name")+"����������˵����������ɽ���˸���Ҳ��\n"NOR,me);
        destruct(this_object());
        return 1;
}
