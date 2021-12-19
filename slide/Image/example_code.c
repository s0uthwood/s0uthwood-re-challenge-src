#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int math;
    int eng;
    int sum;
    char name[20];
} Stu;
int main() {
    FILE* fp;
    Stu stu[5];
    printf("请输入5个同学的信息：姓名，2门成绩:\n");
    for(int i = 0; i < 5; i++) {
        scanf("%s %d %d", stu[i].name, &(stu[i].math),
            &(stu[i].eng));
        stu[i].sum = stu[i].math + stu[i].eng;
    }
    if((fp = fopen("stud","w")) == NULL) {
        printf("error: cannot open file!\n");
        exit(0);
    }
    for(int i = 0; i < 5; i++)
        fprintf(fp, "%s %d %d %d\n", stu[i].name, stu[i].math, 
            stu[i].eng, stu[i].sum); 
    fclose(fp);
    return 0;
}

