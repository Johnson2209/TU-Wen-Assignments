#include <stdio.h>

int main(){
  double tmp=0;
  double totalscore;
  double percentagescore;
  printf("input total score obtained by student \n");

  scanf("%lf", &totalscore);
      printf("total score by student=%f\n", totalscore);
  if(totalscore>=80){
  printf("impossible");
}
percentagescore = (totalscore/80)*(100);
  if(percentagescore>=50 && totalscore<=80){
    totalscore=totalscore;
    percentagescore = percentagescore;
        printf("percentage_score of student:=%f\n", percentagescore);
      printf("Congratulations, you passed!");
  }
  else{
      printf("percentage_score of student:=%f\n", percentagescore);
    printf("sorry, you failed\n");
  }
}
