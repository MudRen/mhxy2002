// jinian bei by tianlin@mhxy 2001/5/1

#include <ansi.h>

inherit ITEM;

void create()
{
           set_name(""CYN"��"NOR""RED"�λ����μ��"CYN"��"NOR"", ({"jinian bei", "bei" }));
        set("long", "�λ����εĸ���������������read������\n");
     set("no_get", "��������λ����ο�վ�ļ������͵�ߡ�\n");
}

void init()
{
  add_action("do_read","read");
}


int do_read(string type)
{
  if (! type)
    write("/adm/daemons/toptend"->query_type());
  else
 write("/adm/daemons/toptend"->topten_query(type));
return 1;

}
