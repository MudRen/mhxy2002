#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void clear_room();

void create()
{
        set_name(HIW"����"NOR, ({"xiao xiao", "xiao"}));
  set("title", HIR"������"NOR);
   set("gender", "Ů��");
set("long", "��Ӣ������Զ��СŮ����������Ů�ϰ塣\n���������ݶ��������˳ƣ������ӣ���\n");
       set("age", 26);
       set("per", 14);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 10);
       set("max_price",20);
        set("vendor_goods", ([
  "fenghuang":"/clone/armor/fenghuang",
          "fork":"/clone/armor/fork",
            "dashenbian":"/clone/armor/whip",
       "kaishanchui":"/clone/armor/hammer",
            "shenweibang":"/clone/armor/bang",
    "damodao":"/clone/armor/blade",
     "jian":"/clone/armor/sword",
"tianmochu":"/clone/armor/staff",
                "feiyu": "/d/tiankongjie/obj/weapon/feiyu",
     "dianjinqiang":"/clone/armor/spear",
      "mace":"/clone/armor/mace",
]) );
        
              setup();
//    carry_object("/d/obj/cloth/cloth")->wear();
        
}

void init()
{
        ::init();
              add_action("do_vendor_list", "list");
}
