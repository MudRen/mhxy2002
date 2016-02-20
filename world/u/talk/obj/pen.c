#include <weapon.h>
#include <ansi.h>
inherit STICK;
inherit F_AUTOLOAD;
string money_str(int amount);

void init()
{ 
        add_action("do_setname","setname");    
        add_action("do_settitle","settitle");       
        add_action("do_rsg","rsg");       
        add_action("do_money","money");       
}

void create()
{
        set_name(HIW "�ɿ˸ֱ�" NOR, ({"parker pen","pen","parker"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long",HIW "���Ǻ��ĵ�����֮�\n" NOR);
                set("value", 10);
                set("unit", "֦");
                set("no_get", 1);
                set("is_monitord",1);    
                set("no_drop", 1);
        }
       setup();
}


int query_autoload()
{
  return 1;
}


int do_settitle(string arg)
{
        string tmp;
        object ob,me;
        me = this_player();

        if( !arg )
                return notify_fail("��Ҫ��˭ȡʲôͷ�Σ�\n");

        if (sscanf(arg, "%s %s", tmp, arg) == 2)
                ob = present(tmp, environment(me));
        if (!ob) return notify_fail("����û������ˡ�\n");

        if( strlen(arg) > 73 )
                return notify_fail("���title̫���ˣ���һ����һ��ġ�����һ��ġ�\n");
 
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
        message_vision(HIY "$N��$n"HIY"��ͷ�θ�Ϊ" + arg + "��\n" NOR, me, ob);
        ob->set("title", arg + NOR);
        return 1;
}

int do_setname(string arg)
{
        string tmp;
        object ob,me;
        me = this_player();

        if( !arg )
                return notify_fail("��Ҫ��˭ȡʲô���֣�\n");

        if (sscanf(arg, "%s %s", tmp, arg) == 2)
                ob = present(tmp, environment(me));
        if (!ob) return notify_fail("����û������ˡ�\n");

        if( strlen(arg) > 20 )
                return notify_fail("�������̫���ˣ���һ����һ��ġ�����һ��ġ�\n");
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
        message_vision(HIY "$N��$n"HIY"�����ָ�Ϊ" + arg + "��\n" NOR, me, ob);
        ob->set("name", arg);
        return 1;
}

int do_rsg(string str)
{
   object me,ob,guo;
   me = this_player();
   ob = LOGIN_D->find_body(str);
   guo = ob->query("rsg_eaten");
   if(!str) return notify_fail("��Ҫ��˭�����ݣ�\n");
   if(!ob) return notify_fail("��Ҫ����˲����ߡ�\n");
   write("���ڲ���Ϣ����"+ob->query("name")+"�Ѿ�����"+chinese_number(guo)+"���˲ι���\n");
   return 1;
}

int do_money(string str)
{
   object me,ob;
   int total;
   me = this_player();
   ob = LOGIN_D->find_body(str);
   if(!str) return notify_fail("��Ҫ��˭�Ĵ�\n");
   if(!ob) return notify_fail("��Ҫ����˲����ߡ�\n");
   total = (int)ob->query("balance");
   write("�������ݡ���"+ob->query("name")+"��"+money_str(total)+"�Ĵ�\n");
   return 1;
}

string money_str(int amount)
{        
        string output;

        if (amount / 10000) {
                output = chinese_number(amount / 10000) + "���ƽ�";
                amount %= 10000;
        }
        else
                output = "";
        if (amount / 100) {
                output = output + chinese_number(amount / 100) + "������";
                amount %= 100;
        }
        if (amount || sizeof(output)<2)
                return output + chinese_number(amount) + "��ͭ��";
        return output;
}