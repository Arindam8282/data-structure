#include<PostfixEval.h>

int main(int argv,char** argc) {
  PostfixEval expr;
  float ans;
  ans = expr.eval(argc[1]);
  printf("answer : %.2f\n",ans);
  ans = expr.eval(argc[2]);
  printf("Answer : %.2f",ans);
  return 1;
}