#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
	char name[20],lastName[20];
	int studentId,mid1Grade,mid2Grade,finalGrade;
	double average;

}stu[100];


struct Course{
	char courseName[60],courseCode[20];
	int currentStudentCount;
	struct Student myStudentArray[40];
};


void createNewStudent(struct Course *myCourse){
	printf("Enter student info as name , last name , id\n");
	scanf("%s %s %d",&myCourse->myStudentArray[myCourse->currentStudentCount].name,
	&myCourse->myStudentArray[myCourse->currentStudentCount].lastName,&myCourse->myStudentArray[myCourse->currentStudentCount].studentId);

}


struct Student * findStudentByID(int id, struct Course *myCourse){
	int i=0;
	for(i=0;i<20;i++){
		if(myCourse->myStudentArray[i].studentId == id){
			return &myCourse->myStudentArray[i];
		}
	}
	return NULL;
}

void setGradeOfStudent(struct Course *myCourse){
	int id,m1,m2,fi;
	printf("Enter student ID:\n");
	scanf("%d",&id);
	if(findStudentByID(id,myCourse) != NULL){
		printf("Enter student grades as midterm1 , midterm2 , final\n");
		scanf("%d %d %d",&m1,&m2,&fi);
		findStudentByID(id, myCourse)->mid1Grade = m1;
		findStudentByID(id, myCourse)->mid2Grade = m2;
		findStudentByID(id, myCourse)->finalGrade = fi;
	}
}

void findAndDisplayAverage(struct Course *myCourse){
	int id,m1,m2,fi;
	double avr;
	printf("Enter student ID:\n");
	scanf("%d",&id);
	if(findStudentByID(id,myCourse) != NULL){
		m1 = findStudentByID(id, myCourse)->mid1Grade;
		m2 = findStudentByID(id, myCourse)->mid2Grade;
		fi = findStudentByID(id, myCourse)->finalGrade;
		avr = (m1 + m2 + fi)/ 3;
		findStudentByID(id, myCourse) -> average = avr;
		printf("Average: %lf\n", avr);
	}

}

void displayAverageOfAllStudents(struct Course *myCourse){
	int i;
	printf("Name \t LastName \t ID \t Average\n");
	for(i=0;i<=myCourse->currentStudentCount;i++){
		printf("%s \t %s \t %d \t %lf\n",myCourse->myStudentArray[i].name,myCourse->myStudentArray[i].lastName,myCourse->myStudentArray[i].studentId,myCourse->myStudentArray[i].average);
	}
}

void displayAverageOfStudentsInInterval(struct Course *myCourse){
	int lowAvr,highAvr,i;
	printf("Enter average as low , high");
	scanf("%d %d",&lowAvr,&highAvr);
	printf("Name \t LastName \t ID \t Average\n");
	for(i=0;i<=myCourse->currentStudentCount;i++){
		if(myCourse->myStudentArray[i].average<=highAvr && myCourse->myStudentArray[i].average>=lowAvr){
			printf("%s \t %s \t %d \t %lf\n",myCourse->myStudentArray[i].name,myCourse->myStudentArray[i].lastName,myCourse->myStudentArray[i].studentId,myCourse->myStudentArray[i].average);
		}
	}
}



int main(){
	int select=1;
	struct Course myCourse;
	strcpy(myCourse.courseName,"Fundementals of Computer Programming");
	strcpy(myCourse.courseCode,"CSE114");
	myCourse.currentStudentCount = 0;

	
	while(select != 0){
		printf("1. Create new student\n");
		printf("2. Set grade of student\n");
		printf("3. Find and display average of a student\n");
		printf("4. Display average of all students\n");
		printf("5. Display students with average in an interval\n");
		printf("0. Exit\n");
		scanf("%d",&select);
		
		if(select == 1){
			createNewStudent(&myCourse);
			myCourse.currentStudentCount++;
		}
		if(select == 2){
			setGradeOfStudent(&myCourse);
		}
		if(select == 3){
			findAndDisplayAverage(&myCourse);
		}
		if(select == 4){
			displayAverageOfAllStudents(&myCourse);
		}
		if(select == 5){
			displayAverageOfStudentsInInterval(&myCourse);
		}
	} 
}
