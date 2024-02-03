#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

// 时间：O（属性值总数 * 已选属性值数量）
// 空间：O（属性值总数 * 属性值总数）
// 思路：构建一个邻接矩阵记录库存中互相关联的属性值的关系，
//      遍历已选属性值对应关联的属性值，通过与操作计算该属性值是否被多个已选的属性值都关联，如果是，则可选，否则，不可选。

class filter {
public:
    // 属性值
    vector<string> vtValue = {
            "a1", "a2", "a3", "a4", "a5",
            "b1", "b2", "b3", "b4", "b5",
            "c1", "c2", "c3", "c4", "c5",
            "d1", "d2", "d3", "d4", "d5"
    };
    // 属性值与坐标ID的反向映射
    map<string, int> mpValue2Idx;

    // 库存的邻接矩阵
    vector<vector<int>> vtGraph;

    filter() {
        int size = vtValue.size();
        // 初始化反向映射
        for (int i = 0; i < size; i++) {
            mpValue2Idx[vtValue[i]] = i;
        }

        // 初始化库存的邻接矩阵
        vtGraph.resize(size, vector<int>(size, 0));

        // 初始化库存情况
        AddProduct({"a1", "b1", "c1", "d1"}, 3);
        AddProduct({"a1", "b1", "c2", "d2"}, 5);
        AddProduct({"a2", "b3", "c4", "d3"}, 1);
        AddProduct({"a2", "b2", "c3", "d1"}, 2);
        AddProduct({"a3", "b4", "c2", "d1"}, 5);
    }

    void AddProduct(vector<string> vtAttr, int num) {
        for (int i = 0; i < vtAttr.size(); i++) {
            for (int j = i; j < vtAttr.size(); j++) {
                int id1 = mpValue2Idx[vtAttr[i]];
                int id2 = mpValue2Idx[vtAttr[j]];
                vtGraph[id1][id2] += num;
                vtGraph[id2][id1] += num;
            }
        }
    }

    void Choose(vector<string>& vtHasChoose, vector<string>& vtCantChoose) {
        // 遍历已选属性与库存邻接矩阵，通过 与逻辑 计算可选的属性列表vtAttr
        vector<bool> vtAttr(vtValue.size(), true);
        for (auto& str: vtHasChoose) {
            int id1 = mpValue2Idx[str];
            for (int i = 0; i < vtGraph[id1].size(); i++) {
                vtAttr[i] = vtAttr[i] && (vtGraph[id1][i] == 0 ? false: true);
            }
        }

        // 如果vtAttr中value对应的值为0，则代表不可选
        for (int i = 0; i < vtAttr.size(); i++) {
            if (!vtAttr[i]) {
                vtCantChoose.push_back(vtValue[i]);
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