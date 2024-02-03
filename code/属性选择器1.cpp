// 销售属性选择器模拟
// 淘宝、京东等电商平台在销售商品时都会有销售属性选择器来让用户进行商品销售属性的喜好选择
// (1)属性项（尺码、颜色分类等），用A、B、C、D、E来表达，个数可能1～5个
// (2)属性值（XS、S、黑色、白色等），A对应的用a1、a2...表示，B对应的用b1、b2...表示，...，E对应的用e1、e2...表示，个数从1～10个不等
// (3)原始的有库存的数据情况举例如下（4个属性项）：
// A   B   C   D   库存数
// a1  b1  c1  d1  3
// a1  b1  c2  d2  5
// a2  b3  c4  d3  1
// a2  b2  c3  d1  2
// a3  b4  c2  d1  5
// (4)不是所有的组合都有库存
// (5)用户按自己想法随意顺序点选界面上属性值（例如A的a1），那么其他属性项中不可能有库存的属性值会被置灰（B的b2、b3、b4，C的c3、c4、c5等等等）
// 要求：
// 自行设计数据结构和算法，来模拟用户的随机属性项顺序点选未置灰属性值那一刻，以最高效的方式计算出每个属性项的属性值列表中哪些属性值需要被置灰


#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

// 时间：O（属性值总数 * 库存总数 * 已选属性值数量 *（库存名字符串长度+属性值字符串长度）），其中（库存名字符串长度+属性值字符串长度）是字符串子串查询的复杂度（KMP算法）
// 空间：O（库存总数）
// 思路：遍历全部属性值与库存，如果某个库存既包含该属性值也包含传参里的已选属性值，那么该属性值可选，否则不可选。

class filter {
public:
    // 属性值
    vector<string> vtValue = {
            "a1", "a2", "a3", "a4", "a5",
            "b1", "b2", "b3", "b4", "b5",
            "c1", "c2", "c3", "c4", "c5",
            "d1", "d2", "d3", "d4", "d5"
    };
    // 库存
    unordered_map<string, int> mpProduct = {
            {"a1_b1_c1_d1", 3},
            {"a1_b1_c2_d2", 5},
            {"a2_b3_c4_d3", 1},
            {"a2_b2_c3_d1", 2},
            {"a3_b4_c2_d1", 5}
    };

    void Choose(vector<string>& vtHasChoose, vector<string>& vtCantChoose) {
        for (auto& value: vtValue) {
            bool find = false;
            // 遍历库存，查询是否有满足属性值vtHasChoose以及value的库存
            for (auto& kv: mpProduct) {
                string product = kv.first;
                int num = kv.second;
                if (num == 0) {
                    continue;
                }

                // 找到符合已选属性值的库存
                bool bHasChoose = true;
                for (auto& str: vtHasChoose) {
                    if (product.find(str) == string::npos) {
                        bHasChoose = false;
                    }
                }
                if (bHasChoose) {
                    if (product.find(value) != string::npos) {
                        // 该库存包含对应属性值
                        find = true;
                        break;
                    }
                }
            }

            // 没有找到满足属性值vtHasChoose以及value的库存，加入到置灰队列里
            if (!find) {
                vtCantChoose.push_back(value);
            }
        }
    }

};


int main() {
    filter st;
    vector<string> vt1 = {"a1"};
    vector<string> vt2;
    st.Choose(vt1, vt2);

    for (auto& str: vt2) {
        cout << str << " ";
    }
    cout << endl;

    vt1 = {"b3"};
    vt2.clear();
    st.Choose(vt1, vt2);

    for (auto& str: vt2) {
        cout << str << " ";
    }
    cout << endl;

    return 0;
}

//a2 a3 a4 a5 b2 b3 b4 b5 c3 c4 c5 d3 d4 d5
//a1 a3 a4 a5 b1 b2 b4 b5 c1 c2 c3 c5 d1 d2 d4 d5
