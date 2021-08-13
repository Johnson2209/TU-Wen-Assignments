#include <stdio.h>

int main(){
  int x1;
  int x2;
  int x3;
  int x4;
  int x5;
  int x6;
  int x7;
  int x8;
  int x9;
  int x10;
  double total_score;
  double percentage_score;
  printf("number of exercise solved in exercise sheet (i) is (xi)\n");
  printf("input (xi)  for (i) ranging from 1 to 10");
printf("input x1=");
  scanf("%d",&x1);
  printf("input x2=");
  scanf("%d",&x2);
  printf("input x3=");
    scanf("%d",&x3);
    printf("input x4=");
  scanf("%d",&x4);
  printf("input x5=");
    scanf("%d",&x5);
    printf("input x6=");
  scanf("%d",&x6);
  printf("input x7=");
  scanf("%d",&x7);
  printf("input x8=");
  scanf("%d",&x8);
  printf("input x9=");
  scanf("%d",&x9);
  printf("input x10=");
  scanf("%d",&x10);

  total_score = x1+x2+x3+x4+x5+x6+x7+x8+x9+x10;

  printf("total score by student=%d", total_score);
  if(x1>8||x2>8||x3>8||x4>8||x5>8||x6>8||x7>8||x8>8||x9>8||x10>8){
  printf("impossible");
}
  else{
    percentage_score = (total_score/80)*(100);
    printf("percentage_score of student:=%d\n", percentage_score);
      printf("Congratulations, you passed!");
  }
  else{
    printf("sorry, you failed\n");
  }
}

}
