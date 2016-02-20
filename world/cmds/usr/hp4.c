//by tianlin 2001/5/1
#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;

string status_color(int current, int max);

int main(object me, string arg)
{       object ob;
       object weapon;
       string line,skill_type;
        mapping my;
        int year, day, hour,anger,x;
       int attack_points, dodge_points, parry_points;
        int i;

        if(!arg)
                ob = me;
        else if (wizardp(me)) {
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
                 if( !ob->is_character() || ob->is_corpse() )
                         return notify_fail("��" + ob->query("name") + "��״̬��Ҫ�鿴��������Ĭ��\n");
        } else
                return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");
 
        my = ob->query_entire_dbase();
 //printf("[37m��������������������������������������������������������������������������\n[2;37;0m");
        printf(HIC" ��Ѫ�� %s%4d/ %4d %s(%3d%%)" +HIC 
                "         ������ %s%4d / %4d (%3d%%) (+%d)\n" NOR,
                status_color(my["kee"], my["eff_kee"]),my["kee"],my["eff_kee"],
                status_color(my["eff_kee"], my["max_kee"]),     
                my["eff_kee"] * 100 / my["max_kee"],
                status_color(my["force"], my["max_force"]),     
                my["force"], my["max_force"],
                my["maximum_force"] ?
                  my["max_force"] * 100 / my["maximum_force"] : 100,
                my["force_factor"] );

        printf(HIC" ���� %s%4d/ %4d %s(%3d%%)"   +HIC 
                "         ������ %s%4d / %4d (%3d%%) (+%d)\n" NOR,
                status_color(my["sen"], my["eff_sen"]),my["sen"],my["eff_sen"],
                status_color(my["eff_sen"], my["max_sen"]),     
                my["eff_sen"] * 100 / my["max_sen"],
                status_color(my["mana"], my["max_mana"]), 
                my["mana"], my["max_mana"],
                my["maximum_mana"] ?
                  my["max_mana"] * 100 / my["maximum_mana"] : 100,
                my["mana_factor"] );
    
        printf(HIW" ʳ� %s%4d/ %4d      " +HIW"          ��ѧ�� %s%d\n" NOR,
                status_color(my["food"], ob->max_food_capacity()),
                my["food"], ob->max_food_capacity(),
                HIY,
                my["combat_exp"]);
        
        year = my["daoxing"] / 1000; 
        day = (my["daoxing"] - year * 1000) / 4;
        hour = (my["daoxing"] - year * 1000 - day * 4) * 3; 
    
        printf(HIW" ��ˮ�� %s%4d/ %4d      "  +HIW"          ���У� %s",
                status_color(my["water"], ob->max_water_capacity()),
                my["water"], ob->max_water_capacity(), HIM );
    
        if(year) printf("%s��", chinese_number(year));
        if(day) printf("%s��", chinese_number(day));
        if(hour) printf("%sʱ��", chinese_number(hour));
        if(!year && !day && !hour)  printf("û�е���");
        printf("\n"NOR);

        printf(CYN" Ǳ�ܣ�  %s%6d         "  +CYN"          ɱ����"+HIR" %s%4d\n"NOR,
              YEL,
                (int)ob->query("potential") - (int)ob->query("learned_points"),
                HIR,
              my["bellicosity"]);       

        if( objectp(weapon = ob->query_temp("weapon")) )
                skill_type = weapon->query("skill_type");
        else
                skill_type = "unarmed";

        attack_points = COMBAT_D->skill_power(ob, skill_type,SKILL_USAGE_ATTACK);
        parry_points = COMBAT_D->skill_power(ob, skill_type,SKILL_USAGE_DEFENSE);
        dodge_points = COMBAT_D->skill_power(ob, "dodge",SKILL_USAGE_DEFENSE);

       printf(CYN" ������  "WHT"%4d           "  +CYN"          ���ף�"WHT" %4d\n"NOR,
                ob->query_temp("apply/damage"),ob->query_temp("apply/armor"));
 anger=ob->query("anger");
        printf(RED" ŭ����"NOR);

 if( !anger || anger==0 )
  printf(HIY"�{�{�{�{�{�{�{�{�{�{\n",NOR);
else {
 for( x=0;x<anger/10;x++)
 {
        printf(HIR+BLINK"�{"NOR);
}
for( i=0;i<(100-anger)/10;i++)
{
        printf(HIY"�{"NOR);
}}
 printf("\n");
// printf("[37m����������������������������������������������������"HIC"�λ�����"NOR"������������������\n[2;37;0m");
        return 1;
}
 
string status_color(int current, int max)
{
        int percent;
 
        if( max>0 ) percent = current * 100 / max;
        else percent = 100;
        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return YEL;
        if( percent >= 10 ) return HIR;
        return RED;
}
 
int help(object me)
{
        write(@HELP
ָ���ʽ : hp
           hp <��������>                   (��ʦר��)
 
���ָ�������ʾ���ָ������(������)�ľ�, ��, ����ֵ��
 
see also : score
HELP
    );
    return 1;
}