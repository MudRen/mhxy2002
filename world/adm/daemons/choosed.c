//By tianlin@Mhxy for 2001.12.30

#include <ansi.h>

inherit F_DBASE;

string *families = ({
  "����ɽ���Ƕ�",
  "�䵱��",
  "��ԯ��Ĺ",
  "��ɽׯ",
  "�¹�",
  "�Ϻ�����ɽ",
  "���޵ظ�",
  "������",
  "��������",
  "�ݿ�ɽ�޵׶�",
  "��ѩɽ",
  "��ׯ��",
  "��ɽ��",
  "��ʥ��",
  "����˧��",
  "��˿��",
  "���ƶ�",
  "���",
  "ħ��",
  "��ս�",
});
string *masters = ({
 "��������",
 "������",
 "槼�",
 "л����",
 "����ĸ",
 "��������",
 "�ز�������",
 "�׷�����",
 "����", 
 "�������",
 "��������", 
 "��Ԫ����",
 "��������", 
 "������", 
 "��˽�", 
 "��ϼ����", 
 "�Ʒɻ�", 
 "��Ҷ����ʦ", 
 "�޺�", 
  "������",
});
void create()
{
        seteuid(getuid());
        set("name","");
        remove_call_out("choose_npc");
        call_out("choose_npc",10);      

}

void choose_npc()
{
        int i, j ,k,ppl;
        object *list, newob;
        string str;
        list = users();
        i = sizeof(list);

        if (i < 10){
        remove_call_out("choose_npc");
        call_out("choose_npc",60);
        return;
        }

        j = random(sizeof(families));
        k = random(sizeof(families));
        while( i-- ) {
                if (!wizardp(list[i]) && list[i]->query("family/family_name") == families[j]
                && (list[i]->query("combat_exp") + list[i]->query("daoxing"))> 10000 )
                {
                newob = new("/u/tianlin/xinmo/npc");
                newob->set("target",families[k]);
                if(newob->invocation(list[i], k )) ppl++;
                else
                destruct(newob);
                }
        }
        reset_eval_cost();
        if (ppl)
        {
        if (j != k)
        message("system",NOR+HIM"��"NOR+HIW"�λ�����"NOR+HIM"��"NOR+CYN+masters[k]+"������"NOR+HIC+chinese_number(ppl)+NOR+CYN"��"
        NOR+RED+families[j]+NOR+CYN"�����ܵ�"NOR+HIY+families[k]+NOR+CYN"��ͷ���������£����ŵ������ٻ���֮��\n"NOR,users());
        else
        message("system",NOR+HIM"��"NOR+HIW"�λ�����"NOR+HIM"��"NOR+CYN+masters[k]+"����˵��"NOR+HIC+chinese_number(ppl)+NOR+CYN"��"
        NOR+HIY+families[j]+NOR+CYN"��Т�����ڱ������¡��뱾�ŵ����ٻ������Ż�!\n"NOR,users());
        remove_call_out("choose_npc");
        call_out("choose_npc",240);
        }
        else
        {
        message("system",NOR+HIM"��"NOR+HIW"�λ�����"NOR+HIM"��"NOR+CYN"������������ƺ���ƽ������������Ǹ������Ԥ�ס�����\n"NOR,users());
        remove_call_out("choose_npc");
        call_out("choose_npc",60);
        }
}

