//By tianlin@mhxy for 2001.10.10

#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void clear_room();

void create()
{
       set_name(HIB"���ϰ�"NOR, ({"han laoban", "han", "laoban", "boss"}));
       set("title", HIR"��Ʒ��"NOR);
       set("gender", "����");
       set("long", "����һ���Ͱ����׵�������,һ�������������Ķ����ò���,������.\n");
       set("age", 21);
       set("per", 14);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 10000);
       set("max_price",20);
       set("vendor_goods", ([
            "yuchang":"/d/shenjian/obj/shop/yuchangjian",
            "zicheng":"/d/shenjian/obj/shop/zicheng",
            "qingzhu":"/d/shenjian/obj/shop/qingzhu",
            "qingxia":"/d/shenjian/obj/shop/qingxia",
            "kandao":"/d/shenjian/obj/shop/kandao",
]) );
        
              setup();
    carry_object("/obj/cloth")->wear();
        
}

void init()
{
        ::init();
              add_action("do_vendor_list", "list");
}
