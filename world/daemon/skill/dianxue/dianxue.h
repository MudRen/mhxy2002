//by ephq
#include "/daemon/skill/dianxue/valid_kill.h";
mapping type(object me)
{
	object weapon;
	string skill_type;
	mapping sc;

	weapon=me->query_temp("weapon");

        if (objectp(weapon = me->query_temp("weapon")))
        skill_type=weapon->query("skill_type") ;
        else skill_type="unarmed";

        switch(skill_type){
                        case "sword":
                        	sc=(["dif": 100,
                        	     "action":"�����͵���",
                        	     "type":"��"
                        	   ]); 	
                                break;                  
                        case "fork":
                        	sc=(["dif":50,
                        	     "action":"��ͷ���ٵ���" ,
                        	     "type":"��",                       		
                        	   ]); 	                        
                                break;
                        case "mace":
                        	sc=(["dif":65,
                        	     "action":"�ͷ���������Ӱ��", 	 
                        	     "type":"��"                       		
                        	   ]); 	                        
                                break;
                        case "needle":
                        	sc=(["dif":120,
                        	     "action":"��ͷ���š��У��С����ƿ���������", 	 
                        	     "type":"��"                       		
                        	   ]); 	                        
                                break;
                        case "blade":
                        	sc=(["dif":67,
                        	     "action":"�����й�ֱ������",
                        	     "type":"��" 	                        		
                        	   ]); 	                        
                                break;                                                                                                
                        case "spear":
                        	sc=(["dif":75,
                        	     "action":"ǹͷһ������", 	 
                        	     "type":"��"                       		
                        	   ]); 	                        
                                break;
                        case "throwing":
                        	sc=(["dif":80,
                        	     "action":"����������ǣ��������,ֱ��" ,
                        	     "type":"��"	                        		
                        	   ]); 	                        
                                break;
                        case "whip":
                        	sc=(["dif":105,
                        	     "action":"�޼������߰����", 	                        		
                        	     "type":"��"
                        	   ]); 	                        

                                break;                                                                                                
                        case "unarmed":
                        	sc=(["dif":110,
                        	     "action":"ʳָ΢����ֱ��" ,	 
                        	     "type":"��"                       		
                        	   ]); 	                        
                                break;                                                                                                                                
                        default: sc=(["type":"none"]);
                                break;
                        }
        
	return sc;
}
