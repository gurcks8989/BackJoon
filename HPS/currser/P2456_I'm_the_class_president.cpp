
/*
문제
나는 학급회장이다
링크: acmicpc.net/problem/2456

N명의 학생들이 모인 초등학교 반에서 학급회장 선거를 하려고 한다. 
그 중 3명이 회장후보로 나왔고, 이들에 대한 선호도를 N명의 학생들 각각에게 적어내도록 하였다. 
세 명의 후보는 후보 1번, 후보 2번, 후보 3번이라 한다.

모든 학생은 3명의 후보 중에서 가장 선호하는 후보에게는 3점, 
두 번째로 선호하는 후보에게는 2점, 가장 선호하지 않는 후보에게는 1점을 주어야 한다. 
3명의 후보에 대한 한 학생의 선호 점수는 모두 다르며, 1점, 2점, 3점이 정확히 한 번씩 나타나야 한다. 

후보의 최종 점수는 학생들로부터 받은 자신의 선호도 점수를 모두 더한 값이 된다. 
그러면 3명의 후보 중 가장 큰 점수를 받은 후보가 회장으로 결정된다. 
단, 점수가 가장 큰 후보가 여러 명인 경우에는 3점을 더 많이 받은 후보를 회장으로 결정하고, 
3점을 받은 횟수가 같은 경우에는 2점을 더 많이 받은 후보를 회장으로 결정한다. 
그러나 3점과 2점을 받은 횟수가 모두 동일하면, 1점을 받은 횟수도 같을 수밖에 없어 회장을 결정하지 못하게 된다.

여러분은 선호도 투표를 통해 얻은 세 후보의 점수를 계산한 후, 
유일하게 회장이 결정되는 경우에는 회장으로 결정된 후보의 번호(1, 2, 3 중 한 번호)와 최고 점수를 출력하고, 
회장을 결정하지 못하는 경우에는 번호 0과 최고 점수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에는 반의 학생들의 수 N (3 ≤ N ≤ 1,000)이 주어진다. 
다음 N개의 각 줄에는 각 학생이 제출한 회장후보 3명에 대한 선호 점수가 주어지는 데, 
첫 번째 점수는 후보 1번에 대한 점수이고 두 번째 점수는 후보 2번에 대한 점수이고 
세 번째 점수는 후보 3번에 대한 점수이다. 이 세 점수는 서로 다르며, 1, 2, 3이 정확히 한 번씩 나타난다. 

출력
학생들의 선호도 투표 결과로부터, 회장이 유일하게 결정되는 경우에는 
회장으로 결정된 후보의 번호와 최고 점수를 출력하고, 
유일하게 결정할 수 없는 경우에는 0과 최고 점수를 출력한다.

예제 입력 1 
6
3 1 2
2 3 1
3 1 2
1 2 3
3 1 2
1 2 3

예제 출력 1 
1 13

*/

#include <iostream>

using namespace std ;

typedef struct score_t
{
    int score ;
    int p3 ;
    int p2 ;
    int num ;
}score ;


int main(){

    int N ;

    cin >> N ;

    score s[3] ;

    for(int i = 0 ; i < 3; i ++){
        s[i].score = 0 ; 
        s[i].p2 = 0 ;
        s[i].p3 = 0 ;
        s[i].num = i + 1 ;
    }

    for(int i = 0 ; i < N; i ++){
        
        int temp[3] ;

        cin >> temp[0] >> temp[1] >> temp[2] ;
    
        for(int i = 0 ; i < 3; i++){
            s[i].score += temp[i] ;

            switch(temp[i]){
                case 3: s[i].p3 += 1 ; break ;
                case 2: s[i].p2 += 1 ; break ;
                default : break ;
            }
        }
    }
    
    /* 
    for(int i = 0 ; i < 3 ; i ++){
        printf("%d\t%d\t%d\t%d\n", s[i].score, s[i].p3, s[i].p2, s[i].num) ;
    }
    */ 

    score max ;

    unsigned char match = 0 ;

    for(int i = 0 ; i < 3 ; i ++){
        if(max.score < s[i].score){
            max = s[i] ;
            if(match != 0)
                match = 0 ;
        }
        else if(max.score == s[i].score){
            if(max.p3 < s[i].p3){
                max = s[i] ;
                if(match != 0)
                    match = 0 ;
            }
            else if(max.p3 == s[i].p3){
                if(max.p2 < s[i].p2){
                    max = s[i] ;
                    if(match != 0)
                        match = 0 ;
                }
                else if(max.p2 == s[i].p2)
                    match = 1 ;
            }
        }
    }

    if(match)
        printf("0 %d", max.score) ;
    else
        printf("%d %d", max.num, max.score);

    printf("\n") ;

    return 0 ;
}