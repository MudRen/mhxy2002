#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"ʥ�����"NOR);
        set("long", @LONG
��������ʥ��������,��֪��Ҫ�߶�ò��ܵ�ͷ,��������
����,��Ҳ�е���Щ�ߴ���ʤ������˼������Ŀ���Ҳ����
��Щϡ���ˣ����в��ߵ��˻��ǲ�Ҫ����ǰ���ĺá�
LONG
        );
        set("exits", ([
                "up" : __DIR__"shengdian6",
                "down" : __DIR__"shengdian4",
                "enter" : __DIR__"shenghan",
        ]) );
        set("coor/x",-1020);
        set("coor/y",-70);
        set("coor/z",-150);
        setup();
}

int valid_leave (object who, string dir)
{
  int to_die = who->query("daoxing") < 100000;

  to_die = 0;
  
  if (dir == "down")
    return 1;

  if (who->query("daoxing")>100000)
    return 1;

  switch (random(3))
  {
    case 0:
    {
      message_vision ("��ֻ������Ŀ���ʵ���ٵĿ�����һ��Ļ���ڵصĸо�����Ϯ����\n\n",who);
      message_vision ("$N��ǿ���˼�����ˤ���ڵء�\n",who);
      who->unconcious();

      if (to_die)
      {
        who->delete_temp("last_damage_from");
        who->set_temp("death_msg","��Ϊȱ�������ˡ�");
        who->die();
        who->save();
      }

      break;
    }
    case 1:
    {
      message_vision ("�е��������ڣ�Ҳ��֪������������⣡\n\n",who);
      message_vision ("$N��ǿ���˼�����ˤ���ڵء�\n",who);
      who->unconcious();
      if (to_die)
      {
        who->delete_temp("last_damage_from");
        who->set_temp("death_msg","����类�������ˡ�");
        who->die();
        who->save();
      }
      break;
    }
    case 2:
    {
      message_vision ("��Ȼ�Ǹߴ���ʤ��ѽ������\n\n",who);
      message_vision ("$N��ǿ���˼�����ˤ���ڵء�\n",who);
      who->unconcious();
      if (to_die)
      {
        who->delete_temp("last_damage_from");
        who->set_temp("death_msg","�����������ˡ�");
        who->die();
        who->save();
      }
      break;
    }
  }  
  if (!to_die)
    call_out ("moving",1,who);
  //return notify_fail("��һ���ת��������\n");
  return ::valid_leave(who, dir);
}

void moving (object who)
{
  who->move(__DIR__"shengdian3");        
}

