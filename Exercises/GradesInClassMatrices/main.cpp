using namespace std;

#include <iostream>
#include <iomanip>

struct metrics{
    double avg;
    int min;
    int max;
};

metrics avgMinMaxGradeStudent(int grades[]);
int minGradeStudent(int grades[]);
int maxGradeStudent(int grades[]);
double avgGradeClass(int grades[][5]);
int minGradeClass(int grades[][5]);
int maxGradeClass(int grades[][5]);
void printMetrics(metrics *pMetrics);
void fillMatrix(int grades[][5]);
int insertVote();
void printMatrix(int mat[][5], int lastRow = 0);

int main ()
{
    int grades2[4][5] = {
        {18, 24, 20, 24, 25 },
        {20, 21, 18, 10, 20 },
        {17, 24, 20, 30, 30 },
        {30, 30, 30, 30, 30 },
    };

    int grades1[4][5];

    metrics studentMetrics, classMetrics;




    //printMatrix(grades2, 2);
    fillMatrix(grades1);
    printMatrix(grades1);


    //take metrics of students
    for(int i = 0; i < 4; i++){

        studentMetrics = avgMinMaxGradeStudent(grades1[i]);
        cout << "Student " << i+1 << endl;
        printMetrics(&studentMetrics);
    
    }

    //take whole class metrics
    classMetrics.avg = avgGradeClass(grades1);
    classMetrics.max = maxGradeClass(grades1);
    classMetrics.min = minGradeClass(grades1);
    
    cout << "Class" << endl;
    printMetrics(&classMetrics);


    return 0;
}


metrics avgMinMaxGradeStudent(int grades[]){
    
    int sum = 0, min = grades[0], max = grades[0];
    metrics studentGrade;
    
    for(int i = 0; i < 5; i++){
        
        sum += grades[i];
        
        if(min > grades[i]){
            min = grades[i];
        }

        if(max < grades[i]){
            max = grades[i];
        }
    }

    studentGrade.avg = sum / 5.0;
    studentGrade.min = min;
    studentGrade.max = max;

    return studentGrade;
}

void printMetrics(metrics *pMetrics){
    cout << "Avg Grade: " << setprecision(3)<< pMetrics -> avg << endl;
    cout << "Max Grade: " << pMetrics -> max << endl;
    cout << "Min Grade: " << pMetrics -> min << endl;
}


double avgGradeClass(int grades[][5]){

    int sum = 0, i, j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 5; j++){

            sum += grades[i][j];

        }

    }

    return (sum /double(i*j));
    

}


int minGradeClass(int grades[][5]){

    int min = grades[0][0], i, j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 5; j++){

            if(min > grades[i][j]){
                min = grades[i][j];
            }
        }

    }

    return min;
    

}


int maxGradeClass(int grades[][5]){

    int max = grades[0][0], i, j;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 5; j++){

            if(max < grades[i][j]){
                max = grades[i][j];
            }
        }

    }

    return max;
    

}

int insertVote(){

    char garbageBuffer[100];
    int grade = -1;
    bool isCorrectlyInserted = false;

    while(!isCorrectlyInserted){

        if(cin.fail()){
            cin.clear();
            cin >> garbageBuffer;
        }
        else if((grade < 0) || (grade > 30)){
            cout << "Insert the grade" << endl;
            cin >> grade;
        }
        else{
            cout << "Grade Inserted Correctly" << endl;
            isCorrectlyInserted = true;
        }


    }

    return grade;
}

void fillMatrix(int grades[][5]){

    for(int studentsNum = 0; studentsNum < 4; studentsNum++){
        for(int gradeNum = 0; gradeNum < 5; gradeNum++){
            grades[studentsNum][gradeNum] = insertVote();
        }
    }
}

void printMatrix(int mat[][5], int lastRow){

    if(lastRow == 0){
        lastRow = 4;
    }

    for (int row = 0; row < lastRow; row++){

        for(int col = 0; col < 5; col++){

            if(col == 0){

                cout <<"[ " << mat[row][col] << ", ";
            }
            else if(col == 4){
                cout << mat[row][col] << " ]" << endl;
            }
            else
                cout << mat[row][col] << ", ";
            
        }
    }
}