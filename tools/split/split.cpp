#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

vector<string> split(const string &s, const string &seperator){
    vector<string> result;
    typedef string::size_type string_size;
    string_size i = 0;

    while (i != s.size()){
        //找到字符串中首个不等于分隔符的字母；
        int flag = 0;
        while (i != s.size() && flag == 0){
            flag = 1;
            for (string_size x = 0; x < seperator.size(); ++x)
                if (s[i] == seperator[x]){
                    ++i;
                    flag = 0;
                    break;
                }
        }

        //找到又一个分隔符，将两个分隔符之间的字符串取出；
        flag = 0;
        string_size j = i;
        while (j != s.size() && flag == 0){
            for (string_size x = 0; x < seperator.size(); ++x)
                if (s[j] == seperator[x]){
                    flag = 1;
                    break;
                }
            if (flag == 0)
                ++j;
        }
        if (i != j){
            result.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    return result;
}

int main(){
  string s = "a,b*c*d,e";
  string s1 = "1563520926707975280,11,253111,1563520926627763952,radar,9,30.6000003815,9.80000019073,0.0,-0.25,9.5,0.0,5.0,2.0,wide,0.371,0.478,0.478,0.616,2,253135,1563520926705086256,radar,1,4.40000009537,-1.0,0.0,0.0,-10.0,-2.40000009537,1.60000002384,1.60000002384,motorcycle,0.371,0.478,0.371,0.616,2,253136,1563520926705374832,radar,0,6.40000009537,2.20000004768,0.0,0.0,11.5,0.0,4.40000009537,1.79999995232,car,0.371,0.478,0.478,0.616,2,253137,1563520926705597616,radar,17,7.19999980927,0.800000011921,0.0,0.0,1.5,0.0,2.0,2.40000009537,car,0.371,0.478,0.371,0.616,2,253138,1563520926705885968,radar,14,10.8000001907,3.59999990463,0.0,0.0,-0.5,0.0,0.20000000298,0.0,point,0.371,0.478,0.478,0.616,2,253139,1563520926706294192,radar,8,12.6000003815,2.20000004768,0.0,0.0,10.5,0.0,2.0,2.40000009537,car,0.371,0.478,0.371,0.616,2,253140,1563520926706504272,radar,12,16.3999996185,2.59999990463,0.0,0.0,3.5,0.0,2.0,2.40000009537,car,0.371,0.478,0.478,0.616,2,253141,1563520926706695408,radar,2,18.0,6.0,0.0,0.0,4.5,0.0,1.0,1.0,point,0.371,0.478,0.478,0.616,2,253142,1563520926706944720,radar,13,20.0,5.19999980927,0.0,0.0,0.0,0.0,1.0,1.0,point,0.371,0.478,0.478,0.616,2,253143,1563520926707198320,radar,11,22.7999992371,4.80000019073,0.0,0.25,13.5,0.0,2.40000009537,3.0,car,0.288,0.478,0.371,0.616,2,253144,1563520926707458672,radar,3,25.7999992371,6.19999980927,0.0,-0.25,6.0,0.0,3.0,2.40000009537,car,0.371,0.478,0.478,0.616,2";
  vector<string> v = split(s1, ","); 
  for(vector<string>::size_type i = 0; i != v.size(); ++i)
    cout << v[i] << " ";
  cout << endl;

  cout << "string size is:" << v.size() << endl;
  int count = stoi(v[1]);
  cout << "count is :" << count << endl;

  //float timestamp = (float)stol(v[0]) / (float)1000000000;
  cout <<" timestamp : " << fixed << setprecision(8) << 1563520926.707975260 << endl;

  return 0;
}