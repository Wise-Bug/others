#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;


char s[10010]; //用来存放被解析的字符串

int len,ctor; //解析字符串的长度、ctor为操作时用到的游标


//这里为一个递归程序，但整个程序的时间复杂度为 O(n)
void dfs(int flag, int kg, int arr_sum, int arr_num)
{
    if(ctor<len&&(arr_sum>arr_num||arr_sum==0))//边界跳出条件
    {
        int num=0;//计数用的
        int zf=1;//判断正负用的


        if(s[ctor]=='+')//简单字符串
            flag=1;
        else if(s[ctor]=='-')//错误
            flag=2;
        else if(s[ctor]==':')//整数型
            flag=3;
        else if(s[ctor]=='$')//批量字符串
            flag=4;
        else if(s[ctor]=='*')//数组
            flag=5;
        else //其他为错误，直接跳出
        {
            printf("Error\n");
            return;
        }


        for(int i=0;i<kg;++i)//为了输出美观
        {
            printf("  |:");
        }


        while(flag==1)//简单字符串的处理操作
        {
            ++ctor;
            if(s[ctor]=='\\'&&s[ctor+1]=='r'&&s[ctor+2]=='\\'&&s[ctor+3]=='n')
            {
                ctor=ctor+4;
                flag=0;
                break;
            }
            printf("%c",s[ctor]);
        }

        while(flag==2)//错误类的处理操作
        {
            ++ctor;
            if(s[ctor]=='\\'&&s[ctor+1]=='r'&&s[ctor+2]=='\\'&&s[ctor+3]=='n')
            {
                ctor=ctor+4;
                flag=0;
                break;
            }
            printf("%c",s[ctor]);
        }

        zf=1;
        while(flag==3)//整数型的处理操作
        {
            ++ctor;
            if(s[ctor]=='-')
            {
                zf=-1;
                ++ctor;
            }
            if(s[ctor]=='\\'&&s[ctor+1]=='r'&&s[ctor+2]=='\\'&&s[ctor+3]=='n')
            {
                ctor=ctor+4;
                flag=0;
                num=num*zf;
                printf("%d",num);

                break;
            }

            num=num*10 + s[ctor]-'0';
        }


        while(flag==4)//批量字符串的处理操作
        {
            ++ctor;
            if(s[ctor]=='-')
            {
                printf("Error\n");
                return;
            }
            if(s[ctor]=='\\'&&s[ctor+1]=='r'&&s[ctor+2]=='\\'&&s[ctor+3]=='n')
            {
                ctor=ctor+4;
                flag=0;
                for(int i=ctor;i<ctor+num;++i)
                {
                    printf("%c",s[i]);
                }
                ctor=ctor+num+4;
                break;
            }
            num=num*10 + s[ctor]-'0';
        }


        while(flag==5)//数组部分的处理操作
        {
            ++ctor;
            if(s[ctor]=='-')
            {
                printf("Error\n");
                return;
            }
            if(s[ctor]=='\\'&&s[ctor+1]=='r'&&s[ctor+2]=='\\'&&s[ctor+3]=='n')
            {
                ctor=ctor+4;
                flag=0;
                printf("---%d\n",num);
                dfs(flag, kg+1, num, 0);
                break;
            }
            num=num*10 + s[ctor]-'0';
        }


        //printf("%d",ctor);

        printf("\n");

        dfs(0,kg,arr_sum,arr_num+1);


    }
}


int main()
{
    while(gets(s))
    {
        ctor=0;//下标初始为0
        len = strlen(s);//计算长度


        dfs(0, 0, 0, 0);//递归：操作类型、空格数（区分数组嵌套）、数组嵌套总数、当前嵌套层数
    }
    return 0;
}

