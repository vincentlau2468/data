data#include <stdio.h>
#include<string.h>
typedef struct student
{
    char id[10];
    char name[10000];
    int math;
    int code;
    int eng;
} Student;

int main(void)
{
    int sum;
    int flag = 0;
    char choice;
    char idcheck[100];
    float average[100] = {0};
    Student data[10];
    scanf("%d", &sum);
    for (int i = 0; i < sum; i++)
    {
        scanf(" %s", &data[i].id);
        scanf(" %s", &data[i].name);
        scanf("%d", &data[i].math);
        scanf("%d", &data[i].code);
        scanf("%d", &data[i].eng);
    }
    for (int i = 0; i < sum; i++)
    {
        average[i] += ((data[i].math + data[i].code + data[i].eng) / 3);
    }
    while(1){

        printf("===== menu =====\n");
        printf("f: find specific student data\n");
        printf("s: show all students' data\n");
        printf("d: show the sorted students' data (high to low)\n");
        printf("a: show the sorted students' data (low to high)\n");
        printf("b: show the average score value\n");
        printf("q: quit\n");
        printf("function choice:");
        scanf(" %c", &choice);
        switch (choice)
        {
        case 'f':
            printf("Student's ID:");
            scanf(" %s", idcheck);
            for (int i = 0; i < sum; i++)
            {
                if (strcmp(idcheck, data[i].id) == 0)
                {
                    printf("%s\t", data[i].id);
                    printf("%s\t", data[i].name);
                    printf("%d\t", data[i].math);
                    printf("%d\t", data[i].code);
                    printf("%d\t", data[i].eng);
                    flag++;
                }
                if (flag == 0)
                {
                    printf("No such student");
                    break;
                }
            }
            break;

        case 's':
            for (int i = 0; i < sum; i++)
            {

                printf("%s\t", data[i].id);
                printf("%s\t", data[i].name);
                printf("%d\t", data[i].math);
                printf("%d\t", data[i].code);
                printf("%d\t", data[i].eng);
                puts("");
            }
            break;

        case 'b':
            
            for (int i = 0; i < sum; i++)
            {
                printf("%s\t", data[i].id);
                printf("%s\t", data[i].name);
                printf("%f\n", average[i]);
            }
            break;
        case 'a':  
            
            struct student temp;
            
            for(int j=0;j<sum;j++){
                for(int k=0;k<sum-1;k++){
                    if(average[k]>average[k+1]){
                        float hold =average[k];
                        temp=data[k];
                        average[k]=average[k+1];
                        data[k]=data[k+1];
                        average[k+1]=hold;
                        data[k+1]=temp;
                    }
                }
            }
            for(int i=0;i<sum;i++){
               printf("%s\t", data[i].id);
                printf("%s\t", data[i].name);
                printf("%d\t", data[i].math);
                printf("%d\t", data[i].code);
                printf("%d\t", data[i].eng);
                puts("");
            }break;
            
        case 'd':

            for(int j=0;j<sum;j++){
                for(int k=0;k<sum-1;k++){
                    if(average[j]<average[j+1]){
                        float hold =average[j];
                        average[j]=average[j+1];
                        average[j+1]=hold;
                    }
                }
            }
            for(int i=0;i<sum;i++){
               printf("%s\t", data[i].id);
                printf("%s\t", data[i].name);
                printf("%d\t", data[i].math);
                printf("%d\t", data[i].code);
                printf("%d\t", data[i].eng);
                puts("");
            }   
            break;
        }
    }
}
