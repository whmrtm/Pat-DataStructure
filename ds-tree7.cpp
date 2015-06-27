#include <iostream>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <sstream>
#include <string>
 
using namespace std;
 
//ifstream fin("in.txt");
//#define cin fin
 
int N, *data;
 
typedef struct nodeT{
    nodeT *left;
    nodeT *right;
    int key;
}nodeT;
 
int log2(int num) {
    int count = 0;
    while (num != 1) {
        num /= 2;
        count++;
    }
    return count;
}
 
 
nodeT *buildCBT(int *cur, int length) {
    if (length <= 0)
        return NULL;
    int exp = log2(length + 1);
    int low = (int)pow(2.0, exp) - 1;
    int mid = (low + (int)pow(2.0, exp + 1) - 1) / 2;
    nodeT *head = new nodeT;
    int headCur = length <= mid ? mid - low : mid - low + length - mid;
    head->key = cur[length - headCur];
    head->left = buildCBT(cur, length - headCur);
    head->right = buildCBT(cur + length - headCur + 1, headCur - 1);
    return head;
}
 
bool cmpNum(int a, int b) {
    return a < b;
}
 
void levelOutput(nodeT *root) {
    queue<nodeT *> q;
    q.push(root);
    string s = "";
    while (!q.empty()) {
        int val = q.front()->key;
        if (q.front()->left != NULL) {
            q.push(q.front()->left);
        }
        if (q.front()->right != NULL) {
            q.push(q.front()->right);
        }
        stringstream ss;
        ss << val;
        s += ss.str() + " ";
        q.pop();
    }
    s = s.substr(0,s.size() - 1);
    cout << s;
}
 
int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d", &N);
    data = new int[N];
    for (int i = 0;i < N; i++) {
        scanf("%d", &data[i]);
    }
    sort(data, data + N, cmpNum);
    nodeT *root = buildCBT(data, N);
    levelOutput(root);
    system("pause");
    return 0;
}
