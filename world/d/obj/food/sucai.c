inherit F_FOOD;
inherit ITEM;

string *names = ({
        "����",
        "Ģ��",
        "ɽҩ",
        "�ƾ�",
        "ʯ����",
        "�ƻ���",
        "�ⶹ��",
        "������",
        "����",
        "�׹�",
        "����",
        "����",
        "����",
        "��ͷ",
        "�ܲ�",
        "����",
        "���",
        "����",
        "��֦",
        "����",
        "ɽ��",
        "����",
        "����",
        "����",
        "����",
        "����",
        "���",
});

string *ids = ({
        "xian sun",
        "mo gu",
        "shan yao",
        "huang jing",
        "shihua cai",
        "huanghua cai",
        "bian doujiao",
        "jiang doujiao",
        "wang gua",
        "bai guo",
        "man qing",
        "qie zi",
        "dong gua",        
        "yu tou",
        "luo bo",
        "lin qin",
        "gan lan",
        "lian rou",
        "li zhi",
        "long yan",
        "shan li",
        "feng ling",
        "shi zi",
        "hu tao",
        "yin xing",
        "jin ju",
        "xiang cheng",        
});

void create()
{
  set_name("�Ϲ��߲�",({"guaguo shucai"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
 set("value", 100);
    set("food_remaining", 5);
    set("food_supply", 35);
    setup();
       }
}
void init()
{
  int i = random(sizeof(names));
  if( query("name") == "�Ϲ��߲�")
  set_name(names[i],({ids[i],"ggsc"}));
 ::init();
}
