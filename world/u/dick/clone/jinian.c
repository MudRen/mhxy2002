// by snowcat 11/22/1997

#include <armor.h>

inherit NECK;

void create()
{
  set_name("�����", ({ "jinianbi","neck","bi" }));
  set("weight", 1);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
     set("value",0);            //this is mainly to prevent selling

        // these are quite important in my opinion, since we don't want
        // a highhand to get a fabao, then give it to his new character.
        // this fact is particularly important since the fabao is usually
        // unique which means once one person has it, there will not be
        // another copy in the mud.
   set("material", "gold");
    set("armor_prop/armor", 1);
  set("armor_prop/intelligence", 10);
      set("armor_prop/personality", 1);
 set("no_drop","��ô�õı�����˶��ϧѽ��\n");
        
set("long","�Ż��п�վ�����!\n");       
set("no_sell", 1);   
}
  setup();
}