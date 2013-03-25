/*
 * 2012/11/29
 */
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <iomanip>

/*STL *algorithm* */
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <map>
#include <set>

#define DEBUG 1
#define MAX_SIZE 500

std::string calculate_sum(std::string num1, std::string num2){
   std::string output;
   char ch;

   int len1, len2, carry, sum, p1, p2;
   len1 = num1.length(); len2 = num2.length();
   carry = 0;
//   std::cout << len1  << "  "  << len2    << std::endl;      
//   std::cout << num1  << "  "  << num2 << std::endl;            
  
   while( len1 > 0 || len2 > 0 ){
      p1 = len1 > 0 && (num1[len1-1] != ' ')? num1[len1-1] - '0' : 0;
      p2 = len2 > 0 && (num2[len2-1] != ' ')? num2[len2-1] - '0' : 0;
            
      sum   = carry + p1 + p2;
      carry = sum/10;
      ch = sum%10+'0';
      output = ch + output;
      len1--; len2--;
//      std::cout << p1  << "  "  << p2    << std::endl;
//      std::cout << sum%10 << "  "  << carry << "  " << output << std::endl;
   }
   if(carry > 0){
      ch     = carry + '0';
      output = ch + output;
   }
   return output;
}


std::string calculate_diff(std::string num1, std::string num2){
   std::string output;
   char ch;

   int len1, len2, carry, diff, p1, p2;
   len1 = num1.length(); len2 = num2.length();
   carry = 0;
//   std::cout << len1  << "  "  << len2    << std::endl;      
//   std::cout << num1  << "  "  << num2 << std::endl;            
   if(num1 == num2){
     output = '0';
   }else{  
      while( len1 > 0 || len2 > 0 ){
         p1 = len1 > 0 ? num1[len1-1] - '0' : 0;
         p2 = len2 > 0 ? num2[len2-1] - '0' : 0;
               
         p1 += carry; carry = 0;
         if(p1 < p2) { carry = -1; p1 += 10;}
         diff = p1 - p2;
         
         ch = diff+'0';
         output = ch + output;
         len1--; len2--;
//         std::cout << p1  << "  "  << p2    << std::endl;
//         std::cout << diff << "  "  << carry << "  " << output << std::endl;
      }
      output = output.substr(output.find_first_not_of("0"));
   }
   return output;
}


std::vector<std::string> calculate_mult(std::string num1, std::string num2){
   std::string output;
   std::vector<std::string> partial_mult;
   std::map<int, std::string> map_mult;
   char ch;

   int len1, len2, carry, mult, p1, p2, count;
   len1 = num1.length(); len2 = num2.length();
   count = 0;
//   std::cout << "size: " << len1  << "  "  << len2    << std::endl;      
//   std::cout << "num:  " << num1  << "  "  << num2 << std::endl;            
   map_mult[0] = '0';  //spcl case :: Check TestCase
  
   while(len2 > 0 ){
      output = ""; carry = 0;
      p2 = num2[len2-1] - '0';
      
      if(map_mult.find(p2) != map_mult.end()){ // We already have this partial pdt
         output = map_mult[p2];
      }
      else{
         len1 = num1.length();
         while(len1 > 0){
            p1    = num1[len1-1] - '0';                 
            mult  = carry + p1*p2;
            carry = mult/10;
            ch    = mult%10+'0';
            output = ch + output;         
            len1--;
//            std::cout << p1  << "  "  << p2    << std::endl;
//            std::cout << mult << "  "  << carry << "  " << output << std::endl;         
         }
         if(carry > 0){
            ch     = carry + '0';
            output = ch + output;
         }
         map_mult[p2] = output;
      }
      
      ch = ' ';
      for(int i = 0; i < count; i++){ output += ch; }
      partial_mult.push_back(output);      
      len2--; count++;
   }
   return partial_mult;
}

std::string calculate_sum_pdt(std::vector<std::string> partial_mult){
   std::string output;
   while(partial_mult.size() > 1){
//      std::cout << "size (decr): " << partial_mult.size() << std::endl;
      output = calculate_sum(partial_mult[0], partial_mult[1]);
      partial_mult.erase(partial_mult.begin(), partial_mult.begin()+2);
      partial_mult.push_back(output);
   }
   return partial_mult[0];
}

int max(int a, int b, int c){
   return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

void print_del(int count, int total){
   std::string _temp;
   while(count-- > 0) { _temp += "-"; }
   std::cout << std::setfill(' ') << std::setw(total) << _temp << std::endl;
}

// **************************************************
int main(){
    int num_test_cases, pos, _max;
    std::cin >> num_test_cases; // num of test cases
    char op;
    std::string expression, num1, num2, _ret;
    std::vector<std::string> partial_mult; 
           
    for(int i = 0; i < num_test_cases; i++){
       std::cin >> expression;
                    
       while(1){
         pos = expression.find('+');
         if(pos != -1){ op = '+'; break; }

         pos = expression.find('-');
         if(pos != -1){ op = '-'; break; }
         
         pos = expression.find('*');
         if(pos != -1){ op = '*'; break; }         
       }
       expression[pos] = ' ';
//       std::cout << expression << std::endl;            
       std::istringstream temp(expression, std::istringstream::in);
       temp >> num1 >> num2;
//       std::cout << num1 << "  " << op << "  "  << num2 << std::endl;
       
       _ret = "";
       if(op == '+' || op == '-'){ 
          if(op == '+') _ret = calculate_sum(num1, num2);
          if(op == '-') _ret = calculate_diff(num1, num2);
          num2 = op + num2;
          _max = max(num1.length(), num2.length(), _ret.length());
          std::cout << std::setfill(' ') << std::setw(_max) << num1 << std::endl;
          std::cout << std::setfill(' ') << std::setw(_max) << num2 << std::endl;
          print_del( max(_ret.length(), num2.length(), 0), _max);
       }
       else if(op == '*') {
          partial_mult = calculate_mult(num1, num2);
          _ret = calculate_sum_pdt(partial_mult);
          if(_ret[0] == '0') _ret = "0";
          num2 = op + num2;
          _max = max(num1.length(), num2.length(), _ret.length());
          std::cout << std::setfill(' ') << std::setw(_max) << num1 << std::endl;
          std::cout << std::setfill(' ') << std::setw(_max) << num2 << std::endl;
          if(partial_mult.size() > 1){
             print_del( max(num2.length(), partial_mult[0].size(), 0), _max);
             for(int i = 0; i < partial_mult.size(); i++){
                std::cout << std::setfill(' ') << std::setw(_max) << partial_mult[i] << std::endl;
             }
             print_del( max(_ret.length(), partial_mult[partial_mult.size()-1].size(), 0), _max);
          }else{
             print_del( max(_ret.length(), num2.length(), 0), _max);
          }
       }
       std::cout << std::setfill(' ') << std::setw(_max) << _ret << std::endl;
       std::cout << std::endl;    
    }
//    while(1) { continue; }
}
