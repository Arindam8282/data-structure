#include<Stack.h>
class PostfixConversion {
  private:
    bool validate(char* expr) {
      if(expr[0]==')' || expr[0]=='+' || expr[0]=='-'|| expr[0]=='/'|| expr[0]=='*') {
        cout<<"cannot start with "<<expr[0];
        return false;
      } 
      else {
        for(int i=0;expr[i]!=NULL;i++) if((expr[i]>=65 && expr[i]<=90) || (expr[i]>=97 && expr[i]<=122)) {
            cout<<"cannot evaluate characters\n";return 0;
        } 
        cout<<"Expression : "<<expr<<endl;
        return 1;
      } 
    }
    
    int precedence(string op)  {  
        if(op == "+" || op == "-")  return 1;  
        if (op == "*" || op == "/") return 2;  
        if(op == "^" ) return 3;       
        return 0; 
    } 
    bool eqlOrhigher(string op1, string op2) {  
      int p1 = precedence(op1);  
      int p2 = precedence(op2);  
      if (p1 == p2) {  
        if (op1 == "^" )  return false;  
        return true;  
      }  
      return  (p1>p2 ? true : false);  
    }

  public:
    Stack* inStack = new Stack("Infix");
    Stack* optStack = new Stack("Operation");
    Stack* postStack = new Stack("Postfix");
    Node* ptr;
    string ch;
    bool IsOperand(string c) {   
      if( c >= "A" && c <= "Z") return true;  
      if (c >= "a" && c <= "z") return true;  
      if(c >= "0" && c <= "9") return true;  
      return false;  
    }  
    bool IsOperator(string c)  {  
      if(c == "+" || c == "-" || c == "*" || c == "/" || c == "^" )  return true;     
      return false;  
    }  
    string chartoString(char ch) {
      string s(1,ch);
      return s;
    }
    string convert(char* expr) {
      string num;
      if(!validate(expr)) return "wrong input";
        optStack->push("(");
        for(int i=0;expr[i]!=NULL;i++) {
          num = "";
          if(IsOperand(chartoString(expr[i]))) {
            for(int j=i;IsOperand(chartoString(expr[i]));i++) num += chartoString(expr[i]);
            inStack->push(num);
            i--;
          }
          else inStack->push(chartoString(expr[i]));
        } 
        inStack->push(")");
        ptr = inStack->head;
        for(int i=0;i<inStack->length();i++) {
          
          ch = ptr->data;  
          ptr = ptr->next;
          if(ch == " ")  continue;  
          else if(ch == "(") optStack->push(ch);  
          else if(IsOperand(ch))  postStack->push(ch);  
          else if(IsOperator(ch))  {  
            while(!optStack->isempty() && eqlOrhigher(optStack->top(), ch)) {  
              postStack->push(optStack->top());  
              optStack->pop();  
            }  
            optStack->push(ch);  
          }  
          else if(ch == ")")  {  
            while(!optStack->isempty() && optStack->top() != "(")  {  
              postStack->push(optStack->top());  
              optStack->pop();  
            }  
            optStack->pop();  
          }  
        }
        return postStack->getdata(); 
    }  
};

class PostfixEval: PostfixConversion {
  public:
  float operation(float a,float b,string op) {
    if(op=="+") return a+b;
    if(op=="-") return a-b;
    if(op=="/") return a/b;
    if(op=="*") return a*b;
    return 0;
  }
  float eval(char* expr) {
    string str;
    // PostfixConversion Expression;
    Stack* result = new Stack("result");
    str = convert(expr);
    float total=0;
    float a;
    float b;
    Node* ptr = postStack->head;
    for(int i=0;i<postStack->length();i++) {

      if(IsOperand(ptr->data)) result->push(ptr->data);
      if(IsOperator(ptr->data)) {
        a =  stof(result->pop());
        b =  stof(result->pop());
        total = operation(b,a,ptr->data);
        result->push(to_string(total));
      }
      ptr = ptr->next;
    }
    return total;
  }

};
