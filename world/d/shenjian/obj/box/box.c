#include <ansi.h>

inherit ITEM;

void create()

           {
        set_name("����", ({ "woodcase" , "case"}) );

        set_weight(500);

        set_max_encumbrance(40000);

        if( clonep() )

        set_default_object(__FILE__);

        else 
        {

                set("unit", "��");

                set("long",

		"һ�ڳ¾�ƽ���������������κ���ע������ӡ�����һ�����ӣ���һ�߶�����߶೤�����������ð���ɫ��ţƤ���š����������make����remake�������������е��κ����������\n");
        
}

            }
int is_container()
 { return 1; }

void init()

         {
	add_action("do_make","make");
}

int do_make(string arg)
      
{
	object me;

	object obj;

	me=this_player();

        if(environment()==this_player() && (int) this_player()->query("sen")>250)

{		
	if(!arg) return 0;

	{
	me->set("sen",1);

             if(arg=="ningsword")
        {obj=new(__DIR__"nsword");
         obj->move(me);
        
write("�㽫���е����Ӵ򿪣������е����ƴ����һ�����̽���\n");}

             if(arg=="yunblade")
        {obj=new(__DIR__"yunblade");
         obj->move(me);
        
write("�㽫���е����Ӵ򿪣������е����ƴ����һ��嫺����̡�\n");}     	
		                     if(arg=="bloomblade")
        {obj=new(__DIR__"bloomblade");
         obj->move(me);
        
write("�㽫���е����Ӵ򿪣������е����ƴ����һ��Ѫ����\n");}
    
        if(arg=="wandao") 
        {obj=new(__DIR__"lou");
         obj->move(me);
        
write("�㽫���е����Ӵ򿪣������е����ƴ����һ��Բ���䵶��\n");}

             if(arg=="feidao")
        {obj=new(__DIR__"xlfd");
         obj->move(me);
        
write("�㽫���е����Ӵ򿪣������е����ƴ����һ��С��ɵ���\n");}

             if(arg=="cangqiong")
        {obj=new(__DIR__"cq");
         obj->move(me);
        
write("�㽫���е����Ӵ򿪣������е����ƴ����һ�Ѳ���񽣡�\n");}
             if(arg=="long-blade")
        {obj=new(__DIR__"long-blade");
         obj->move(me);
        
write("�㽫���е����Ӵ򿪣������е����ƴ����һ��������������\n");}

             if(arg=="seasword")
        {obj=new(__DIR__"seasword");
         obj->move(me);
        
write("�㽫���е����Ӵ򿪣������е����ƴ����һ�Ѻ�Ԩ����\n");}	
   if(arg=="staff")
        {obj=new(__DIR__"jgstaff");
         obj->move(me);
        
write("�㽫���е����Ӵ򿪣������е����ƴ����һ�ѽ�����ȡ�\n");}	
   if(arg=="rustysword")
        {obj=new(__DIR__"musword");
         obj->move(me);
        
write("�㽫���е����Ӵ򿪣������е����ƴ����һ�Ѱ���һ��ľͷ������Ƭ��\n");}	
   if(arg=="hammer")
        {obj=new(__DIR__"starhammer");
         obj->move(me);
        
write("�㽫���е����Ӵ򿪣������е����ƴ����һ�����Ǵ���\n");}	
   if(arg=="whip")
        {obj=new(__DIR__"cbwhip");
         obj->move(me);
        
write("�㽫���е����Ӵ򿪣������е����ƴ����һ�Ѵȱ��ޡ�\n");}	
   if(arg=="windblade")
        {obj=new(__DIR__"dafeng");
         obj->move(me);
        
write("�㽫���е����Ӵ򿪣������е����ƴ����һ�Ѵ�絶��\n");}	
   if(arg=="darksword")
        {obj=new(__DIR__"yasword");
         obj->move(me);
        
write("�㽫���е����Ӵ򿪣������е����ƴ����һ�����ڹŽ���\n");}	
   if(arg=="soulcrasher")
        {obj=new(__DIR__"xuesword");
         obj->move(me);
        
write("�㽫���е����Ӵ򿪣������е����ƴ����һ�Ѻ��촵Ѫ��\n");}	
   if(arg=="fulongblade")
        {obj=new(__DIR__"dragonblade");
         obj->move(me);
        
write("�㽫���е����Ӵ򿪣������е����ƴ����һ�ѷ���������\n");}	
   if(arg=="fireblade")
        {obj=new(__DIR__"fireblade");
         obj->move(me);
        
write("�㽫���е����Ӵ򿪣������е����ƴ����һ�ѻ��泤����\n");}	
   if(arg=="deitysword")
        {obj=new(__DIR__"deitysword");
         obj->move(me);
        
write("�㽫���е����Ӵ򿪣������е����ƴ����һ��������˫��\n");}		
if(arg=="jewelsword")
        {obj=new(__DIR__"jewelsword");
         obj->move(me);
        
write("�㽫���е����Ӵ򿪣������е����ƴ����һ������ʮ��������Ľ���\n");}
 destruct(this_object());
	}

	return 1;
}

        return 0;
}