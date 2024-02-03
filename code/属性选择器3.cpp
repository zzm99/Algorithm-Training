#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

// 时间：O（属性值总数）
// 空间：O（库存总数 * 64（例如4种属性类型，长度大于0小于等于4的字符串总数为64=4*3*2*1+4*3*2+4*3+4，总数=n!+..+n!/(n-2)!+n!/(n-1)!））
// 思路：记录一个库存情况的Map，其中Key为实际库存里属性值的所有可能组合（包括乱序情况），
//      入参为已选属性值拼接字符串，遍历所有属性值，将属性值与入参的字符串拼接，在Map里查找是否有该字符串即可知道该属性值是否可选，否则不可选

class filter {
public:
    // 属性值
    vector<string> vtValue = {
            "a1", "a2", "a3", "a4", "a5",
            "b1", "b2", "b3", "b4", "b5",
            "c1", "c2", "c3", "c4", "c5",
            "d1", "d2", "d3", "d4", "d5"
    };

    // 所有可能属性组合的库存情况
    unordered_map<string, int> mpProduct;

    filter() {
        // 初始化库存情况
        AddProduct({"a1", "b1", "c1", "d1"}, 3);
        AddProduct({"a1", "b1", "c2", "d2"}, 5);
        AddProduct({"a2", "b3", "c4", "d3"}, 1);
        AddProduct({"a2", "b2", "c3", "d1"}, 2);
        AddProduct({"a3", "b4", "c2", "d1"}, 5);
    }

    void AddProduct(vector<string> vtAttr, int num) {
        vector<int> visited(vtAttr.size(), 0);
        unordered_map<string, int> mpAttr;
        AddProductImpl(vtAttr, num, 0, "", visited, mpAttr);
        for (auto& kv: mpAttr) {
            mpProduct[kv.first] += kv.second;
        }
    }

    void AddProductImpl(vector<string> vtAttr, int num, int idx, string cur, vector<int>& visited, unordered_map<string, int>& mpAttr) {
        if (idx == vtAttr.size()) {
            if (cur.size() > 0 && mpAttr[cur] == 0) {
                mpAttr[cur] += num;
            }
            return;
        }
        for (int i = 0; i < vtAttr.size(); i++) {
            if (visited[i] == 1) {
                continue;
            }
            string tmp = cur;
            tmp += vtAttr[i];
            tmp += "_";
            visited[i] = 1;
            AddProductImpl(vtAttr, num, idx+1, tmp, visited, mpAttr);
            AddProductImpl(vtAttr, num, idx+1, cur, visited, mpAttr);
            visited[i] = 0;
        }
    }

    void Choose(string strHasChoose, vector<string>& vtCantChoose) {
        for (auto& str: vtValue) {
            string tmp = strHasChoose + str;
            tmp += "_";
            bool find = false;
            if (mpProduct.find(tmp) != mpProduct.end() && mpProduct[tmp] > 0) {
                find = true;
            }
            if (!find) {
                vtCantChoose.push_back(str);
            }
        }
    }

};

int main() {
    filter st;
    vector<string> vt2;
    st.Choose("a1_", vt2);

    for (auto& str: vt2) {
        if (str == "a1") {continue;}
        cout << str << " ";
    }
    cout << endl;

    vt2.clear();
    st.Choose("b3_", vt2);

    for (auto& str: vt2) {
        if (str == "b3") {continue;}
        cout << str << " ";
    }
    cout << endl;

    return 0;
}

//a2 a3 a4 a5 b2 b3 b4 b5 c3 c4 c5 d3 d4 d5
//a1 a3 a4 a5 b1 b2 b4 b5 c1 c2 c3 c5 d1 d2 d4 d5