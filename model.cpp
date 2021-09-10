#include <fstream>
#include "model.h"
#include "vector3.h"


Model::Model(const char *filename){
	fstream file;

	file.open(filename);

	while(file.good()){
		string input;

		Vector3 vertex;
		file >> input;

		if(input == "v"){
			file >> vertex.x;
			file >> vertex.y;
			file >> vertex.z;
			vertices.push_back(vertex);
			center.add(vertex);
		}
		else if(input == "f"){
			file >> vertex.x;
			file >> vertex.y;
			file >> vertex.z;

			//vertex indices start from 1
			vertex.x -= 1;
			vertex.y -= 1;
			vertex.z -= 1;
			
			faces.push_back(vertex);
		}
	}
	
	center.divide((float)vertices.size());
	file.close();
}

void Model::mesh(){
	for(auto it : faces){
		triangles.push_back({vertices[it.x], vertices[it.y], vertices[it.z]});
	}
}