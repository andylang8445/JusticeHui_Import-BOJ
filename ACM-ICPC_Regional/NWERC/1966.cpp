#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p; //pair<int, int>를 p로 줄여 씁니다.

void testcase(){ //각각 testcase마다 실행합니다.
    int n, m;
    int ans = 0;
    queue<p> q;
    priority_queue<int> pq; //우선순위 큐 선언
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){ //우선순위 입력
        int tmp; scanf("%d", &tmp);
        q.push(make_pair(tmp, i)); //{중요도, 인덱스} 형태로 저장
        pq.push(tmp); //가중치들의 최대값을 찾기 위해 우선순위 큐에 집어넣습니다.
    }
    while(!q.empty()){ //큐가 빌 때 까지
        p poped = q.front();
        q.pop();
        if(pq.top() == poped.first){ //최대값과 현재 문서의 중요도가 같은지 비교
            ans++; //하나를 출력하니까 ans 1 증가
            pq.pop(); //우선순위 큐에서 최대값 pop
            if(poped.second == m) break; //현재 문서의 중요도가 최대이고, 그 문서가 내가 찾고자 하는 문서이면 반복문 종료
        }else q.push(poped);
    }
    printf("%d\n", ans);
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        testcase();
    }
}
