inherit ITEM;

void create()
{
        set_name("�ٱ���", ({ "box" }) );
        set_weight(500000);
        set_max_encumbrance(40000);
        if( clonep() ) {
                object a,b,c,d,e;
                  seteuid(getuid());
                if(a=new("/u/gua/obj/ja"))
                  a->move(this_object());

                  seteuid(getuid());
                if(b=new("/u/gua/obj/pen"))
		  b->move(this_object());

                  seteuid(getuid());
                if(e=new("/u/gua/obj/jiezhi"))
                  e->move(this_object());

                  seteuid(getuid());
                if(c=new("obj/roommaker"))
		  c->move(this_object());
                set_default_object(__FILE__);
        } else {
                set("unit", "��");
                set("long", "�����ϹϷŶ����ļ��ӣ������ճ��ر��Ķ�����\n");
                set("value", 0);
        }
}

int is_container() { return 1; }

