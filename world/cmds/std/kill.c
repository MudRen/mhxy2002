// by tianlin 2001/5/1
// �����Ż�,����һЩҪ�����
#include <ansi.h>
#include "valid_kill.h";

inherit F_CLEAN_UP;
void do_kill(object,object);

mapping kill=([]);
mapping query_kill() {return kill;}
void remove_list(string me, string obj);

int main(object me, string arg)
{
        object obj, guard_ob;
        string *killer, callname;
        int just_issued=0;

        if( !wizardp(me) && environment(me)->query("no_fight") )
                return notify_fail(HIY"���ﲻ׼ս����\n"NOR);

        if( !arg )
                return notify_fail(HIR"����ɱ˭��\n"NOR);

        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("����û������ˡ�\n");
        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail(CYN"�����һ�㣬�ǲ����ǻ��\n"NOR);

        if(wizardp(obj)&&!wizardp(me))//��Ҳ��ܶ�wiz��killָ��,��wiz���� 
                return notify_fail(""HIY"���"NOR"���ܶ�"HIC"��ʦ"NOR"��"HIR"Kill"NOR"ָ��!!\n");

        if (obj->query_temp("netdead")&&!wizardp(me))//��仰����Ҳ��ܶԶ��ߵ��˽���ս��wiz����
                return notify_fail("�㲻�ܶ�"HIG"����"NOR"��"HIY"���"NOR"����"HIR"ս��"NOR"��\n");

	 if(userp(obj) && obj->query("age")<16)
		  return notify_fail("�����к���ֻ��,�ͷŹ�С���Ӱɡ�\n");

if(me->query("combat_exp")<100000 && userp(obj))//��仰��С��50000 wx���˲���ɱ��
		  return notify_fail("�Լ�����û���þ���ɱ�ˣ�\n");

	 if(me->query("daoxing")<100000 && userp(obj))//��仰��С��50000 dx���˲���ɱ��
		  return notify_fail("�Լ�����û���þ���ɱ�ˣ�\n");	

        if(obj==me)//��仰��������Լ�ʹ��
                return notify_fail("�� suicide ָ���ȽϿ�:P��\n");

        if(!valid_kill(me,obj,0)) return 0;
        set_to_killer(me,obj);

        callname = RANK_D->query_rude(obj);

        //mon 5/29/99
        if(userp(me)) {
          string myid=me->query("id");
          string objid=obj->query("id");

          if(undefinedp(kill[myid])) {
            just_issued=0;
            kill+=([myid:({objid})]);
            call_out("remove_list",1,myid,objid);
          } else {
            string *targs=kill[myid];
            if(targs && member_array(objid,targs)!=-1) {
                // just issued kill on this target recently.
                just_issued=1;
            } else {
                // not issue kill recently.
                just_issued=0;
                if(!targs)
                    targs=({objid});
                else
                    targs+=({objid});
                kill[myid]=targs;
                call_out("remove_list",1,myid,objid);
            }
          }
        }

        if(just_issued==0) {
            message_vision("\n$N����$n�ȵ�����" 
                + callname + "�����ղ������������һ��\n\n", me, obj);        
        } else {
            // avoid too much screen rolling to the target.
            write("\n�����"+obj->name()+"�ȵ�����"
                    + callname + "�����ղ������������һ��\n\n");
                   
            return 1;
        }

        if( obj->query_temp("protected")
          && objectp(guard_ob=present(obj->query_temp("protect_ob"), environment(obj)))
          && (string)guard_ob->query_temp("protect")==obj->query("id")
          && guard_ob!=me ) {

message_vision(HIC"$N����$n����˵�������ڴˣ����õ��ģ�\n"NOR,guard_ob,obj);
                        message_vision(HIC"$N����ǰȥ��ס��$n�Ĺ�����\n"NOR, guard_ob, me);
                        guard_ob->kill_ob(me);
                        me->kill_ob(guard_ob);
                }


        do_kill(me, obj);

        return 1;
}
void do_kill(object me, object obj)
{

        me->kill_ob(obj);
        if( !userp(obj) ){
        
                if(!obj->accept_kill(me) )
                obj->kill_ob(me);

        } else if( !userp(me) ) {
                obj->kill_ob(me);
        } else {
                obj->kill_ob(me);
                tell_object(obj, HIR "�����Ҫ��" + me->name() 
                        + "�����ಫ������Ҳ���������һ�� kill ָ�\n" NOR);

        }

}

void remove_list(string me, string obj)
{
    string *targs;

    if(undefinedp(kill[me])) return;
    targs=kill[me];
    if(!targs || sizeof(targs)<2) {
        map_delete(kill, me);
    } else {
        targs-=({obj});
        kill[me]=targs;
    }
}

int help(object me)
{
  write(@HELP
ָ���ʽ : kill <����>
 
���ָ������������ʼ����һ��������ҡ���ɱ���Է���kill �� fight ����
��ͬ����˫�������浶ʵǹ�ش򶷣�Ҳ����˵����������ˡ����� kill ֻ�赥��
��һ����Ը�Ϳ��Գ������������κ���ʹ�� kill ָ��Ὺʼս����ͨ�����
�Է��� NPC �Ļ�������Ҳ��ͬ������ʹ�� kill��

�����˶���ʹ�� kill ָ��ʱ����ֺ�ɫ�����������㣬����һ����Ҷ��ԣ����
��û�ж�һ������ʹ�ù� kill ָ��Ͳ��Ὣ�Է���Ĵ��˻�ɱ��( ʹ�÷�����
��)��

�������ָ��: fight

�й� fight �� kill �������뿴 'help combat'.
HELP
    );
    return 1;
}
 

