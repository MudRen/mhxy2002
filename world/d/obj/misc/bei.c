//create by guoth

#include <ansi.h>

inherit ITEM;

void create()
{
   set_name( HIG "��"+HIC+"��ʦ���"+HIG+"��" NOR , ({ "jinian bei" }) );
   set_weight(200000);
   set("long", @LONG
����Ϊ���μǵĴ���Ӣ���������ļ��
���������ǵ����֣�

            ��:  ( elva   )
            ��: С    �� (tianlin )
            ��: ˮ �� �� (lovechao)
            ��: ���С�� ( pkyou  )
            ��: �������� (  momo  )
            ��: ��    Ե (stygian )
            ��: С    ѩ (xiaoxue )

         ϣ����Ҳ�ܳ�Ϊ������е�һԱ
LONG);
       if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "stone");
                set("value", 2000);
                set("no_get", 1);
                set("amount",30);
        }
 
            setup();
}

