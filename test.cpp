/*
#include <iostream>
#include "model.h"

using namespace std;

int main(){
	Model model("Monkey.txt");
	model.mesh();

	for(auto it : model.triangles){
		cout << "A : (" << it.a.x << " " << it.a.y << " " << it.a.z << ")\n";
		cout << "B : (" << it.b.x << " " << it.b.y << " " << it.b.z << ")\n";
		cout << "C : (" << it.c.x << " " << it.c.y << " " << it.c.z << ")\n";
	}

	return 0;
}
*/