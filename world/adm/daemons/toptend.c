// BY LANDIS@MYTH
// 2002.02.06

#include <ansi.h>
#include <mudlib.h>

inherit F_DBASE;
inherit F_SAVE;

/**********************************************
mapping topten = ([
        "type1"  :     ([
                "id1"   :     ([
                        "name"  :    name,
                        "value" :    value,
                        ]),
                "id2"   :     ([
                        "name"  :    name,
                        "value" :    value,
                        ]),
                ]),
        ]);
***********************************************/

mapping topten;
mapping direct;

static mapping types = ([
        "dx"    :       HIW"���и��֣�DX��",
        "exp"   :       HIM"��ѧ���֣�EXP��",
        "age"   :       HIC"�������ǣ�AGE��",
        "die"   :       HIB"�������DIE��",
        "per"   :       HIM"������Ů��PER��",
        "hsm"   :       HIG"����˧�磨HSM��",
        "nker"  :       HIY"N K ���֣�NKER��",
        "pker"  :       HIB"P K ��ħ��PKER��",
        "rich"  :       HIR"����������RICH��",
        "mana"  :       NOR CYN"�������֣�MANA��",
        "force" :       NOR WHT"�������֣�FORCE��",
        "quest" :       HIW"���Ը��֣�QUESTS��",
        ]);

int get_all_data(object, string);
int topten_add(object, string);

void create()
{
        int size;
        string *map;

        seteuid(ROOT_UID);
        set("channel_id", "���о���");
        CHANNEL_D->do_channel( this_object(), "sys", "����ϵͳ�Ѿ�������");

        restore();

        if (! mapp(topten))
                topten = ([ ]);

        if (! mapp(direct))
                direct = ([ ]);

        map  = keys(types);
        size = sizeof(map);

        while (size--)
        {
                if (! mapp(topten[map[size]]))
                        topten[map[size]] = ([ ]);
        }
}

string query_save_file()
{
        return DATA_DIR "toptend";
}

void save()
{
        int i, j;
        string id;
        string *ids;
        string *tmp;
        string *key;

        mapping map;
        mapping *maps;

        tmp = keys(types);

        for (i=0; i<sizeof(tmp); i++)
        {
                map = topten[tmp[i]];

                if (mapp(map) && sizeof(keys(map)) > 1)
                {
                        maps = ({ });
                        ids = keys(map);

                        for (j=0; j<sizeof(ids); j++)
                        {
                                map[ids[j]]["id"] = ids[j];
                                maps += ({ map[ids[j]] });
                        }

                        map = ([ ]);
                        key = ({ });
                        maps = sort_array(maps, "sort_value");


                        for (j=0; j<sizeof(maps); j++)
                        {
                                id   = maps[j]["id"];
                                map_delete(maps[j], "id");

                                key += ({ id });
                                map[id] = maps[j];
                        }

                        direct[tmp[i]] = key;
//                      topten[tmp[i]] = map;
                }
        }

        ::save();
}

int topten_checkplayer(object player)
{
        int i;
        int flag;
        string *tmp;

        flag = 0;
        tmp  = keys(types);
        i    = sizeof(tmp);

        while (i--)
        {
                if (topten_add(player, tmp[i]))
                        flag ++;
        }

        save();

        if (flag == sizeof(tmp))
                return 1;

        return 0;
}

string query_type()
{
        int i;
        string str;
        string tmp;
        string msg;
        string *key;

        str  = HIW + INTERMUD_MUD_NAME + " �����������͵����а�\n";
        str += HIB + "��������������������������������������������\n";
        msg  = "������" + HIW + INTERMUD_MUD_NAME + " ";

        key = keys(types);

        for (i=0; i<sizeof(key); i++)
        {
                tmp  = HIR + sprintf("%-4s", chinese_number(i+1)) + msg;
                tmp += types[key[i]];
                tmp += "\n";

                str += tmp;
        }

        str += HIB + "��������������������������������������������\n" + NOR;

        return str;
}

string topten_query(string type)
{
        int i;
        string str;
        string id, name;
        string *ids;
        mapping map;

        if (member_array(type, keys(types)) == -1)
                return WHT"û�д����͵����а�\n"NOR;

        str  = HIW + INTERMUD_MUD_NAME + " ʮ�� ";
        str += types[type] + "\n";
        str += HIB + "����������������������������\n" + NOR;

        ids = direct[type];
        map = topten[type];

        if (! mapp(map) || sizeof(keys(map)) < 10)
                return WHT"���������а�������δ�ռ���ȫ��\n"NOR;

        for (i=0; i<sizeof(ids); i++)
        {
                str += WHT + "�� ";
                str += HIY + chinese_number(i+1) + NOR;
                str += WHT + " ��  ";

                id   = ids[i];
                name = map[id]["name"];

                str += name + "(" + capitalize(id) + ")";
                str += "\n" + NOR;
        }

        str+= HIB + "����������������������������\n" + NOR;

        return str;
}

int topten_del(string id, string type)
{
        string *tmp;
        mapping dir;

        tmp = keys(topten);
        if (member_array(type, tmp) == -1)
                return notify_fail(WHT + "û��" + type + "�������а�\n" + NOR);

        dir = topten[type];
        map_delete(dir, id);

        save();
        return 1;
}

int topten_add(object player,string type)
{
        int val;
        int size;
        string *tmp;
        string id, name;
        mapping value;
        mapping map;

        tmp = keys(types);

        if (! userp(player) || wizardp(player))
                return 0;

        if (member_array(type, tmp) == -1)
                return notify_fail(WHT + "û��" + type + "�������а�\n" + NOR);

        if (! mapp(topten[type]))
                topten[type] = ([]);

        name = player->name();
        id   = player->query("id");

        if (get_all_data(player,type) > 0)
                val = get_all_data(player,type);
        else
                return notify_fail(WHT"��ѯ���ʹ�����˶ԡ�\n"NOR);

        map = ([ ]);
        map["name"]  = name;
        map["value"] = val;

        value = topten[type];
        value[id] = map;

        tmp  = keys(value);
        size = sizeof(tmp);

        if (size > 10)
        {
                while (size--)
                {
                        map = value[tmp[size]];

                        if (map["value"] <= val)
                        {
                                map_delete(value, tmp[size]);
                                break;
                        }
                }
        }                                

        topten[type] = value;
        return 1;
}

int get_all_data(object player, string type)
{
        int total;
        mapping my;

        my = player->query_entire_dbase();

        switch(type)
        {
                case "rich":
                        total = my["balance"] + my["money"];
                        break;
                case "quests":
                        total = my["quest/number"] + my["TASK"];
                        break;
                case "pker":
                        total = my["PKS"];
                        break;
                case "nker":
                        total = my["MKS"];
                        break;
                case "exp":
                        total = my["combat_exp"];
                        break;
                case "dx":
                        total = my["daoxing"];
                        break;
                case "force":
                        total = my["max_force"];
                        break;
                case "age":
                        total = my["mud_age"];
                        break;
                case "hsm":
                        if (my["gender"] != "����")
                                total = -1;
                        else
                                total = my["per"];
                        break;
                case "per":
                        if (my["gender"] != "Ů��")
                                total = -1;
                        else
                                total = my["per"];
                        break;
                case "mana":
                        total = my["max_mana"];
                        break;
                default:
                        total = -1;//��-1��־���ͳ���
        }

        return total;
}

int sort_value(mapping map1, mapping map2)
{
        int num1, num2;

        num1 = map1["value"];
        num2 = map2["value"];

        if (num1 > num2) return -1;
        if (num1 < num2) return  1;

        return 0;
}

