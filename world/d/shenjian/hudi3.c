// LLY@FYSY
inherit ROOM;

void create()
{
        set("short", "��ˮ������");

        set("long", @LONG
��ˮ���ĺ�ˮ�峺��������ʽ����������������ǰ������ȥ,ż�����м���ˮ�ݴ���ǰƯ����
LONG
        );
              set("exits", ([ 
  "south" : __DIR__"hudi1", "north" : __DIR__"hudi4",

]));

	set("objects",([
			__DIR__"obj/fish" : 1,
       	]) );
set("item_desc", ([
                "ˮ��": "ˮ���к�����ʲô��������ˮ��һ��,���������(search)����\n",
                "grass" : "ˮ���к�����ʲô��������ˮ��һ��,���������(search)����\n",
              ]) );
                       set("coor/x",-1065);

	               set("coor/y",35);

	               set("coor/z",-10);


set("no_magic",1);
	
setup();

}



void init()
{
   add_action("do_search", "search");
}

int do_search(string arg)
{
   object me, obj;
   int llvl;

   me = this_player();
   llvl = (int)me->query("kar");
   if(!me->query_temp("marks/yansword") && !query("got")) {
	set("got",1);
      if (llvl > 19) {  
         if(random(40) <= llvl) {
            message_vision("$N��Ư��Ưȥ��ˮ���е���������\n", me);
            tell_object(me, "����ˮ�����ҵ�һ�ѳ�����\n"); 
            message("vision", me->name()+"��ˮ���г��һ�ѳ�����\n", environment(me), me);
            obj = new(__DIR__"obj/jewelsword");
            obj->move(me);
            me->set_temp("marks/yansword", 1);
            return 1;
         } 
         message_vision("$N��Ư��Ưȥ��ˮ���е���������\n", me);
         tell_object(me, "ˮ��������ˮƯ���ˣ���ʲôҲû�ҵ���\n");
         return 1;
      }
      else {
         if(random(200) <= llvl) {
            message_vision("$N��Ư��Ưȥ��ˮ���е���������\n", me);
            tell_object(me, "����ˮ�����ҵ�һ�ѳ�����\n"); 
            message("vision", me->name()+"��ˮ���г��һ�ѳ�����\n", environment(me), me);
            obj = new(__DIR__"obj/jewelsword");
            obj->move(me);
            me->set_temp("marks/yansword", 1);
            return 1;
         }
         message_vision("$N��Ư��Ưȥ��ˮ���е��������˺�һ��\n", me);
         tell_object(me, "ˮ��������ˮƯ���ˣ���ʲôҲû�ҵ���\n");
         return 1;
      }
      return 1;
   }
   message_vision("$N��Ư��Ưȥ��ˮ���е���������\n", me);
   tell_object(me, "ˮ��������ˮƯ���ˣ���ʲôҲû�ҵ���\n");
   return 1;
}
void reset()
{
::reset();
delete("got");
}
