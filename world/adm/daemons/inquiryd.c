//By tianlin@Mhxy for 2001.12.30
#include <ansi.h>

int parse_inquiry(object me, object ob, string topic)
{
	switch( topic ) {
		case "name":
			message_vision( CYN "$N��$n�ʵ�������" + RANK_D->query_respect(ob)
				+ "���մ�����\n" NOR, me, ob);
			return 1;
		case "here":
			message_vision(CYN "$N��$n�ʵ�����λ" + RANK_D->query_respect(ob)
				+ "��" + RANK_D->query_self(me) + "�����󱦵أ���֪������Щʲ��������飿\n" NOR,
				me, ob);
			return 1;
		case "news":
			message_vision(CYN "$N��$n�ʵ�����λ" + RANK_D->query_respect(ob)
				+ "����֪�����û����˵ʲô���µ���Ϣ��\n" NOR, me, ob);
                    return 1;
              case "rumors":
                    message_vision(CYN "$N��$n�ʵ�����λ" + RANK_D->query_respect(ob)
                           + "����֪�����û����˵ʲô��Ϣ��\n" NOR, me, ob);
                    return 1;
		case "all":
                    message_vision(CYN "$N��$n�ʵ�����λ" + RANK_D->query_respect(ob)
                           + "���㶼֪��Щʲô����ѽ��\n" NOR, me, ob);
                    return 1;
		default:
                    return 0;
	}
}