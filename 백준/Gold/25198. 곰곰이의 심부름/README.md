# [Gold I] 곰곰이의 심부름 - 25198 

[문제 링크](https://www.acmicpc.net/problem/25198) 

### 성능 요약

메모리: 6968 KB, 시간: 52 ms

### 분류

그래프 이론, 그래프 탐색, 수학, 트리

### 제출 일자

2023년 11월 5일 22:19:44

### 문제 설명

<p>곰곰이는 닭 다리를 좋아한다. 특히 두 개를 좋아하는데, 집에 갈 때마다 닭 다리를 두 개씩 사 간다. 곰곰이는 심부름이 있기 때문에 집에 가기 전, 심부름 장소를 들리고 가야 한다. </p>

<p>곰곰이의 나라는 $N$개의 도시로 이루어져 있고, $N-1$개의 양방향 도로로 이어져 있다. 곰곰이는 현재 $S$도시에, 곰곰이의 집은 $H$도시에, 심부름 장소는 $C$도시에 있다. 곰곰이의 나라는 연결그래프이다.</p>

<p>곰곰이는 현재 도시 - 심부름 도시 - 집 도시의 최단 경로로 이동할 것이다. 곰곰이는 각 도시에서 최대 한 개의 닭 다리를 살 수 있다. 곰곰이는 집에 도착했을 때, 닭 다리가 정확히 두 개 있어야 한다. 곰곰이는 노트에 자신이 닭 다리를 산 도시의 순서쌍을 적어둔다. 예를 들어 $3$번 도시에서 닭 다리를 산 뒤, $1$번 도시에서 닭 다리를 샀으면 $(3, 1)$로 표기한다. 만들어질 수 있는 순서쌍의 개수를 구해보자.</p>

### 입력 

 <p>첫째 줄에 도시의 개수 $N (1 \leq N \leq 100\,000)$이 주어진다.</p>

<p>둘째 줄에 곰곰이의 현재 도시 $S$, 심부름 도시 $C$, 집 도시 $H$가 공백으로 구분되어 주어진다. $(1 \leq S, C, H \leq N)$</p>

<p>$N-1$줄에 거쳐 도로로 연결된 두 도시 $u, v$가 주어진다. $(1 \leq u, v \leq N)$</p>

<p>입력으로 주어지는 값은 모두 정수이다.</p>

### 출력 

 <p>첫째 줄에 만들어질 수 있는 순서쌍의 개수를 출력한다.</p>

