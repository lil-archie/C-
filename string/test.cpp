#define  _CRT_SECURE_NO_WARNINGS 1

#include"string.h"


//void Test1()
//{
//	mystring::string s1;
//	//cout << s1.size() << endl;
//
//	/*s1 += "hello world";
//	cout << s1 << endl;*/
//
//	s1 += "hello";
//	s1 += '\0';
//	s1 += "xxxxxxxx";
//
//	cout << s1 << endl;
//
//}
//void Test2()
//{
//	mystring::string s1("hello");
//	mystring::string s2("hello");
//	cout << (s1 < s2) << endl;
//	cout << (s1 > s2) << endl;
//	cout << (s1 == s2) << endl << endl;
//
//
//	mystring::string s3("hello");
//	mystring::string s4("helloxxx");
//	cout << (s3 < s4) << endl;
//	cout << (s3 > s4) << endl;
//	cout << (s3 == s4) << endl << endl;
//
//
//	mystring::string s5("helloxxx");
//	mystring::string s6("hello");
//	cout << (s5 < s6) << endl;
//	cout << (s5 > s6) << endl;
//	cout << (s5 == s6) << endl << endl;
//}

//void Test3()
//{
//	mystring::string s1("hello world");
//	mystring::string s2;
//	s2= s1;
//	cout << s2<< endl;
//
//}

//void Test3()
//{
//	string s1("Acdd");
//	string s2;
//	char ret;
//	for (auto ch : s1)
//	{
//		ret = tolower(ch);
//		s2 += ret;
//	}
//	for (auto ch : s2)
//	{
//		cout << ch;
//	}
//	//cout << s1 << endl;

void Test3()
{

    /*class Solution {
    public:
        bool isPalindrome(string s) {
            string t;
            int n = s.size();
            for (int i = 0; i < n; i++)
            {
                if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
                {
                    if (s[i] >= 'A' && s[i] <= 'Z')
                    {
                        s[i] += 32;
                    }
                    t += s[i];
                }
            }
            int l = 0, r = t.size() - 1;
            while (l < r)
            {
                if (t[l] != t[r])
                {
                    return false;
                }
                l++;
                r--;
            }
            return true;
        }
    };*/

    size_t i = 0;
    cout << i << endl;
    string s2("hello");
    string::iterator ptr1 = s2.end();
    string::iterator ptr2 = s2.begin();

    class Solution {
    public:
        //第一个参数要加&这个符号，否则不改变结果
        void reverse(string& s, int left, int right) {
            while (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        string reverseStr(string s, int k) {
            //每次跳2K个距离
            for (int i = 0; i < s.size(); i += 2 * k) {
                // 每隔 2k 个字符的前 k 个字符进行反转
                // 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
                if (i + k <= s.size()) {
                    //反转区间一般为左闭右开（直接调用官方reverse函数）
                    //自己写的左闭右闭的反转函数，所以减一
                    reverse(s, i, i + k - 1);
                }
                else {//剩余字符少于 k 个，将剩余字符全部反转
                    reverse(s, i, s.size() - 1);
                }
            }
            return s;
        }
    };

   



        class Solution {
        public:
            string reverseStr(string s, int k) {
                for (int i = 0; i < s.size(); i += (2 * k)) {
                    // 1. 每隔 2k 个字符的前 k 个字符进行反转
                    // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
                    if (i + k <= s.size()) {
                        reverse(s.begin() + i, s.begin() + i + k);
                        continue;
                    }
                    // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
                    reverse(s.begin() + i, s.begin() + s.size());
                }
                return s;
            }
    };


        class Solution {
        public:
            string reverseWords(string s) {
                int start = 0;
                for (int i = 0; i < s.length(); i++) {
                    if (s[i] == ' ') {
                        reverse(s.begin() + start, s.begin() + i);
                        start = i + 1;
                    }
                }
                reverse(s.begin() + start, s.end());//注意最后一个单词是特殊情况
                return s;
            }
        };


    
}
	
int main()
{
	//Test1();
	//Test2();
	Test3();

}