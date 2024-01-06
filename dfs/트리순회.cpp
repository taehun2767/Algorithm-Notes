#include <iostream>
#include <map>

#define endl "\n"
#define fastio() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int n;
char leftChild, parent, rightChild;
map<char, pair<char, char>> dic;

void preOrderTraversal(char parent){
    char left = dic[parent].first;
    char right = dic[parent].second;

    cout << parent;
    if(left != '.') preOrderTraversal(left);
    if(right != '.') preOrderTraversal(right);
}

void inOrderTraversal(char parent){
    char left = dic[parent].first;
    char right = dic[parent].second;

    if(left != '.') inOrderTraversal(left);
    cout << parent;
    if(right != '.') inOrderTraversal(right);

}

void postOrderTraversal(char parent){
    char left = dic[parent].first;
    char right = dic[parent].second;

    if(left != '.') postOrderTraversal(left);
    if(right != '.') postOrderTraversal(right);
    cout << parent;
}

void solution(){
    preOrderTraversal('A');
    cout << endl;
    inOrderTraversal('A');
    cout << endl;
    postOrderTraversal('A');
    cout << endl;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> parent >> leftChild >> rightChild;
        dic.emplace(parent, make_pair(leftChild, rightChild));
    }

    solution();
}
