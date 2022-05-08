//O(kn), 메모리를 많이 사용하는 코드
#include <stdio.h>

char str, strvalue[30], data[300], tree[1500000];

int main()
{
    int k;
    scanf("%d", &k);

    for(int i=1; i<=k; i++)
    {
        scanf("\n%c %s", &str, strvalue);

        int idx=1;

        for(int idx=0; strvalue[idx]!='\0'; idx++)
        {
            if(strvalue[idx] == '0') idx*=2;
            else idx=idx*2+1;
        }
        tree[idx]=str; //호프만코드로 주어진 문자를 이진트리에 저장
    }

    scanf("\n%s", data);
    int idx=1;

    for(int i=0; data[i]!='\0'; i++)
    {
        if(data[i]=='0') idx*=2;
        else idx=idx*2+1;
        if(tree[idx]!=0) //이진트리 탐색 중 저장된 문자 발견한다면
        {
            printf("%c", tree[idx]); //문자출력
            idx=1; //맨처음으로 복귀
        }
    }

    return 0;
}


/*O(k*lg n) 문자의 개수 k, map을 만드는 시간 O(lg n)
#include <map>
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int mian()
{
    map<string, char> mp;
    int k, i;
    char ch;
    string str, a;

    cin >> k;

    for(i=0; i<k; i++)
    {
        cin >> ch >> str;
        mp[str] = ch;
    }

    cin >> str;

    for(i=0; i<str.length(); i++)
    {
        a+=str[i];
        if(mp[a])
        {
            cout << mp[a];
            a.clear();
        }
    }
    return 0;
}
*/