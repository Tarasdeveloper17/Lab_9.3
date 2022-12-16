#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

struct StudentInfo
{
    string surname;
    string init;
    unsigned php;
    unsigned math;
    unsigned c;
    unsigned web;
    unsigned java;
};

void Create(StudentInfo* p, int N);
void Print(StudentInfo* p, const int N);
void EditInfo(StudentInfo* &p, int &N);
void NewStud(StudentInfo* &p, int &N);
void EditStudent(StudentInfo*& p, int& N);
void DeleleStudent(StudentInfo*& p, int& N, int numb);
void MaxScore(StudentInfo* p, const int N);
void ThreeScore(StudentInfo* p, const int N);
int TwoScore(StudentInfo*& p, int& N);
void DeleleStudentWithTwo(StudentInfo*& p, int& N, int res);
int main()
{
    int N;
    cout << "N: "; cin >> N;
    StudentInfo* p = new StudentInfo[N];
    Create(p, N);
    int menuItem;
    string store;
    
    do
    {
        cout << endl;
        cout << "Your choise:" << endl;
        cout << "[1] - Write info" << endl;
        cout << "[2] - change info" << endl;
        cout << "[3] - List of all students" << endl;
        cout << "[4] - list of students who passed exams only for 5"<< endl;
        cout << "[5] - List of students with 3" << endl;
        cout << "[6] - list of students with  2" << endl << endl;

        cout << "[0] - End." << endl << endl;
        cout << "Enter: "; cin >> menuItem;
        switch (menuItem)
        {
        case 0:
            break;
        case 1:
            cout << "N: "; cin >> N;
            Create(p, N);
            break;
        case 2:
            EditInfo(p, N);
            break;
        case 3:
            Print(p, N);
            break;
        case 4:
            cout << endl;
            cout << "Students who have passed all exams for max mark: " << endl;
            MaxScore(p, N);
            break;
        case 5:
            cout << endl;
            cout << "Students with  3: " << endl;
            ThreeScore(p, N);
            break;
        case 6:
            cout << endl;
            cout << "Students with  2: " << endl;
            TwoScore(p, N);
            break;
        default:
            cout << "Error ";
        }
    } while (menuItem != 0);
    return 0;
}

void Create(StudentInfo* p, int N)
{
    for (int i = 0; i < N; i++) {
        cout << endl;
        cout << "Student № " << i + 1 << ":" << endl;
        cin.get();
        cin.sync();
        cout << "Surname: "; getline(cin, p[i].surname);
        cout << "INIT: "; getline(cin, p[i].init);
        cout << "Assessment in math: "; cin >> p[i].math;
        if (p[i].math > 5) {
            cout << "Max assessment in math" << endl << endl;
            p[i].math = 5;
        }
         if (p[i].math < 0) {
            cout << "Min assessment in math" << endl << endl;
            p[i].math = 0;
        }
        cout << "Assessment in C: "; cin >> p[i].c;
        if (p[i].c > 5) {
            cout << "Max assesment in C" << endl << endl;
            p[i].c = 5;
        }
        if (p[i].c < 0) {
            cout << "Min assessment in C" << endl << endl;
            p[i].c = 0;
        }
        cout << "Assessment in PHP: "; cin >> p[i].php;
        if (p[i].php > 5) {
            cout << "Max assessment in PHP" << endl << endl;
            p[i].php = 5;
        }
        if (p[i].php < 0) {
            cout << "Min assessment in PHP" << endl << endl;
            p[i].php = 0;
        }
        cout << "Assessment in WEB: "; cin >> p[i].web;
        if (p[i].web > 5) {
            cout << "Max assessment in web" << endl << endl;
            p[i].web = 5;
        }
        if (p[i].web < 0) {
            cout << "Min assessment in web" << endl << endl;
            p[i].web = 0;
        }
        cout << "Assessment in JAVA: "; cin >> p[i].java;
       if (p[i].java > 5) {
            cout << "Max assessment in java" << endl << endl;
            p[i].java = 5;
        }
        if (p[i].java < 0) {
            cout << "Min assessment in java" << endl << endl;
            p[i].java = 0;
        }
        cout << endl;
    }
    cout << endl;
}

void Print(StudentInfo* p, const int N)
{
    cout << "=================================================================================================================="
        << endl;
    cout << "|  №  |  Surname  |  INIT  |  PHP  |  MATH  |  C |  WEB  |  JAVA  |"
        << endl;
    cout << "------------------------------------------------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "|" << setw(3) << i + 1 << setw(3) << "|";
        cout << setw(6) << p[i].surname << setw(7) << "|";
        cout << setw(6) << p[i].init << setw(7) << "|";
        cout << setw(5) << p[i].php << setw(6) <<  "|";
        cout << setw(7) << p[i].math << setw(8) << "|";
        cout << setw(9) << p[i].c << setw(9) << "|";
        cout << setw(8) << p[i].web << setw(9) << "|";
        cout << setw(10) << p[i].java << setw(10) << "|";
        cout << endl;
    }
    cout << "=================================================================================================================="
        << endl;
    cout << endl;
}

void EditInfo(StudentInfo* &p, int &N) {
    int item;
    int res = TwoScore(p, N);
    cout << endl << endl;
    cout << "[1] - Add new student" << endl;
    cout << "[2] - Edit student information" << endl;
    cout << "[3] - Remove info about student with 2" << endl;
    cout << "[4] - Remove info about student " << endl << endl;

    cout << "[0] - Back" << endl << endl;
    cout << "Your choise: "; cin >> item;
    switch (item) {
    case 0:
        return;
        break;
    case 1:
        NewStud(p, N);
        break;
    case 2:
        EditStudent(p, N);
        break;
    case 3:
            DeleleStudentWithTwo(p, N, res);
        break;
    case 4:
        cout << endl;
            int numb;
            cout << "Number of student to delete "; cin>> numb;
            numb--;
            DeleleStudent(p, N, numb);
        break;
    default:
        cout << "ERROR " << endl;
    }
}


void NewStud(StudentInfo* &p, int &N) {
    StudentInfo* temp = new StudentInfo[N];
    for (int i = 0; i < N; i++) {
        temp[i] = p[i];
    }
    delete[] p;
    N++;
    StudentInfo* s = new StudentInfo[N];
    p = s;
    for (int i = 0; i < N; i++) {
        p[i] = temp[i];
    }
    int i = N - 1;
    cout << endl;
    cout << endl;
    cout << "Student № " << i + 1 << ":" << endl;
    cout << "Surname: "; cin >> p[i].surname;
    cout << "INIT: "; cin >> p[i].init;
    cout << "Assessment in math: "; cin >> p[i].math;
    if (p[i].math > 5) {
        cout << "Max assessment in math" << endl << endl;
        p[i].math = 5;
    }
     if (p[i].math < 0) {
        cout << "Min assessment in math" << endl << endl;
        p[i].math = 0;
    }
    cout << "Assessment in C: "; cin >> p[i].c;
    if (p[i].c > 5) {
        cout << "Max assesment in C" << endl << endl;
        p[i].c = 5;
    }
    if (p[i].c < 0) {
        cout << "Min assessment in C" << endl << endl;
        p[i].c = 0;
    }
    cout << "Assessment in PHP: "; cin >> p[i].php;
    if (p[i].php > 5) {
        cout << "Max assessment in PHP" << endl << endl;
        p[i].php = 5;
    }
    if (p[i].php < 0) {
        cout << "Min assessment in PHP" << endl << endl;
        p[i].php = 0;
    }
    cout << "Assessment in WEB: "; cin >> p[i].web;
    if (p[i].web > 5) {
        cout << "Max assessment in web" << endl << endl;
        p[i].web = 5;
    }
    if (p[i].web < 0) {
        cout << "Min assessment in web" << endl << endl;
        p[i].web = 0;
    }
    cout << "Assessment in JAVA: "; cin >> p[i].java;
   if (p[i].java > 5) {
        cout << "Max assessment in java" << endl << endl;
        p[i].java = 5;
    }
    if (p[i].java < 0) {
        cout << "Min assessment in java" << endl << endl;
        p[i].java = 0;
    }
    cout << endl;
}



void EditStudent(StudentInfo*& p, int& N) {
    int numb;
    cout << "Number: "; cin >> numb;
    int i = numb - 1;
    cout << endl;
    cout << "Student № " << i + 1 << ":" << endl;
    cout << "Surname: "; cin >> p[i].surname;
    cout << "INIT: "; cin >> p[i].init;
    cout << "Assessment in math: "; cin >> p[i].math;
    if (p[i].math > 5) {
        cout << "Max assessment in math" << endl << endl;
        p[i].math = 5;
    }
     if (p[i].math < 0) {
        cout << "Min assessment in math" << endl << endl;
        p[i].math = 0;
    }
    cout << "Assessment in C: "; cin >> p[i].c;
    if (p[i].c > 5) {
        cout << "Max assesment in C" << endl << endl;
        p[i].c = 5;
    }
    if (p[i].c < 0) {
        cout << "Min assessment in C" << endl << endl;
        p[i].c = 0;
    }
    cout << "Assessment in PHP: "; cin >> p[i].php;
    if (p[i].php > 5) {
        cout << "Max assessment in PHP" << endl << endl;
        p[i].php = 5;
    }
    if (p[i].php < 0) {
        cout << "Min assessment in PHP" << endl << endl;
        p[i].php = 0;
    }
    cout << "Assessment in WEB: "; cin >> p[i].web;
    if (p[i].web > 5) {
        cout << "Max assessment in web" << endl << endl;
        p[i].web = 5;
    }
    if (p[i].web < 0) {
        cout << "Min assessment in web" << endl << endl;
        p[i].web = 0;
    }
    cout << "Assessment in JAVA: "; cin >> p[i].java;
   if (p[i].java > 5) {
        cout << "Max assessment in java" << endl << endl;
        p[i].java = 5;
    }
    if (p[i].java < 0) {
        cout << "Min assessment in java" << endl << endl;
        p[i].java = 0;
    }
    cout << endl;
}


void DeleleStudent(StudentInfo*& p, int& N, int numb) {
    StudentInfo* temp = new StudentInfo[N];
    for (int i = 0; i < N; i++) {
        temp[i] = p[i];
    }
    
    delete[] p;

    StudentInfo* s = new StudentInfo[N - 1];
    p = s;
    int j = 0;
    for (int i = 0; i < N; i++) {
        if (i != numb) {
            p[j] = temp[i];
            j++;
        }
    }
    N--;
}

void MaxScore(StudentInfo* p, const int N)
{
    cout << "=================================================================================================================="
        << endl;
    cout << "|  №  |  Surname  |  INIT  |  PHP  |  MATH  |  C |  WEB  |  JAVA  |"
        << endl;
    cout << "------------------------------------------------------------------------------------------------------------------"
        << endl;
    int k = 0;
    for (int i = 0; i < N; i++)
    {
        if (p[i].math == 5.0 &&
            p[i].java == 5.0 &&
            p[i].web == 5.0 &&
            p[i].c == 5.0 &&
            p[i].php == 5.0) {
            cout << "|" << setw(3) << i + 1 << setw(3) << "|";
            cout << setw(6) << p[i].surname << setw(7) << "|";
            cout << setw(6) << p[i].init << setw(7) << "|";
            cout << setw(5) << p[i].php << setw(6) << "|";
            cout << setw(7) << p[i].math << setw(8) << "|";
            cout << setw(9) << p[i].c << setw(9) << "|";
            cout << setw(8) << p[i].web << setw(9) << "|";
            cout << setw(10) << p[i].java << setw(10) << "|";
            cout << endl;
            k++;
        }
    }
    if (k == 0) {
        cout << endl;
        cout << "NOT FOUND student who passed everything good " << endl << endl;
    }
    cout << "=================================================================================================================="
        << endl;
    cout << endl;
}

void ThreeScore(StudentInfo* p, const int N) {
    cout << "=================================================================================================================="
        << endl;
    cout << "|  №  |  Surname  |  INIT  |  PHP  |  MATH  |  C |  WEB  |  JAVA  |"
        << endl;
    cout << "------------------------------------------------------------------------------------------------------------------"
        << endl;
    int k = 0;
    for (int i = 0; i < N; i++)
    {
        if (p[i].math == 3.0 ||
            p[i].java == 3.0 ||
            p[i].web == 3.0 ||
            p[i].c == 3.0 ||
            p[i].php == 3.0) {
            cout << "|" << setw(3) << i + 1 << setw(3) << "|";
            cout << setw(6) << p[i].surname << setw(7) << "|";
            cout << setw(6) << p[i].init << setw(7) << "|";
            cout << setw(5) << p[i].php << setw(6) << "|";
            cout << setw(7) << p[i].math << setw(8) << "|";
            cout << setw(9) << p[i].c << setw(9) << "|";
            cout << setw(8) << p[i].web << setw(9) << "|";
            cout << setw(10) << p[i].java << setw(10) << "|";
            cout << endl;
            k++;
        }
    }
    if (k == 0) {
        cout << endl;
        cout << "NOT FOUND Student who passed everything norm" << endl << endl;
        
    }
    cout << "=================================================================================================================="
        << endl;
    cout << endl;
    
    
}




int  TwoScore(StudentInfo*& p, int& N){
    cout << "=================================================================================================================="
        << endl;
    cout << "|  №  |  Surname  |  INIT  |  PHP  |  MATH  |  C |  WEB  |  JAVA  |"
        << endl;
    cout << "------------------------------------------------------------------------------------------------------------------"
        << endl;
    int k = 0;
    int res = 0;

    for (int i = 0; i < N; i++)
    {
        int k = 0;
        if(p[i].math == 2.0 ||
           p[i].java == 2.0 ||
           p[i].web == 2.0 ||
           p[i].c == 2.0 ||
           p[i].php == 2.0) {
            res = i+1;
            cout << "|" << setw(3) << i + 1 << setw(3) << "|";
            cout << setw(6) << p[i].surname << setw(7) << "|";
            cout << setw(6) << p[i].init << setw(7) << "|";
            cout << setw(5) << p[i].php << setw(6) << "|";
            cout << setw(7) << p[i].math << setw(8) << "|";
            cout << setw(9) << p[i].c << setw(9) << "|";
            cout << setw(8) << p[i].web << setw(9) << "|";
            cout << setw(10) << p[i].java << setw(10) << "|";
            cout << endl;
            k++;
            
            

        }
    
    }
    if (k == 0) {
        cout << endl;
        cout << "NOT FOUND Student who passed everything bad" << endl << endl;
        
    }
    cout << "=================================================================================================================="
        << endl;
    cout << endl;
    if(k > 1)
    {
        return res;
    }
    
return res;
}


void DeleleStudentWithTwo(StudentInfo*& p, int& N, int res) {
    StudentInfo* temp = new StudentInfo[N];
    for (int i = 0; i < N; i++) {
        temp[i] = p[i];
    }

    delete[] p;

    StudentInfo* s = new StudentInfo[N - 1];
    p = s;
    int j = 0;
    for (int i = 0; i < N; i++) {
        if (i !=res) {
            p[j] = temp[i];
            j++;
        }
    }
    N--;
}



