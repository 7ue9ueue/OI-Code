#include "bits/stdc++.h"
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "");
    wstring s;
    wprintf(L"请输入数据:\n");
    getline(wcin, s);
    wprintf(L"请稍等\n");
    int n = s.size();
    int ind = 0;
    vector<wstring> ans;
    ans.push_back(L"");

    for (int i = 0; i < n; i++)
    {
        if (s[i] == ',')
        {
            ans.push_back(L"");
            ind++;
        }
        else
        {
            ans[ind] = ans[ind] + s[i];
        }
    }
    sort(ans.begin(), ans.end());
    vector<wstring> rep;
    int cnt = 0;
    wprintf(L"\n");
    wprintf(L"去重复后词组\n");
    for (int i = 0; i < ans.size(); i++)
    {
        if (i != ans.size() - 1)
        {
            if (ans[i] == ans[i + 1])
            {
                rep.push_back(ans[i]);
                cnt++;
            }
            else
                wprintf(L"%s,", ans[i].c_str());
        }
        else
            wprintf(L"%s. \n", ans[i].c_str());
    }
    wprintf(L"词数 %d \n", ans.size());
    wprintf(L"不重词数 %d \n", ans.size()-cnt);
    wprintf(L"重复词数 %d 如下:\n", cnt);
    for (int i = 0; i < rep.size(); i++)
    {
        wprintf(L"%s\n", rep[i].c_str());
    }
    system("pause");
}


//g++ -Wall -o test test.cpp -static
//TTTS,Porcelain,CERAMIC,Pottery,Glass,Wine,Lamp,Light,Tile,Sanitary,Stone,Solar, Plaster,LCD,Display,Screen,Mug, Bottle, Mirror,brick,Tiles,bricks,lights,marble,marbles,lamps,used,fragile, 易碎品,玻璃,陶瓷,洁具,地砖,瓷砖,大理石,板材,灯,窗,玻璃杯,陶瓷杯,玻璃管,酒,显示屏,液晶屏,二手货物,旧,在用,返修,手机,电脑,游戏机,学习机,主板,电源,酒类,酒,白酒,红酒,茅台,五粮液,茅台酒,MOUTAI,五粮液酒,沉香,aquilaria,Tablet, PC,Mobile,Phone,Laptop,Camera,watch,computer,  ipad,iphone,Table pc,watches,金,银,纪念,币,珠宝,钻石,玉,首饰,古,邮票,艺术品,文物,现金,有价证券,票据,文件,档案,账册,图纸,资料,雕,工艺品,玉石,画,瓷器,鱼粉,豆粕,花生,豆,谷,米,面,粮食,籽,蛋,花,蛤,牡蛎,蛤蜊,贻贝,毛蚶,蚬,血,疫,爆炸,放射,燃,爆,危险,军用,武器,枪,炮,弹,飞机,箭,船,艇,舰,驳,酒精,油,煤,柴,精密,成套,大型,平衡,稳定,防震,防尘,恒温,恒湿,水泥,舱面,饲料,煤炭,鸡,鸭,牛,羊,马,动物,猪,狗,油漆,涂料,染料,农药,炭黑,清洁剂,机油,香精,香料,电池,电瓶,油墨,胶水,树脂,LIQUORS,cigarette,helicopter,BULBS,peck,LITHIUM,晶圆,芯片,INTEGRATED,CIRCUITS,UN3480,UN3090,UN1866,dangerous,UN3,UN1,3480,3090,1866,li-,2331,UN2,香烟,medicine,drug,medicament,agentia,medicinal,LED,LIGHTING,STEEL,爆炸,放射,燃,爆,危险,酒精,油,煤,柴,油漆,涂料,染料,炭黑,清洁剂,机油,香精,香料,电瓶,油墨,胶水,树脂,电池,radiation,combustion,explosion,alcohol,fire,paints,dyes,cleaners,fragrances,spices,inks,resins,pesticide,chemicals,biocide,druss,coom,pigment,detergent,abluent,essence,resinoid,perfume,spice,condiment,mucilage,Battery,LITHIUM,UN3480,UN3090,li-,2331,UN2,TTS,fruit,grapes,grape,citrus,grapefruit,peach,melon, apricot,litchi,persimmon,lemon,banana, pineapple,pomegranate,medlar,hawthorn,mulberry,chestnut,grapefruit,strawberry,orange,loquat, longan,mangosteen,rambutan,brown,Peach,guava,Gautama, wampee,pomegranate,apple,vegetable,chrysanthemum, radish,yam,potato,onion,taro,lotus,garlic,flowers,pepper, persimmon,melon,eggplant,beans,konjac,bud,gourd,mustard,pepper,ginger,anise,mushroom,mushroom,leek,celery,fungus,refrigerated,frozen,meat,poultry,aquatic products,milk,eggs,fish,shrimp,crab,GARLIC,果,梨,葡萄,红提,枣,柑橘,柚,桃,瓜,杏,荔枝,甘蔗,柿,柠檬,香蕉,菠萝,李,石榴,枸杞,山楂,椰子,桑葚,荸荠,柚子,草莓,桔,橙,龙眼,枇杷,山竹,红毛丹,布朗,桃,芭乐,梅,释迦,黄皮,榴,莲雾,蔬菜,菜,茼蒿,萝卜,山药,薯,葱,芋头,莲,藕,竹,笋,蒜,花,椒,瓜,柿,茄子,豆,米,魔芋,菇,芽,葫芦,芥,辣椒,姜,菇,茴香,蘑,韭,芹,菌,冷藏,冷冻,冻结,肉,禽,水产,乳,鱼,蛋,虾,蟹,冰,低温,恒温,海, 镍矿,煤炭,矿石类,原木,盐,比亚迪,电动车,小车,大巴,大巴车,直升机,货车,汽车,机动,卡车,拖车,泥头车,火车,轿车,面包车,旅行车,公务车,私家车,越野,吉普,卧车,房车,汽车,卡车