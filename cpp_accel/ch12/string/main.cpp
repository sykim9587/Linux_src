#include "string.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    String s1;
    String s2(10, 'a');
    String s3 = "hello";

    const char *str = "hello, world";
    String s4(str, str + strlen("hello, world"));

    for (String::size_type i = 0; i != s4.size(); ++i)
        cout << s4[i] << endl;

    cin >> s1;
    cout << s1 << endl;

    String s5 = "hello, ";
    s5 += "world";

    String s6 = "world";
    String s7 = "hello, " + s6;

    cout << s5 << endl;
    cout << s7 << endl;

    return 0;
}