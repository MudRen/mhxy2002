static mapping zhangmen_skills = ([
"ħ��"      : ({ "tianmo","tianmo-blade" }),
"�¹�"        : ({ "moonshentong","moonforce","snowsword"}),
"��ׯ��"      : ({ "taiyi","zhenyuan-force" }),
"�Ϻ�����ɽ"  : ({ "buddhism","lotusforce" }),
"��������"    : ({ "seashentong","dragonforce" }),
"������"      : ({ "lengquan-force" }),
"���޵ظ�"    : ({ "gouhunshu","tonsillit","hellfire-whip" }),
"�ݿ�ɽ�޵׶�": ({ "kugu-blade","huntian-qigong" }),
"�齣��"      : ({ "lingjian-force","sword" }),
"����ɽ���Ƕ�": ({ "dao","qianjun-bang","wuxiangforce" }),
"��ѩɽ"      : ({ "dengxian-dafa","ningxie-force" }),
]);

static mapping skills_limit = ([
"moonshentong":150,
"moonforce"   :150,
"snowsword"   :160,
"taiyi"       :150,
"zhenyuan-force" :150,
"buddhism"    :150,
"lotusforce"  :150,
"seashentong" :150,
"tianmo"  :100,
"tianmo-blade"  :100,
"dragonforce" :150,
"lengquan-force":150,
"gouhunshu"   :150,
"tonsillit" :130,
"hellfire-whip":150,
"kugu-blade"  :181,
"huntian-qigong":130,
"lingjian-force"  :150,
"sword" :150,
"dao"          :150,
"qianjun-bang" :160,
"wuxiangforce"  :150,
"dengxian-dafa":150,
"ningxie-force":150,
]);

#define DEBUG 1

int can_zhangmen(object ob)
{
 string family_name,skillname;
 string* fname;
 int myskill,limitskill;
 int i,j;

 family_name=ob->query("family/family_name");
 if(!family_name) return 0;

 fname=keys(zhangmen_skills);
 if(!fname) return 0;

 for(i=0;i<sizeof(fname);i++)
  if(fname[i]==family_name) break;
 if(i>=sizeof(fname)) return 0;

 fname=zhangmen_skills[family_name];
 if(!fname) return 0;

 j=0;
 for(i=0;i<sizeof(fname);i++)
  {
   skillname=fname[i];
   limitskill=skills_limit[skillname];
   if(limitskill) {
      myskill=ob->query_skill(skillname,1);
      if(myskill>=limitskill) j++;
    }
  }
 if(j==sizeof(fname)) return 1;
 return 0;
}
