//By tianlin@mhxy for 2001.9.28
//�벻Ҫ�޸������ߵ�����лл.

#include <ansi.h>
inherit F_DBASE;
void create() 
{
        seteuid(getuid());
        set("channel_id", HIW"����"NOR+HIC"����"NOR+HIR"("NOR+HIY"clone"NOR+HIR")"NOR+HIG);
}

int main(object me, string arg)
{
   object obj;
   string err,msg,str,file,afile,flag;
   string filegold,filesilver,filecoin;
     int times;
    filegold="/clone/money/gold.c";
    filesilver="/clone/money/silver.c";
    filecoin="/clone/money/coin.c";

    if ( !arg )
        return notify_fail("[1;30mָ���ʽ:[2;37;0m [36mclone [1;33m<����> \n"NOR);
    if (sscanf(arg, "%s %d", file, times) != 2)
    {
        file = arg;
        times = 1;
    }
        seteuid( geteuid(me) );
        if (!file) file = me->query("cwf");
        if (!file)
                return notify_fail(HIY"��Ҫ����ʲ�������\n"NOR);
        flag = "";
        if( sscanf( file, "%s %s", flag, afile ) == 2 && flag == "-f" )
        file = afile;
        file = resolve_path(me->query("cwd"), file);
        if( sscanf(file, "%*s.c") != 1 ) file += ".c";
        me->set("cwf", file);

        if( file_size(file) < 0 )
                return notify_fail(YEL"û���������(" + file + ")��\n"NOR);

              if(this_player()->query("id")=="yinbin")
                return notify_fail(HIC"���������������˲���ʹ�ô����\n"NOR);//��������idʹ�ô�ָ��
        if( !find_object(file) ) {
                err = catch(call_other(file, "???"));
                if (err) {
                        write("����ʧ�ܣ�" + err + "\n");
                        return 1;
                }
        }
        if( file->query_unique() )  {
           write("Ŀǰ�ڣͣ�������"+file->query_number()+
                        "�����ƣ�Ӧ�����"+
                        file->query_compare_number()+"����\n");
        if( file->in_mud() && flag != "-f" )  {
        write("����ƷΪ" + HIR + "Unique Item" + NOR + "������ clone -f ��ǿ�и��ơ�\n");
        return 1;
        }
        }

        err = catch(obj = new(file));
        if (err) {
                write("����ʧ�ܣ�" + err + "\n");
                return 1;
        }
        
         if ((!(file==filegold) && !(file==filesilver) &&
                 !(file==filecoin)) && (times>10))
        {
                return notify_fail(BLINK+HIR"STOP"NOR+HIR"��"NOR+BLINK+HIR"STOP"NOR+HIR"��"NOR+HIW"���ֻ�ܸ���"NOR+HIC"10"NOR+HIW"����λ��\n"NOR);
        }
        else
                if (times>100)
                {
                return notify_fail(HIM"�����ǲ������ϣ���Ǯ���ֻ�ܸ���"NOR+HIY"100"NOR+HIM"����λ!\n"NOR);
                }          
        
        if( !stringp(msg = me->query("env/msg_clone")) )
                msg = "ֻ��$N�������һָ�������$n��\n";
        str = me->query("name") + "(" + me->query("id") + ")������" + 
                times + "��" + obj->query("name")
                + "(" + obj->query("id") + ")    " + ctime(time())+ "  ��\n";
        write_file("/log/cmds/clone", str);  
        CHANNEL_D->do_channel(this_object(),"sys",me->query("name")+
                "("+me->query("id")+")������" + 
                  times + "��" + obj->query("name")
                  + "(" + base_name(obj) + ")  ��\n");


       if (!obj->is_character()){
       for (int i = times;i>0;i--) {
         obj = new(file);
         obj->move(me);
       }
                write(times + "��" +obj->query("name") + "���Ƴɹ������������Ʒ����\n");
        message_vision(msg + "\n", me, obj);
                return 1;
        }
       for(int j = times; j>0; j--) {
          obj=new(file);
          obj->move(environment(me));
       }
                write(times + "��" + obj->query("name") + "���Ƴɹ�������������䡣\n");
        message_vision(msg + "\n", me, obj);
                return 1;

        destruct(obj);
        return notify_fail(CYN"�޷����Ʋ����ƶ������(" + file + ")��\n"NOR);
       }

int help(object me)
{
  write(@HELP
ָ���ʽ : clone [1;33m<����>[2;37;0m

���ô�ָ��ɸ����κ����ƶ�֮���(������),
��Ʒ,����,Ҳ����npc,obj���͵Ķ�����
[4;53m[1;31mBy tianlin@mhxy for 2001.9.28����[2;37;0m
HELP
    );
    return 1;
}
