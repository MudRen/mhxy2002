// myupdated.c by LitChi 2001/7/26

#include <ansi.h>
#define UPDATE_HOUR 1
inherit F_DBASE;

void updateit(string file);
int update_file(string file);

void create()
{
        seteuid( ROOT_UID );
        set("channel_id","��ʱ���¾���");
        remove_call_out("updateit");
          call_out( "updateit", 1, "/adm/daemons/choosed.c");
           call_out( "updateit", 5, "/daemon/skill/*.c");//open by tianlin �����Ҹ�cut��,Ϊ�˼���ϵͳ����,������ʱ��Ҳ����skillsû�б�ȫ������.�����ȸ���ͨ
}

void updateit(string file)
{
        int i;
        object obj, *inv;
        string err;
        string dir, result;
        object ob;
        mixed *files;
        object me = this_object();

        seteuid( ROOT_UID );

    message("channel:sys", HIG"��UPDATE��"BLK + "UPDATE���鿪ʼ����["+ file +"]������\n"NOR, users());
    dir = resolve_path(me->query("cwd"), file);

    if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' )   dir += "/";
    files = get_dir(dir, -1);

    dir = dir[0..strsrch(dir,"/",-1)];

    if( !sizeof(files) ){
        if (file_size(dir) == -2) return;
        else
            return;
    }

    result = "";
    
    for(i=0; i<sizeof(files); i++){
        files[i][0] = resolve_path(dir,files[i][0]);
          if(files[i][1] != -2) {
            if( file_size(files[i][0])==-1 )
               return;
            update_file(files[i][0]);
          }
    }
    message("channel:sys", HIG"��UPDATE��"BLK + "���������������"+ i +"���ļ����´α��뽫��" + UPDATE_HOUR + "��Сʱ��ʼ��\n"NOR, users());
//    remove_call_out("updateit");
    call_out( "updateit", UPDATE_HOUR * 3600, file);
}

int update_file(string file)
{
        int i;
        object obj, *inv;
        string err;
        
        if (obj = find_object(file)) destruct(obj);

        if (obj) return notify_fail("�޷�����ɳ�ʽ�롣\n");

//        message("channel:sys", HIG"��UPDATE��"BLK + "���±���"+ file + "��"NOR, users());
        err = catch( call_other(file, "???") );
        if (err)
                message("channel:sys", "��������"+ err +"\n"NOR, users());
        else 
//              message("channel:sys", "�ɹ���\n"NOR, users());

        return 1;
}
