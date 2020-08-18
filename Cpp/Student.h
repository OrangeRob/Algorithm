#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <iostream>

struct Student {
	std::string name;
	int score;

	bool operator<(const Student& otherStudent) {
		return score != otherStudent.score ? score < otherStudent.score : name < otherStudent.name;
	}

	friend std::ostream& operator<<(std::ostream& os, const Student& student) {
		os << "Student " << student.name << " : " << student.score << std::endl;
		return os;
	}
};

#endif //__STUDENT_H__