#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<sstream>

using namespace std;

static vector<pair<long long, long long>> spots;

long long dis(pair<long long, long long> a, pair<long long, long long> b) { // 거리의 제곱을 반환
    long long x = a.first - b.first;
    long long y = a.second - b.second;
    return x * x + y * y;
}

long long min(long long a, long long b, long long c) { // 세 수 중 최솟값 반환
    return std::min(a, std::min(b, c));
}

long long closest(int start, int end) {
    int size = end - start + 1;
    if (size == 2) return dis(spots[start], spots[start + 1]); // 사이즈가 2나 3일 때는 바로 거리 최소값 반환
    else if (size == 3) {
        return min(dis(spots[start], spots[start + 1]), dis(spots[start], spots[start + 2]), dis(spots[start + 1], spots[start + 2]));
    }

    int mid = (start + end) / 2; // 중간 인덱스
    long long MIN = min(closest(start, mid), closest(mid + 1, end)); // 좌우 영역에서의 최소값

    vector<pair<long long, long long>> vec;
    long long line = (spots[mid].first + spots[mid + 1].first) / 2; // 중간선을 만들어주고 중간선과 x값 차이 제곱이 MIN보다 작은 점들만 벡터에 넣어줌

    for (int i = start; i <= end; i++) {  // 범위 수정
        long long temp = line - spots[i].first;
        if (temp * temp < MIN) {
            vec.push_back(spots[i]);
        }
    }

    sort(vec.begin(), vec.end(), [](pair<long long, long long> a, pair<long long, long long> b) {
        return a.second < b.second; // y값 기준으로 정렬
    });

    for (int i = 0; i < vec.size(); i++) {
        for (int j = i + 1; j < vec.size(); j++) {
            long long temp = vec[j].second - vec[i].second;
            if (temp * temp >= MIN) break; // y값 차이 제곱이 MIN보다 크면 break
            else MIN = min(MIN, dis(vec[i], vec[j])); // 아니면 최소값 갱신
        }
    }
    return MIN;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    cin.ignore();//남아있는 개행문자 제거
    for (int i = 0; i < n; i++) {
        long long temp1, temp2;
        string input;
        getline(cin, input);//한 줄 입력
        stringstream ss(input);//입력받은 문자열을 공백을 기준으로 나누기 위해 stringstream 사용
        char comma;
        ss >> temp1 >> comma >> temp2;//콤마를 기준으로 x,y값을 나눔
        spots.push_back(make_pair(temp1, temp2));//pair로 저장해 spots에 넣어줌
    }

    sort(spots.begin(), spots.end(), [](pair<long long, long long> a, pair<long long, long long> b) {
        return a.first < b.first; // x값 기준으로 정렬
    });

    printf("%.6f", sqrt(closest(0, n - 1)));//소수점 6자리까지 출력
}