//By waiwai@mszj 2000/10/26

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIB"Ұ����ҽ��������"NOR);
        set("long", 

HIB"\n��������վ��Ұ����ҽ�ݵ��������ȫ��һ�ѵ��ɹŴ��\n"+
"������һ��������С��������ٺٵ���Ц��......ǽ�Ϲ���\n"+
"һ��Сľ���� "+HIR"(paizi)\n\n"NOR);
	set("item_desc", ([
		"paizi": HIC"���� "+HIR"\"bianxing id\""+HIC" ����ʼ���������� \n\n"NOR,
	]));

        set("objects", ([
		__DIR__"npc/menggu" : 1,
        ]));

 
        setup();
}
void init()
{
	add_action("do_bianxing","bianxing");
}

int do_bianxing(string arg)
{
  object me,ob;

   me=this_player();
   ob = present(arg, environment(me));

  if (arg) {
    if(ob->query("gender")=="Ů��") ob->set( "gender", "����" );
    else ob->set( "gender", "Ů��" );
    message_vision(HIR"$Nû���ü���Ӧ,ֻ��"+HIG"�ɹŴ��"+HIR"������,"+HIW"��.... "+HIR"$N�̲�ס��ʹ������һ�����˹�ȥ......\n\n"NOR,this_player());
    message("shout", HIM "��ҥ�ԡ�ĳ�ˣ���˵ "HIW+me->query("name")+HIM" ��ϧ���ʣ����ɹŴ��ҽ�ݳɹ�������һ�αȽϱ�̬�ı�������������\n" NOR,users());
    me->save();
    me->unconcious();
    me->move("/d/changan/bx1");

    return 1;
  }
}
