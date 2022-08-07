#include <iostream>
using namespace std;

int N;
int arr[10001] = { 0 };

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        arr[num]++;
    }

    for (int i = 0; i < 10001; i++) {
        if (arr[i] != 0) {
            for (int j = 0; j < arr[i]; j++) {
                cout << i << "\n";
            }
        }
    }

    return 0;
}