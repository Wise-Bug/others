#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;


char s[10010]; //������ű��������ַ���

int len,ctor; //�����ַ����ĳ��ȡ�ctorΪ����ʱ�õ����α�


//����Ϊһ���ݹ���򣬵����������ʱ�临�Ӷ�Ϊ O(n)
void dfs(int flag, int kg, int arr_sum, int arr_num)
{
    if(ctor<len&&(arr_sum>arr_num||arr_sum==0))//�߽���������
    {
        int num=0;//�����õ�
        int zf=1;//�ж������õ�


        if(s[ctor]=='+')//���ַ���
            flag=1;
        else if(s[ctor]=='-')//����
            flag=2;
        else if(s[ctor]==':')//������
            flag=3;
        else if(s[ctor]=='$')//�����ַ���
            flag=4;
        else if(s[ctor]=='*')//����
            flag=5;
        else //����Ϊ����ֱ������
        {
            printf("Error\n");
            return;
        }


        for(int i=0;i<kg;++i)//Ϊ���������
        {
            printf("  |:");
        }


        while(flag==1)//���ַ����Ĵ������
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

        while(flag==2)//������Ĵ������
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
        while(flag==3)//�����͵Ĵ������
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


        while(flag==4)//�����ַ����Ĵ������
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


        while(flag==5)//���鲿�ֵĴ������
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
        ctor=0;//�±��ʼΪ0
        len = strlen(s);//���㳤��


        dfs(0, 0, 0, 0);//�ݹ飺�������͡��ո�������������Ƕ�ף�������Ƕ����������ǰǶ�ײ���
    }
    return 0;
}

