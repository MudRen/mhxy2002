//By tianlin@mhxy for 2002.1.2�޸�nuwa boss�������
//BY tianlin@mhxy for 2002.1.25,�޸�������������enable��bug
#include <ansi.h>
#include <weapon.h>
#include <armor.h>
#include <login.h>

inherit ROOM;

#define MAX_FABAO   3

int M(int x);
int do_sm();
int do_dispose(string arg);
int do_upgrade(string arg);
int do_list();
int do_cost(string arg);

void get_type(string arg, object ob);
void get_subtype(string arg, object ob);
void get_id(string arg, object ob);
void get_name(string arg, object ob);
void get_desc(string arg, object ob);
void get_unit(string arg, object ob);
void build_weapon(object ob);
void build_armor(object ob);
void build_special_fabao(object ob);
int check_legal_name(string name, int max_len);
int check_legal_id(string name);
void confirm_dispose(string arg, object ob, object fabao_ob);

void init()
{
    add_action("do_sm", "make_fabao");
    add_action("do_dispose", "dispose");
    add_action("do_list", "list");
    add_action("do_cost", "cost");
    add_action("do_upgrade", "upgrade");
    add_action("do_change_name", "change_name");
    add_action("do_change_id", "change_id");
    add_action("do_change_desc", "change_desc");
    add_action("do_change_unit", "change_unit");
    add_action("do_koujian","koujian");

   seteuid(getuid());
}

void create ()
{
        set ("short", HIM"Ů洲��촦"NOR);
        set ("long", @LONG

������һƬ�����ء�����������һ����һ�����ι�״ɫ�ʰ�쵵�
������ʯ����ѩɫӳ����������⡣����һ���ʯ�Ͽ��ż��д�
�֣�

                 [1;37m[4;53m���ؾ���[0m

                 [1;33m[4;53mŮ洲���[0m

                 [1;35m[4;53m��ʯδ��[0m

                 [1;36m[4;53m�Ÿ�����[0m

���»���������ؿ���һƪС��[1;33m(words)[0m����Զ��Ҳ������˵����
ʲô��
LONG);

        set("item_desc", ([ "words" : 
@TEXT
make_fabao     ���Ʒ���
dispose        ע������
list           �оٿ��Ʒ�������
upgrade        ��������
cost ����      �������Ƽ��������ܷ���
change_name    ����������
change_id      �������Ĵ���
change_desc    ������������
change_unit    �������ĵ�λ����
�������а취��
����ÿ���������һ���ǣ����Ϊ���ǡ�
TEXT
	]));
        set("exits", 
        ([ //sizeof() == 1 
                "east" : __DIR__"fabao-road2",
        ]));


   set("no_fight", 1);
   set("no_magic", 1);

    setup();
}

int M(int x)
{
    int i,result=1;
    if (x==0) return 1;
    for(i=0;i<x;i++) result*=2;
    return result;
}

int do_sm()
{
    object me = this_player();
   int  fabao_num;
   
   if( me->query("balance") < 500000 )
      return notify_fail("����������̫�ߣ�������ȥ���ưɡ�\n");
     
   if( me->query("daoxing") < 50000)
     return notify_fail("��ĵ��в������������취����\n");

   if( RANK_D->grade_fali( RANK_D->describe_fali( (int)me->query("max_mana") ) ) 
                < RANK_D->grade_fali(HIB "���Ƽ���" NOR) ) //max_mana 360+.
     return notify_fail("��ķ�����Ϊ�������޷����Ʒ�����\n");

   if( me->query("max_force") < 300)
     return notify_fail("���������Ϊ�������������취����\n");
	
   if( me->query("force") < (me->query("max_force")+100) )
     return notify_fail("�������������ʱ���취����\n");
	
   if( me->query("mana") < (me->query("max_mana")+100) )
     return notify_fail("���Ŀǰ����������ӯ���޷����Ʒ�����\n");
				   
   fabao_num = 0;     
   if( me->query("fabao/weapon") )     fabao_num++;
   if( me->query("fabao/armor1") )     fabao_num++;
   if( me->query("fabao/armor2") )     fabao_num++;
   
   if( fabao_num >= MAX_FABAO && me->query("special_fabao") )
     return notify_fail("�㲻�������Ʒ����ˣ����� dispose ע����Ҫ�ķ�����\n");
     
   write("��Ҫ�����෨����\n");
   if( !me->query("fabao/weapon") )
     write("w. ����\n");
   if( !me->query("fabao/armor1") || !me->query("fabao/armor2") )
     write("a. ����\n");
   if( !me->query("special_fabao") )
     write("o. ���ⷨ��\n");

   seteuid(getuid());
   // Other kinds of fabao can be added too.. if there is somefile
   // we can use as a default object.
   write("��ѡ��(q ��ȡ��)");
   input_to( (: get_type :), me );
   
   return 1;   
}

void get_type(string arg, object ob)
{  
   if( arg == "q" || arg == "Q" )
      return;

   if( arg != "a" && arg != "w" && arg != "o" )
   {
      write("��Ҫ�����෨����\n");
      write("w. ����\n");
      write("a. ����\n");
      write("o. ���ⷨ��\n");
      write("��ѡ��(q ��ȡ��)");
      input_to( (: get_type :), ob );
      return;
   }
   
   if(( arg == "o" && ob->query("special_fabao") )
     || ( arg == "a" && ob->query("fabao/armor1") && ob->query("fabao/armor2") )
     || ( arg == "w" && ob->query("fabao/weapon") ))
   {
      write("��Ҫ�����෨����\n");
      if( !ob->query("fabao/weapon") )
      write("w. ����\n");
      if( !ob->query("fabao/armor1") || !ob->query("fabao/armor2") )
      write("a. ����\n");
      if( !ob->query("special_fabao") )
      write("o. ���ⷨ��\n");
      write("��ѡ��(q ��ȡ��)");
      input_to( (: get_type :), ob );
      return;
   }

   if( arg == "w" )    {
     ob->set_temp("fabao_type", "weapon");
     write("\n");
     write("��ѡ���������ࣺ\n");
     write("1. ��  2. ��  3. ��  4. ��  5. �  6. ǹ\n");
     write("7. ��  8. ��  9. ��  10. �� 11. �\n");
     write("��ѡ��(q ��ȡ��)");
   }
   else if( arg == "a" )   {
     ob->set_temp("fabao_type", "armor");
     write("\n");
     write("��ѡ��������ࣺ\n");
     write("1. ��  2. Ь  3. �·�  4. ָ��  5. ����  6. ͷ��\n");
     write("7. ����  8. ��  9. ����  10. ����  11. ����\n");
     write("��ѡ��(q ��ȡ��)");
   }
   //�������ⷨ��
   else {
     if(ob->query("balance")<5000000||ob->query("daoxing")<500000
     || ob->query("max_force")<500 || ob->query("max_mana")<500)
     {
          tell_object(ob,"�㲻���������������� cost ��ѯ��\n");
          return;
     }
     ob->set_temp("fabao_type","special");
     write("\n");
     write("��ѡ�����ⷨ�����ࣺ\n");
     write("1. ������  2. ��ȡ��  3. ������\n");
     write("��ѡ��(q ��ȡ��)");
   }   
   input_to( (: get_subtype :), ob);
}

void get_subtype(string arg, object ob)
{
    int order;
   string fabao_type = ob->query_temp("fabao_type");
  	      
   if( arg == "q" || arg == "Q" ) return;

   else if(sscanf(arg, "%d", order)!=1
   || fabao_type == "weapon" && (order <= 0 || order > 10)
   || fabao_type == "armor" &&  (order <= 0 || order > 11) 
   || fabao_type == "special" &&(order <= 0 || order > 3))
   {
     	if( fabao_type == "weapon")    
     	{
        write("\n");
        write("��ѡ���������ࣺ\n");
        write("1. ��  2. ��  3. ��  4. ��  5. �  6. ǹ\n");
        write("7. ��  8. ��  9. ��  10. �� 11. �\n");
        write("��ѡ��(q ��ȡ��)");
     	}
     	else if( fabao_type == "armor" )   
     	{  
        write("\n");
        write("��ѡ��������ࣺ\n");
        write("1. ��  2. Ь  3. �·�  4. ָ��  5. ����  6. ͷ��\n");
        write("7. ����  8. ��  9. ����  10. ����  11. ����\n");
        write("��ѡ��(q ��ȡ��)");
     	}
        else if( fabao_type == "special" ) 
        {
        write("\n");
        write("��ѡ�����ⷨ�����ࣺ\n");
        write("1. ������  2. ��ȡ��  3. ������\n");
        write("��ѡ��(q ��ȡ��)"); 
        }     	
        input_to( (: get_subtype :), ob);
        return;
   }
   
   ob->set_temp("fabao_subtype",  order);

   write("\n");
   write("���趨Ӣ�� id ��");
   input_to( (: get_id :), ob ); 
}


int check_legal_id(string id)
{
   int i;
   string   *legalid;
   
   i = strlen(id);
    if( (strlen(id) < 3) || (strlen(id) > 20 ) ) {
     write("�Բ���Ӣ�� id ������ 3 �� 20 ��Ӣ����ĸ��\n");
     return 0;
    }
    while(i--)
       if( id[i] != ' ' && (id[i]<'a' || id[i]>'z') )  {
         write("�Բ���Ӣ�� id ֻ����Ӣ����ĸ��\n");
         return 0;
       }
    
    legalid = explode(read_file(BANNED_ID), "\n");
    for(i=0; i<sizeof(legalid); i++)   {
       if( id == legalid[i] )   {
         write("�Բ������� id ����������˵����š�\n");
         return 0;
       }
    }
    
    return 1;
}


int check_legal_name(string name, int max_len)
{
   int i;
   string   *legalname;     //not implemented..may add later
   
   i = strlen(name);
    if( (strlen(name) < 2) || (strlen(name) > max_len ) ) {
       write( sprintf("�Բ��𣬷��������ֱ����� 1 �� %d �������֡�\n",
        max_len/2) );
     return 0;
    }
    while(i--)   {
       if( name[i]<=' ' )   {
         write("�Բ��𣬷��������ֲ����ÿ�����Ԫ��\n");
         return 0;
       }
       if( i%2==0 && !is_chinese(name[i..<0]) )  {
         write("�Բ��������á����ġ�������ȡ���֡�\n");
         return 0;
       }
    }
   
    return 1; 
}


void get_id(string arg, object ob)
{
   arg = lower_case(arg);
   if( !check_legal_id(arg) )   {
     write("���趨Ӣ�� id ��");
     input_to( (: get_id :), ob ); 
     return;
   }

   arg = replace_string(arg, " ", "_");   
   ob->set_temp("fabao_id",arg);
   
   write("\n");
   write("���趨��������(�ɼ���ɫ)");
   input_to( (: get_name :), ob);
}

void get_name(string arg, object ob)
{
   string  arg_old;
   
   arg += "$NOR$";
   arg_old = arg;
        arg = replace_string(arg, "$BLK$", "");
        arg = replace_string(arg, "$RED$", "");
        arg = replace_string(arg, "$GRN$", "");
        arg = replace_string(arg, "$YEL$", "");
        arg = replace_string(arg, "$BLU$", "");
        arg = replace_string(arg, "$MAG$", "");
        arg = replace_string(arg, "$CYN$", "");
        arg = replace_string(arg, "$WHT$", "");
        arg = replace_string(arg, "$HIR$", "");
        arg = replace_string(arg, "$HIG$", "");
        arg = replace_string(arg, "$HIY$", "");
        arg = replace_string(arg, "$HIB$", "");
        arg = replace_string(arg, "$HIM$", "");
        arg = replace_string(arg, "$HIC$", "");
        arg = replace_string(arg, "$HIW$", "");
        arg = replace_string(arg, "$NOR$", "");

   if( !check_legal_name(arg, 12) )  {
        write("���趨��������(�ɼ���ɫ)");
     input_to( (: get_name :), ob);
     return;
   }

   arg = arg_old;

        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);
   
   ob->set_temp("fabao_name", arg + NOR);
   
   write("\n");
   write("������������");
   input_to( (: get_desc :), ob);
}

void get_desc(string arg, object ob)
{
   if( !check_legal_name(arg, 60) )  {
     write("������������");
     input_to( (: get_desc :), ob);
     return;
   }

   ob->set_temp("fabao_desc",  arg);
   
   write("\n");
   write("���������ʣ�(Return for default)");
   input_to( (: get_unit :), ob);
}


void get_unit(string arg, object ob)
{
   string fabao_unit, fabao_type;

    if( arg == "" )
       fabao_unit = "";
   else if( !check_legal_name(arg, 2) )  {
       write("���������ʣ�(Return for defult)");
      input_to( (: get_unit :), ob);
      return;
    }
    else
       fabao_unit = arg; 
   
   fabao_type = ob->query_temp("fabao_type");
   ob->set_temp("fabao_unit", fabao_unit);
   if( fabao_type == "weapon" )
     build_weapon(ob);   
   else if( fabao_type == "armor" )
     build_armor(ob);   
   else if( fabao_type == "special" )
     build_special_fabao(ob);     
   // may have more later
}

//�������ⷨ������newob1ֻ�������洢����Լ��趨����Ϣ
void build_special_fabao(object ob)
{
   object newob1,newob2;
   string *id_list, *t_list;
   int rev;
   int fabao_subtype = ob->query_temp("fabao_subtype");
   string fabao_id = ob->query_temp("fabao_id");
   string fabao_name = ob->query_temp("fabao_name");
   string fabao_desc = ob->query_temp("fabao_desc");
   string fabao_unit = ob->query_temp("fabao_unit");
       
   newob1 = new("/obj/Tfabao");
   if(!newob1)
     return;
                
   seteuid(fabao_id);
   rev = export_uid(newob1);
   seteuid(getuid());

   switch( fabao_subtype )   {
     case 1://����
     newob2 = new("/d/obj/tfabao/tfabao1");
     break;
     case 2://��ȡ
     newob2 = new("/d/obj/tfabao/tfabao2");
     break;
     case 3://����
     newob2 = new("/d/obj/tfabao/tfabao3");
     break;
     }
   if(!newob2) return;
   newob1->set("long", fabao_desc);
        
   newob2->set("long", fabao_desc);
        
   if( fabao_unit != "" )
   {
     newob1->set("unit", fabao_unit);
     newob2->set("unit", fabao_unit);
   }
   id_list = ({ fabao_id });
   t_list = explode( fabao_id, "_");
   if( sizeof(t_list) > 1 )   {
     id_list += t_list;
   }
   newob1->set_name( fabao_name, id_list );
   newob2->set_name( fabao_name, id_list ); 

   // set owner of fabao�����������ⷨ��
   newob1->set("owner_id", getuid(ob));
   newob1->set("special_fabao",fabao_subtype); 
   newob2->set("owner_id", getuid(ob));
   newob2->set("special_fabao",fabao_subtype);
        
   newob1->save(); 

   ob->add("max_force", -300);
   ob->add("max_mana", -300);
   ob->add("balance", -5000000);
   ob->add("daoxing",-200000);

   //user.c���Դ�Ϊ���ݴ�������
   ob->set("special_fabao",fabao_subtype);

   newob1->setup();
   if( !newob2->move(ob) )
   newob2->move(environment(ob));
   ob->save();
   destruct(newob1);
   write("�������Ƴɹ���\n");

   return;
        
}

void build_weapon(object ob)
{
   object newob;
   string weapon_dir, ob_file;
   string *id_list, *t_list;
   int rev;
   int    fabao_subtype = ob->query_temp("fabao_subtype");
   string fabao_id = ob->query_temp("fabao_id");
   string fabao_name = ob->query_temp("fabao_name");
   string fabao_desc = ob->query_temp("fabao_desc");
   string fabao_unit = ob->query_temp("fabao_unit");
   
   newob = new("/obj/fabao");
   if(!newob)
     return;
     
   seteuid(fabao_id);
   rev = export_uid(newob);
   seteuid(getuid());

   newob->set("value", 1);
   newob->set("no_get", 1);   
   newob->set("no_give", 1);   
   newob->set("no_sell", 1);
   newob->set("no_steal",1);   
   newob->set("no_drop", 1);   
   newob->set("no_put", 1);   
   
   weapon_dir = "/d/obj/weapon/";
   newob->set("weapon_prop/damage", 10);
   newob->set("flag", TWO_HANDED);
   newob->set("weight", 1000);
   switch( fabao_subtype )   {
     case 1:
        ob_file = weapon_dir + "axe/bigaxe";
        break;
     case 2:
        ob_file = weapon_dir + "blade/blade";
        break;
     case 3:
        ob_file = weapon_dir + "fork/gangcha";
        break;
     case 4:
        ob_file = weapon_dir + "hammer/hammer";
        break;
     case 5:
        ob_file = weapon_dir + "mace/ironmace";
        break;
     case 6:
        ob_file = weapon_dir + "spear/gangqiang";
        break;
     case 7:
        ob_file = weapon_dir + "staff/muzhang";
        break;
     case 8:
        ob_file = weapon_dir + "stick/qimeigun";
        break;
     case 9:
        ob_file = weapon_dir + "sword/changjian";
        break;
     case 10:
        ob_file = weapon_dir + "whip/pibian";
        break;
     case 11:
        ob_file = weapon_dir + "halberd/halberd";
        break;
   }

   newob->set_default_object( ob_file );
   
   newob->set("long", fabao_desc);
   newob->set("stars/damage", 1);
   newob->set("upgraded/damage", 0);
   newob->set("fabao/max_attack_qi", 1);
   newob->set("fabao/max_attack_shen", 1);   
   if( fabao_unit != "" )
      newob->set("unit", fabao_unit);
   id_list = ({ fabao_id });
   t_list = explode( fabao_id, "_");
   if( sizeof(t_list) > 1 )   {
     id_list += t_list;
   }
   newob->set_name( fabao_name, id_list ); 

   // set owner of fabao
   newob->set("owner_id", getuid(ob));
   newob->set("series_no", "1");
   newob->set("default_file", ob_file);


   newob->save();   
   ob->add("balance", -500000);
   ob->add("force", -200);
   ob->add("mana", -200);   
   ob->set("fabao/weapon",  newob->query("series_no"));

   newob->setup();
   if( !newob->move(ob) )
      newob->move(environment(ob));
   ob->save();
   
   write("�������Ƴɹ���\n");

   return;
}

void build_armor(object ob)
{
   object   newob;
   string   armor_dir, ob_file;
   string   *id_list, *t_list;
   int     rev;
   string  fabao_id = ob->query_temp("fabao_id");
   string  fabao_name = ob->query_temp("fabao_name");
   string  fabao_desc = ob->query_temp("fabao_desc");
   string  fabao_unit = ob->query_temp("fabao_unit");
   int     fabao_subtype = ob->query_temp("fabao_subtype");

   newob = new("/obj/fabao");
   if(!newob)
     return;
   
   seteuid(fabao_id);
   rev = export_uid(newob);
   seteuid(getuid());

   newob->set("value", 1);
   newob->set("no_get", 1);   
   newob->set("no_sell", 1);   
   newob->set("no_give", 1);   
   newob->set("no_steal",1);   
   newob->set("no_drop", 1);   
   newob->set("no_put", 1);   

   armor_dir = "/d/obj/";
   newob->set("armor_prop/armor", 5);     
   newob->set("armor_prop/dodge", 0);     
   newob->set("armor_prop/spells", 0);
   newob->set("weight", 1000);
   // anything else need to be set?
   
   switch( fabao_subtype )   {
   
   // Add ob_file if you can find the same kind of file
     case 1:
        ob_file = armor_dir + "armor/tenjia";
        break;
     case 2:
        ob_file = armor_dir + "cloth/buxie";
        break;
     case 3:
        ob_file = armor_dir + "cloth/linen";
        break;
     case 4:
        ob_file = armor_dir + "cloth/ring";
        break;
     case 5:
        ob_file = armor_dir + "cloth/gloves";
        break;
     case 6:
        ob_file = armor_dir + "cloth/hat";
        break;
     case 7:
        ob_file = armor_dir + "cloth/necklace";
        break;
     case 8:
        ob_file = armor_dir + "armor/niupi";
        break;
     case 9:
        ob_file = armor_dir + "cloth/surcoat";
        break;
     case 10:
        ob_file = armor_dir + "cloth/wrists";
        break;
     case 11:
        ob_file = armor_dir + "cloth/belt";
        break;
   }
   
   newob->set_default_object( ob_file );
   
   newob->set("long", fabao_desc);
   newob->set("stars/dodge", 1);
   newob->set("stars/armor", 1);
   newob->set("stars/armor_vs_force", 1);
   newob->set("stars/spells", 1);
   newob->set("stars/armor_vs_spells", 1);
   newob->set("upgraded/dodge", 0);
   newob->set("upgraded/armor", 0);
   newob->set("upgraded/armor_vs_force", 0);
   newob->set("upgraded/spells", 0);
   newob->set("upgraded/armor_vs_spells", 0);
   newob->set("fabao/max_defense_qi", 1);
   newob->set("fabao/max_defense_shen", 1);
   newob->set("fabao/max_defense_shou", 1);   
   if( fabao_unit != "" )
      newob->set("unit", fabao_unit);
   id_list = ({ fabao_id });
   t_list = explode( fabao_id, "_");
   if( sizeof(t_list) > 1 )   {
     id_list += t_list;
   }
   newob->set_name( fabao_name, id_list ); 

   // set owner of fabao
   newob->set("owner_id", getuid(ob));
   if( !ob->query("fabao/armor1") )
     newob->set("series_no", "2");
   else if( !ob->query("fabao/armor2") )
     newob->set("series_no", "3");
   newob->set("default_file", ob_file);

    newob->save();   

   ob->add("balance", -500000);
   ob->add("force", -200);
   ob->add("mana", -200);   

   if( !ob->query("fabao/armor1") )
     ob->set("fabao/armor1",  newob->query("series_no"));
   else if( !ob->query("fabao/armor2") )
     ob->set("fabao/armor2",  newob->query("series_no"));
   
   newob->setup();
   if( !newob->move(ob) )
      newob->move(environment(ob));
   ob->save();

   write("�������Ƴɹ���\n");
   
   return;
}

int  do_dispose(string arg)
{
   object ob = this_player();
   object fabao_ob;
  
   if( !arg || arg == "" )
     return notify_fail("��Ҫ����ʲô������\n");

   if( !objectp(fabao_ob=present(arg, ob)) )
      return notify_fail("������û��������������\n");
      
   if(!fabao_ob->query("owner_id")
   || (!fabao_ob->query("series_no") && !fabao_ob->query("special_fabao"))) 
      return notify_fail("�Ǹ����Ƿ���Ү��\n");
      
   write("��ȷ��Ҫ����÷�����(y/n)");
   input_to( (: confirm_dispose :), ob, fabao_ob); 
   return 1;
}

void confirm_dispose(string arg, object ob, object fabao_ob)
{
   mapping  fabao_list;
   string*  names;
   string fabao_name;   
   int i;

   if( arg == "y" || arg == "Y" )  
   {
	fabao_name = fabao_ob->query("name");    
        if(fabao_ob->query("special_fabao"))
        {
                ob->delete("special_fabao");
                destruct( fabao_ob );
		write("ֻ���䣡��һ����"+fabao_name+"ը�˿�����\n");
        }
        else
        {   
     		fabao_list = ob->query("fabao");
     		if( !mapp(fabao_list) )     return;
     		names = keys(fabao_list);
     		for(i=0; i<sizeof(names); i++)  
     		{
      			if( fabao_list[names[i]] == fabao_ob->query("series_no") )  
      			{
        		//seteuid(getuid(ob));
        		//rm( fabao_ob->query_save_file() + __SAVE_EXTENSION__ );
        		ob->delete("fabao/"+names[i]);
               		destruct( fabao_ob );
			write("ֻ���䣡��һ����"+fabao_name+"ը�˿�����\n");
        		break;
      			}
     		}
	}
   }

   return;
}

int  do_list()
{
    write("Ŀǰ���취�������У�\n");   
    write("w. �����ࣺ\n");
   write("       ��  ��  ��  ��  �  ǹ\n");
   write("       ��  ��  ��  ��  �\n\n");
   write("a. �����ࣺ\n");
   write("       ����  Ь  �·�  ָ��  ����  ͷ��\n");
   write("       ����  ��  ����  ����  ����\n\n");
   write("Ŀǰ�������������ࣺ\n");
   write(HIY"w."HIG" ������\n"NOR);
   write("       �������˺���(damage)\n");
   write("       �ӷ����˺���֮��Ѫ�˺���(attack_qi)��\n"); //0-25
   write("       �ӷ����˺���֮�����˺���(attack_shen)��\n\n");//0-25   
   write(HIY"a."HIC" �����ࣺ\n"NOR);
   write("       �ӷ�����(dodge)\n");
   write("       �ӵֿ���(armor)\n");
   write("       ���ڹ��ֿ���(armor_vs_force)\n");
   write("       ��ħ��������(spells)\n");
   write("       ��ħ���ֿ���(armor_vs_spells)\n");
   write("       �ӷ���������֮��Ѫ������(defense_qi)��\n");//0-25
   write("       �ӷ���������֮���񱣻���(defense_shen)��\n");//0-25
   write("       �ӷ���������֮������ȡ��(defense_shou)��\n\n");//0-25
   return 1;   
}

int do_cost(string arg)
{
   object fabao_ob, me=this_player();
   int i, damage_stars, dodge_stars, armor_stars, force_stars;
   int spells_stars, vs_spells_stars;
   int neili_req, fali_req, dx_req;
   int neili_cost, fali_cost, dx_cost;   
   int a_qi, a_shen, d_qi, d_shen, d_shou;   

   if( !arg || arg == "" )  {
      write("���취����Ҫ��ʮ���ƽ𡣲��ҵ��б�������ʮ�����ϣ�������Ϊ���������Ƽ���������Ϊ�����������Ϸ��ɡ� \n");
      write("���ⷨ������������\n");
      return 1;
   }
  
   if( !objectp(fabao_ob=present(arg, me)) )
      return notify_fail("������û��������������\n");

   if(fabao_ob->query("special_fabao"))
      return notify_fail("���ⷨ������������\n");
            
   if(!fabao_ob->query("owner_id") || !fabao_ob->query("series_no")) 
      return notify_fail("�Ǹ����Ƿ���Ү��\n");

   a_qi = fabao_ob->query("fabao/max_attack_qi");
   a_shen = fabao_ob->query("fabao/max_attack_shen");
   d_qi = fabao_ob->query("fabao/max_defense_qi");
   d_shen = fabao_ob->query("fabao/max_defense_shen");
   d_shou = fabao_ob->query("fabao/max_defense_shou");
	      
   if( fabao_ob->query("series_no") == "1" )  
      {
      write("�����ȼ���    " + HIR);
      damage_stars = fabao_ob->query("stars/damage");
      for(i=0; i<damage_stars; i++)
         write("��");
      write(NOR + "\n");
      if (damage_stars==5) write("��ķ���"+HIG+"�����˺���"+NOR+"�Ѿ������������ˡ�\n");
      else 
	  {
          write(HIG+"�����˺���" + NOR+ "(damage)������Ҫ��\n");
          write("    ����"+chinese_number(100*M(damage_stars))+"�����ϡ�\n");
          write("    ���Ľ���"+chinese_number(damage_stars)+"��\n");
        }
		write("\n�����˺�����\n");        
		write( fabao_ob->show_status() );
		
		if(a_qi >= 25 )
			write(RED"��Ѫ�˺���" + NOR + "������������\n");
		else
		{
			dx_req = (a_qi + 1)*100000;
			neili_req =  ( a_qi + 1)*200;
			dx_cost = ( a_qi + 1)*1000;
			neili_cost = (a_qi + 1)*3;
			
			write(RED"��Ѫ�˺���" + NOR + "(attack_qi)������Ҫ��\n");
			write("    ����"+chinese_number(dx_req/1000)+"�꣬������Ϊ"+chinese_number(neili_req/100)+"�ꡣ\n");
			write("    ����"+chinese_number(dx_cost/1000)+"�꣬������Ϊ"+chinese_number(neili_cost)+"��(100���൱��һ��)��\n");
		}

		if( a_shen >= 25 )
			write(BLU"�����˺���" + NOR + "������������\n");
		else
		{
			dx_req = ( a_shen + 1)*100000;
			fali_req =  ( a_shen + 1)*200;
			dx_cost = (a_shen + 1)*1000;
			fali_cost = ( a_shen + 1)*3;
			
			write(BLU"�����˺���" + NOR + "(attack_shen)������Ҫ��\n");
			write("    ����"+chinese_number(dx_req/1000)+"�꣬������Ϊ"+RANK_D->describe_fali(fali_req)+"��\n");
			write("    ����"+chinese_number(dx_cost/1000)+"�꣬������Ϊ"+chinese_number(fali_cost)+"�㡣\n");
		}        
      }
   else if( fabao_ob->query("series_no") == "2"  ||  fabao_ob->query("series_no") == "3" )  
      {
      dodge_stars = fabao_ob->query("stars/dodge");
      armor_stars = fabao_ob->query("stars/armor");
      force_stars = fabao_ob->query("stars/armor_vs_force");
      spells_stars = fabao_ob->query("stars/spells");
      vs_spells_stars = fabao_ob->query("stars/armor_vs_spells");
      write("�����ȼ���\n");
      write("    " + HIY+"������        "+HIR);
      for(i=0; i<dodge_stars; i++)
         write("��");
      for(i=dodge_stars; i<10; i++)
         write("��");
      write("    " + HIB+"�ֿ���        "+HIR);
      for(i=0; i<armor_stars; i++)
         write("��");
      write("\n"); 
      write("    " + HIM+"�ڹ��ֿ���    "+HIR);
      for(i=0; i<force_stars; i++)
         write("��");
      for(i=force_stars; i<10; i++)
         write("��");
      write("    " + HIC+"ħ��������    "+HIR);
      for(i=0; i<spells_stars; i++)
         write("��");
      write("\n"); 
      write("    " + HIW+"ħ���ֿ���    "+HIR);
      for(i=0; i<vs_spells_stars; i++)
         write("��");
      write(NOR+"\n"); 
      
      if (dodge_stars==5) write("��ķ���"+HIY+"������"+NOR+"�Ѿ������������ˡ�\n");
      else {
	  write(HIY+"������" + NOR+ "(dodge)������Ҫ��\n");
          write("    ����"+chinese_number(100*M(dodge_stars))+"�����ϡ�\n");
          write("    ���Ľ���"+chinese_number(dodge_stars)+"��\n");
          }

      if (armor_stars==5)  write("��ķ���"+HIB+"�ֿ���"+NOR+"�Ѿ������������ˡ�\n");
      else { 
	  write(HIB+"�ֿ���" + NOR+ "(armor)������Ҫ��\n");
          write("    ����"+chinese_number(100*M(armor_stars))+"�����ϡ�\n");
          write("    ���Ľ���"+chinese_number(armor_stars)+"��\n");
          }
 
      if (force_stars==5) write("��ķ���"+HIM+"�ڹ��ֿ���"+NOR+"�Ѿ������������ˡ�\n");
      else {
	  write(HIM+"�ڹ��ֿ���" + NOR+ "(armor_vs_force)������Ҫ��\n");
          write("    ����"+chinese_number(100*M(force_stars))+"�����ϡ�\n");
          write("    ���Ľ���"+chinese_number(force_stars)+"��\n");
	  }

      if (spells_stars==5) write("��ķ���"+HIC+"ħ��������"+NOR+"�Ѿ������������ˡ�\n");
      else {
	  write(HIC+"ħ��������" + NOR+ "(spells)������Ҫ��\n");
          write("    ����"+chinese_number(100*M(spells_stars))+"�����ϡ�\n");
          write("    ���Ľ���"+chinese_number(spells_stars)+"��\n");
	  }

      if (vs_spells_stars==5) write("��ķ���"+HIW+"ħ���ֿ���"+NOR+"�Ѿ������������ˡ�\n");
      else {
	  write(HIW+"ħ���ֿ���"+NOR+ "(armor_vs_spells)������Ҫ��\n");
          write("    ����"+chinese_number(100*M(vs_spells_stars))+"�����ϡ�\n");
          write("    ���Ľ���"+chinese_number(vs_spells_stars)+"��\n");
	  }
		write("\n������������\n");  	
		write( fabao_ob->show_status() );
		
		if( d_qi >= 25 )
			write(RED"��Ѫ������" + NOR + "������������\n");
		else
		{
			dx_req = ( d_qi + 1)*100000;
			neili_req =  ( d_qi + 1)*200;
			dx_cost = ( d_qi + 1)*1000;
			neili_cost = ( d_qi + 1)*3;
			
			write(RED"��Ѫ������" + NOR+ "(defense_qi)������Ҫ��\n");
			write("    ����"+chinese_number(dx_req/1000)+"�꣬������Ϊ"+chinese_number(neili_req/100)+"�ꡣ\n");
			write("    ����"+chinese_number(dx_cost/1000)+"�꣬������Ϊ"+chinese_number(neili_cost)+"��(100���൱��һ��)��\n");
		}

		if( d_shen >= 25 )
			write(RED"���񱣻���" + NOR + "������������\n");
		else
		{
			dx_req = ( d_shen + 1)*100000;
			fali_req =  ( d_shen + 1)*200;
			dx_cost = ( d_shen + 1)*1000;
			fali_cost = ( d_shen + 1)*3;
			
			write(BLU"�����˺���" + NOR+ "(defense_shen)������Ҫ��\n");
			write("    ����"+chinese_number(dx_req/1000)+"�꣬������Ϊ"+RANK_D->describe_fali(fali_req)+"��\n");
			write("    ����"+chinese_number(dx_cost/1000)+"�꣬������Ϊ"+chinese_number(fali_cost)+"�㡣\n");
		}

		if( d_shou >= 25 )
			write(YEL"������ȡ��" + NOR + "������������\n");
		else
		{
			dx_req = ( d_shou + 1)*100000;
			fali_req =  ( d_shou + 1)*200;
			neili_req =  ( d_shou + 1)*200;
			dx_cost = ( d_shou + 1)*1000;
			fali_cost = ( d_shou + 1)*3;
			neili_cost = ( d_shou + 1)*3;
			
			write(YEL"������ȡ��" + NOR+ "(defense_shou)������Ҫ��\n");
			write("    ����"+chinese_number(dx_req/1000)+"�꣬������Ϊ"+RANK_D->describe_fali(fali_req)+"��������Ϊ"+chinese_number(neili_req/100)+"�ꡣ\n");
			write("    ����"+chinese_number(dx_cost/1000)+"�꣬������Ϊ"+chinese_number(fali_cost)+"�㣬������Ϊ"+chinese_number(neili_cost)+"��(100���൱��һ��)��\n");
		}	
   }   
   return 1;
}

int  do_upgrade(string arg)
{
   string name, property;
   object fabao_ob, me=this_player();
   int   stars, upgraded;
   int neili_req, fali_req, dx_req;
   int neili_cost, fali_cost, dx_cost;
   int a_qi, a_shen, d_qi, d_shen, d_shou;
   int my_dx, my_fali, my_neili;  

   if( !arg || arg == "")   {
      write("���� upgrade ������ for �������� ��������\n");
      write("�������Կ��� cost ������ ���鿴��\n");
      return 1;
   }
      
   if( sscanf(arg, "%s for %s", name, property) != 2)  {
      write("���� upgrade ������ for �������� ��������\n");
      write("�������Կ��� cost ������ ���鿴��\n");
      return 1;
   }
   
   if( !objectp(fabao_ob=present(name, me)) )
      return notify_fail("������û��������������\n");

   if(fabao_ob->query("special_fabao"))
      return notify_fail("���ⷨ������������\n");
            
   if(!fabao_ob->query("owner_id") || !fabao_ob->query("series_no")) 
      return notify_fail("�Ǹ����Ƿ���Ү��\n");
     
   if( fabao_ob->query("equipped") )
      return notify_fail("�������·�������������������\n");

   a_qi = fabao_ob->query("fabao/max_attack_qi");
   a_shen = fabao_ob->query("fabao/max_attack_shen");
   d_qi = fabao_ob->query("fabao/max_defense_qi");
   d_shen = fabao_ob->query("fabao/max_defense_shen");
   d_shou = fabao_ob->query("fabao/max_defense_shou");
          
   my_dx = me->query("daoxing");
   my_fali = me->query("max_mana");
   my_neili = me->query("max_force");
	          
   if( fabao_ob->query("series_no") == "1")  
      {
		if( property == "attack_qi" )
		{
			if(a_qi >= 25 )
				return notify_fail("�����������Ѫ�˺���������������\n");

			dx_req = (a_qi + 1)*100000;
			neili_req =  ( a_qi + 1)*200;
			dx_cost = ( a_qi + 1)*1000;
			neili_cost = (a_qi + 1)*3;
			
			if( my_dx < dx_req )
				return notify_fail("����ĵ��У�Ŀǰ���������������������Ѫ�˺�����\n");
			if( my_neili < neili_req )
				return notify_fail("�����������Ϊ��Ŀǰ���������������������Ѫ�˺�����\n");
			//now, let's upgrade...
			me->add("daoxing", -dx_cost);
			me->add("maximum_force", -neili_cost);//By tianlin@mhxy for 2002.1.25
			me->add("max_force", -neili_cost);
			fabao_ob->set("fabao/max_attack_qi", a_qi+1);
			fabao_ob->add("weapon_prop/damage", 1);//will be 75+10 in max.
			me->save();
			fabao_ob->save();
			message_vision(HIR "$N����������ע��$n"HIR"�У�ֻ��$n"HIR"�ų����ϼ�⣬������ֹ��\n" NOR, me, fabao_ob);
			return 1;
		}

		else if( property == "attack_shen" )
		{
			if(a_shen >= 25 )
				return notify_fail("��������ľ����˺���������������\n");

			dx_req = (a_shen + 1)*100000;
			fali_req =  ( a_shen + 1)*200;
			dx_cost = ( a_shen + 1)*1000;
			fali_cost = (a_shen + 1)*3;
			
			if( my_dx < dx_req )
				return notify_fail("����ĵ��У�Ŀǰ������������������ľ����˺�����\n");
			if( my_fali < fali_req )
				return notify_fail("����ķ�����Ϊ��Ŀǰ������������������ľ����˺�����\n");
			//now, let's upgrade...
			me->add("daoxing", -dx_cost);
			me->add("maximum_mana", -fali_cost);//By tianlin@mhxy for 2002.1.25
			me->add("max_mana", -fali_cost);
			fabao_ob->set("fabao/max_attack_shen", a_shen+1);
			me->save();
			fabao_ob->save();
			message_vision(HIR "$N����������ע��$n"HIR"�У�ֻ��$n"HIR"�ų����ϼ�⣬������ֹ��\n" NOR, me, fabao_ob);
			return 1;
		}
      		else if(property == "damage" )
      		{
      			stars = fabao_ob->query("stars/"+property);
      			if (stars==5) return notify_fail("��ķ����Ѿ������������ˡ�\n");
      			upgraded = fabao_ob->query("upgraded/"+property) + 1;
      			if( me->query("daoxing") < 100000*M(stars) ||
			me->query("jieshu") < stars )
         		return notify_fail("������������������ cost ��ѯ��\n");
      			fabao_ob->add("weapon_prop/damage", 4);
      			fabao_ob->add("upgraded/"+property, 1);
      			if( upgraded == 5 )  
	  		{
          		fabao_ob->add("stars/"+property, 1);
          		fabao_ob->set("upgraded/"+property, 0);
          		}
      			me->set("jieshu",me->query("jieshu")-stars);
      			write(fabao_ob->query("name")+"��"+HIG+"�˺���"+NOR+"�����ˣ�\n");
		}
		else 
		{
			return notify_fail("�������û������������ԣ����� cost <������> ���鿴��\n");
		}
      }
   else if(fabao_ob->query("series_no") == "2" ||
             fabao_ob->query("series_no") == "3")   
      {   
      if( property != "dodge" && property != "armor" &&
      property != "armor_vs_force" && property != "spells" &&
      property != "armor_vs_spells" && property != "defense_qi" && 
      property != "defense_shen" && property != "defense_shou" )
         return notify_fail("����û������������ԣ����� cost <������> ���鿴��\n");
		if( property == "defense_qi" )
		{
			if(d_qi >= 25 )
				return notify_fail("�����������Ѫ������������������\n");

			dx_req = (d_qi + 1)*100000;
			neili_req =  ( d_qi + 1)*200;
			dx_cost = ( d_qi + 1)*1000;
			neili_cost = (d_qi + 1)*3;
			
			if( my_dx < dx_req )
				return notify_fail("����ĵ��У�Ŀǰ���������������������Ѫ��������\n");
			if( my_neili < neili_req )
				return notify_fail("�����������Ϊ��Ŀǰ���������������������Ѫ��������\n");
			//now, let's upgrade...
			me->add("daoxing", -dx_cost);
			me->add("maximum_force", -neili_cost);//By tianlin@mhxy for 2002.1.25
			me->add("max_force", -neili_cost);
			fabao_ob->set("fabao/max_defense_qi", d_qi+1);
			me->save();
			fabao_ob->save();
			message_vision(HIR "$N����������ע��$n"HIR"�У�ֻ��$n"HIR"�ų����ϼ�⣬������ֹ��\n" NOR, me, fabao_ob);
			return 1;
		}

		else if( property == "defense_shen" )
		{
			if(d_shen >= 25 )
				return notify_fail("��������ľ��񱣻���������������\n");

			dx_req = (d_shen + 1)*100000;
			fali_req =  ( d_shen + 1)*200;
			dx_cost = ( d_shen + 1)*1000;
			fali_cost = (d_shen + 1)*3;
			
			if( my_dx < dx_req )
				return notify_fail("����ĵ��У�Ŀǰ������������������ľ��񱣻�����\n");
			if( my_fali < fali_req )
				return notify_fail("����ķ�����Ϊ��Ŀǰ������������������ľ��񱣻�����\n");
			//now, let's upgrade...
			me->add("daoxing", -dx_cost);
			me->add("maximum_mana", -fali_cost);//By tianlin@mhxy for 2002.1.25
			me->add("max_mana", -fali_cost);
			fabao_ob->set("fabao/max_defense_shen", d_shen+1);
			me->save();
			fabao_ob->save();
			message_vision(HIR "$N����������ע��$n"HIR"�У�ֻ��$n"HIR"�ų����ϼ�⣬������ֹ��\n" NOR, me, fabao_ob);
			return 1;
		}

		else if( property == "defense_shou" )
		{
			if(d_shou >= 25 )
				return notify_fail("��������ķ�����ȡ��������������\n");

			dx_req = (d_shou + 1)*100000;
			fali_req =  ( d_shou + 1)*200;
			dx_cost = ( d_shou + 1)*1000;
			fali_cost = (d_shou + 1)*3;
			
			if( my_dx < dx_req )
				return notify_fail("����ĵ��У�Ŀǰ������������������ķ�����ȡ����\n");
			if( my_fali < fali_req )
				return notify_fail("����ķ�����Ϊ��Ŀǰ������������������ķ�����ȡ����\n");
			//now, let's upgrade...
			me->add("daoxing", -dx_cost);
			me->add("maximum_mana", -fali_cost);//By tianlin@mhxy for 2002.1.25
			me->add("max_mana", -fali_cost);
			fabao_ob->set("fabao/max_defense_shou", d_shou+1);
			me->save();
			fabao_ob->save();
			message_vision(HIR "$N����������ע��$n"HIR"�У�ֻ��$n"HIR"�ų����ϼ�⣬������ֹ��\n" NOR, me, fabao_ob);
			return 1;
		}
      else
      {	      
      stars = fabao_ob->query("stars/"+property); 
      if (stars==5) return notify_fail("��ķ����Ѿ������������ˡ�\n");
      upgraded = fabao_ob->query("upgraded/"+property) + 1; 

      if( property == "dodge" )   
	  {
          if( me->query("daoxing") < 100000*M(stars) ||
		me->query("jieshu") < stars )
              return notify_fail("������������������ cost ��ѯ��\n");
          fabao_ob->add("armor_prop/dodge", 1);
          fabao_ob->add("upgraded/"+property, 1);
          if( upgraded == 5 )  
	      {
              fabao_ob->add("stars/"+property, 1);
              fabao_ob->set("upgraded/"+property, 0);
              }
	  me->set("jieshu",me->query("jieshu")-stars);
          write(fabao_ob->query("name")+"��"+HIY+"������"+NOR+"�����ˣ�\n");
         }
      else if( property == "armor" )  {
          if( me->query("daoxing") < 100000*M(stars) ||
		me->query("jieshu") < stars )
              return notify_fail("������������������ cost ��ѯ��\n");
          fabao_ob->add("armor_prop/armor", 2);
          fabao_ob->add("upgraded/"+property, 1);
          if( upgraded == 5 )  {
              fabao_ob->add("stars/"+property, 1);
              fabao_ob->set("upgraded/"+property, 0);
              }
	  me->set("jieshu",me->query("jieshu")-stars);
          write(fabao_ob->query("name")+"��"+HIB+"�ֿ���"+NOR+"�����ˣ�\n");
          }
      else if( property == "armor_vs_force" )  {
          if( me->query("daoxing") < 100000*M(stars) ||
		me->query("jieshu") < stars )
              return notify_fail("������������������ cost ��ѯ��\n");
          fabao_ob->add("armor_prop/armor_vs_force", 20);
          fabao_ob->add("upgraded/"+property, 1);
          if( upgraded == 5 )  {
               fabao_ob->add("stars/"+property, 1);
               fabao_ob->set("upgraded/"+property, 0);
               }
	  me->set("jieshu",me->query("jieshu")-stars); 
          write(fabao_ob->query("name")+"��"+HIM+"�ڹ��ֿ���"+NOR+"�����ˣ�\n");
          }
      else if( property == "spells" )  {
          if( me->query("daoxing") < 100000*M(stars) ||
		me->query("jieshu") < stars )
              return notify_fail("������������������ cost ��ѯ��\n");
          fabao_ob->add("armor_prop/spells", 1);
          fabao_ob->add("upgraded/"+property, 1);
          if( upgraded == 5 )  {
               fabao_ob->add("stars/"+property, 1);
               fabao_ob->set("upgraded/"+property, 0);
               }
	  me->set("jieshu",me->query("jieshu")-stars);
          write(fabao_ob->query("name")+"��"+HIC+"ħ��������"+NOR+"�����ˣ�\n");
          }
      else if( property == "armor_vs_spells" )  {
          if( me->query("daoxing") < 100000*M(stars) ||
		me->query("jieshu") < stars )
              return notify_fail("������������������ cost ��ѯ��\n");
          fabao_ob->add("armor_prop/armor_vs_spells", 20);
          fabao_ob->add("upgraded/"+property, 1);
          if( upgraded == 5 )  {
               fabao_ob->add("stars/"+property, 1);
               fabao_ob->set("upgraded/"+property, 0);
               }
	  me->set("jieshu",me->query("jieshu")-stars);
          write(fabao_ob->query("name")+"��"+HIW+"ħ���ֿ���"+NOR+"�����ˣ�\n");
          }
	}         
   }
  
   me->save(); 
   fabao_ob->save();
   
   return 1;
}

int  do_change_name(string arg)
{
   string name, newname;
   object fabao_ob, me=this_player();
  
   if( !arg || arg == "") 
      return notify_fail("���� change_name ���� �������� ��������\n");
      
   if( sscanf(arg, "%s %s", name, newname) != 2)
      return notify_fail("���� change_name ���� �������� ��������\n");
   
   if( !objectp(fabao_ob=present(name, me)) )
      return notify_fail("������û��������������\n");

   if( !fabao_ob->query("owner_id") ||
      (!fabao_ob->query("series_no") && !fabao_ob->query("special_fabao")) )
      return notify_fail("�Ǹ����Ƿ���Ү��\n");

   if( fabao_ob->query("equipped") )
      return notify_fail("�������·������ܸ�����\n");
   
   newname += "$NOR$";      
   arg = newname;
            
        arg = replace_string(arg, "$BLK$", "");
        arg = replace_string(arg, "$RED$", "");
        arg = replace_string(arg, "$GRN$", "");
        arg = replace_string(arg, "$YEL$", "");
        arg = replace_string(arg, "$BLU$", "");
        arg = replace_string(arg, "$MAG$", "");
        arg = replace_string(arg, "$CYN$", "");
        arg = replace_string(arg, "$WHT$", "");
        arg = replace_string(arg, "$HIR$", "");
        arg = replace_string(arg, "$HIG$", "");
        arg = replace_string(arg, "$HIY$", "");
        arg = replace_string(arg, "$HIB$", "");
        arg = replace_string(arg, "$HIM$", "");
        arg = replace_string(arg, "$HIC$", "");
        arg = replace_string(arg, "$HIW$", "");
        arg = replace_string(arg, "$NOR$", "");
        
   if( !check_legal_name(arg, 12) )   {
      return 1; 
   }
  
   arg = newname;
    
        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);
  
   fabao_ob->set("name", arg);
   fabao_ob->save();     
   
   write("�Ķ��ɹ���\n");
   return 1;
}
      
int  do_change_id(string arg)
{
   string name, newname;
   object fabao_ob, me=this_player();
   string *id_list, *t_list;
  
   if( !arg || arg == "") 
      return notify_fail("���� change_id ���� ��Ӣ���� ��������\n");
      
   if( sscanf(arg, "%s %s", name, newname) != 2)
      return notify_fail("���� change_id ���� ��Ӣ���� ��������\n");
   
   if( !objectp(fabao_ob=present(name, me)) )
      return notify_fail("������û��������������\n");

   if( !fabao_ob->query("owner_id") ||
      (!fabao_ob->query("series_no") && !fabao_ob->query("special_fabao")) )
      return notify_fail("�Ǹ����Ƿ���Ү��\n");

   if( fabao_ob->query("equipped") )
      return notify_fail("�������·������ܸ�����\n");

   if( !check_legal_id( newname ) )     return 1;
  
   newname = replace_string(newname, " ", "_"); 
   fabao_ob->set("id", newname);

   id_list = ({ newname });
   t_list = explode( newname, "_");
   if( sizeof(t_list) > 1 )   {
     id_list += t_list;
   }
   fabao_ob->set_name( fabao_ob->query("name"), id_list ); 
   fabao_ob->save();
   
   write("�Ķ��ɹ���\n");
   return 1;
}

      
int  do_change_desc(string arg)
{
   string name, newname;
   object fabao_ob, me=this_player();
  
   if( !arg || arg == "") 
      return notify_fail("���� change_desc ���� ������ ����������������\n");
      
   if( sscanf(arg, "%s %s", name, newname) != 2)
      return notify_fail("���� change_desc ���� ������ ����������������\n");
   
   if( !objectp(fabao_ob=present(name, me)) )
      return notify_fail("������û��������������\n");

   if( !fabao_ob->query("owner_id") ||
      (!fabao_ob->query("series_no") && !fabao_ob->query("special_fabao")) )
      return notify_fail("�Ǹ����Ƿ���Ү��\n");

   if( fabao_ob->query("equipped") )
      return notify_fail("�������·������ܸ�����\n");

   if( !check_legal_name(newname, 60 ) )     return 1;
   
   fabao_ob->set("long", newname);
   fabao_ob->save();
   
   write("�Ķ��ɹ���\n");
   return 1;
}
      
int  do_change_unit(string arg)
{
   string name, newname;
   object fabao_ob, me=this_player();
  
   if( !arg || arg == "") 
      return notify_fail("���� change_unit ���� ��λ ��ָ��������λ��\n");
      
   if( sscanf(arg, "%s %s", name, newname) != 2)
      return notify_fail("���� change_unit ���� ��λ ��ָ��������λ��\n");
   
   if( !objectp(fabao_ob=present(name, me)) )
      return notify_fail("������û��������������\n");

   if( !fabao_ob->query("owner_id") ||
      (!fabao_ob->query("series_no") && !fabao_ob->query("special_fabao")) )
      return notify_fail("�Ǹ����Ƿ���Ү��\n");

   if( fabao_ob->query("equipped") )
      return notify_fail("�������·������ܸ�����\n");

   if( !check_legal_name(newname, 2 ) )     return 1;
   
   fabao_ob->set("unit", newname);
   fabao_ob->save();
   
   write("�Ķ��ɹ���\n");
   return 1;
}
int valid_leave(object me, string dir)
{
	if (me->query_temp("koujian_nuwa") && dir == "east")
	{
	   message_vision("$Nվ�����������������ϵ�����\n",me);
	   me->delete_temp("koujian_nuwa");
	}
	remove_call_out("check_hp");
	return ::valid_leave(me,dir);
}

int do_koujian(string arg)
{
	object ob=this_player();
	if (!arg || (arg != "nuwa" && arg !="nuwa niangniang"))
	  return notify_fail("��Ҫߵ��˭��\n");
	if (ob->query_temp("koujian_nuwa"))
	{ 
		message_vision("$N���������Ŀ��˼���ͷ.\n",ob);
		return 1;
	}
	else
	   ob->set_temp("koujian_nuwa",1);
	message_vision("$N��ͨһ���򵽵��ϣ����������ؿ���һ��ͷ����������������"+ob->query("name")
	+"�ݼ�Ů������\n",ob);
	if (ob->query("family/master_id")=="nuwa niangniang")
	  {
	      message_vision(HIC"һ����紵������$N����ؾ����ˡ�\n"NOR,ob);
	      ob->move(__DIR__"nuwaroom");
	      return 1;
	  }
	call_out("check_hp",15,ob);
	return 1;
}

void check_hp(object ob)
{
	remove_call_out("check_hp");
	if (random(50-ob->query_kar())!=0)
	 {
	   if (ob->query("sen")<=10)
	     {
	     	ob->unconcious();
	     	return;
	     } else 
	     {
	     	ob->receive_damage("sen",ob->query("sen")/5);
	     	if (ob->query("sen")*2 < ob->query("max_sen"))
	     	  message_vision("$N�Ѿ����ͷ���ۻ����ˣ�������������\n",ob);
	     	else
	     	  message_vision("$N������Щͷ�Ρ�\n",ob);
	     }
	   call_out("check_hp",15,ob);
	   return;
	 }
	//ob->delete_temp("koujian_nuwa");
	message_vision(HIC"����д���һ��̾Ϣ�����������Ǻο���?\n"NOR,ob);
	if (ob->query("family/family_name")=="�¹�") {
        message_vision(HIC"һ����紵������$N����ؾ����ˡ�\n"NOR,ob);
	ob->move(__DIR__"nuwaroom");
	}
} 
