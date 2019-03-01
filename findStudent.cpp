#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int student_id, chapter_no, max_exercise, max_student = 122;
    cout << "Student Id, Chapter No, Max Exercise" << endl;
    cin >> student_id >> chapter_no >> max_exercise;

    cout << "Exercise No : " << (((student_id % 1000)+ chapter_no*20) % max_exercise) + 1 << endl;

    cout << "Checker Student : " << (((student_id % 1000) + chapter_no*5 + 60) % max_student) + 1 << endl;

    cout << "Checker Of : " << (((student_id %1000) - 1) - (chapter_no*5) + 62)%122;
    getch();

    return 0;
}
