// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "[33m�ڵ�[m");
  set ("long", @LONG
���������۵ı����ˣ���Ȼ�ǿ���һ�ˣ������������䣬�㲻��Ҳ��
    ��ȥ������
LONG);

  set("exits", ([ /* sizeof() == 1 */
]));


  set("objects", ([ /* sizeof() == 1 */
]));

  setup();
}

void init()
{
        object me=this_player();
                remove_call_out("greeting");
                call_out("greeting",5, me);

}

void greeting(object me)
{            int kar,con;

        kar=me->query("kar");
        con=me->query("con");
        if( !me || environment(me) != this_object() ) return;

   message_vision("��Ȼ�����һ�����ĵ���ʹ��һֻȫ���ںڵĴ��Ѿ�������ҧס�����С��
���������ѣ��Ժ��ֱ�һ�����У�\n", me);
   message_vision("������һ�����ϵ���Ϣ�������Ϸ�������������\n",me);  
  if (random(kar+con)<40)
 {      
   me->set_temp("death_msg","�ô��������������Ȯ�������������ˡ�\n");
   me->die();
   me->save();}
   else  
  { me->unconcious();
   me->move("/d/sky/zhanyaotai");}
   return;
}
