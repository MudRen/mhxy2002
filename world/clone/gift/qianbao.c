//By tianlin@mhxy for 2002.1.20
//���story��������һ��Ǯ��,�����ҷ���50 gold,hehe

#include <ansi.h>
inherit ITEM;

void create()
{
	int i;
        object a;

        set_name(HIY"Ǯ��"NOR, ({ "qian bao","qianbao","bao" }) );
        set_weight(500);
        set_max_encumbrance(10000);
        if( clonep() )
          {
          seteuid(getuid());
	  for (i=1;i<=50;i++) 	
            {
            a=new("/obj/money/gold");
            a->move(this_object());
            }
          set_default_object(__FILE__);
          }
        else 
          {
          set("unit", "��");
          set("long", "���ǰ׾�����Ǯ��,�����˼��Ѿ��ܶ����ˡ�\n");
          set("no_give", "����Ǳ��ﰡ,�����ô������?\n");
          }
}

int is_container() { return 1; }

