// �ƽ�ʥ���ٻ� by LitChi 2001/8/12
#include <ansi.h>
inherit F_CLEAN_UP;

int help(object me);
int main(object me, string arg)
{
        object ob, *inv;
        string cloth_name, cloth_id;
        int i;
        
        if (!me->query("12gong/all") || me->query("12gong/number") < 12 )
          return notify_fail("��δ����ƽ�ʮ������\n");
        
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++) {
            if(inv[i]->query("id") == "huangjin shengyi") return notify_fail("�ƽ�ʥ�¾��������ϣ��㻹�ٻ�ʲô����\n");
        }       
        cloth_name = me->query("12gong/cloth_name");
        if(!cloth_name) cloth_name = "�ƽ�ʥ��";
        cloth_name = HIY+cloth_name+NOR;
        cloth_id = me->query("12gong/cloth_id");
        if(!cloth_id) cloth_id = "huangjin shengyi";
        
        ob = new("/d/12gong/obj/gold_cloth");
        ob->set_name(cloth_name,({cloth_id}));
        ob->setup();
        ob->move(me);
        message_vision("$N���һ�������ƽ�ʥ�¡�������������ֻ������г�����һ��$n��׼ȷ��������$N���ϣ�\n",me,ob);
        "/cmds/std/wear"->main(me,cloth_id);
        
        return 1;

}

int help(object me)
{
write(@HELP
ָ���ʽ : mycloth
 
��������˻ƽ�ʮ��������������������ٻ��Լ���ʥ�¡� 
 
HELP
    );
    return 1;
}

