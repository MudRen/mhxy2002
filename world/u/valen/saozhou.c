
inherit NPC;

void create()
{
    set_name("ɨ��", ({"sao zhou", "sao"}));
  set("under_water",1);

    set("long", "������һͷҰ�ޣ������㻯����һ�Ѵ�ɨ�㡣\n");
  set("race", "Ұ��");
  set("age", 10);
  set("age", 30);
  set("combat_exp", 200000);
  set("daoxing", 100000);

  set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
  set("verbs", ({ "bite"}));
  set("ride/msg", "��");
    set("ride/dodge", 120);
  set_temp("apply/attack", 80);
  set_temp("apply/armor", 80);

  setup();
}

�
