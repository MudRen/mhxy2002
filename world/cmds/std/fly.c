//by tianlin@mhxy for 2001.9.30
//���¸�д,�벻Ҫ��!

#include <ansi.h>

int main(object me, string arg)
{
	string loc;
        int mana_cost;
	object ridee, map;
	string ridemsg;

        seteuid(getuid());

        if( me->is_fighting() )
                return notify_fail("������ս�����ɲ�����\n");
        if( me->is_busy() || me->query_temp("pending/exercising"))
                return notify_fail("����æ���أ�û�������Ƽ���\n");
	if( !wizardp(me) && !environment(me)->query("outdoors") )
		return notify_fail("��Χû��һƬ�ƣ�û�취���Ƽ���\n");
	if( me->is_ghost() )
		return notify_fail("[34m���˹��ˣ�����ʵ��ɣ�[2;37;0m\n");
        if( !arg )
                return notify_fail("��Ҫ�ɵ�����ȥ��\n");
	if( me->query_temp("no_move") )
	    return notify_fail("�㱻��ס�ˣ�����ɵ�������\n");

	if( RANK_D->grade_dx( RANK_D->describe_dx( (int)me->query("daoxing") ) ) 
		< RANK_D->grade_dx(BLU "�������" NOR) )
	{
		message_vision(HIY
"$N��������һ�����ƺ���������������ز������߾�һ�����Դ�ˤ��������\n"
NOR, me);
		return notify_fail("�����ڻ����������̸���ϣ�����ɵ�������\n");
	}

	if( RANK_D->grade_fali( RANK_D->describe_fali( (int)me->query("max_mana") ) ) 
		< RANK_D->grade_fali(HIB "���Ƽ���" NOR) )
	{
		message_vision(HIY
"$N��������һ�����ƺ���������������ز������߾�һ�����Դ�ˤ��������\n"
NOR, me);
		return notify_fail("��������ķ�����Ϊ���������Ƽ���\n");
	}

	if( (int)me->query("mana") < 200 )
	{
		message_vision(HIY
"$N��������һ�����ƺ���������������ز������߾�һ�����Դ�ˤ��������\n"
NOR, me);
		return notify_fail("��Ŀǰ����������ӯ��\n");
	}


        if( (int)me->query("sen") * 100 / (int)me->query("max_sen") < 50 )
                return
notify_fail("������ͷ�Բ�̫���ѣ����ĵ�����ˤ����\n");

        if( (int)me->query("kee") * 100 / (int)me->query("max_kee") < 50 )
                return
notify_fail("��������������������ƺ��е㲻֧��\n");

        mana_cost=-(100-(int)me->query_skill("spells"))/4-40;
        if(mana_cost > 0) mana_cost=0;

          if( (string)me->query("family/family_name") == "�ݿ�ɽ�޵׶�") {
                  message_vision(HIB"ֻ��ƽ�����Ȼ����һ�����磬��$N������ס��\n"+
  "��̼�$N����ȥ����ʧ����Ӱ���١� \n\n"NOR, me);
}
           if( (string)me->query("family/family_name") == "������") {
      message_vision(HIY"$N��������һָ��ֻ�����Ͻ���һ��������ƣ�\n"+
"$N����Ծ�ϣ�������Ʈҡ��ȥ......\n\n"NOR, me);
}
        if( (string)me->query("family/family_name") == "���޵ظ�") {
                message_vision(CYN"$N���ڰ���һָ��ֻ����ָ֮���·����һ���ţ�\n"+
"$N�����룬��Ҳ��֮��ʧ�� \n\n"NOR, me);
              }
        if( (string)me->query("family/family_name") == "����ɽ���Ƕ�") {
                message_vision(HIG"$N����ھ�����������ԣ����һ��������ƣ�����\n"+
"ֻ�����Ͻ���һ����ɫ�Ʋʣ�$N����Ծ�ϣ��ɳ۶�ȥ......\n\n"NOR, me);
              }
        if( (string)me->query("family/family_name") == "�¹�") {
                message_vision(HIM"$N����һЦ����Ȼ���裬����һ���㣬����ʧ���¹��С�\n"NOR, me);
              }
        if( (string)me->query("family/family_name") == "��ʥ��") {
                message_vision(HIY"$N˫�۽��棬Ĭ������һ���������������$N����ʧ�ڹ����С�\n"NOR, me);
              }
        if( (string)me->query("family/family_name") == "��ׯ��") {
                message_vision(HIB"$N����һ�ڣ�ֻ��������ӿ�����ѽ����֮���ڿ��д���ȥ��\n"NOR, me);
              }
        if( (string)me->query("family/family_name") == "��ѩɽ") {
                message_vision(HIW"$N����һ�ӣ�ֻ��һ��ѩ���ס������ת��ȥ�� \n"NOR, me);
              }
        if( (string)me->query("family/family_name") == "�Ϻ�����ɽ") {
                message_vision(HIY"$N�������ŷ�ţ������������ƣ�������ط�ȥ��  \n"NOR, me);
              }
        if( (string)me->query("title/title_name") =="��ͨ����") {
                message_vision(BLU"$N������:����������,������ۡ����һ�̡�.һ�����紵��,$N��ʧ����Ӱ����....\n"NOR, me);
        }
        if( (string)me->query("family/family_name") =="���") {
                message_vision(MAG"$N�����ͳ�������,������ּ�,��������Զ,������һƬ���䣬�������ޱߵļ�į..\n"NOR, me);
        }
        if( (string)me->query("family/family_name") =="ħ��") {
                message_vision(RED"����ħ���Σ���ħ��Ӱ����ħ���١��������������꣬$N��Ϊһ��"NOR+HIR"���"NOR+RED"����˼�..\n"NOR, me);
        }
        if( (string)me->query("family/family_name") =="��ս�") {
                message_vision(HIB"$N���������Լ����ػ��ޣ�Ծ���ػ��޵ĺ󱳣�������ȥ��\n"NOR, me);
        }
        if( (string)me->query("family/family_name") == "��������") {
                message_vision(HIC"$Nҡ��һ�䣬�ֳ�ԭ�Σ�����һ���������漴���ƶ�ȥ�� \n"NOR, me);
              }
        if( (string)me->query("family/family_name") == "���ƶ�") {
              message_vision(RED"$N������ھ������������,ͻȻ���䡱��ð��һ�ź���,$N�漴��������С�\n"NOR, me);
              }
        if( (string)me->query("family/family_name") == "��ʯɽ�̲�̶") {
              message_vision(CYN"$Nҡ��һ�䣬�ֳ�ԭ�Σ�����һ���������漴���ƶ�ȥ�� \n"NOR, me);
              }
        if( (string)me->query("family/family_name") == "����˧��") {
              message_vision(WHT"$N���д�һ��: ������. . .������̤��һ��"HIR"��"HIM"��"HIC"��"HIY"��"NOR WHT"������ʡ� \n"NOR, me);
              }
        if( (string)me->query("family/family_name") == "�䵱��") {
              message_vision(HBRED+HIW"$N�������˼���ھ�,����һ��"NOR+HBBLU HIY"��̫��ʮ��ʽ��"NOR+HBRED+HIW",��������ȥ..... \n"NOR, me);//By tianlin@mhxy for 2001.9.30����
              }
        if( (string)me->query("family/family_name") == "��ɽׯ") {
              message_vision(WHT"$N�������˼���ھ�,ֻ�����Ϸ��������Ľ����������˽�ȥ.\n"NOR, me);//By tianlin@mhxy for 2001.12.14����
              }
        if( (string)me->query("family/family_name") == "������") {
              message_vision(WHT"$N���д�һ��: ������. . .������̤��һ��"HIR"��"HIM"��"HIC"��"HIY"��"NOR WHT"������ʡ� \n"NOR, me);
              }
         if( (string)me->query("family/family_name") == "��ɽ��") {
             message_vision(HIC"$N������ھ����ӳ�һ�ѱ�����$N�ɳ۶��ϣ�һ�С��������С���Զ����ȥ��������\n"NOR, me);
              }
        if( (string)me->query("family/family_name") == "��˿��") {
             message_vision(MAG"$N����ᶶ������һ���ʺ���������,$N�������ƮȻ����,ϼ��һ��,�ʺ���ʧ����Ӱ���١�\n"NOR, me);
              }
        if((string)me->guery("family/family_name") == "��������"){
             message_vision(HBYEL+HIB" $N����һ�䣬���д�һ�� ���� ��$N�������Լ��������������ãã�˺���ʧ�Ĳ����ۼ���\n"NOR, me); 
              }

        me->add("mana", mana_cost);

        if(arg=="stone") loc="/d/dntg/hgs/entrance";
        else if(arg=="kaifeng") loc="/d/kaifeng/tieta";
        else if(arg=="moon") loc="/d/moon/ontop2";
        else if(arg=="lingtai") loc="/d/lingtai/gate";
        else if(arg=="putuo") loc="/d/nanhai/gate";
        else if(arg=="changan") loc="/d/city/center";
        else if(arg=="sky") loc="/d/dntg/sky/nantian";
	 else if(arg=="wuzhuang") loc="/d/qujing/wuzhuang/gate";
	 else if(arg=="meishan") loc="/d/meishan/erlangwai";
        else if(arg=="wudang") loc="/d/wudang/xuanyuegate";
        else if(arg=="lingjie") loc="/d/lingjie/rukou";
//        else if(arg=="shenjian") loc="/d/shenjian/wuc";
        else if(arg=="shaolin") loc="/d/southern/shaolin/simen";//by tianlin@mhxy for 2001.9.27�޸�
        else if(arg=="wudangshan") loc="/d/wudang1/guangchang";//by tianlin@mhxy for 2001.9.25����wudang��
        else if(arg=="33tian") loc="/d/33tian/33tian";//by tianlin 2001.7.1
      else if(arg=="shushan") loc="/d/shushan/shanmen";
              else if(arg=="penglai") {
		if(!(map=present("eastsea map", me)) && !wizardp(me)) {
			write("��������ת�˰���Ҳ��֪�����Ǳ߷ɡ�����\n");
			message_vision("\n$Nʧ���ش���������������\n", me);
			return 1;
			}
		if( !wizardp(me)&&(string)map->query("unit")!="��" ){
			write("��������ת�˰���Ҳ��֪�����Ǳ߷ɡ�����\n");
                        message_vision("\n$Nʧ���ش���������������\n", me);
                        return 1;
                        }
//		write("����������򶫱ߺ��з�ȥ������\n\n");
		loc="/d/penglai/penglai";
	}
//by tianlin 2001.7.17�����޸�xueshan��fly xueshan����map
	else if(arg=="xueshan") {
		if(!(map=present("xueshan map", me)) &&(string)me->query("family/family_name")!="��ѩɽ"&& !wizardp(me)){
			write("��������ת�˰���Ҳ��֪�����Ǳ߷ɡ�����\n");
			message_vision("\n$Nʧ���ش���������������\n", me);
			return 1;
			}
		if( !wizardp(me)&&(string)me->query("family/family_name")!="��ѩɽ"&&(string)map->query("unit")!="��" ){
                        write("��������ת�˰���Ҳ��֪�����Ǳ߷ɡ�����\n");
                        message_vision("\n$Nʧ���ش���������������\n", me);
                        return 1;
                        }
		loc="/d/xueshan/binggu";
	}
//By tianlin@mhxy for 2002.1.10,����ֻ��shenjian�ĵ��ӿ���fly shenjian
	else if(arg=="shenjian") {
		if((string)me->query("family/family_name")!="��ɽׯ"&& !wizardp(me)){
			write(HIC"����������������룬��������ȥ��ɽׯ��·��!\n"NOR);
			message_vision(HIY"\n$N��������������,�ǳ�ʧ����\n"NOR, me);
			return 1;
			}
		if( !wizardp(me)&&(string)me->query("family/family_name")!="��ɽׯ"){
                        write("��������ת�˰���Ҳ��֪�����Ǳ߷ɡ�����\n");
                        message_vision("\n$Nʧ���ش���������������\n", me);
                        return 1;
                        }
		loc="/d/shenjian/wuc";
	}
	else if(arg=="wusheng"){
		loc = "/d/wusheng/room1.c";
		loc[strlen(loc)-3] = '1'+random(4);
	}
	else if(arg=="baoxiang"){
		loc = "/d/qujing/baoxiang/bei1.c";
		loc[strlen(loc)-3] = '1'+random(4);
	}else if(arg=="pingding"){
		loc = "/d/qujing/pingding/ping1.c";
		loc[strlen(loc)-3] = '1'+random(4);
	}else if(arg=="yalong"){
		loc = "/d/qujing/pingding/yalong1.c";
		loc[strlen(loc)-3] = '1'+random(3);
	}else if(arg=="wuji"){
		loc = "/d/qujing/wuji/square.c";
		//loc[strlen(loc)-3] = '1'+random(9);
	}else if(arg=="chechi"){
		loc = "/d/qujing/chechi/jieshi1.c";
		loc[strlen(loc)-3] = '1'+random(9);
	}else if(arg=="tongtian"){
		loc = "/d/qujing/tongtian/hedong1.c";
		loc[strlen(loc)-3] = '1'+random(6);
	}else if(arg=="jindou"){
		loc = "/d/qujing/jindou/jindou1.c";
		loc[strlen(loc)-3] = '1'+random(4);
	}else if(arg=="nuerguo"){
		loc = "/d/qujing/nuerguo/towna1.c";
		/*
		if (me->query("obstacle/nuerguo")!="done" && !wizardp(me)){
			write("\nһ�����㶫������ش��˻�����\n");
			write("�����ӷɲ���ȥ��\n");
			return 1;
			}
		*/
		loc[strlen(loc)-4] = 'a'+random(3);
		loc[strlen(loc)-3] = '1'+random(3);
	}else if(arg=="dudi"){
		loc = "/d/qujing/dudi/dudi1.c";
		loc[strlen(loc)-3] = '1'+random(4);
	}else if(arg=="huangfeng"){
                loc = "/d/qujing/huangfeng/huangfeng1.c";
		loc[strlen(loc)-3] = '1'+random(7);
        }else if(arg=="baigudong"){
                loc = "/d/qujing/baigudong/sroad1.c";
                loc[strlen(loc)-3] = '1'+random(6);
       }else if(arg=="shuangcha"){
		loc = "/d/qujing/shuangcha/shanlu1.c";
		loc[strlen(loc)-3] = '1'+random(5); 
       }else if(arg=="liusha"){
         	loc = "/d/qujing/liusha/river.c";
       }else if(arg=="heifeng"){
		loc = "/d/qujing/heifeng/road1.c";
		loc[strlen(loc)-3] = '1'+random(4);
       }else if(arg=="yingjian"){
		loc = "/d/qujing/yingjian/xiaolu1.c";
		loc[strlen(loc)-3] = '1'+random(4); 
        }else if(arg=="firemount"){
         	loc = "/d/qujing/firemount/cuiyun1.c";
		loc[strlen(loc)-3] = '1'+random(5);
	}else if(arg=="jilei"){
		loc = "/d/qujing/jilei/jilei1.c";
		loc[strlen(loc)-3] = '1'+random(3);
	}else if(arg=="jisaiguo"){
		loc = "/d/qujing/jisaiguo/east1.c";
		loc[strlen(loc)-3] = '1'+random(4);
	}else if(arg=="jingjiling"){
		loc = "/d/qujing/jingjiling/jingji1.c";
	}else if(arg=="xiaoxitian"){
		loc = "/d/qujing/xiaoxitian/simen.c";
        }else if(arg=="zhuzi"){
         	loc = "/d/qujing/zhuzi/zhuzi1.c";
		loc[strlen(loc)-3] = '1'+random(5);
        }else if(arg=="qilin"){
         	loc = "/d/qujing/qilin/yutai.c";
        }else if(arg=="pansi"){
         	loc = "/d/qujing/pansi/ling1.c";
		loc[strlen(loc)-3] = '1'+random(6);
        }else if(arg=="biqiu"){
         	loc = "/d/qujing/biqiu/jie1.c";
		loc[strlen(loc)-3] = '1'+random(9);
        }else if(arg=="qinghua"){
         	loc = "/d/qujing/biqiu/zhuang.c";
	}else if(arg=="wudidong"){
		loc = "/d/qujing/wudidong/firemount-wudidong3.c";
		loc[strlen(loc)-3] = '1'+random(3);
        }else if(arg=="qinfa"){
         	loc = "/d/qujing/qinfa/jiedao1.c";
		loc[strlen(loc)-3] = '1'+random(8);
        }else if(arg=="yinwu"){
         	loc = "/d/qujing/yinwu/huangye1.c";
        }else if(arg=="fengxian"){
         	loc = "/d/qujing/fengxian/jiedao1.c";
		loc[strlen(loc)-3] = '1'+random(9);
        }else if(arg=="yuhua"){
         	loc = "/d/qujing/yuhua/xiaojie1.c";
		loc[strlen(loc)-3] = '1'+random(9);
        }else if(arg=="baotou"){
         	loc = "/d/qujing/baotou/shanlu1.c";
		loc[strlen(loc)-3] = '1'+random(9);
        }else if(arg=="zhujie"){
         	loc = "/d/qujing/zhujie/shanlu11.c";
		loc[strlen(loc)-3] = '1'+random(8);
        }else if(arg=="jinping"){
         	loc = "/d/qujing/jinping/xiaojie1.c";
		loc[strlen(loc)-3] = '1'+random(7);
        }else if(arg=="qinglong"){
         	loc = "/d/qujing/qinglong/shanjian.c";
        }else if(arg=="tianzhu"){
         	loc = "/d/qujing/tianzhu/jiedao11.c";
		loc[strlen(loc)-3] = '1'+random(8);
        }else if(arg=="maoying"){
         	loc = "/d/qujing/maoying/shanpo1.c";
		loc[strlen(loc)-3] = '1'+random(9);
        }else if(arg=="lingshan"){
         	loc = "/d/qujing/lingshan/dalu1.c";
		loc[strlen(loc)-3] = '1'+random(3);
        }else{
                write("\n\n���ˣ��㰴����ͷ����������\n");
                write("�ף���������ô����ԭ���ĵط���\n");
                return 1;
        }

	if (! loc)
		return 1;
		
	// mon /10/18/98
	if(MISC_D->random_capture(me,0,1)) return 1;

	if (ridee = me->ride()) {
	  ridemsg = ridee->query("ride/msg")+"��"+ridee->name();
	  ridee->move(loc);
	}  
	else  
	  ridemsg = "";
	                                            	
	me->move(loc);
       write("\n\n���ˣ��㰴����ͷ����������\n");

          if( (string)me->query("family/family_name") == "�ݿ�ɽ�޵׶�") {
message_vision(HIB"\n��Ȼ�����һ�����磬�羡����$N���˳����� \n"
  NOR, me);
}
           if( (string)me->query("family/family_name") == "������") {
   message_vision(HIY"\nֻ������Ʈ��һ��������ƣ�$N�����ƶ����˳����� \n"
  NOR, me);
}
        if( (string)me->query("family/family_name")=="���޵ظ�") {
                message_vision(CYN"\n��Ӱ�д���һ����磬��������ɭɭ��Ц����$N"+ridemsg+"�����Ȱ�Ӻڰ��г��֡� \n"
NOR, me);

        }
            if( (string)me->query("family/family_name")=="����ɽ���Ƕ�") {
                message_vision(HIG"\nֻ�������ϴ���һ����������Ҳ����������������$N"+ridemsg+"�ӽ����ȽȽ���¡�\n"
NOR, me);
            }
            if( (string)me->query("family/family_name")=="�¹�") {
                message_vision(HIM"\nֻ��һ���¹���������ǰ������ģ�����ģ�$N"+ridemsg+"����ƮȻ������ \n"
NOR, me);
        }
            if( (string)me->query("family/family_name")=="��ׯ��") {
                message_vision(HIB"\nһ����紵����$N"+ridemsg+"�ӿ��н��䡣 \n"
NOR, me);
        }
            if( (string)me->query("family/family_name")=="��ѩɽ") {
                message_vision(HIW"\n��ʱ�䣬��ѩ�׷ɣ�$N"+ridemsg+"���羧Ө��͸��ѩ�����Ʈ�¡� \n"
 NOR, me);
        }
            if( (string)me->query("family/family_name")=="�Ϻ�����ɽ") {

                message_vision(HIY"\nһ�������ġ����ް����ӷ𡱣�$N"+ridemsg+"�ӷ���У��������߳��� \n"
NOR, me);
        }
        if( (string)me->query("title/title_name") =="��ͨ����") {
                message_vision(BLU"�������,$N���˳���.......\n"NOR, me);
        }
        if( (string)me->query("family/family_name") =="���") {
                message_vision(MAG"΢������,$N"+ridemsg+"�ֳ�һ�ѻ�Ԫ��������ɡ�������˳���������һ˿�����¼�..........\n"NOR, me);
        }
        if( (string)me->query("family/family_name") =="ħ��") {
                message_vision(RED"һ��"+HIR"���"NOR+RED"$N"+ridemsg+"ƾ�ճ��֣�ϸ����Ȼ����һ������...\n"NOR, me);
        }
        if( (string)me->query("family/family_name") =="��ս�") {
                message_vision(HIB"һ���Х������$N"+ridemsg+"����ս���ػ����ޱ�����������..... \n"NOR, me);
        }
            if( (string)me->query("family/family_name")=="��������") {
                message_vision(HIC"\n����з·���һ��ˮ����$N"+ridemsg+"��ˮ��������������¡�  \n"
NOR, me);
        }
            if( (string)me->query("family/family_name")=="���ƶ�") {
                message_vision(RED"\nһ�ź�ɫ������ӿ�˹���,$N"+ridemsg+"ͻȻ��������˳���. \n"
NOR, me);
        }
        if( (string)me->query("family/family_name") == "��ʯɽ�̲�̶") {
              message_vision(CYN"\n����з·���һ��ˮ����$N"+ridemsg+"��ˮ��������������¡�  \n"
NOR, me);
              }
        if( (string)me->query("family/family_name") == "����˧��") {
              message_vision(WHT"\n�Ʋʳ�������ʣ�$N"+ridemsg+"һ����������������  \n"
NOR, me);
              }
        if( (string)me->query("family/family_name") == "�䵱��") {
              message_vision(HBRED HIW"\nͻȻ������䣬$N"+ridemsg+"�������˹�����  \n"
NOR, me);
              }
        if( (string)me->query("family/family_name") == "��ɽׯ") {
              message_vision(WHT"\nͻȻ����г����������꣬$N"+ridemsg+"�ӽ��������˹�����  \n"
NOR, me);
              }
        if( (string)me->query("family/family_name") == "������") {
              message_vision(WHT"\n�Ʋʳ�������ʣ�$N"+ridemsg+"һ����������������  \n"
NOR, me);
              }
            if( (string)me->query("family/family_name")=="��ɽ��") {
                message_vision(HIC"\nһ����������,$N"+ridemsg+"�ӽ������������� \n"
NOR, me);
        }        
            if( (string)me->query("family/family_name") == "��˿��") {
                message_vision(MAG"\n����һ���ʺ����ջ�����$N"+ridemsg+"��ʺ�ƮȻ������ \n"
NOR, me);
        }
            if( (string)me->query("family/family_name") == "��ʥ��") {
                message_vision(HIY"\nֻ������һ����Х��$N"+ridemsg+"��һ������ƮȻ������ \n"
NOR, me);
        }
            if( (string)me->query("family/family_name") == "��������"){
                message_vision(HBYEL+HIB"\n����������ž���������$N"+ridemsg+"��������һ�������\n"NOR, me);
        }
                 return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : fly|fei [Ŀ�ĵ�]

����ĵ��кͷ�����ǿʱ����������Ƽ���

Ŀǰ����Էɵ��ĵط���
[33mchangan[2;37;0m         ->[37m������                 [33mkaifeng[2;37;0m        ->[37m�����
[33mstone[2;37;0m           ->[37m����ɽ��ʯ             [33msky[2;37;0m            ->[37m������
[33mmoon[2;37;0m      	->[37m����ɽ�¹�             [33mpenglai[2;37;0m        ->[37m�����ɵ�
[33mlingtai[2;37;0m         ->[37m��̨����ɽ    	 [33mputuo[2;37;0m     	->[37m�Ϻ�����ɽ
[33mxueshan[2;37;0m	        ->[37m��ѩɽ������           [33mmeishan[2;37;0m        ->[37m÷ɽ�཭��
[33mwuzhuang[2;37;0m        ->[37m����ɽ��ׯ��           [33mshushan[2;37;0m        ->[1;32m��֮����ɽ[2;37;0m
[33mwusheng[2;37;0m	        ->[37m��ʥ��                 [33m33tian[2;37;0m           ->[37m���ʹ�
[33mlingjie[2;37;0m	        ->[37m���                 


[33mbaoxiang[2;37;0m	->[37m�����		 [33mpingding[2;37;0m  	->[37mƽ��ɽ
[33myalong[2;37;0m    	->[37mѹ��ɽ 		 [33mwuji[2;37;0m           ->[37m�ڼ���
[33mchechi[2;37;0m		->[37m���ٹ� 		 [33mtongtian[2;37;0m	->[37mͨ���
[33mjindou[2;37;0m  	->[37m��ɽ 		 [33mnuerguo[2;37;0m	->[37mŮ����
[33mdudi[2;37;0m   		->[37m����ɽ 		 [33mfiremount[2;37;0m	->[37m����ɽ
[33mjilei[2;37;0m    	->[37m����ɽ 		 [33mjisaiguo[2;37;0m	->[37m������
[33mjingjiling[2;37;0m	->[37m������		 [33mxiaoxitian[2;37;0m	->[37mС����
[33mzhuzi[2;37;0m		->[37m���Ϲ�		 [33mqilin[2;37;0m		->[37m����ɽ
[33mpansi[2;37;0m		->[37m��˿��		 [33mbiqiu[2;37;0m		->[37m����� 
[33mqinghua[2;37;0m		->[37m�廪ׯ		 [33mwudidong[2;37;0m       ->[37m�޵׶�
[33mqinfa[2;37;0m           ->[37m�շ���		 [33mfengxian[2;37;0m	->[37m���ɿ� 
[33myinwu[2;37;0m    	->[37m����ɽ		 [33myuhua[2;37;0m   	->[37m���� 
[33mbaotou[2;37;0m  	->[37m��ͷɽ		 [33mzhujie[2;37;0m  	->[37m���ɽ
[33mjinping[2;37;0m 	->[37m��ƽ��		 [33mqinglong[2;37;0m	->[37m����ɽ 
[33mtianzhu[2;37;0m 	->[37m���ù�		 [33mmaoying[2;37;0m 	->[37mëӱɽ 
[33mlingshan[2;37;0m	->[37m��ɽ                   [33mbaigudong[2;37;0m      ->[1;31m�׹Ƕ�[2;37;0m   
[33mhuangfeng[2;37;0m       ->[1;31m�Ʒ綴[2;37;0m                 [33mshuangcha[2;37;0m      ->[1;31m˫����[2;37;0m
[33myingjian[2;37;0m        ->[1;31mӥ�[2;37;0m                 [33mheifeng[2;37;0m        ->[1;31m�ڷ�ɽ[2;37;0m
[33mliusha[2;37;0m          ->[1;31m��ɳ��[2;37;0m                 




HELP
        );
        return 1;
}

