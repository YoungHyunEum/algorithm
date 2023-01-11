#include <iostream>
#include <vector>
using namespace std;

int N;
char word[26][2];

void preorder(char x) {
    if (x == '.') return;
    cout << x;
    preorder(word[x - 'A'][0]);
    preorder(word[x - 'A'][1]);
}

void inorder(char x) {
    if (x == '.') return;
    inorder(word[x - 'A'][0]);
    cout << x;
    inorder(word[x - 'A'][1]);
}

void postorder(char x) {
    if (x == '.') return;
    postorder(word[x - 'A'][0]);
    postorder(word[x - 'A'][1]);
    cout << x;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        char a, b, c;
        cin >> a >> b >> c;
        word[a - 'A'][0] = b;
        word[a - 'A'][1] = c;
    }

    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');


    return 0;
}
