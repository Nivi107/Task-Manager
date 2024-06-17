#include<stdio.h>
#define MAX_TASKS 100
#include<string.h>
struct Tasks{
    char taskname[100];
    int completed;
    int priority;
};
void Addtask(struct Tasks tasklist[],int *taskcount,char tasktodo[],int prior){
       if(*taskcount < MAX_TASKS){
         strcpy(tasklist[*taskcount].taskname,tasktodo);
         tasklist[*taskcount].completed = 0;
         tasklist[*taskcount].priority = prior;
         (*taskcount)++;
         printf("Task has been added successfully\n");
        }
        else{
            printf("Sorry.The maximum of task reached.No more tasks can be added\n");
        }
}
void Bubblesort(struct Tasks tasklist[], int taskcount){
    for(int m=0;m<taskcount-1;m++){
    for(int n=0;n<taskcount-m-1;n++){
      if (tasklist[n].priority < tasklist[n + 1].priority) {
                struct Tasks temp1 = tasklist[n];
                tasklist[n] = tasklist[n + 1];
                tasklist[n + 1] = temp1;
    }
  }
}
  for(int i=0;i < taskcount-1;i++){
    for(int j=0;j<taskcount-i-1;j++){
      if (tasklist[j].completed > tasklist[j + 1].completed) {
                struct Tasks temp = tasklist[j];
                tasklist[j] = tasklist[j + 1];
                tasklist[j + 1] = temp;
    }
  }
}
}
void Listtask(struct Tasks tasklist[],int taskcount){
  if(taskcount==0){
    printf("Opps! There is no tasks to list\n");
  }
    else{
            printf("The list of tasks for today\n");
            Bubblesort(tasklist,taskcount);
            int i;
             for(i=0;i<taskcount;i++){
                printf("%d. %s [%s] #Priority level:%d\n",i+1,tasklist[i].taskname,
                       tasklist[i].completed ? "Completed" : "Not completed",tasklist[i].priority);
             }
    }
}
void MarkTaskAsCompleted(struct Tasks taskList[],int taskcount,int index){
 if(index>=0 && index<taskcount)
    {
        taskList[index].completed=1;
        printf("Task marked as completed.\n");
        Listtask(taskList,taskcount);
    }
    else
    {
        printf("Invalid task index.\n");
    }
}
void ChangePriority(struct Tasks taskList[],int taskcount,int index,int changeprior){
 if(index>=0 && index<taskcount)
    {
        taskList[index].priority= changeprior;
        printf("Priority level changed to %d.\n",changeprior);
        Listtask(taskList,taskcount);
    }
    else
    {
        printf("Invalid task index.\n");
    }
}
void Searchtask(struct Tasks tasklist[],int taskcount,char tosearch[]){

 char tosearch_lowercase[200];
 int tosearch_length = strlen(tosearch);
 int found=0;
 for(int j = 0; tosearch[j] != '\0'; j++) {
        tosearch_lowercase[j] = tolower(tosearch[j]);
    }
    tosearch_lowercase[tosearch_length] = '\0';

    for(int i = 0; i < taskcount; i++) {
        int task_length = strlen(tasklist[i].taskname);
        char task_lowercase[100];

        for(int j = 0; tasklist[i].taskname[j] != '\0'; j++) {
            task_lowercase[j] = tolower(tasklist[i].taskname[j]);
        }
        task_lowercase[task_length] = '\0';

        while (task_length > 0 && ispunct(task_lowercase[task_length - 1])) {
            task_length--;
        }

        if (tosearch_length == task_length && strncmp(task_lowercase, tosearch_lowercase, tosearch_length) == 0) {
            printf("Task found at index %d\n",i+1);
            printf("TASK: %s\n", tasklist[i].taskname);
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("No such task found\n");
    }
}

    printf("Tasks starting with letter '%c':\n", letter);
    int taskfound=0;
    for (int i = 0; i < taskcount; i++) {
        if (tolower(tasklist[i].taskname[0]) == tolower(letter)) {
            printf("%d. %s [%s] #Priority level:%d\n", i + 1, tasklist[i].taskname,
                tasklist[i].completed ? "Completed" : "Not completed", tasklist[i].priority);
                taskfound=1;
        }
    }
    if(taskfound==0){
        printf("No tasks are starting with letter %c\n",letter);
    }
}
void Removetask(struct Tasks taskList[],int  *taskcount,int index)
{
    if((index>=0) && (index < *taskcount))
    {
        int i;
        for(i=index; i<*taskcount-1;i++)
        {
            taskList[i]=taskList[i+1];
        }
        (*taskcount)--;
        printf("Task removed successfully.\n");
    }
    else
    {
        printf("Invalid task index.\n");
    }
}

int main(){
struct Tasks tasklist[MAX_TASKS];
int taskcount=0;
int choice,index;
char tasktodo[200];
char tosearch[200];
int prior;
int changeprior;
do{
    printf("Welcome to Task manager!\n");
    printf("1.Add task\n");
    printf("2.List the tasks\n");
    printf("3.Mark task as completed\n");
    printf("4.Change the priority level of task\n");
    printf("5.Search for a task\n");
    printf("6.List all the tasks starting with particular letter\n");
    printf("7.Delete task\n");
    printf("8.Exit\n");
    printf("Enter your choice:\n");
    scanf("%d",&choice);

switch(choice){
 case 1:
    printf("Enter the task:\n");
    getchar();
    gets(tasktodo);
    printf("Enter the priority level(2-High,1-Medium,0-Low) ");
    scanf("%d",&prior);
    Addtask(tasklist,&taskcount,tasktodo,prior);
    break;
 case 2:
    Listtask(tasklist,taskcount);
    break;
 case 3:
    printf("Enter the index of the task to mark as completed:");
    scanf("%d",&index);
    MarkTaskAsCompleted(tasklist,taskcount, index-1);
    break;
 case 4:
    printf("Enter the index of task to change the priority level\n");
    scanf("%d",&index);
    printf("Enter the priority level to be changed\n");
    scanf("%d",&changeprior);
    ChangePriority(tasklist,taskcount,index-1,changeprior);
    break;
 case 5:
    printf("Enter the task to search\n");
    getchar();
    gets(tosearch);
    Searchtask(tasklist,taskcount,tosearch);
    break;
 case 6:
    printf("Enter the letter to list tasks starting with: ");
    getchar();
    char letter;
    scanf("%c", &letter);
    ListTasksStartingWithLetter(tasklist, taskcount, letter);
    break;
 case 7:
     printf("Enter the index of the task to remove:");
     scanf("%d",&index);
     Removetask(tasklist,&taskcount, index-1);
     break;
 case 8:
    printf("Exiting the Task Manager.\n");
    break;
 default:
    printf("Invalid choice. Please try again.\n");
}
}while(choice!=8);
return 0;
}
