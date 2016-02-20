// LLY@FYSY
// boat.c
inherit ROOM;
void create()
{
 set("short", "ľ��");
 set("long", @LONG
�ϵô���������Է��ִ��в����о��вˣ�����һ���٣�һ���壬һ���飬
һ��⻬��Ӳ��ʯͷ��
LONG
 );
    set("objects", ([
        __DIR__"npc/xzg": 1 ,
        __DIR__"obj/cbook" : 1,
        __DIR__"obj/cqi" : 1,
        __DIR__"obj/cqin" : 1,
__DIR__"obj/cstone" : 1,
         ]) );
  set("coor/x",-1110);

	set("coor/y",65);

	set("coor/z",-5);
set("no_magic",1);
 setup();
}   

void boat_run(int counter)
{
 object dest;
 object *inv;
 int i;

 inv=all_inventory(this_object());		
 for (i=0;i<sizeof(inv);i++)
 if (userp(inv[i]))
  {
   if (query_temp("mark/dest")=="sjhupan1")
    switch(counter)
     {
      case 0 :  message("vision","С���������뿪�˰���,ˮ����������ӳ������Ϧ����Զ���Ĵ��Ʒ������ͼ����\n",this_object());
                break;
      case 1 :  message("vision","л�ƹ��Ц��˵���õ���ɽׯȥ���ˣ����ѿ��ö��ˣ�ÿ���������������ᣬ�����¶���һ����\n",this_object());
                break;
      case 2 :  message("vision","л�ƿ�����е���һ�ϴ��������Ⱦ�,Ҳ�е���ϲ�����٣����飬�������е���ϲ��һ���˴����ס�\n",this_object());
                break;
      case 3 :  message("vision", "Ϧ�����ˣ�ĺɫŨ��,Զ������ɽ���ѽ�������û��ŨŨ��ĺɫ�������һ��������ɫ��ͼ����\n",this_object());
                break;
      case 4 :  message("vision", "���Ȼ�����˺ܶ��£��ܶ಻������¡���������һȥ���ǲ��ǻ��ܻ��Ż�����\n���������Լ���ͯ�꣬��������Щ�ഺʱ���ΰ顣Ҳ��������Щ���������µ��ˡ������ж������ǲ������ģ�\n",this_object());
                break;
      case 5 :  message("vision","����������ȴȫ���������ˣ���ú��ҡ�������˼�����ҵ�ʱ���㿴����һ���ˣ���վ����Ϧĺ�У���ˮ���ϡ�\n",this_object());
                set("exits/up",__DIR__"sjhupan1");
                if (!objectp(dest=find_object(__DIR__"sjhupan1")))
                dest=load_object(__DIR__"sjhupan1");
                set_temp("mark/dest","jiujia2");
                dest->set("exits/down",__DIR__"xiaochuan");
                message("vision","һ��С������ʻ�˹�����\n",dest);
                call_out("leave",10,dest);
                return;
     } 
    else
     switch(counter)
      {
       case 0 :  message("vision","л�ƹ������ڵ��¶���,��ĬĬ�������������£����˱��ơ�\n",this_object());
                 break;
       case 1 :  message("vision","���밶��������ʻ��������ҹɫ�У������ĺ�ˮ�䡣\n",this_object());
                 break;
       case 2 :  message("vision","�����ĺ�ˮ��������ҹɫ��\n",this_object());
                 break;
       case 3 :  message("vision", "С���������ں�����Ư���š�\n",this_object());
                 break;
       case 4 :  message("vision", "�������ں��ġ�\n",this_object());
                 break;
       case 5 :  message("vision","�����⣺�������Ѻδ������������������!�㷢�ִ��Ѿ������ˡ�\n",this_object());
                 set("exits/up",__DIR__"jiujia2");
                 if (!objectp(dest=find_object(__DIR__"jiujia2")))
                 dest=load_object(__DIR__"jiujia2");
                 set_temp("mark/dest","sjhupan1");
                 dest->set("exits/down",__DIR__"xiaochuan");
                 message("vision","һ��С������ʻ�˹�����\n",dest);
                 call_out("leave",10,dest);
                 return;
     } 
   call_out("boat_run",3,counter+1);
   return;
  }
}

void leave(object dest)
{
 object *inv;
 object oob;
 int i;
 inv=all_inventory(this_object());		
 for (i=0;i<sizeof(inv);i++)
  if (userp(inv[i]))
   {
    message("vision","������������ˮ����Ư���ˡ�\n",dest);
    if (query_temp("mark/dest")=="sjhupan1")
     message("vision","С����Զ������ɽׯ��ȥ��\n",this_object());
     else message("vision","С����Զ����л�Ҵ廮ȥ��\n",this_object());
    delete("exits/up");
    dest->delete("exits/down");
    call_out("boat_run",3,0);
    return;                    
   }
 message("vision","������������ˮ����Ư���ˡ�\n",dest);          
 delete("exits/up");
 dest->delete("exits/down");
 return;
}
