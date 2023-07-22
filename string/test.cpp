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
        //��һ������Ҫ��&������ţ����򲻸ı���
        void reverse(string& s, int left, int right) {
            while (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        string reverseStr(string s, int k) {
            //ÿ����2K������
            for (int i = 0; i < s.size(); i += 2 * k) {
                // ÿ�� 2k ���ַ���ǰ k ���ַ����з�ת
                // ʣ���ַ�С�� 2k �����ڻ���� k ������תǰ k ���ַ�
                if (i + k <= s.size()) {
                    //��ת����һ��Ϊ����ҿ���ֱ�ӵ��ùٷ�reverse������
                    //�Լ�д������ұյķ�ת���������Լ�һ
                    reverse(s, i, i + k - 1);
                }
                else {//ʣ���ַ����� k ������ʣ���ַ�ȫ����ת
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
                    // 1. ÿ�� 2k ���ַ���ǰ k ���ַ����з�ת
                    // 2. ʣ���ַ�С�� 2k �����ڻ���� k ������תǰ k ���ַ�
                    if (i + k <= s.size()) {
                        reverse(s.begin() + i, s.begin() + i + k);
                        continue;
                    }
                    // 3. ʣ���ַ����� k ������ʣ���ַ�ȫ����ת��
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
                reverse(s.begin() + start, s.end());//ע�����һ���������������
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