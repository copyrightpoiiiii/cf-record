#include<cstdio>
#include<cstdlib>
#include<ctime>

int main()
{   long s,t;
    while(1){
    	
        system("cls");
        do{
            system("data > try.in"); //data???????
            s=clock();
            system("C < try.in > try1.out");  //a??????
            t=clock();
            system("7 < try.in > try2.out");  //b??????
            if(system("fc try1.out try2.out > nul"))
                break;
            else printf("AC time: %ldms\n",t-s);
        }while(1);
        printf("WA time: %ldms\n",t-s);  //???? 
        system("fc try1.out try2.out");
        system("pause>nul");
    }
    return 0;
}
