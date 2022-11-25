#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;

struct Element {
    string ID;
    string name;
    string job;
    double salary;
    
    Element *next;
};


struct List {
    int size;
    Element *head, *tail;
};

List * createEmptyList(){
    List *ls;
    ls = new List();

    ls->size = 0;
    ls->head = NULL;
    ls->tail = NULL;

    return ls;
}

int isIdExist(List *ls, string ID){
    Element *tmp;
    tmp = ls->head;
    int result = 0;

    while (tmp != NULL)
    {
        if(tmp->ID == ID) {
            result = 1;
        }
        tmp = tmp->next;
    }
    return result;
}




void insertBegin(List *ls, string ID, string name, string job, double salary) {
    Element * e;
    e = new Element();

    if(isIdExist(ls, ID) == 1) cout<<"\n\tThis ID is already existed"<<endl;

    e->salary = salary;
    e->ID = ID;
    e->name = name;
    e->job = job;

    e->next = ls->head;
    ls->head = e;
    if(ls->size == 0) {
        ls->tail = e;
    }
    ls->size ++; 

}

void insertEnd(List *ls, string ID, string name, string job, double salary){
    Element * e;
    if(ls->size == 0){
        insertBegin(ls, ID, name, job, salary);
    }
    else {
        e = new Element();

        e->salary = salary;
        e->ID = ID;
        e->name = name;
        e->job = job;

        e->next = NULL;

        ls->tail->next = e;
        ls->tail = e;
        ls->size ++;
    }

}

void displayData(List *ls){
    Element * tmp;
    tmp = ls->head;
    if(ls->size == 0) cout<<"\n\tThere is no data right now!!!"<<endl;
    while (tmp != NULL)
    {
        cout<<"\n\tAll data in this list"<<endl;
        cout<<"\n\tName: "<<tmp->name<<"\tID: "<<tmp->ID<<"\tJob: "<<tmp->job<<"\tSalary: $"<<tmp->salary<<endl;
        tmp = tmp->next;
    }
    
}

void deleteBegin(List *ls){
    Element * tmp;
    tmp = ls->head;
    ls->head = ls->head->next;
    
    delete tmp;

    if(ls->size == 1) ls->tail = NULL;
    ls->size--; 
}

void deleteLast(List *ls){
    Element * tmp;
    int i;
    if(ls->size == 1){
        deleteBegin(ls);
    }
    else{
        tmp = ls->head;
        for ( i = 1; i <= ls->size - 2; i++)
        {
            tmp = tmp->next;
        }
        ls->tail = tmp;
        tmp = tmp->next;
        ls->tail->next = NULL;
        delete(tmp);
        ls->size--;
    }
}


void deleteAll(List *ls){
    while (ls->size > 0)
    {
        deleteBegin(ls);
    }
    
}


void searchById(List *ls, string ID){
    Element *tmp;
    tmp = ls->head;
    int counter = 0;
    if(isIdExist(ls, ID) == 0) cout<<"\n\tThis ID is not found"<<endl;
    else cout<<"\n\tHere is the information about this ID you searched for"<<endl;
    while (tmp != NULL)
    {
        if(tmp->ID == ID) {
            cout<<"\n\tID: "<<tmp->ID<<endl;
            cout<<"\n\tName: "<<tmp->name<<endl;
            cout<<"\n\tJob: "<<tmp->job<<endl;
            cout<<"\n\tSalary: "<<tmp->salary<<endl;
        }
        tmp = tmp->next;
    }
}


int isSalaryExist(List *ls, double salary){
    Element *tmp;
    tmp = ls->head;
    int result = 0;

    while (tmp != NULL)
    {
        if(tmp->salary == salary) {
            result = 1;
        }
        tmp = tmp->next;
    }
    return result;
}

void filterUserBySalary(List *ls, double salary){
    Element *tmp;
    tmp = ls->head;
    int counter = 0;
    if(isSalaryExist(ls, salary) == 0) cout<<"\n\tThe salary you search for is not found"<<endl;
    else cout<<"\n\tHere is the information about the salary you searched for"<<endl;
    while (tmp != NULL)
    {
        if(tmp->salary == salary) {
            cout<<"\n\tID: "<<tmp->ID<<endl;
            cout<<"\n\tName: "<<tmp->name<<endl;
            cout<<"\n\tJob: "<<tmp->job<<endl;
            cout<<"\n\tSalary: "<<tmp->salary<<endl;
        }
        tmp = tmp->next;
    }
}

int isSalaryExist(List *ls, string job){
    Element *tmp;
    tmp = ls->head;
    int result = 0;

    while (tmp != NULL)
    {
        if(tmp->job == job) {
            result = 1;
        }
        tmp = tmp->next;
    }
    return result;
}

void filterUserByJob(List *ls, string job){
    Element *tmp;
    tmp = ls->head;
    int counter = 0;
    if(isSalaryExist(ls, job) == 0) cout<<"\n\tThe job you search for is not found"<<endl;
    else cout<<"\n\tHere is the information about the job you searched for"<<endl;
    while (tmp != NULL)
    {
        if(tmp->job == job) {
            cout<<"\n\tID: "<<tmp->ID<<endl;
            cout<<"\n\tName: "<<tmp->name<<endl;
            cout<<"\n\tJob: "<<tmp->job<<endl;
            cout<<"\n\tSalary: "<<tmp->salary<<endl;
        }
        tmp = tmp->next;
    }
}


void searchByIdAndDelete(List *ls, string ID)
{
      //temp is used to freeing the memory
    Element *temp;
    Element *e;
    e = new Element();
    //key found on the head Element.
    //move to head Element to the next and free the head.
    if(isIdExist(ls, ID) == 0) cout<<"\n\tThis ID is not found"<<endl;
    if(ls->head->ID== ID)
    {
        
        temp = ls->head;    //backup to free the memory
        ls->head = ls->head->next;
        delete temp;
    }
    else
    {
        // Element *current  = ls->head;
        e = ls->head;
        while(e->next != NULL)
        {
            //if yes, we need to delete the current->next Element
            if(e->next->ID == ID)
            {   
                
                temp = e->next;
                //Element will be disconnected from the linked list.
                e->next = e->next->next;
                delete temp;
                break;
            }
            //Otherwise, move the current Element and proceed
            e = e->next;
           
        }
    }
    
}



double findMax1(List *ls){
    double max1 = -99999999; //make assumption
    Element *t;

    t = ls->head;
    while (t != NULL)
    {
        if(t->salary > max1) {
            max1 = t->salary;
        }
        t = t->next;
    }
    return max1;
}

double findMax2(List *ls){
    double max2 = -99999999; //make assumption
    double max1 = findMax1(ls);
    Element *t;

    t = ls->head;
    while (t != NULL)
    {
        if(t->salary > max2 && t->salary != max2) {
            max2 = t->salary;
        }
        t = t->next;
    }
    return max2;
}

double findMax3(List *ls){
    double max3 = -99999999; //make assumption
    double max2 = findMax2(ls);
    Element *t;

    t = ls->head;
    while (t != NULL)
    {
        if(t->salary > max3 && t->salary != max3) {
            max3 = t->salary;
        }
        t = t->next;
    }
    return max3;
}

int counter = 0;

void displayMax(List *ls, double max1){
    Element *tmp;
    tmp = ls->head;
    while (tmp != NULL)
    {
        if(tmp->salary == max1){
            cout<<"\n\tUsers ID: "<<tmp->ID<<endl;
            cout<<"\n\tUsers name: "<<tmp->name<<endl;
            cout<<"\n\tUsers job: "<<tmp->job<<endl;
            cout<<"\n\tUsers Salary "<<tmp->salary<<endl;
            counter++;
            if(counter == 3){
                break;
            } 
        }
        tmp = tmp -> next;
    }
}


double findAverageSalary(List *ls) {
    Element *t;
    t = ls->head;

    int count = 0; // Initialize count
    int sum = 0;
    double average = 0.0;
    while (t != NULL)
    {
        count++;
        sum += t->salary;
        t = t->next;
    }
     // calculate average
    average = (double)sum / count;
    return average;
}

double findMin(List *ls) {
    double min = 9999999999;
    Element *t;
    t = ls->head;
    while (t != NULL)
    {
        if(t->salary < min){
            min = t->salary;
        }
        t = t->next;
    }
    return min;
}


void updateData(List*ls, string ID, string newID, string name, string job, double salary) {
   int pos = 0;
   
   if(ls->head ==NULL) {
      printf("Linked List not initialized");
      return;
   } 

   ls->tail = ls->head;
   while(ls->tail->next!=NULL) {
      if(ls->tail->ID == ID) {
         ls->tail->ID= newID; 
         ls->tail->name= name; 
         ls->tail->job= job; 
         ls->tail->salary= salary; 
         cout<<"\n\tID: "<<ID<<" has been updated: "<<endl;
         cout<<"\n\tID: "<<ID<<endl;
         cout<<"\n\tName: "<<name<<endl;
         cout<<"\n\tJob: "<<job<<endl;
         cout<<"\n\tSalary: "<<salary<<endl;
         return;
      }
      
      ls->tail = ls->tail->next;
      pos++;
   }
   cout<<"\n\tThat ID is not exist in the list"<<endl;
}

void sort(List * ls) {
    Element * current;
    current = ls->head;
    Element * index;
    index = NULL;

    int temp;
    if(current == NULL) {  
        
        return;  
    }  
    else {  
        while(current != NULL) {  
            //Node index will point to node next to current  
            index = current->next;  
                
            while(index != NULL) {  
                //If current node's data is greater than index's node data, swap the data between them  
                if(current->salary > index->salary) {  
                    temp = current->salary;  
                    current->salary = index->salary;  
                    index->salary = temp;  
                }  
                index = index->next;  
            }  
            current = current->next;  
        }      
    } 
}

void sortReverse(List * ls) {
    Element * current;
    current = ls->head;
    Element * index;
    index = NULL;

    int temp;
    if(current == NULL) {  
        
        return;  
    }  
    else {  
        while(current != NULL) {  
            //Node index will point to node next to current  
            index = current->next;  
                
            while(index != NULL) {  
                //If current node's data is greater than index's node data, swap the data between them  
                if(current->salary < index->salary) {  
                    temp = current->salary;  
                    current->salary = index->salary;  
                    index->salary = temp;  
                }  
                index = index->next;  
            }  
            current = current->next;  
        }      
    } 
}

void saveData(List *ls){
    fstream file;
    file.open("data.txt", ios::app);
    Element * tmp;
    tmp = ls->head;
    if(file.is_open()) {
        while (tmp != NULL)
        {
            file<<"\n\tName: "<<tmp->name<<"\tID: "<<tmp->ID<<"\tJob: "<<tmp->job<<"\tSalary: $"<<tmp->salary<<endl;
            tmp = tmp->next;
        }
    }
    
    file.close();
}


int loading(){
    const int trigger = 500; // ms
    const int numDots = 4;
    const char prompt[] = "\n\tLoading";
    long long k = 0;
    while (1 && k < 1) {
        // Return and clear with spaces, then return and print prompt.
        printf("\r%*s\r%s", sizeof(prompt) - 1 + numDots, "", prompt);
        fflush(stdout);

        // Print numDots number of dots, one every trigger milliseconds.
        for (int i = 0; i < numDots; i++) {
            usleep(trigger * 1000);
            fputc('.', stdout);
            fflush(stdout);
        }
        k += 1;
    }
    return 0;
}
