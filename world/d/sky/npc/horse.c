// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */

inherit NPC;

string *names = ({
  "������",
  "������",
  "������",
  "������",
  "������",
  "׷����",
  "������",
  "������",
});

void create()
{
  set_name(names[random(sizeof(names))], ({"tian-ma","horse", "ma"}));
  set("race", "Ұ��");
  set("age", 20);
  set("long", "һƥ�����Ƽ��������,����ǧ��,ҹ�߰˰�,������(ride)��\n");
//  set("combat_exp", 50000);
  set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
//  set("verbs", ({ "bite"}));

 // set("chat_chance", 1);
 // set_skill("dodge", 100);
 // set_skill("parry", 100);
 // set_skill("unarmed", 100);
 // set("ride/msg", "��");
 // set("ride/dodge", 20+random(6));
 // set_temp("apply/dodge", 40);
 // set_temp("apply/attack", 40);
 // set_temp("apply/armor", 40);

  setup();
}
void init()
{
        add_action("do_ride", "ride");
}
int do_ride(string arg)
{
        object me = this_player();
        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
        if (this_player()->query_temp("marks/��") ) {
                       write("���Ѿ����������ˡ�\n");
                        return 1;
        }
        else {
               message("vision",this_player()->name() + "��������\n",
                        environment(me), ({me}) );
               write("��һ������,������,��ʽ��Ϊ������\n");
                this_player()->set_temp("marks/��", 1);
        return 1;
        }
}
