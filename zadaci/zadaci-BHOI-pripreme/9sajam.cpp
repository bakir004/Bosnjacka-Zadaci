#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int countUnique(vector<int> nums) {
    int sum = 0;

    

    return sum;
}

int main() {
    int N, K, M;
    int p, v;
    fstream file;
    vector<int> nums;
    vector<int> res;

    file.open("sajam.txt", ios::in);
    file >> N >> K >> M;

    for (int i = 0; i < N; i++) {
        int num;
        file >> num;
        nums.push_back(num);
    }

    for (int i = 0; i < M; i++) {
        int prompt;
        file >> prompt;
        if(prompt == 1) {
            int pos, num;
            file >> pos >> num;
            nums[pos - 1] = num;
        } else {
            res.push_back(countUnique(nums));
        }
    }

    file.close();

    for (int i = 0; i < res.size(); i++){
        cout << res[i] << "\n";
    }
    
    


    return 0;
}

// djelivi sa 8, banane, sajam, velikaana