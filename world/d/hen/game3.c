// by happ@YSZZ
inherit ROOM;
#include <ansi.h>
#define RESULT "/log/hen_game3"

void create ()
{
  set ("short", "�赸��������");
  set ("long", @LONG

             С���ǵ��赸�������������,�����Ҫ��ѯ�ϴα������,������last.

LONG);

  set("exits", ([ /* sizeof() == 4 */
        "east": __DIR__"baoming",
]));

  set("no_clean_up",1);
  set("no_fight", 1);
  set("no_magic", 1);
        setup();
}

void init()
{
           add_action("do_last","last");
}
int do_last()
{

   if( file_size("/log/hen_game3") <=0 )

                return notify_fail("��ʱû�б������.\n");

  if( this_player()->query_temp("hen/game_3") )
                return notify_fail("���������ڱ����С�\n");
      cat(RESULT);
  return 1;
}

void begin()
{
        object me = this_object();
        object *list=all_inventory(me);
        object *gamer=({});
        object temp;
        string name,id;
        int i,x,n;
        object gold = new("/obj/money/gold");

        for(i=0;i<sizeof(list);i++)
        {
      if( present("zhandou ji",list[i]) && list[i]->query_temp("hen/game_3") )
        gamer+=({list[i]});
        }

        if( gamer==({}) )
        return ;                

        for(n=0;n<sizeof(gamer);n++)
        {

                for(x=1;x<sizeof(gamer);x++)
                {
               if( gamer[x-1]->query("hen/charm") > gamer[x]->query("hen/charm") )
                        {
                        temp = gamer[x-1];
                   gamer[x-1] = gamer[x];
                   gamer[x] = temp;
                        }

                }    

        }
         for( i=0;i<sizeof(gamer);i++ )
         {
                     log_file("hen_game3",sprintf("%-12s[%-10s]��С���赸�����л���˵�"+HIR
           +chinese_number(i+1)+NOR+"����\n", gamer[sizeof(gamer)-i-1]->query("name"),

           gamer[sizeof(gamer)-i-1]->query("id")));
        gold->set_amount((int)100/(i+1));
        gold->move(gamer[sizeof(gamer)-i-1]);
        gamer[sizeof(gamer)-i-1]->add("hen/money",(int)5000/(i+1));
        gamer[sizeof(gamer)-i-1]->start_busy(17);
         }
       tell_room(me,"����������......��λѡ�ֶ�����������У������õ���õĳɼ���\n");
         me->start_busy(23);            
        remove_call_out("end1");
          call_out("end1",10);

}
        

void end1()
{
           object me = this_object();

             tell_room(me,"������Ҫ�����ˣ����Ͼ�Ҫ���������,ÿ���˶��н�Ŷ\n");

        remove_call_out("end");
        call_out("end",10);
}
void end()
{
        
        object me = this_player();
        cat(RESULT);
        me->delete_temp("hen_game");
        me->delete_temp("hen/game_3");       
}
