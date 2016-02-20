#include <ansi.h>

inherit F_DBASE;

string *families = ({
  "��ѩɽ",
  "����ɽ���Ƕ�",
  "�¹�",
  "�Ϻ�����ɽ",
  "���޵ظ�",
  "��˿��",
  "������",
  "��������",
  "�ݿ�ɽ�޵׶�",
  "��ׯ��",
  "���ƶ�",
  "��ɽ��",
  "��ԯ��Ĺ",
  "���ƻʹ�",
  "�ڼ���",
  "�����",
  "���ù�",
  "Ů����",
  "����",
//  "����ɽ",
});

string *feizei=({"fei-putuo","fei-moon","fei-wzg","fei-shushan","fei-hyd",
    "fei-fangcun","fei-hell","fei-jjf","fei-pansi","fei-dragon", "fei-xueshan",
     "fei-wudidong", "fei-gumu",});

void create()
{
        seteuid(getuid());
        set("name","");
        remove_call_out("choose_npc");
call_out("choose_feizei",2);
}

void choose_feizei()
{
        int i, j ,k,ppl;
        object *list, newob;
        string str,m_name;
        string smp;
        smp  = "������ɽ֮��";                 
        j = random(sizeof(families));
        k = random(sizeof(families));
        newob = new(__DIR__+feizei[random(sizeof(feizei))]);
        newob->set("target",families[k]);
        newob->invocation( j );
        reset_eval_cost();
        
        switch(families[k])
        {
                case "����ɽ���Ƕ�":
                        m_name="��������(Master puti)";//
                        newob->carry_object("/u/tianlin/feizei/obj/stick");
                        break;
                case "�¹�":
                        m_name="����ĸ(Xi wangmu)";//
                        newob->carry_object("/u/tianlin/feizei/obj/whip");
                        break;
                case "���޵ظ�":
                        m_name="�ز�������(Dizang pusa)";//
                        newob->carry_object("/u/tianlin/feizei/obj/whip");
                        break;
                case "�ݿ�ɽ�޵׶�":
                        m_name="����(Yu shu)";//
                        newob->carry_object("/u/tianlin/feizei/obj/blade");
                        break;
                case "������":
                        m_name="�׷�����(lao ren)";//
                        newob->carry_object("/u/tianlin/feizei/obj/axe");
                           break;
                case "���ƶ�":
                        m_name="ţħ��(niumo wang)";//
                        newob->carry_object("/u/tianlin/feizei/obj/spear");
                        break;
                case "��ѩɽ":
                        m_name="��������(Dapeng mingwang)";//
                        newob->carry_object("/u/tianlin/feizei/obj/qin");
                        break;
                case "��ׯ��":
                        m_name="��Ԫ����(Zhenyuan daxian)";
                        if(random(2)) 
                        newob->carry_object("/u/tianlin/feizei/obj/staff");
                        else
                        newob->carry_object("/d/obj/drug/renshen-guo");
                        break;
                case "�Ϻ�����ɽ":
                        m_name="��������(Guanyin pusa)";//
                        newob->carry_object("/u/tianlin/feizei/obj/staff");
                        break;
                case "��������":
                        m_name="����(Ao guang)";//
                        newob->carry_object("/u/tianlin/feizei/obj/fork");
                        break;
                case "��˿��":
                        m_name="��ϼ����(zixia xianzi)";//
                        newob->carry_object("/u/tianlin/feizei/obj/whip");
                        break;
                case "��ɽ����":
                        m_name="��ɽ��ʥ(jian sheng)";//
                        newob->carry_object("/u/tianlin/feizei/obj/sword");
                        break;
                case "��ԯ��Ĺ":
                        m_name="槼�(Da ji)";//
                        newob->carry_object("/u/tianlin/feizei/obj/needle");
                        break;
                case "���ƻʹ�":
                        m_name="��̫��(tang taizong)";//
                        newob->carry_object("/u/tianlin/feizei/obj/mace");
                        smp = "���ƹ���";
                        break;
                case  "�ڼ���":
                        m_name="�ڼ�������(wuji guowang)";//
                        newob->carry_object("/u/tianlin/feizei/obj/kui");
                        smp = "�ڼ�������";
                        break;
                case  "�����":
                        m_name="���������(baoxiang guowang)";//
                        newob->carry_object("/u/tianlin/feizei/obj/magua");
                        smp = "���������";
                        break;
                case  "���ù�":
                        m_name="���ù�����(tianzhu guowang)";//
                        newob->carry_object("/u/tianlin/feizei/obj/pifeng");
                        smp = "���ù�����";
                        break;
                case  "Ů����":
                        m_name="Ů��������(nuer guowang)";//
                        newob->carry_object("/u/tianlin/feizei/obj/ring");
                        smp = "Ů��������";
                        break;
                case  "����":
                        m_name="��������(yuhua xianling)";//
                        newob->carry_object("/u/tianlin/feizei/obj/shoes");
                        smp = "���ع���";
                        break;
                        
            //    case "����ɽ":
            //          m_name="��ʥ��ʦ������(guoshiwang pusa)";
            //          newob->carry_object("/u/tianlin/feizei/obj/halberd");
            //          break;
        }
          message("system",HIG"��"+HIR+"����׷ɱ��"+HIG+"��"+HIW+m_name+HIG"�����������������"+smp+"�������Ӵ���"+families[j]+"һ��,ɱ���⡣\n"NOR,users());
 remove_call_out("choose_feizei");
call_out("choose_feizei",250);
       
}
