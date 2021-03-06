//P_18512

#include <iostream>

using namespace std;

    /*
    문제
    춘향이는 편의점 카운터에서 일한다.
    손님이 2원짜리와 5원짜리로만 거스름돈을 달라고 한다. 2원짜리 동전과 5원짜리 동전은 무한정 많이 가지고 있다. 
    동전의 개수가 최소가 되도록 거슬러 주어야 한다. 거스름돈이 n인 경우, 최소 동전의 개수가 몇 개인지 알려주는 프로그램을 작성하시오.
    예를 들어, 거스름돈이 15원이면 5원짜리 3개를, 거스름돈이 14원이면 5원짜리 2개와 2원짜리 2개로 총 4개를, 
    거스름돈이 13원이면 5원짜리 1개와 2원짜리 4개로 총 5개를 주어야 동전의 개수가 최소가 된다.

    입력
    첫째 줄에 거스름돈 액수 n(1 ≤ n ≤ 100,000)이 주어진다.

    출력
    거스름돈 동전의 최소 개수를 출력한다. 만약 거슬러 줄 수 없으면 -1을 출력한다.

    예제 입력 1 
    13
    예제 출력 1 
    5

    예제 입력 2 
    14
    예제 출력 2 
    4

    1 -> -1
    2 -> m2 = 1 
    3 -> -1
    4 -> m2 = 2
    5 -> m5 = 1
    6 -> m2 = 3
    7 -> m5 = 1, m2 = 1
    8 -> m2 = 4
    9 -> m5 = 1, m2 = 2
    10 > m5 = 2
    11 > m5 = 1, m2 = 3
    12 > m5 = 2, m2 = 1
    13 > m5 = 2, m2 = 4
    14 > m5 = 2, m2 = 2
    15 > m5 = 3
    16 > m5 = 2, m2 = 3
    17 > m5 = 3, m2 = 1
    18 > m5 = 2, m2 = 4
    19 > m5 = 3, m2 = 2
    20 > m5 = 4

    99999 -> m5 = 19999, m2 = 2
    100000 -> m5 = 20000

    */


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);

    int n, count ;
    unsigned short m5 = 0, m2 = 0;
    // n = a * m5 + b * m2
    // a + b < a_n + b_n
    // output -> a + b
    cin >> n ;

    if(n%5 != 0 && n%2 != 0 && n < 4){
        printf("-1\n");
        return 0 ;
    }
    else if(n%5 == 0){
        m5 = n/5 ;
    }
    else if(n%2 != 0){      // odd nember
        m5 += 1 ;
        n -= 5 ;
        m5 += (n / 10) * 2 ;
        m2 += (n % 10) / 2 ;
    }
    else{
        m5 += (n / 10) * 2 ;
        m2 += (n % 10) / 2 ;
    }
    
    count = m5 + m2 ;
    printf("%d\n", count) ;
    
    return 0;
}