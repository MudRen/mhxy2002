// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// by mon

int valid_perform(object me, object target)
{    int pk_k, pk_v;   

//  if( userp(target) && userp(me) ) return notify_fail("Ŀǰ�ǰ�ȫ�գ���ֹPK\n");
     
     if(userp(target) && me->query_condition("no_pk_time")>240 
       && userp(me))
       return notify_fail("�����ɱ��̫�࣬��ʱ��Ȼ�����������أ��²�ȥ�֡�\n");

     return 1;
}

